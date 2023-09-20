
#!/bin/bash
while true; do
echo "Choose any option:"
echo "A. Display long listing of files."
echo "B. Display long listing of files including hidden files."
echo "C. Delete files from directory"
echo "D. Exit"

read ch

case "$ch" in
A) 
ls -l
;;
B)
ls -la
;;
C)
echo "Enter the directory where you want to delete files : "
read dir
echo "Enter the file extension (e.g. -> .txt): "
read ext
rm "$dir"/*"$ext"
echo "Files with extension $ext deleted from $dir"
;;
D)
echo "Do you wish to quit? (y/n?)"
read confirm
if [ "$confirm" = "y" ]; then
echo "Exiting..."
exit 0
fi
;;
*)
echo "Invalid option. Please choose a valid option."
;;
esac
done
