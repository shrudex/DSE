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

**7.5** Write  a  PL/SQL  block  to  accept  an  employee  code  and  project  id  to  find  the  rating  obtained  on  the project. Depending on the rating assign an additional incentive (A-10000, B-5000, C-3000). Display the information in the following format-
+ Employee Number:
+ Employee Name:
+ Salary:
+ Project Name:
+ Rating:
+ Incentive:
+ Total Salary: Salary + (A-10000, B-5000, C-3000)

Update the Other_incentive of employee in Pay_check depending on rating.
```
SET SERVEROUTPUT ON
DECLARE
    eCode emp.EMPCODE%TYPE := &eCode;
    prjId PRJ_DETAILS.PRJID%TYPE := &prjId;
    empName EMP.NAME%TYPE;
    s EMP.BASIC_SALARY%TYPE;
    pName PRJ_DETAILS.PRJ_NAME%TYPE;
    r VARCHAR2(1);
    inc PAY_CHECK.REGULAR_INCENTIVE%TYPE;
    tS NUMBER;
BEGIN
    SELECT e.Name, e.BASIC_SALARY, p.PRJ_NAME, ex.RATING
    INTO empName, s, pName, r
    FROM prj_details p
    INNER JOIN experience ex
    ON p.prjid = ex.prjid
    INNER JOIN emp e
    ON ex.EMPNO = e.EMPCODE;
    WHERE e.EMPCODE = eCode
    AND p.PRJID = prjId;
    IF r = 'A' THEN
        inc := 10000;
    ELSIF r = 'B' THEN
        inc := 5000;
    ELSE
        inc := 3000;
    END IF;
    tS := tS + inc;
    DBMS_OUTPUT.PUT_LINE('Employee Number: ' || eCode);
    DBMS_OUTPUT.PUT_LINE('Employee Name: ' || empName);
    DBMS_OUTPUT.PUT_LINE('Salary: ' || s);
    DBMS_OUTPUT.PUT_LINE('Project Name: ' || pName);
    DBMS_OUTPUT.PUT_LINE('Rating: ' || r);
    DBMS_OUTPUT.PUT_LINE('Incentive: ' || inc);
    DBMS_OUTPUT.PUT_LINE('Total Salary: ' || tS);
    UPDATE PAY_CHECK
    SET other_incentive = inc
    WHERE EMPCODE = eCode;
END;
/
```

**7.6** Write a PL/SQL block to calculate Jan-2021 monthly salary of employee and other components of
salary depending on Salary values in EMP table for the employee number 100. Display the salary
information of employee 100 in the following format.
+ Name:
+ Basic_Salary: Salary from EMP table
+ Regular Increment: Regular_Increment
+ Increased Basic Salary: Salary+ Regular_Increment
+ Performance incentive: performnce_incentive
+ DA: 50% of Increased Basic Salary.
+ PF: 12% of Increased Basic Salary.
+ Other Incentive: other_incentives
+ Advance tax paid: advance_tax
+ Monthly Gross Salary: Salary+Regular_Increment + Performnce_incentive + DA + PF + other_incentives.
+ Monthly Take home salary: Gross Salary – PF- advance_tax.
```
DECLARE
    Name VARCHAR2(50);
    s NUMBER;
    rinc NUMBER;
    pinc NUMBER;
    da NUMBER;
    pf NUMBER;
    oinc NUMBER;
    advTax NUMBER;
    gs NUMBER;
    tHsal NUMBER;
    iS NUMBER;
BEGIN
    SELECT e.NAME, e.BASIC_SALARY, p.REGULAR_INCREMENT, p.PERFORMANCE_INCENTIVE, p.DA, p.PF, p.OTHER_INCENTIVE, p.ADVANCE_TAX INTO
    INTO Name, s, rinc, pinc, da, pf, oinc, advTax
    FROM emp
    INNER JOIN PAY_CHECK p ON e.EMPCODE = p.EMPCODE
    WHERE e.empcode = 100 AND TO_DATE(p.PAY_DATE, 'MON-YYYY') = 'JAN-2021';
    iS = s + rinc;
    da = 0.5*iS;
    pf = 0.12*iS;
    gS = s + rinc + pinc + da + pf + oinc;
    tHsal = gS - pf - advTax;
    DBMS_OUTPUT.PUT_LINE('Name: ' || Name);
    DBMS_OUTPUT.PUT_LINE('Basic_Salary: ' || s);
    DBMS_OUTPUT.PUT_LINE('Regular Increment: ' || rinc);
    DBMS_OUTPUT.PUT_LINE('Increased Basic Salary: ' || iS);
    DBMS_OUTPUT.PUT_LINE('Performance Incentive: ' || pinc);
    DBMS_OUTPUT.PUT_LINE('DA: ' || da);
    DBMS_OUTPUT.PUT_LINE('PF: ' || pf);
    DBMS_OUTPUT.PUT_LINE('Other Incentives: ' || oinc);
    DBMS_OUTPUT.PUT_LINE('Advance Tax Paid: ' || advTax);
    DBMS_OUTPUT.PUT_LINE('Monthly Gross Salary: ' || gS);
    DBMS_OUTPUT.PUT_LINE('Monthly Take Home Salary: ' || tHsal);
END;
/
```

**7.7** 
```
SET SERVEROUTPUT ON
DECLARE
    Name VARCHAR2(50);
    s NUMBER;
    rinc NUMBER;
    pinc NUMBER;
    da NUMBER;
    pf NUMBER;
    oinc NUMBER;
    advTax NUMBER;
    gs NUMBER;
    tHsal NUMBER;
    iS NUMBER;
    CURSOR empCursor IS
        SELECT EMP.*, p.REGULAR_INCREMENT, p.PERFORMANCE_INCENTIVE, p.DA, p.PF, p.OTHER_INCENTIVE, p.ADVANCE_TAX
        FROM EMP e
        INNER JOIN PAY_CHECK p ON e.EMPCODE = p.EMPCODE
        WHERE TO_DATE(PAY_CHECK.PAY_DATE, 'MON-YYYY') = 'JAN-2021';

BEGIN
    FOR R IN empCursor LOOP
        Name := R.NAME;
        s := R.BASIC_SALARY;
        rinc := R.REGULAR_INCREMENT;
        pinc := R.PERFORMANCE_INCENTIVE;
        da := R.DA;
        pf := R.PF;
        oinc := R.OTHER_INCENTIVE;
        advTax := R.ADVANCE_TAX;

        iS := s + rinc;
        da := 0.5*iS;
        pf := 0.12*iS;
        gS := s + rinc + pinc + da + pf + oinc;
        tHsal := gS - pf - advTax;

        DBMS_OUTPUT.PUT_LINE('Name: ' || Name);
        DBMS_OUTPUT.PUT_LINE('Basic_Salary: ' || s);
        DBMS_OUTPUT.PUT_LINE('Regular Increment: ' || rinc);
        DBMS_OUTPUT.PUT_LINE('Increased Basic Salary: ' || iS);
        DBMS_OUTPUT.PUT_LINE('Performance Incentive: ' || pinc);
        DBMS_OUTPUT.PUT_LINE('DA: ' || da);
        DBMS_OUTPUT.PUT_LINE('PF: ' || pf);
        DBMS_OUTPUT.PUT_LINE('Other Incentives: ' || oinc);
        DBMS_OUTPUT.PUT_LINE('Advance Tax Paid: ' || advTax);
        DBMS_OUTPUT.PUT_LINE('Monthly Gross Salary: ' || gS);
        DBMS_OUTPUT.PUT_LINE('Monthly Take Home Salary: ' || tHsal);
    END LOOP;
END;
/
```
