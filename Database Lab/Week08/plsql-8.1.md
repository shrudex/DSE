## 8.1
Create a Table ACCOUNT (Account_Number, Balance) with constraint on Balance that Balance must be more than 1000(minimum balance). Insert few records into the table. Write a stored procedure to accept an account number, withdrawal amount from the user. Update the Balance by deducting the withdrawal amount from the balance in the case updated balance is going to be more than minimum balance (1000) otherwise do not update the Balance. In both cases display proper message 
+ Case 1: Current Balance: Balance

     Withdrawal of <Withdrawal_amount> is Successful 
     
     Updated Current Balance: Updated balance after withdrawal
+ Case 2: Current Balance: Balance
      
     Insufficient fund to withdraw, try with lesser withdrawal amount. 
     
Use PL/SQL block to call the stored procedure.

```
CREATE TABLE ACCOUNT (
  Account_Number INT,
  Balance DECIMAL(10,2) NOT NULL CHECK (Balance >= 1000)
);

INSERT INTO ACCOUNT (Account_Number, Balance) VALUES (19, 5000.00);
INSERT INTO ACCOUNT (Account_Number, Balance) VALUES (23, 2320.00);
INSERT INTO ACCOUNT (Account_Number, Balance) VALUES (34, 1500.00);
INSERT INTO ACCOUNT (Account_Number, Balance) VALUES (62, 12500.00);
INSERT INTO ACCOUNT (Account_Number, Balance) VALUES (49, 9500.00);
INSERT INTO ACCOUNT (Account_Number, Balance) VALUES (32, 44500.00);
INSERT INTO ACCOUNT (Account_Number, Balance) VALUES (50, 6800.00);
```

```
CREATE OR REPLACE PROCEDURE withdrawFromBank (
  accNum IN ACCOUNT.Account_Number%TYPE,
  withAmount IN ACCOUNT.Balance%TYPE
) IS
  currBalance ACCOUNT.Balance%TYPE;
BEGIN
  SELECT Balance INTO currBalance
  FROM ACCOUNT
  WHERE Account_Number = accNum;

  IF currBalance - withAmount >= 1000 THEN
    UPDATE ACCOUNT
    SET Balance = currBalance - withAmount;
    WHERE Account_Number = accNum;

    DBMS_OUTPUT.PUT_LINE('Current Balance: ' || currBalance || ', Withdrawal of ' || withAmount || ' is Successful');
    DBMS_OUTPUT.PUT_LINE('Updated Current Balance: ' || (currBalance - withAmount));
  ELSE
    DBMS_OUTPUT.PUT_LINE('Current Balance: ' || currBalance || ', Insufficient fund to withdraw, try with lesser withdrawal amount.');
  END IF;
END;
/
```

```
SET SERVER OUTPUT ON
DECLARE
  accountNumber ACCOUNT.Account_Number%TYPE := 49;
  withdrawalAmount ACCOUNT.Balance%TYPE := 400.00;
BEGIN
  withdrawFromBank(accountNumber, withdrawalAmount);
END;
/
```
