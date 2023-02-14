**the correct order of inserting the values, without _dropping_ any constraint!!!**
```
INSERT into EMP
Values (106, 'PRSAD', 'PHD', 1234426889, 'prasad@digisol.com', 'CEO', 99001, NULL);

INSERT into EMP
Values (105, 'MANISH', 'MCA', 1231117889, 'manish@digisol.com', 'DEVELOPER', 147001, 106);

INSERT into EMP
Values (109, 'XYZ', 'PHD', 1234437889, 'shrudex@digisol.com', 'CEO', 290000, 105);

INSERT into EMP
Values (110, 'SMITH', 'PHD', 1234949889, 'smith49@digisol.com', 'CEO', 99901, 109);

INSERT into EMP
Values (102, 'VIJAY', 'BTECH', 1223567889, 'vijay@digisol.com', 'PROJECT MANAGER', 97011, 110);

INSERT into EMP
Values (101, 'RAVI', 'MTECH', 1234511889, 'ravi@digisol.com', 'PROJECT LEADER', 97022, 102);

INSERT into EMP
Values (100, 'RAJESH', 'BTECH', 1234567889, 'rajesh@digisol.com', 'DEVELOPER', 97001, 101);

INSERT into EMP
Values (108, 'RAKESH', 'MTECH', 6334567889, 'rakkesh@digisol.com', 'DEVELOPER', 98641, 106);

INSERT into EMP
Values (103, 'RAJ', 'MSC', 1234567839, 'raj@digisol.com', 'PROJECT LEADER', 217001, 110);

INSERT into EMP
Values (107, 'RAKESH', 'MTECH', 1232567889, 'rakesh@digisol.com', 'PROJECT LEADER', 99901, 103);

INSERT into EMP
Values (112, 'AJAY', 'BTECH', 9234567889, 'ajay@digisol.com', 'TECHNICAL HEAD', 227001, 102);

INSERT into EMP
Values (113, 'BHASKAR', 'MTECH', 1232327889, 'bhaskar@digisol.com', 'PROJECT DIRECTOR', 99341, 106);

INSERT into EMP
Values (111, 'RAJ', 'BTECH', 1234666389, 'rajjj@digisol.com', 'DEVELOPER', 99021, 110);
```

_here is a rough file used, can refer to it, just for reference_
[table-emp-rough work.txt](https://github.com/shrudex/DSE/files/10728667/table-emp-rough.work.txt)

the values given in the question have some _logical errors_ which won't work directly because of the constraints, earlier imposed on the columns. thus, we will have to fix those values and then insert. the order should be followed otherwise the concept of '**referential integrity**' will not be respected.


_output of the SELECT query after all the values have been inserted_

![image](https://user-images.githubusercontent.com/91502997/218637097-75689838-762d-4d7c-9e90-65c604087642.png)
![image](https://user-images.githubusercontent.com/91502997/218637151-0fa0ed1d-dad9-44e6-99bc-243701b50732.png)
![image](https://user-images.githubusercontent.com/91502997/218637177-bba1c76c-8dcb-4211-a02b-2085962f6831.png)


