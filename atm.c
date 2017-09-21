/* Aidan Shea 9/8/17 CIS 2107 Lab#3 ATM*/

#include <stdio.h>
#include <stdlib.h>

//Prototypes
float getBalance();
float withdraw();
float deposit();
void quit();

//Global Variables
float balance = 5000.0;
float withdrawnTotal= 0.0;
float depositTotal = 0.0;
int pin = 3014;
int transactions = 0;

//Main function: Runs the menu
int main(void){
	int action;
	
	//Takes input from user and performs corresponding action	
	while(1==1){
		printf("Welcome to the ATM!\nPlease select an action below by typing the corresponding number.\n\t1. Display Balance\n\t2. Deposit Money\n\t3. Withdraw Money\n\t4. Quit\n");	
		scanf("%d", &action);
	
		switch(action){
			case 1 :
				getBalance();
				break;
			case 2:
				deposit();
				break;
			case 3:
				withdraw();
				break;
			case 4:
				quit();
				break;
			default:
				printf("Please enter a valid input\n");
		}
	}
}

//Prints out and returns the balance
float getBalance(){
	printf("Your balance is $%.2f\n", balance);

	
	printf("Would you like a receipt?\n\t1. Yes\n\t2. No\n");
	int yesNo;
	scanf("%d", &yesNo);
	
	if(yesNo == 1){
		printf("%s", "Your receipt has been sent.\n");
	} else{
		printf("%s", "No receipt.\n");
	}
	
	++transactions;
	return balance;
}

//Asks the user for amount to deposit. Returns the new balance after deposit. Exits the program if pin or deposit value fail 3 times
float deposit(){
	printf("%s", "Please enter an amount to deposit.\n");
	
	unsigned int amount = 0;
	unsigned int failedAttempts = 0;

	//Takes user input and checks if it's valid
	while(amount <=0 || depositTotal + amount > 10000.0){
		if(failedAttempts >= 3){
			printf("You have failed to provide valid input too many times.\nTerminating Program.\n");
			exit(1);		
		}

		scanf("%d", &amount);


		if(amount <= 0){
			printf("%s", "Please enter an amount greater than 0.\n");		
			++failedAttempts;
		}

		if(depositTotal + amount > 10000.0){
			printf("This exceeds the daily $10000.00 limit for deposits.\nYou have already deposited $%.2f today.\nPlease deposit a smaller amount.\n", depositTotal);
			++failedAttempts;
		}
	}
	
	//Checks PIN and completes deposit if entered correctly	
	failedAttempts = 0;
	int attemptPin = 0;
	while(failedAttempts < 3){
		printf("Please input your PIN in order to complete the transaction\n");
		scanf("%d", &attemptPin);

		if(attemptPin == pin){
	
			printf("$%d have been deposited to your account.\nYour new balance is $%.2f\nWould you like a receipt?\n\t1. Yes\n\t2. No\n", amount, balance+amount);

			int yesNo;
			scanf("%d", &yesNo);

			if(yesNo == 1){
				printf("%s", "Your receipt has been sent.\n");
			} else{
				printf("%s", "No receipt.\n");
			}
		
			depositTotal += amount;
			balance += amount;
			++transactions;
			return balance + amount;
		} else {
			printf("Invalid pin. %d attempt(s) remaining.\n", 3-++failedAttempts); 		
		}	
	}

	printf("You've failed to input your pin too many times.\n Terminating program");
	exit(1);
}

//Asks the user for amount to deposit. Returns the new balance after deposit. Exits the program if pin or withdrawl value fail 3 times
float withdraw(){
	printf("%s", "Please enter an amount to withdraw.\nOnly multiples of 20 are allowed (i.e $20, $40, $60...etc)\n");

	unsigned int amount = 0;
	unsigned int failedAttempts = 0;
	
	//Takes user input and checks if it's valid
	while(amount <=0 || amount%20 != 0 || withdrawnTotal + amount > 1000.0){
		if(failedAttempts >= 3){
			printf("You have failed to provide valid input too many times.\nTerminating Program.\n");
			exit(1);		
		}

		scanf("%d", &amount);

		if(amount%20 != 0){
			printf("%s", "This amount is not a multiple of 20.\nPlease try again.\n");
			++failedAttempts;
		}
		
		if(amount <= 0){
			printf("%s", "Please enter an amount greater than 0.\n");		
			++failedAttempts;
		}

		if(withdrawnTotal + amount > 1000.0){
			printf("This exceeds the daily $1000.00 limit for deposits.\nYou have already deposited $%.2f today.\nPlease deposit a smaller amount.\n", withdrawnTotal);
			++failedAttempts;
		}
	}

	//Checks PIN and completes withdrawal if entered correctly
	failedAttempts = 0;
	int attemptPin = 0;
	while(failedAttempts < 3){
		printf("Please input your PIN in order to complete the transaction\n");
		scanf("%d", &attemptPin);

		if(attemptPin == pin){
			printf("$%d have been withdrawn from your account.\nYour new balance is $%.2f\nWould you like a receipt?\n\t1. Yes\n\t2. No\n", amount, balance-amount);

			int yesNo;
			scanf("%d", &yesNo);

			if(yesNo == 1){
				printf("%s", "Your receipt has been sent.\n");
			} else{
				printf("%s", "No receipt.\n");
			}
	
			withdrawnTotal += amount;
			balance -= amount;
			++transactions;
			return balance - amount;		
		} else {
			printf("Invalid pin. %d attempt(s) remaining\n", 3-++failedAttempts); 		
		}	
	}

	printf("You've failed to input your pin too many times.\n Terminating program");
	exit(1);
}

//Prints thank you message and exits program
void quit(){
	printf("Thank you for using our ATM!\nYou completed %d transactions.\nPlease come again!\n", transactions);
	exit(0);
}
