#HANSWHEELS

Welcome to HansWheels, a sophisticated car rental system developed for the users in a hurry. We aim to provide a simple and easy to use UI so that the users can rent the cars they use without much worry.

##Assumptions
We have a scoring system for users from 0 to 100 and each user starts from 100 and for each delay, the score decreases till the score reaches below 70 when the user cannot rent anymore. The only way the user below the score of 70 can rent again is by contacting the manager who can create a new user with a processing fee.<br>
The databases are included in the main.cpp file itself as an unordered map. Add,delete,update etc all such functions are possible.<br>
When renting a car, all the dues are sent to the payment dues which are basically per day price * number of days and the fine is 1.5 times the per day rental price. The score reduces by 2* the number of delayed days.<br>
For payments, only the manager can clear them.

##Working of the App
After opening the app, the options the user has will be to login, register or exit. A new user has to register wherein the app will collect his username and password. Every username will be associated with a unique id. Also, the user has a choice to register as a customer or a employee.<br>
Any existing user can login as a customer, employee or a manager. They will be required to enter their username and password. Username is also unique.
There can only be one manager who is existing and can't be changed.<br>
The only difference between customer and employee is the 15 percent discount the employee of the app gets. The fines are the same for both of them.<br>
A user(customer and employee) can browse and rent a car, view rented cars and return a car, view payment dues and logout.
The availability of the car is shown when browsing.<br>
Now, a manager can add, update or delete a customer, employee or a car.He/she can view all the details of the users, condition and statuses of the cars, their rental status etc.<br>
Customer  and employees have an id, username, password, score and payment dues.<br>
A manager only has a username and a password.<br>
Cars have a plate number,model,price,condition,name, and days of the renting.<br>
Well, these are the details of the application, hope you have a fruitful experience with HANSWHEELS.# CS253-Assignment-1