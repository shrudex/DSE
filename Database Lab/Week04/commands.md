**4.1** Retrieve all Clients information
```
SELECT * from CLIENT;
```

**4.2** Display name, phone and email of employees having designation DEVELOPER.
```
SELECT Name, Phone, Email FROM Emp
WHERE Designation = 'DEVELOPER';
```

**4.3** Display name of employees who are working under employee with code 106.
```
SELECT NAME from emp 
WHERE REPORTS_TO = 106;
```

**4.4** Display name and email id of employees working as TECHNICAL HEAD and Designation BTECH.
```
SELECT Name, Email FROM EMP
WHERE QUALIFICATION = 'BTECH' AND DESIGNATION = 'TECHNICAL HEAD';
```

**4.5** Find name of employees who is drawing salary in the range 100000 to 200000. (two queries using 
comparison and BETWEEN)
```
--using comparison
SELECT Name FROM Emp WHERE Salary >= 100000 AND Salary <= 200000;

--using range
SELECT Name FROM Emp WHERE Salary BETWEEN 100000 AND 200000;
```

**4.6** List the Skills owned by the employee with Employee number 101.
```
SELECT SKILLID from EMP_SKILL
where EMPNO=101;
```

**4.7** Display the name of skills that employee with emp code 101 is having.
```
SELECT SKILL.SKILLNAME FROM SKILL INNER JOIN EMP_SKILL ON SKILL.SkillID = EMP_SKILL.SkillID 
WHERE EMP_SKILL.EmpNo = 101; 
```

**4.8** Retrieve Employee code of employees who worked with clients C1 or C2 and having rating either A or B.
```
SELECT EMPCODE FROM WORK_EXP
WHERE CLIENTID IN ('C1', 'C2') 
AND Rating IN ('A', 'B');
```

**4.9** Display the name of Employees who worked with client C2 and having Rating B.
```
SELECT e.Name FROM EMP e 
INNER JOIN WORK_EXP w ON e.EMPCODE = w.EmpCode 
WHERE w.ClientID = 'C2' AND w.Rating = 'B';
```

**4.10** List How many dependents an employee RAVI is having?
```
SELECT COUNT(*) 
FROM EMP 
WHERE REPORTS_TO = (SELECT EMPCODE FROM EMP WHERE NAME = 'RAVI');
```

**4.11** Retrieve employee name, Designation and Total annual salary (Salaryx12) and rename the column as Annual_Salary. (using join)
```
SELECT e.Name, e.Designation, (e.Salary * 12) AS Annual_Salary FROM EMP e;
```

**4.12** List name of all employees and their dependents name if exist otherwise null.
```
SELECT e.NAME AS Name, m.NAME AS Dependents
FROM EMP e
LEFT JOIN EMP m ON e.EMPCODE = m.REPORTS_TO;
```

**4.13** List the project leader name and name of projects which have completed without time slippage and budget slippage. 
```
SELECT e.Name AS ProjectLeader, p.ProjectName AS ProjectName
FROM PRJ_DETAILS p INNER JOIN EMP e ON p.ProjectLeaderCode = e.EmployeeCode 
WHERE p.ActualEndDate <= p.TargetEndDate AND p.ActualBudget <= p.TargetBudget;
```

**4.14** Display employee name, Salary and pay check details corresponding to month -March.
```
SELECT e.Name, e.Salary, p.empcode, p.pay_date, p.regular_increment, p.other_incentives, p.advance_tax
FROM EMP e INNER JOIN pay_check p ON e.EmpCode = p.EmpCode 
WHERE p.PAY_DATE BETWEEN '01-MAR-21' AND '31-MAR-21';
```

**4.15** Find the Employee name and his higher authority name, phone to who the employee reports.
```
SELECT e.Name AS EmployeeName, m.Name AS HigherAuthorityName, m.Phone 
FROM EMP e INNER JOIN EMP m ON e.Reports_To = m.EmpCode;
```

**4.16** Display the project details in the descending order of their actual closing date.
```
SELECT * FROM PRJ_DETAILS ORDER BY Actual_End_Date DESC;
```

**4.17** Display Employee names, skill name in ascending order of employee number and descending order of their skill experience.
```
SELECT e.Name AS EmployeeName, s.SkillName 
FROM EMP e INNER JOIN EMP_SKILL es ON e.EMPCODE = es.EmpNo 
INNER JOIN Skill s ON es.SkillID = s.SkillID 
ORDER BY e.EMPCODE ASC, es.Skill_Experience DESC;
```

**4.18** Display Employee name, dependent name, age where the relationship is SON and sort employee name in ascending and age in descending order.
```
SELECT e.Name AS EmployeeName, d.Dep_Name, d.AGE AS Age 
FROM EMP e INNER JOIN FAMILY_DEPENDENTS d ON e.EMPCODE = d.EMPNO 
WHERE d.Relationship = 'SON' 
ORDER BY e.Name ASC, d.Age DESC;
```

**4.19** Retrieve Employee names in Ascending order and Project names in descending order in which employees have worked.
```
SELECT e.name, pd.prj_name 
FROM emp e 
JOIN work_exp we ON e.empcode = we.empcode 
JOIN prj_details pd ON we.prj_id = pd.prj_id 
WHERE e.empcode IN (SELECT we1.empcode 
                    FROM work_exp we1 
                    JOIN emp e1 ON e1.empcode = we1.empcode 
                    WHERE e1.empcode = 101) 
ORDER BY e.name ASC, pd.prj_name DESC;
```

**4.20** Find name of employees who have worked in SPYDER or APOLLO (use set Operator)
```
SELECT DISTINCT emp.name 
FROM emp 
INNER JOIN project ON emp.empcode = project.empcode 
WHERE project.name IN ('SPYDER', 'APOLLO');
```

**4.21** Find the name of employees who are having both skills Oracle & AZURE (use set Operator)
```
SELECT emp.name 
FROM emp 
INNER JOIN emp_skill ON emp.empcode = emp_skill.empcode 
INNER JOIN skill ON emp_skill.skillcode = skill.skillcode 
WHERE skill.name IN ('Oracle', 'AZURE')
GROUP BY emp.empcode, emp.name 
HAVING COUNT(DISTINCT skill.name) = 2;

```

**4.22** Retrieve the name of employees who do not work in project JUPITOR (use set Operator)
```
SELECT name 
FROM emp 
WHERE empcode NOT IN (SELECT DISTINCT empcode FROM project WHERE name = 'JUPITOR');

```

**4.23** Display the name of employee who reports to none.
```
SELECT name 
FROM emp 
WHERE empcode NOT IN (SELECT DISTINCT reports_to FROM emp WHERE reports_to IS NOT NULL);

```

**4.24** Display all employee names, email whose name starts with RA.
```
SELECT name, email 
FROM emp 
WHERE name LIKE 'RA%';

```

**4.25** Retrieve the name of projects which are started between 01-01-2020 to 41-12-2020.
```
SELECT name 
FROM project 
WHERE start_date BETWEEN '2020-01-01' AND '2020-12-31';

```

**4.26** Display the name of employees who has at least few skills that employee with employee number 101 is having.
```
```
