the corrected values to be inserted are as follows:

```
INSERT into CLIENT
values ('C1', 'ABC', '+48-87489389', 'aaa@abc.com');

INSERT into CLIENT
values ('C2', 'LTS', '+91-78389397', 'bbb@lts.com');

INSERT into CLIENT
values ('C3', 'RK', '+44-67838934', 'ccc@rk.com');

INSERT into CLIENT
values ('C4', 'MMA', '+31-77839093', 'ddd@mma.com');

INSERT into CLIENT
values ('C5', 'AKS', '+81-66822903', 'eee@aks.com');

INSERT into CLIENT
values ('C6', 'GKS', '+48-75628982', 'fff@gks.com');

INSERT into CLIENT
values ('C7', 'B&B', '+91-64839839', 'ggg@bb.com');

INSERT into CLIENT
values ('C8', 'ABT', '+31-67554667', 'shrudex@gmail.com');

INSERT into CLIENT
values ('C9', 'XYZ', '+44-87114667', 'xyz@ab.com');
```

_here is a rough file used, can refer to it, just for reference:_ [table-client-rough work.txt](https://github.com/shrudex/DSE/files/10728801/table-client-rough.work.txt)

3 values are logically invalid because of the constraints imposed. **C9** has _email constraint issue_ & **C8** and **C6** have _phone constraint issues_.

_output of the SELECT query after all the values have been inserted_

![image](https://user-images.githubusercontent.com/91502997/218640788-562bad42-272c-4041-a52c-20cd3a567ead.png)
![image](https://user-images.githubusercontent.com/91502997/218640815-aef9a9c5-6b1a-41f2-9a04-c813487a02bd.png)
