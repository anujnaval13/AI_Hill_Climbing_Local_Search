#!/bin/bash

# Check if the number of command-line arguments is correct
if [ $# -ne 2 ]; then
  echo "Usage: $0 input_file output_file"
  exit 1
fi

input_file="$1"
output_file="$2"

./main "$input_file" "$output_file"
