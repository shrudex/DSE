## Q8 - Write a shell script which accepts two strings and compares the two strings for equality.
+ Check if the given strings are empty or not.
+ If empty, display appropriate messages

### Shell Script
```
echo '
#!bin/bash
echo -n "Enter the first string : "
read str1
echo -n "Enter the second string : "
read str2

if [ -z "$str1" ] && [ -z "$str2" ]; then
  echo "Both the strings - $str1 & $str2 are EMPTY!"
elif [ -z "$str1" ]; then
  echo "First string is EMPTY"
elif [ -z "$str2" ]; then
  echo "Second string is EMPTY"
elif [ "$str1" == "$str2" ]; then
  echo "$str1 and $str2 are EQUAL strings"
else echo "$str1 and $str2 are UNEQUAL strings"
fi' > compare2Strings.sh
```

### Command to make it an executable script
```
chmod +x compare2Strings.sh
```


### Command to run the file
```
./compare2Strings.sh
```

### Output
![image](https://github.com/shrudex/DSE/assets/91502997/e93d7617-098a-49cb-813c-a620e8858376)
