```
create table family_dependents (
	EMPNO number(3) references EMP (EMPCODE),
	DEP_NAME varchar(20),
	RELATIONSHIP varchar(16),
	AGE number(3) CONSTRAINT VALID_AGE CHECK (AGE between 1 and 130),
	PRIMARY KEY (EMPNO, DEP_NAME)
);
```
