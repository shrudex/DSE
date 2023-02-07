```
create table pay_check (
	EMPCODE number(3) references EMP(EMPCODE),
	PAY_DATE date,
	REGULAR_INCREMENT number(4) CONSTRAINT VALID_REGU_INCENTIVE check (REGULAR_INCREMENT in (2000, 3000, 5000, 7000, 9000)),
	PERFORMNCE_INCENTIVE number(5),
	DA number(7),
	PF number(6),
	OTHER_INCENTIVES number(4),
	ADVANCE_TAX number(5),
	PRIMARY KEY (EMPCODE, PAY_DATE));
  ```
