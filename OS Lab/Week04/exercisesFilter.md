## Exercises for sort, cut and tr:

### Table to test the above commands/filters:
![image](https://github.com/shrudex/DSE/assets/91502997/ff0370cc-2454-4656-af4c-449e1c720df2)



### Perform the following operations:
#### 1. Sort all records based on location.
```
sort -k3 < table.txt
```
- sort: This command is used to sort lines of text files.
- -k3: This option specifies that we want to sort based on the third column (Location).
- < table.txt: It takes the input from the table.txt file.

#### 2. Sort all records based on State.
```
sort -k4 < table.txt
```
- -k4: This option specifies that we want to sort based on the fourth column (State).
#### 3. Sort all records based on BMI index
```
sort -k12n < table.txt
```
- -k12n: This option specifies that we want to sort based on the twelfth column (BMI Index) numerically.

#### 4. Display all records sorted on State and the location (California -> Los Angeles, Oakland, San Francisco)
```
grep "California" table.txt | sort -k3
```
- grep "California" table.txt: This command filters the records that contain "California" in the State column.
- sort -k3: This sorts the filtered records based on the Location column (third column).

#### 5. Display only the Row no, Name, Age, Gender and BMI columns
```
cut -d' ' -f1,2,4,6,12 < table.txt
```
- cut: This command is used to cut out sections from each line of files.
- -d' ': This option specifies a space (' ') as the delimiter.
- -f1,2,4,6,12: This specifies the fields (columns) to be displayed.

#### 6. Change all names into upper case
```
tr 'a-z' 'A-Z' < table.txt
```
- tr: This command is used to translate characters.
- 'a-z' 'A-Z': This specifies to translate lowercase letters to uppercase letters.

#### 7. Sort all records based on age
```
sort -k7n < table.txt
```
- -k7n: This option specifies that we want to sort based on the seventh column (Age) numerically.
  
#### 8. Display all records ordered on Month in a file called Personnel_data_month2022.dat
```
sort -k9M < table.txt > Personnel_data_month2022.dat
```
- -k9M: This option specifies that we want to sort based on the ninth column (Month of entry) as a month.

#### 9. Display records where names begin with S and J. Store in a new file SJ_Names.dat
```
grep -E "^[S|J]" table.txt > SJ_Names.dat
```
- grep -E "^[S|J]": This command uses a regular expression to match names that start with either 'S' or 'J'.
- "> SJ_Names.dat": This redirects the matched records to a new file named SJ_Names.dat.

#### 10. Move columns Name, Location, State, Age and Index into a new file after sorting on Name field
```
cut -d' ' -f2,3,4,6,12 < table.txt | sort -k1 > New_File.txt
```
- cut -d' ' -f2,3,4,6,12: This command extracts and displays the specified columns.
- |: This pipe symbol is used to send the output of the first command as input to the second command.
- sort -k1: This sorts the output based on the first column (Name).
- "> New_File.txt": This redirects the sorted output to a new file named New_File.txt.
