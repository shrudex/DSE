## Q4 - Write script to print the sum of digits of a given number.

### Shell Script
```
echo '                 
#!/bin/bash
echo -n "Enter any number : "
read num
sum=0

while [ $num -gt 0 ]; do
digit=$((num%10))
sum=$((sum+digit))
num=$((num/10))
done
echo "Sum of digits = $sum"' > sumOfDigits.sh
```

### Command to make it an executable script
```
chmod +x sumOfDigits.sh
```


### Command to run the file
```
./sumOfDigits.sh
```

### Output
![image](https://github.com/shrudex/DSE/assets/91502997/360b250e-4cc2-4e47-8d04-2988629761f3)
