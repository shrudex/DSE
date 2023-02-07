**2.1 Add column REPORTS_TO to EMP table with Foreign Key constraint refereeing to EMPCODE and constraint name -FK_REPORTS_TO_EMPCODE.**
```
alter table EMP
add (REPORTS_TO number(3))
add CONSTRAINT FK_REPORTS_TO_EMPCODE FOREIGN KEY (REPORTS_TO) references EMP (EMPCODE);
```

**2.2 Set a constraint on SKILLID column belonging to SKILL table- every column value starts with letter 'S'.**
```
alter table SKILL
add CONSTRAINT CK_SKILLID CHECK (SKILLID LIKE 'S%');
```

**2.3 Add primary key constraint on EMPNO, SKILLID columns belonging to EMP_SKILL table having constraint name- PK_EMPNO_SKILLID.**
```
alter table EMP_SKILL
add CONSTRAINT PK_EMPNO_SKILLID PRIMARY KEY(EMPNO, SKILLID);
```

**2.4 Set Unique constraint on PRJ_NAME belonging to PRJ_DETAILS table with constraint name UNQ_PRJ_NAME.**
```
alter table prj_details
add CONSTRAINT UNQ_PRJ_NAME UNIQUE(PRJ_NAME);
```

**2.5 ADD column EMAIL to CLIENT & constraint with name 'VALID_EMAIL', valid only if-contains @. Symbols as in email format and there must be only 3 letters after. symbol on EMAIL column.**
```
alter table CLIENT
add (EMAIL varchar(255))
add CONSTRAINT VALID_EMAIL CHECK (EMAIL LIKE '%@%.___%');
```

**2.6 Add Unique Key constraint on PHONE belonging to EMP having constraint name -UNQ_PHONE.**
```
alter table EMP
add CONSTRAINT UNQ_PHONE UNIQUE(PHONE);
```

**2.7 Add Unique Key constraint on EMAIL belonging to EMP having constraint name -UNQ_EMAIL.**
```
alter table EMP
add CONSTRAINT UNQ_EMAIL UNIQUE(EMAIL);
```

**2.8 Drop primary key constraint from MEDICAL_POLICY table and add primary key constraint on EMPNO, POLICYNO, POLICYDATE.**
```
alter table MEDICAL_POLICY
drop PRIMARY KEY;
alter table MEDICAL_POLICY
add CONSTRAINT MED_PRIM PRIMARY KEY (EMPNO, POLICYNO, POLICYDATE);
```

**2.9 Drop constraint from PREMIUM belonging to MEDICAL_POLICY table & add new constraint that PREMIUM amount must be more than 1000/-.**
```
alter table MEDICAL_POLICY
drop CONSTRAINT MEDPRE;
alter table MEDICAL_POLICY
add CONSTRAINT MEDPREAMT CHECK (PREMIUM>1000);
```
