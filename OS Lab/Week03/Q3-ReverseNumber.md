## Q3 - Write script to print given number in reverse order.

### Shell Script
```
echo '                   
#!/bin/bash
echo -n "Enter any number : "
read num
rev=""

while [ $num -gt 0 ]; do
  digit=$((num%10))
  rev="${rev}${digit}"
  num=$((num/10))
done
echo "Reversed Number : $rev" '> reverseNumber.sh
```

### Command to make it an executable script
```
chmod +x reverseNumber.sh
```


### Command to run the file
```
./reverseNumber.sh
```

### Output
![image](https://github.com/shrudex/DSE/assets/91502997/54f983e2-7f8a-494d-9c21-89965a9d4837)

