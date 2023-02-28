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
```

5.8 List the name of employees who workedin the project and client combinations in which Empcode 100 has worked. (Use set cardinality) 
```
```

5.9 List the name of employees who didn’t work on any of the project in which employee with empcode 106 has worked. (Use set cardinality)
```
```

5.10 Find  the  name  of projects  for  which  Allocated  budget  is  at  least  more  than  the  total  salary  of employees working on those projects. (correlation variable)
```
```

5.11 Display project name and the number of employeesworking on those projects andwho obtained A or B ratings on the project  they have worked.Sort  the displayed records in descending order of number of employees worked. 
```
```

5.12 Display the name of projects under which more than 2 employees are working.
```
```

5.13 Find Employee name and the number of dependents they are having.
```
```

5.14 Retrieve total premium amount collected each year.
```
```

5.15 Find employee name and having more than 20 months of total skill experience (irrespective of kind of skill) Use WITH clause.
```
```

5.16 Create a table called EMP_PRJcontaining Employee name (Emp_Name), Project Budget (Budget) and Name of the project (Project_Name) which are led by employee with code 110.
```
```

5.17 Increment the salary of employees by 10% for the employees whoare PROJECT LEADERand 5% for employees who are DEVELOPER(use update ... case.)
```
```

5.18 Create  a  view  EMP_SKILL_EXPERIENCEcontaining  employee  name,  skill_name  &  skill_experience where experience is more than 20 months.After  creating  view,  update  the  skill_  experience  of  any  employee  and  confirm  the  result  with reasoning.
```
```

5.19 Create a view EMP_DESIGNATION containing Empno, Name, Salary of employees working with role DEVELOPER, PROJECT LEADER. Aftercreating view, update the salary of any employee and confirm the result with reasoning.
```
```

5.20 Display employee name and number of projects in which they are working (using scalar sub query)Optional-Try writing 5.5 to 5.9 queries in alternate way.
```
```
