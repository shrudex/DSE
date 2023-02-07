_the correct order for creating the tables:_
1) EMP
2) SKILL
3) EMP_SKILL
4) CLIENT
5) PRJ_DETAILS
6) FAMILY_DEPENDENTS
7) MEDICAL_POLICY
8) PAY_CHECK
9) WORK_EXP

the table **WORK_EXP** references to the table *EMP, PRJ_DETAILS and CLIENT*, so need to be created after these 3 tables.

syntax to delete a table : _DROP TABLE [table-name];_
