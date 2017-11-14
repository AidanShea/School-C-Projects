/*Aidan Shea 9/29/17 CIS 2107 Lab 5 2D Arrays and Arrays of Pointers to Functions*/

#include<stdio.h>
#include<stdlib.h>

#include<stdio.h>
#include<stdlib.h>

size_t rows;
size_t columns;

void printArray(int gradeArray[rows][columns]);
void minimum(int gradeArray[rows][columns]);
void maximum(int gradeArray[rows][columns]);
void average(int gradeArray[rows][columns]);
void exitGrades(int gradeArray[rows][columns]);


//Read input from user to determine number of rows and columns of the array and which functions to call. Create array of function pointers.
int main(){
	printf("Let's create a 2Dim array!\n\tHow many rows?\n");
	scanf("\t%lu", &rows);
	printf("\tHow many columns?\n");
	scanf("\t%lu", &columns);
	
        int gradeArray[rows][columns]; 
	void (*processGrade[5])(int[rows][columns]) = {printArray, minimum, maximum, average, exitGrades};

	for(size_t i = 0; i<rows; ++i){
		for(size_t j = 0; j < columns; ++j){
			printf("\tenter [%lu][%lu]:", i, j);
			scanf("%d", &gradeArray[i][j]);
		}	
	}

	puts("");

	int choice;

	while(1 == 1){
		printf("Enter a choice:\n\t0. Print the array of grades\n\t1. Find the minimum grade\n\t2. Find the maximum grade\n\t3. Print the average on all tests for each student\n\t4. End Program\n\n");

		scanf("%d", &choice);
		
		if(choice <0 || choice>4){
			printf("Please provide valid input\n");
		} else {
			(processGrade[choice])(gradeArray);
		}	
	}
}

//Loop through array and print values
void printArray(int gradeArray[rows][columns]){
	printf("\nThe array is:\n");

	printf("                ");
	for(size_t i = 0; i<columns;++i){
		printf("[%lu]  ", i);	
	}
	
	puts("");

	for(size_t i = 0; i<rows; ++i){
		printf("studentGrades[%lu]", i);

		for(size_t j = 0; j < columns; ++j){
			printf("%-5d", gradeArray[i][j]);
		}
		puts("");	
	}
	
	puts("");
}

//Loops through the array to find a value smaller than "minimum" and if it exists assigns it as the new value of minimum
void minimum(int gradeArray[rows][columns]){
	int minimum = 100; //Assuming that the highest grade that can be received is 100
	
	for(size_t i = 0; i<rows; ++i){
		for(size_t j = 0; j < columns; ++j){
			if(minimum>gradeArray[i][j]){
				minimum = gradeArray[i][j];
			}
		}
	}

	printf("\nLowest grade: %d\n\n", minimum);
}

//Loops through the array to find a value larger than "minimum" and if it exists assigns it as the new value of maximum
void maximum(int gradeArray[rows][columns]){
	int maximum = 0; //Assuming that the lowest grade that can be received is 0
	
	
	for(size_t i = 0; i<rows; ++i){
		for(size_t j = 0; j < columns; ++j){
			if(maximum<gradeArray[i][j]){
				maximum = gradeArray[i][j];
			}
		}
	}

	printf("\nLowest grade: %d\n\n", maximum);
}

//Calculates the average of each student and prints it
void average(int gradeArray[rows][columns]){
	puts("");
	
	float sum;
	float entries;
	float average;
	
	for(size_t i = 0; i<rows; ++i){
		sum = 0.0;
		entries = 0.0;
		average = 0.0;
		
		for(size_t j = 0; j < columns; ++j){
			sum += gradeArray[i][j];
			++entries;
		}

		average = sum/entries;
		printf("The average grade for student %lu is %.2f\n", i, average);
	}

	puts("");
}

//exit the program
void exitGrades(int gradeArray[rows][columns]){
	exit(1);
}



