**7.1** Write PL/SQL block to display reverse of a number.
```
SET SERVEROUTPUT ON
DECLARE
  num number:= &num;
  reverse number:= 0;
  digit number;
BEGIN
  WHILE num!=0 LOOP
    digit:= MOD(num, 10);
    reverse:= reverse*10 + digit;
    num:= TRUNC(num/10);
  END LOOP;
  DBMS_OUTPUT.PUT_LINE('Reverse of the number is : ' || reverse);
END;
/
```

**7.2** Write a PL/SQL block to check a given word is palindrome or not.
```
SET SERVEROUTPUT ON
DECLARE
  string varchar2(20):= &string;
  charExtract varchar2(2);
  reverse varchar2(20);
BEGIN
  FOR i IN REVERSE 1..LENGTH(string) LOOP 
        charExtract := SUBSTR(string, i, 1); 
        reverse := reverse || '' || charExtract; 
  END LOOP;
  IF string = reverse THEN
    DBMS_OUTPUT.PUT_LINE(string || ' is a PALINDROME word.');
  ELSE
    DBMS_OUTPUT.PUT_LINE(string || ' is NOT a PALINDROME word.'); 
  END IF;
END;
/
```

**7.3** Write a PL/SQL block to accept an employee code from the user and display the employee details.
```
SET SERVEROUTPUT ON
DECLARE
  employeeCode EMP.EMPCODE%TYPE:= &employeeCode;
  employee EMP%ROWTYPE;
BEGIN
  SELECT * into employee from EMP where EMPCODE = employeeCode;
  DBMS_OUTPUT.PUT_LINE(employee.EMPCODE);
  DBMS_OUTPUT.PUT_LINE(employee.NAME);
  DBMS_OUTPUT.PUT_LINE(employee.QUALIFICATION);
  DBMS_OUTPUT.PUT_LINE(employee.PHONE);
  DBMS_OUTPUT.PUT_LINE(employee.EMAIL);
  DBMS_OUTPUT.PUT_LINE(employee.DESIGNATION);
  DBMS_OUTPUT.PUT_LINE(employee.SALARY);
END;
/
```

**7.4** Write a PL/SQL block to count number of vowels, consonants, numbers and special characters in a sentence.
```
SET SERVEROUTPUT ON
DECLARE
  string varchar2(50):= &string;
  countVowels number:= 0;
  countConsonants number:= 0;
  countNumbers number:= 0;
  countSpecialCharacters number:= 0;
  extractedCharacter char(1);
BEGIN
  FOR i IN 1..LENGTH(string) LOOP
    extractedCharacter:= SUBSTR(string, i, 1);
    IF extractedCharacter IN ('A', 'E', 'I', 'O', 'U') OR extractedCharacter IN ( 'a', 'e', 'i', 'o', 'u' ) THEN 
          countVowels := countVowels + 1; 
    ELSIF extractedCharacter NOT IN ('A', 'E', 'I', 'O', 'U') AND extractedCharacter IN ( 'a', 'e', 'i', 'o', 'u' ) THEN
          countConsonants := countConsonants + 1;
    ELSIF extractedCharacter IN ('0', '1', '2', '3', '4', '5', '6', '7', '8', '9') THEN
          countNumbers := countNumbers + 1;
    ELSE
          countSpecialCharacters := countSpecialCharacters + 1;
    END IF;
  END LOOP;
  DBMS_OUTPUT.PUT_LINE("Vowels : " || countVowels);
  DBMS_OUTPUT.PUT_LINE("Consonants : " || countConsonants);
  DBMS_OUTPUT.PUT_LINE("Numbers : " || countNumbers);
  DBMS_OUTPUT.PUT_LINE("Special Characters : " || countSpecialCharacters);
END;
/
```
