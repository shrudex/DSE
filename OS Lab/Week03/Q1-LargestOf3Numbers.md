## Q1 - Write a shell script to find the largest of three numbers.

### Shell Script
```
echo '
#!/bin/bash
echo "Enter 3 numbers : "
read n1
read n2
read n3
if [ $n1 -gt $n2 ] && [ $n1 -gt $n3 ]; then 
  echo "$n1 is GOAT!"
elif [ $n2 -gt $n1 ] && [ $n2 -gt $n3 ]; then
  echo "$n2 is GOAT!"
else "$n3 is GOAT!"
fi' > largestOf3.sh
```

### Command to make it an executable script
```
chmod +x largestOf3.sh
```


### Command to run the file
```
./largestOf3.sh
```

### Output
![image](https://github.com/shrudex/DSE/assets/91502997/475d9b98-7f86-4022-af29-7245bae23cc3)

