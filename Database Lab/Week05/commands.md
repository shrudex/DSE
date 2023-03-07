5.1 List all employee names who are having same designation as that of employee 100.

```
Select NAME from EMP
Where DESIGNATION = (Select DESIGNATION from EMP
                     Where EMPCODE = 100);
```

5.2 Find the name of all employees who reports to Vijay.  (use set membership)
```
SELECT Name FROM EMP 
WHERE REPORTS_TO = (SELECT EMPCODE FROM EMP WHERE Name = 'VIJAY');
```

5.3 List the name, designation and email of employees who have worked in the at leastone of the projects in which Vijay has worked. (use set membership)
```
select e.name from emp e where e.empcode in (
select W.empcode from work_exp w
where W.prjid in (SELECT w.prjid from work_exp w where
w.empcode IN ((select e.empcode from emp e where e.name='VIJAY'))));
```

5.4 List the name of employees who has Daughters.
```
SELECT e.NAME from EMP e
JOIN FAMILY_DEPENDENTS f on e.empcode = f.empno
WHERE e.empcode in ((Select f.empno from family_dependents 
			   where f.RELATIONSHIP = 'DAUGHTER'));
```

5.5 List the name of employees who do not work on SPYDER. (use set membership)
```
SELECT NAME
FROM EMP
WHERE EMPCODE NOT IN (
    SELECT EMPCODE
    FROM WORK_EXP
    WHERE PRJID = (
        SELECT PRJID
        FROM PRJ_DETAILS
        WHERE PRJ_NAME = 'SPYDER'
    )
);
```

5.6 List the employees who have at least one skill that employees working on project P1 are possessing. (set comparison)
```
SELECT NAME FROM EMP
WHERE EMPCODE IN ( SELECT EMPNO FROM EMP_SKILL
WHERE SKILLID IN ( SELECT SKILLID FROM EMP_SKILL WHERE EMPNO IN (
SELECT EMPCODE FROM WORK_EXP WHERE PRJID = 'P1')));
```

5.7 List the employee names who has more work experience in project P1 compared to experience of every employee working in project P2. (set comparison)
```
SELECT e.NAME
FROM EMP e
JOIN work_EXP we1 ON e.EMPCODE = we1.EMPCODE
JOIN work_EXP we2 ON e.EMPCODE = we2.EMPCODE
WHERE we1.prjid = 'P1'
GROUP BY e.empcode, e.name
HAVING MAX(we1.work_experience) > COALESCE(MAX(CASE WHEN we2.prjid = 'P2' THEN we2.work_experience END), 0);
```

5.8 List the name of employees who workedin the project and client combinations in which Empcode 100 has worked. (Use set cardinality) 
```
Select e.Name from EMP e
Join WORK_EXP w on e.empcode = w.empcode
Where w.prjid in (Select prjid from work_exp where empcode = 100) and clientid in (Select clientid from work_exp where empcode = 100);
```

5.9 List the name of employees who didn’t work on any of the project in which employee with empcode 106 has worked. (Use set cardinality)
```
SELECT DISTINCT e.Name from EMP e
JOIN WORK_EXP w on e.empcode = w.empcode
WHERE w.prjid NOT IN (Select prjid from work_exp where empcode = 106);
```

5.10 Find  the  name  of projects  for  which  Allocated  budget  is  at  least  more  than  the  total  salary  of employees working on those projects. (correlation variable)
```
SELECT DISTINCT p.PRJ_NAME from PRJ_DETAILS p
JOIN work_exp w on p.prjid = w.prjid
JOIN emp e on w.empcode = w.empcode
where p.BUDGET_ALLOCATED > (Select SUM(SALARY) from EMP where e.empcode = w.empcode);
```

5.11 Display project name and the number of employees working on those projects andwho obtained A or B ratings on the project  they have worked.Sort  the displayed records in descending order of number of employees worked. 
```
SELECT p.PRJ_NAME, COUNT(DISTINCT w.EMPCODE) 
FROM PRJ_DETAILS p 
JOIN WORK_EXP w ON p.prjid = w.prjid 
WHERE RATING IN ('A', 'B') 
GROUP BY p.PRJ_NAME 
ORDER BY COUNT(DISTINCT w.EMPCODE) DESC;
```

5.12 Display the name of projects under which more than 2 employees are working.
```
SELECT p.PRJ_NAME FROM PRJ_DETAILS p
JOIN WORK_EXP w ON p.prjid = w.prjid
GROUP BY p.PRJ_NAME
HAVING COUNT(DISTINCT w.EMPCODE) > 2;
```

5.13 Find Employee name and the number of dependents they are having.
```
SELECT e.NAME, COUNT(d.DEP_NAME) as NUM_DEPENDENTS
FROM EMP e
LEFT JOIN FAMILY_DEPENDENTS d ON e.EMPCODE = d.EMPNO
GROUP BY e.NAME;
```

5.14 Retrieve total premium amount collected each year.
```
SELECT TO_CHAR(POLICYDATE, 'YYYY') AS YEAR, SUM(PREMIUM) AS TOTAL_PREMIUM
FROM MEDICAL_POLICY
GROUP BY TO_CHAR(POLICYDATE, 'YYYY');
```

5.15 Find employee name and having more than 20 months of total skill experience (irrespective of kind of skill) Use WITH clause.
```
WITH EMPLOYEE_SKILL_EXPERIENCE AS (
  SELECT EMPNO, SUM(SKILL_EXPERIENCE) AS TOTAL_EXPERIENCE
  FROM EMP_SKILL
  GROUP BY EMPNO
)
SELECT E.NAME
FROM EMP E
JOIN EMPLOYEE_SKILL_EXPERIENCE ESE ON E.EMPCODE = ESE.EMPNO
WHERE ESE.TOTAL_EXPERIENCE > 20;
```

5.16 Create a table called EMP_PRJ containing Employee name (Emp_Name), Project Budget (Budget) and Name of the project (Project_Name) which are led by employee with code 110.
```
CREATE TABLE EMP_PRJ AS
SELECT E.NAME AS Emp_Name, P.BUDGET_ALLOCATED AS Budget, P.PRJ_NAME AS Project_Name
FROM EMP E
JOIN WORK_EXP w on e.empcode = w.empcode
JOIN PRJ_DETAILS p ON w.prjid = p.prjid
WHERE E.EMPCODE = 110;
```

5.17 Increment the salary of employees by 10% for the employees whoare PROJECT LEADERand 5% for employees who are DEVELOPER(use update ... case.)
```
UPDATE EMP
SET SALARY = CASE
              WHEN DESIGNATION = 'PROJECT LEADER' THEN SALARY * 1.1
              WHEN DESIGNATION = 'DEVELOPER' THEN SALARY * 1.05
              ELSE SALARY
             END;
```

5.18 Create  a  view  EMP_SKILL_EXPERIENCE containing  employee  name,  skill_name  &  skill_experience where experience is more than 20 months. After creating  view,  update  the  skill_  experience  of  any  employee  and  confirm  the  result  with reasoning.
```
CREATE VIEW EMP_SKILL_EXPERIENCE AS
SELECT E.NAME, S.SKILLNAME, ES.SKILL_EXPERIENCE
FROM EMP E
JOIN EMP_SKILL ES ON E.EMPCODE = ES.EMPNO
JOIN SKILL S ON ES.SKILLID = S.SKILLID
WHERE ES.SKILL_EXPERIENCE > 20;
```
```
UPDATE EMP_SKILL
SET SKILL_EXPERIENCE = 25
WHERE EMPNO = 102 AND SKILLID = 'S4';
```

5.19 Create a view EMP_DESIGNATION containing Empno, Name, Salary of employees working with role DEVELOPER, PROJECT LEADER. Aftercreating view, update the salary of any employee and confirm the result with reasoning.
```
CREATE VIEW EMP_DESIGNATION AS
SELECT EMPCODE, NAME, SALARY
FROM EMP
WHERE DESIGNATION IN ('DEVELOPER', 'PROJECT LEADER');
```
```
UPDATE EMP
SET SALARY = SALARY * 1.1
WHERE EMPCODE = 101;
```

5.20 Display employee name and number of projects in which they are working (using scalar sub query)
```
SELECT NAME, 
    (SELECT COUNT(*) 
     FROM PRJ_DETAILS 
     WHERE EMPCODE = EMP.EMPCODE) AS NUM_PROJECTS
FROM EMP;
```
