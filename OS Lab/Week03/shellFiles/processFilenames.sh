
#!/bin/bash

for filename in "$@"; do
if [ ! -e "$filename" ]; then
echo "File/directory - $filename does not exist."
else
if [ -f "$filename" ]; then
echo "Contents of file : $filename :"
cat "$filename"

[ -x "$filename" ] && echo "$filename has execute permissions."
elif [ -d "$filename" ]; then
numFiles=$(find "$filename" -type f | wc -l)
echo "Number of files in directory - $filename : $numFiles"
fi
fi
done
