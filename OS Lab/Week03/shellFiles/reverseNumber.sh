
#!/bin/bash
echo -n "Enter any number : "
read num
rev=""

while [ $num -gt 0 ]; do
digit=$((num%10))
rev="${rev}${digit}"
num=$((num/10))
done
echo "Reversed Number : $rev" 
