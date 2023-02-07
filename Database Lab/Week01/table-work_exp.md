```
create table work_exp (
	EMPCODE number(3) CONSTRAINT EMP_CODEREF references EMP (EMPCODE),
	PRJID char(3) references PRJ_DETAILS (PRJID),
	WORK_EXPERIENCE number(10) CONSTRAINT WORK_EXPE CHECK (WORK_EXPERIENCE >= 0) NOT NULL,
	CLIENTID char(3) references CLIENT (CLIENTID) on delete set NULL,
	RATING char(1) check (RATING IN ('A', 'B', 'C')),
	PRIMARY KEY (EMPCODE, PRJID));
  ```
