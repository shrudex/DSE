
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
fi
