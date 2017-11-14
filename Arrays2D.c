/*Aidan Shea 9/29/17 CIS 2107 Lab 5 2D Arrays and Arrays of Pointers to Functions*/

#include<stdio.h>
#include<stdlib.h>

size_t rows;
size_t columns;

int max();
int rowSum(int array[rows][columns], int row);
int columnSum(int array[rows][columns], int column);
int isSquare();
void displayOutputs(int array[rows][columns]);

//Read input from user to determine number of rows and columns. Create array, call functions and display output
int main(){
	printf("Let's create a 2Dim array!\n\tHow many rows?\n");
	scanf("\t%lu", &rows);
	printf("\tHow many columns?\n");
	scanf("\t%lu", &columns);
	
        int array[rows][columns]; 
        
        size_t i;
        size_t j;
	for(i = 0; i<rows; ++i){
		for(j = 0; j < columns; ++j){
			printf("\tenter [%lu][%lu]:", i, j);
			scanf("%d", &array[i][j]);
		}	
	}

	puts("");

	for(int i = 0; i<rows; i++){
		printf("Sum of row: %d = %d\n", i+1, rowSum(array, i));
	}

	puts("");

	for(int i = 0; i<columns; i++){
		printf("Sum of column: %d = %d\n", i+1, columnSum(array, i));
	}

	puts("");

	if(isSquare()){
		printf("This is a square array.\n");
	} else {
		printf("This is not a square array.\n");	
	}

	puts("");
	
	displayOutputs(array);
	
	
}

//Loop through array and print values
void displayOutputs(int array[rows][columns]){
	printf("Here is your 2Dim array:\n");
	
        size_t i;
        size_t j;
	for(i = 0; i<rows; ++i){
		printf("[");
		for(j = 0; j < columns; ++j){
			printf("%4d", array[i][j]);
			if(j!=columns-1){
				printf(", ");			
			}
		}
		printf("]\n");	
	}
}

//Loop through given row and add each value to sum, then return it
int rowSum(int array[rows][columns], int row){
	int sum = 0;
	for(int i = 0; i<columns; ++i){
		sum += array[row][i];
	}
	return sum;
}

//Loop through given column and add each value to sum, then return it
int columnSum(int array[rows][columns], int column){
	int sum = 0;
	for(int i = 0; i<rows; ++i){
		sum += array[i][column];
	}
	return sum;
}

//Check if number of rows is equal to number of columns. Return true if it is
int isSquare(){
	if(rows == columns){
		return 1;
	}
	
	return 0;
}
