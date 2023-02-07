```
create table medical_policy (
	EMPNO number(3) CONSTRAINT MEDEMP references EMP (EMPCODE),
	POLICYNO varchar(6) CONSTRAINT MEDPOL check (POLICYNO like 'MED%'),
	PREMIUM number (5) CONSTRAINT MEDPRE check (PREMIUM > 0),
	POLICYDATE date,
	PRIMARY KEY (EMPNO, POLICYNO));
```
