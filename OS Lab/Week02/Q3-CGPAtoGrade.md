## Q3 - Write a shell script to display grade of a user. If cgpa (user input) is:
- 7.0, grade ‘C’
- 8.0, grade ‘B’
- 9.0 grade ‘A’
- 10.0 grade ‘A+’, any other cgpa, grade is ‘D'
### Shell Script
```
echo '
#!/bin/bash
echo "Enter your CGPA : "
read cgpa

if (( $(echo "$cgpa == 10.0" | bc -l) ))
  then echo "Grade : A+"
elif (( $(echo "$cgpa >= 9.0" | bc -l) ))
  then echo "Grade : A"
elif (( $(echo "$cgpa >= 8.0" | bc -l) ))
  then echo "Grade : B"
elif (( $(echo "$cgpa >= 7.0" | bc -l) ))
  then echo "Grade : C"
else echo "Grade : D"
fi' > CGPAtoGrade.sh
```

### Command to make it an executable script
```
chmod +x CGPAtoGrade.sh
```


### Command to run the file
```
./CGPAtoGrade.sh
```

### Output
![image](https://github.com/shrudex/DSE/assets/91502997/495c00f3-d5b6-41d0-9598-d9e79d42f6e8)
