
#!/bin/bash
read -p "Enter the file name: " file

if [ ! -f "$file" ]; then
echo "404: File not found : $file !!!"
exit 1
fi

read -p "Enter the start line : " startLine
read -p "Enter the number of lines to print : " numLines
sed -n "$startLine,$((startLine + numLines - 1))p" "$file"

echo 
