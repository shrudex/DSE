the corrected values to be inserted are as follows:

```
INSERT into PRJ_DETAILS
values ('P1', 'SPYDER', '10-JAN-20', '11-OCT-22', '21-OCT-22', 102, 2000000, 1990000);

INSERT into PRJ_DETAILS
values ('P2', 'APOLLO', '01-JAN-19', '10-JUL-21', '30-DEC-21', 108, 3000000, 3600000);

INSERT into PRJ_DETAILS
values ('P3', 'UNICORN', '03-NOV-21', '10-OCT-23', '11-OCT-23', 106, 7500000, 8000000);

INSERT into PRJ_DETAILS
values ('P4', 'ZEUS', '28-FEB-20', '09-JUN-21', '10-JAN-22', 110, 5500000, 5000000);

INSERT into PRJ_DETAILS
values ('P5', 'JUPITOR', '07-AUG-18', '04-FEB-20', '01-NOV-20', 110, 9000000, 9000000);

INSERT into PRJ_DETAILS
values ('P6', 'MARS', '21-FEB-22', '07-AUG-22', '30-AUG-22', 110, 3100000, 1830000);

INSERT into PRJ_DETAILS
values ('P8', 'XXX', '21-OCT-17', '11-DEC-22', '21-DEC-22', 106, 4300300, 3850000);

INSERT into PRJ_DETAILS
values ('P7', 'BGT', '15-JUN-21', '11-JAN-22', '11-JAN-22', 113, 3330303, 3460000);
```

here is a rough file used, can refer to it, just for reference: [table-prj_details-rough work.txt](https://github.com/shrudex/DSE/files/10729121/table-prj_details-rough.work.txt)

2 values are logically invalid because of the constraints imposed. **P7** has _lead_by_empcode_ constraint issue as it references to EMP table and **P8** has _NOT NULL_ constraint issues.

_output of the SELECT query after all the values have been inserted_

![image](https://user-images.githubusercontent.com/91502997/218649182-3d188383-fd84-487a-9f14-b70fa372ec92.png)
![image](https://user-images.githubusercontent.com/91502997/218649305-4ef29089-7daa-4795-865c-745f15a81d22.png)




