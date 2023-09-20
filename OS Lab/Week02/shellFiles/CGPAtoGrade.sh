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
fi
