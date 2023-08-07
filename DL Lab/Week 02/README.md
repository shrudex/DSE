# Experimenting with Deep Neural Networks

Consider the following dataset ```‘Churn_Modelling.csv’```

[Dataset Link](https://www.kaggle.com/datasets/aakash50897/churn-modellingcsv)

The data set has 14 features which are as follows:-
- RowNumber:- Represents the number of rows
- CustomerId:- Represents customerId
- Surname:- Represents surname of the customer
- CreditScore:- Represents credit score of the customer
- Geography:- Represents the city to which customers belongs to
- Gender:- Represents Gender of the customer
- Age:- Represents age of the customer
- Tenure:- Represents tenure of the customer with a bank
- Balance:- Represents balance hold by the customer
- NumOfProducts:- Represents the number of bank services used by the customer
- HasCrCard:- Represents if a customer has a credit card or not
- IsActiveMember:- Represents if a customer is an active member or not
- EstimatedSalary:- Represents estimated salary of the customer
- Exited:- Represents if a customer is going to exit the bank or not.

## Exercises
- Perform the required pre-processing (attribute removal, encoding, feature scaling) and write
comment lines to explain the pre-processing steps.
- Perform experiments using (70,15,15) split and tabulate the performance in terms of Accuracy,
Precision & Recall for the following experimental setup :
  1. Number of Hidden Layers and Number of Units per Layer
  2. Epochs (10,20,30)
  3. Activation function in output layer (Sigmoid )
  4. Learning rate ( 0.1, 0.01,0.001)
  5. Visualize the training and validation loss against the epochs using appropriate plots.
  6. Comment on performance.
  ![image](https://github.com/shrudex/DSE/assets/91502997/149e0e0b-73dd-49f1-a8a6-24f07051fbb2)
