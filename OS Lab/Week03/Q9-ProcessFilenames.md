## Q9 - Write a shell script to accept many filenames through command line. Do the following for each filename 
+ If it is an ordinary file, display its content and also check whether it has execute permission. 
+ If it is directory, display the number of files in it. 
+ If the file/directory does not exist, display a message

### Shell Script
```
echo '
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
done' > processFilenames.sh
```

### Command to make it an executable script
```
chmod +x processFilenames.sh
```


### Command to run the file
```
./processFilenames.sh
```

### Output
![image](https://github.com/shrudex/DSE/assets/91502997/91dd3001-e541-473b-8932-d3896e7794e6)
![image](https://github.com/shrudex/DSE/assets/91502997/739149aa-dac8-44c1-88b1-0c1d4ec3a90b)
