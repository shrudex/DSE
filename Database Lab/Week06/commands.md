**6.1** Display name of all employees in Upper, Lower, 1st letter capital format.
```
SELECT NAME, 
       UPPER(NAME) AS UPPER_NAME, 
       LOWER(NAME) AS LOWER_NAME, 
       INITCAP(NAME) AS INITCAP_NAME 
FROM EMP;
```
**6.2** Display employee name and Designation of all the employees in the following format (using concatenation operator ||) “Rajesh Works as Developer.”
```
SELECT NAME || ' Works as ' || DESIGNATION
FROM EMP;
```

**6.3** Assume that you are displaying salary value in place with 10 space width. Display the salary so that remaining left side spaces after displaying salary value is padded with * characters. (LAPD).
```
SELECT LPAD(SALARY, 10, '*') AS SALARY_PADDED
FROM EMP;
```
**6.4** Try the question 6.3 with RPAD.
```
SELECT RPAD(SALARY, 10, '*')
FROM EMP;
```
**6.5** Retrieve number of characters in employee names.
```
SELECT NAME, LENGTH(NAME)
FROM EMP;
```
**6.6** Retrieve substring part of employee email ids starting from 3rd position to 9th position characters.
```
SELECT NAME, SUBSTR(EMAIL, 3, 7)
FROM EMP;
```
**6.7** Retrieve the emails of all employees by replacing digisol with digitech.
```
SELECT NAME, REPLACE(EMAIL, 'digisol', 'digitech')
FROM EMP;
```
**6.8** Retrieve employee name and Dependent-Name concatenated (concat ())
```
SELECT e.NAME || '-' || d.DEP_NAME
FROM EMP e
INNER JOIN FAMILY_DEPENDENTs d
ON e.empcode = d.EMPNO;
```
**6.9** Display ClientID and number of characters from Client table.
```
SELECT CLIENTID, LENGTH(CLIENTID)
FROM CLIENT;
```
**6.10** Retrieve right trimmed ClientID (RTRIM) and number of characters in the trimmed client id.
```
SELECT RTRIM(CLIENTID) AS "Trimmed_ClientID", LENGTH(RTRIM(CLIENTID))
FROM CLIENT;
```
**6.11** Try 6.10 with LTRIM and TRIM also.
```
SELECT LTRIM(CLIENTID) AS "Left_Trimmed_ClientID", LENGTH(LTRIM(CLIENTID))
FROM CLIENT;

SELECT TRIM(CLIENTID) AS "Trimmed_ClientID", LENGTH(TRIM(CLIENTID))
FROM CLIENT;
```
**6.12** Display ASCII value of ‘A’ and Character corresponding to ascii value 65. (ASCII, CHR)
```
SELECT ASCII('A') AS "ASCII_Value", CHR(65) AS "Corresponding_Character"
FROM DUAL;
```
**6.13** Display the value 123.456 truncated to 2nd decimal position.
```
SELECT TRUNC(123.456, 2)
FROM DUAL;
```
**6.14** Consider any number (say 9) Retrieve square root, square and 5th power of the number.
```
SELECT SQRT(9) AS "Square_Root", POWER(9,2) AS "Square", POWER(9,5) AS "5th_Power"
FROM DUAL;
```
**6.15** Display the value 123.456 rounded to 2nd decimal position.
```
SELECT ROUND(123.456, 2)
FROM DUAL;
```
**6.16** Retrieve absolute value of -123 and remainder after dividing 123 from 10.
```
SELECT ABS(-123) AS "Absolute_Value", MOD(123,10) AS "Remainder"
FROM DUAL;
```
**6.17** Retrieve floor and ceiling value of 234.36 and -234.26.
```
SELECT FLOOR(234.36), CEIL(-234.26)
FROM DUAL;
```
**6.18** Display start and end dates of projects in the format DD-Month-YYYY format. (use TO_CHAR)
```
SELECT TO_CHAR(START_DATE, 'DD-Month-YYYY') AS "Start_Date", TO_CHAR(END_DATE, 'DD-Month-YYYY') AS "End_Date"
FROM PRJ_DETAILS;
```
**6.19** Display month and Year on which projects are actually closed. (use TO_CHAR)
```
SELECT TO_CHAR(END_DATE, 'Month-YYYY') AS "Month_Year"
FROM PRJ_DETAILS;
```
**6.20** Display month, day, year extracted from Start_Date from Prj_Details. (use TO_CHAR)
```
SELECT TO_CHAR(START_DATE, 'Month') AS "Month", TO_CHAR(START_DATE, 'DD') AS "Day", TO_CHAR(START_DATE, 'YYYY') AS "Year"
FROM PRJ_DETAILS;
```
**6.21** Display the project name and the number of months between the start and end dates of the projects. Use MONTHS_BETWEEN ()
```
SELECT PRJ_NAME, MONTHS_BETWEEN(END_DATE, START_DATE)
FROM PRJ_DETAILS;
```
**6.22** Display all the project name, end_date of the projects and the date after 2 months of end_date. Use ADD_MONTHS ()
```
SELECT Prj_Name, End_Date, ADD_MONTHS(end_Date, 2)
FROM Prj_Details;
```
**6.23** Find the date of next Thursday based on today’s date.
```
SELECT NEXT_DAY(SYSDATE, 'THURSDAY')
FROM DUAL;
```
