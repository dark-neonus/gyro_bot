""" Git to C array utility """
import argparse
import pathlib

from PIL import Image, ImageSequence
import numpy as np


def frame_to_c_array(frame: Image, width: int, height: int) -> list:
    """ Convert a frame to a byte-packed array for Adafruit OLEDs """
    frame = frame.convert("1")  # Convert to monochrome (1-bit)
    pixels = np.array(frame)

    # Pad width to the next byte boundary (if not already multiple of 8)
    padded_width = (width + 7) // 8 * 8

    # Convert to 1-bit packed format
    byte_array = []
    for y in range(height):
        row_bytes = []
        for x in range(0, padded_width, 8):
            byte = 0
            for bit in range(8):
                if x + bit < width:  # Ensure we don't go out of bounds
                    byte |= (1 if pixels[y, x + bit] else 0) << (7 - bit)
            row_bytes.append(byte)
        byte_array.append(row_bytes)

    return byte_array

def gif_to_c_arrays(file_path: str) -> tuple[int, int, list]:
    """ Gif to C arrays """
    gif = Image.open(file_path)

    frames = []

    width, height = gif.size
    num_frames = gif.n_frames
    print(f"GIF size: {width}x{height}, Number of frames: {num_frames}")

    for frame in ImageSequence.Iterator(gif):
        frames.append(frame_to_c_array(frame, width, height))

    return frames, width, height

def get_array_name(filename: str, i: int):
    """ Get array filename """
    return f"anim_{filename}_frame_{i}"

def frames_to_file(frames: list, width: int, height: int, filename: str):
    """ Frames to file """
    header = (
        f"// C Array of {filename}.gif\n"
        f"#ifndef ANIMATION_{filename.upper()}\n"
        f"#define ANIMATION_{filename.upper()}\n"
        "#include <memory>\n"
        "#include <vector>\n"
        "#include \"../Animation.h\"\n"
    )

    content1 = []
    for i, frame in enumerate(frames):
        frame_text = f"const uint8_t {get_array_name(filename, i)}[] PROGMEM = " + "{\n"
        for row in frame:
            frame_text += "    " + ", ".join(f"0x{byte:02X}" for byte in row) + ",\n"
            # frame_text += f"0b{''.join(map(str, row))},{' ' * 4}//"
            # frame_text += "".join(("#" if value else " ") for value in row)
            # frame_text += "\n"
        frame_text += "};"

        content1.append(frame_text)

    content2 = (
        f"std::shared_ptr<Animation> animation_{filename} = std::make_shared<Animation>(\n" +
        f"\t\"{filename}\",\n" +
        f"\t{width}, {height},\n" +
        "\tstd::vector<const uint8_t*>({\n" +
        ",\n".join("\t" + get_array_name(filename, i) for i in range(len(frames))) +
        "\n\t})" +
        "\n);"
    )

    footer = "#endif"

    with open(f"anim_{filename}.h", "w", encoding="utf-8") as file:
        file.write("\n\n".join([header] + content1 + [content2] + [footer]))



def main() -> str:
    """ Main function """
    # Pass
    parser = argparse.ArgumentParser(description="Process some integers.")

    parser.add_argument("--file",
                        type=pathlib.Path,
                        help="Path to .gif file")

    args = parser.parse_args()
    filename = args.file.stem
    filetype = args.file.suffix

    if filetype != ".gif":
        print(f"File must be of type \".gif\", not \".{filetype}\"")
        return "Failed to convert because of icorrect file type!"

    frames, width, height = gif_to_c_arrays(args.file)

    frames_to_file(frames, width, height, filename)

    return "Succesfully convereted .gif to .h file!"

if __name__ == "__main__":
    print(main())
