
#!bin/bash
read -p "Enter the filename : " file
if [ ! -f "$file" ]; then
echo "404: File not found : $file !!!"
exit 1
fi

chmod +x "$file"

echo "Permission changed for the file - $file"
echo 
