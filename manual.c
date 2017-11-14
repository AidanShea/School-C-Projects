/*Aidan Shea 10/19/17 CIS 2107 Lab 7 Manual*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

void upperLower();
void convertStrtoInt();
void convertStrtoFloat();
void compareStr();
void comparePartialStr();
void randomize();
void tokenizeTelNumb();
void reverse();
void countSubstr();
void countChar();
void countAlpha();
void countWords();
void startswithB();
void endsWithed();

char* strupr(char *string);
char* strlwr(char *string);
int countCharNV(char temp, char *string);

//Calls all functions, comment out which ones you don't want to call
int main(){
	upperLower();
	convertStrtoInt();
	convertStrtoFloat();
	compareStr();
	comparePartialStr();
	randomize();
	tokenizeTelNum();
	reverse();
	countSubstr();
	countChar();
	countAlpha();
	countWords();
	startsWithB();
	endsWithed();
}

//Uses other functions to convert to upper and lower
void upperLower(){
	char s[100];
	printf("Please input string.\n");
	scanf("%[^\n]", s);

	printf("%s\n", strupr(s));
	printf("%s\n", strlwr(s));

}

//converts each character in a string to uppercase
char* strupr(char *string){	
	char* temp = string;

	while(*temp!='\0'){
		*temp = toupper((unsigned char) *temp);
		++temp;
	}

	return string;
}

//converts each character in a string to lowercase
char* strlwr(char *string){	
	char* temp = string;

	while(*temp!='\0'){
		*temp = tolower((unsigned char) *temp);
		++temp;
	}

	return string;
}

//Uses atoi to convert string to integer, then prints out the sum of the given values
void convertStrtoInt(){
	printf("Please input four integers\n");
	char string1[20];
	char string2[20];
	char string3[20];
	char string4[20];
	
	scanf("%s", string1);
	scanf("%s", string2);
	scanf("%s", string3);
	scanf("%s", string4);	
	
	printf("The sum of these integers is %d\n", atoi(string1) + atoi(string2) + atoi(string3) + atoi(string4));
}

//Uses atof to convert string to float, then prints out the sum of the given values
void convertStrtoFloat(){
	printf("Please input four floats\n");
	char string1[20];
	char string2[20];
	char string3[20];
	char string4[20];
	
	scanf("%s", string1);
	scanf("%s", string2);
	scanf("%s", string3);
	scanf("%s", string4);	
	
	printf("The sum of these floats is %f\n", atof(string1) + atof(string2) + atof(string3) + atof(string4));
}

//Uses strcmp to compare strings and prints out which is greater
void compareStr(){
	printf("Please input two strings\n");
	char string1[100];
	char string2[100];

	scanf(" %[^\n]", string1);
	scanf(" %[^\n]", string2);
	
	int compare = strcmp(string1, string2);

	if(compare > 0){
		printf("The first string was greater than the second string\n");
	} else if(compare < 0){
		printf("The first string was less than the second string\n");
	} else{
		printf("The first string was equal to the second string\n");
	} 	
}

//Uses strncmp to compare parts of strings and prints out the relation
void comparePartialStr(){
	char string1[100];
	char string2[100];
	int amount;

	printf("Please input two strings\n");

	scanf(" %[^\n]", string1);
	scanf(" %[^\n]", string2);
	
	printf("Please input how many characters of these two strings to compare\n");
	
	scanf("%d", &amount);
	
	int compare = strncmp(string1, string2, amount);

	if(compare > 0){
		printf("The first string was greater than the second string\n");
	} else if(compare < 0){
		printf("The first string was less than the second string\n");
	} else{
		printf("The first string was equal to the second string\n");
	}
}

//Uses different arrays to create psuedo random sentences
void randomize(){
	char sentence[100];
	char* article[] = {"the", "a", "one", "some", "any"};
	char* noun[] = {"boy", "girl", "dog", "town", "car"};
	char* verb[] = {"drove", "jumped", "ran", "walked", "skipped"};
	char* preposition[] = {"to", "from", "over", "under", "on"};
	
	for(int i = 0; i<20;++i){
		strcpy(sentence, "");
		
		srand(time(NULL)*i);
	
		strcat(sentence, article[rand()%5]);
		strcat(sentence, " ");
		strcat(sentence, noun[rand()%5]);
		strcat(sentence, " ");
		strcat(sentence, verb[rand()%5]);
		strcat(sentence, " ");
		strcat(sentence, preposition[rand()%5]);
		strcat(sentence, " ");
		strcat(sentence, article[rand()%5]);
		strcat(sentence, " ");
		strcat(sentence, noun[rand()%5]);
		strcat(sentence, ".");	
	
		sentence[0] = toupper(sentence[0]);
	
		printf("%s\n", sentence);
	}
}

//Takes a telephone number as input and tokenizes it.
void tokenizeTelNum(){
	char* phone[15];
	char* number[8];
	printf("Please input a phone number with format (xxx) xxx-xxxx\n");
	scanf("%[^\n]", &phone);
	
	char *tokenPtr= strtok(phone, "()");
	
	int areaCode = atoi(tokenPtr);
	
	tokenPtr = strtok(NULL, " -");
	
	strcpy(number, tokenPtr);
	
	tokenPtr = strtok(NULL, " -");
	
	strcat(number, tokenPtr);

	long phoneNumber = atoll(number); 
	
	printf("The area code is %d and the phone number is %li\n", areaCode, phoneNumber);
}

//Tokenizes input, seperating words by spaces and storing them in an array. Then prints out the arry in reverse order
void reverse(){
	char** array[100];
	char* string[1000];
	int condition = 1;
	int index = 1;

	printf("Please input a string with multiple words.\n");
	scanf("%[^\n]", &string);

	array[0] = strtok(string, " ");
	
	while(condition){
		array[index] = strtok(NULL, " ");
		if(array[index] != NULL){		
			++index;		
		} else {
			condition = 0;
		}
	}
	
	--index;
	
	for(; index >=0; --index){
		printf("%s ", array[index]);
	}
	
	puts("");
}

//Uses strstr to count the number of occurences of a specified substring
void countSubstr(){
	char* string[100];
	char* substring[100];
	char* temp = string;
	int occurences = 0;
		
	printf("Please input a string.\n");
	scanf(" %[^\n]", string);	
	printf("Please input a substring to search for.\n");
	scanf(" %[^\n]", substring);

	while((temp = strstr(temp, substring))!= NULL){
		++temp;
		++occurences;
	}

	printf("The substring occurred %d times.\n", occurences);
}

//Much like the previous function. Uses strchr to find occurences of specified character
void countChar(){
	char* string[100];
	char subchar;
	char* temp = string;
	int occurences = 0;
		
	printf("Please input a string.\n");
	scanf(" %[^\n]", string);	
	printf("Please input a character to search for.\n");
	scanf(" %c", &subchar);

	while((temp = strchr(temp, subchar))!= NULL){
		++temp;
		++occurences;
	}

	printf("The character occurred %d times.\n", occurences);
}

//Identical to previous function except instead of user input it is passed input from elsewhere in the code
int countCharNV(char subchar, char* string){
	int occurences = 0;
	char *temp = string;
	
	while((temp = strchr(temp, subchar))!= NULL){
		++temp;
		++occurences;
	}

	return occurences;
}

//Uses countCharNV to find the amount of occurrences of each letter in the alphabet. Then stores that value in an array
void countAlpha(){
	char* string[100];
	int alpha[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
	printf("Please input a string.\n");
	scanf(" %[^\n]", string);

	char temp = 'a';

	for(int i = 0; i < 26; ++i){
		alpha[i] = countCharNV(temp, strlwr(string));
		printf("%5c", temp);
		++temp;
	}

	puts("");

	for(int i = 0; i< 26; ++i){
		printf("%5d", alpha[i]);
	}

	puts("");
}

//Tokenizes input seperating by spaces and counts the amount of words
void countWords(){
	char* string[1000];
	int words = 1;

	printf("Please input a string with multiple words.\n");
	scanf("%[^\n]", &string);
	
	char* temp = strtok(string, " ");
	
	while((temp = strtok(NULL, " ") != NULL)){
		++words;
	}	

	printf("There are %d words in this string\n", words);
}

//Checks to see if the first character is b and saves the word in an array if it is
void startsWithB(){
	char* array[100];
	char temp[100];
	int condition = 1;
	int words = 0;
	char tempChar;
	
	printf("Input up to 100 words, all words beginning with b will be returned. To stop inputting words, type '^'\n");
	
	while(condition){
		scanf("%s", temp);
		tempChar = temp[0];
		
		if(tempChar == 'b'){
			array[words] = strdup(temp);
			++ words;
		} else if(strcmp(temp, "^") == 0){
			condition = 0;		
		}
	}

	puts("");
	
	for(int i = 0; i < words; ++i){
		printf("%s\n", array[i]);	
	}
}

//Checks last two characters for 'ed' and if it's there it stores the array in an array to be printed later
void endsWithed(){
	char* array[100];
	char temp[100];
	int condition = 1;
	int words = 0;
	char tempChar;
	char tempChar2;
	int tempLen;
	
	printf("Input up to 100 words, all words ending with 'ed' will be returned. To stop inputting words, type '^'\n");
	
	while(condition){
		scanf("%s", temp);
		tempLen = strlen(temp);
			
		tempChar = temp[tempLen-1];
		tempChar2 = temp[tempLen-2];
	
		if(tempChar == 'd' && tempChar2 == 'e'){
			array[words] = strdup(temp);
			++words;
		} else if(strcmp(temp, "^") == 0){
			condition = 0;		
		}
	}

	puts("");
	
	for(int i = 0; i < words; ++i){
		printf("%s\n", array[i]);	
	}
}
