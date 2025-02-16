""" Git to C array utility """
import argparse
import pathlib

from PIL import Image, ImageSequence
import numpy as np

def frame_to_c_array(frame: Image, width: int, height: int) -> list:
    """ Convert a frame to a 2D array representing pixels (1 for white, 0 for black) """
    frame = frame.convert("1")  # Convert to monochrome (1-bit)
    pixels = np.array(frame)

    # Create 2D array where each pixel is represented as 1 (white) or 0 (black)
    pixel_array = [[1 if pixels[y, x] else 0 for x in range(width)] for y in range(height)]

    return pixel_array

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

def frames_to_file(frames: list, width: int, height: int, filename: str):
    """ Frames to file """
    header = (
        f"// C Array of {filename}.gif\n"
        f"#ifndef ANIMATION_{filename.upper()}\n"
        f"#define ANIMATION_{filename.upper()}\n"
    )

    content = []
    for i, frame in enumerate(frames):
        frame_text = f"const uint8_t anim_{filename}_frame_{i}[] PROGMEM = " + "{\n"
        for row in frame:
            frame_text += f"0b{''.join(map(str, row))},{' ' * 4}//"
            frame_text += "".join(("#" if value else " ") for value in row)
            frame_text += "\n"
        frame_text += "};"

        content.append(frame_text)

    footer = "#endif"

    with open(f"anim_{filename}.h", "w", encoding="utf-8") as file:
        file.write("\n\n".join([header] + content + [footer]))



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
