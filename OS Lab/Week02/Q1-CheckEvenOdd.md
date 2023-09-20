## Q1 - Write a shell script to find if a given number is even or odd.

### Shell Script
```
echo '
#!/bin/bash

echo "Enter any number : "
read number

if [ $ ((number%2)) -eq 0 ]; then
  echo "Even number"
else
  echo "Odd number"
fi' > evenOdd.sh
```

### Command to make it an executable script
```
chmod +x evenOdd.sh
```

### Command to run the file
```
./evenOdd.sh
```

### Output
![image](https://github.com/shrudex/DSE/assets/91502997/6580e424-1c9b-4a35-994e-d1a223ae84cb)


