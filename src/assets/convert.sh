#!/bin/bash

PYTHON_BIN=".venv/bin/python"
PYTHON_SCRIPT="gif_to_c_array.py"

# Find all .gif files in the current directory
GIF_FILES=$(find . -type f -name "*.gif")

# Check if any GIF files are found
if [ -z "$GIF_FILES" ]; then
    echo "No GIF files found in the current directory."
    exit 1
fi

# Loop through each found .gif file (handling filenames with spaces)
echo "$GIF_FILES" | while IFS= read -r GIF_FILE; do
    echo "Processing: $GIF_FILE"
    "$PYTHON_BIN" "$PYTHON_SCRIPT" --file "$GIF_FILE"
done
