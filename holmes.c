//Aidan Shea CIS 2107 Sherlock Holmes to Southie accent
#include <stdio.h> 
#include <string.h>
#include <ctype.h>

#define BUFFER 10000

void makeWordSouthie(char* string, int i);
void makeSentenceSouthie(char* string, char* dest);
int isVowel(char c);
void getDialogue(FILE *fp, char* dest);
int copyHolmes(FILE *fp, char* dest);


int main() {
	FILE *cfPtr; //read file pointer
	FILE *wfPtr; //write file pointer
	char output[1000000];
	char temp[BUFFER];
	char southieDialogue[BUFFER];

	// fopen opens the file; exits if file cannot be opened
	if ((cfPtr = fopen("holmes - Copy.txt", "r")) == NULL) {
		puts("File could not be opened.");
	}
	else {
		while (copyHolmes(cfPtr, temp)) {//Parses the text and writes to output
			strcat(output, temp);

			getDialogue(cfPtr, temp);
			makeSentenceSouthie(temp, southieDialogue);

			strcat(output, southieDialogue);
		}

		if ((wfPtr = fopen("southie-sherlock.txt", "w")) == NULL) {//writes to file
			puts("File could not be opened.");
		}
		else {
			fprintf(wfPtr, "%s", output);
		}
	}
}

//Copies all of Holmes until a " is reached, then calls getDialogue
int copyHolmes(FILE *fp, char* dest) {
	int i = 0;
	char ch;

	while((ch = fgetc(fp)) != EOF && ch != '"'){
		dest[i] = ch;
		++i;
	}

	if (ch == EOF) {
		return 0;
	}
	dest[i] = ch;

	dest[++i] = '\0';

	return 1;
}

//Writes each character inside the quotation to destination, stopping when " or EOF is encountered.
void getDialogue(FILE *fp, char* dest) {
	char ch;
	int i;

	//Write till second quotation or EOF
	for (i = 0; EOF != (ch = fgetc(fp)); ++i) {
		if (ch == '"') break;
		dest[i] = ch;
	}
	dest[i] = '"';
	dest[++i] = '\0';
}

//Passes each word to makeWordSouthie and writes the result to a buffer
void makeSentenceSouthie(char* string, char* dest) {
	char buffer[BUFFER];
	char word[50];
	int i = 0;//Position in word
	int j = 0;//Position in buffer
	int k = 0;//Position in string

	while (k < strlen(string)) {
		i = 0;
		//Write word to word
		while (!isblank(string[k]) && string[k] != '\0') {
			word[i] = string[k];
			++i;
			++k;
		}

		word[i] = '\0';
	
		//Turn word into Southie version
		i = 0;
		while (word[i] != '\0') {
			makeWordSouthie(word, i);
			++i;
		}

		//Copy the word into the buffer
		strncpy(&buffer[j], word, i);
		j += i;
		buffer[j++] = ' ';
		++k;
	}

	buffer[j] = '\0';

	//Copy the buffer to the destination
	strcpy(dest, buffer);
}

//Checks the rules and changes the word accordingly
void makeWordSouthie(char* string, int i) {
	if ((!strcmp(string, "very"))) {
		strcpy(string, "wicked");
	}
	else if (i!= 0 && string[i] == 'r' && isVowel(string[i - 1])) {
		if ((strlen(string) - 1 == i || ispunct(string[i+1])) && ((i >= 2 && string[i - 1] == 'e' && string[i - 2] == 'e') || string[i - 1] == 'i')) {
			if (ispunct(string[i + 1])) {
				char temp = string[i + 1];
				string[i] = 'y';
				string[i + 1] = 'a';
				string[i + 2] = 'h';
				string[i + 3] = temp;
				string[i + 4] = '\0';
			}
			else {
				string[i] = 'y';
				string[i + 1] = 'a';
				string[i + 2] = 'h';
				string[i + 3] = '\0';
			}

		}
		else if ((strlen(string) - 1 == i  || ispunct(string[i + 1]))&& i >= 2 && string[i - 1] == 'o' && string[i - 2] == 'o') {
			if (ispunct(string[i + 1])) {
				char temp = string[i + 1];
				string[i] = 'w';
				string[i + 1] = 'a';
				string[i + 2] = 'h';
				string[i + 3] = temp;
				string[i + 4] = '\0';
			}
			else {
				string[i] = 'w';
				string[i + 1] = 'a';
				string[i + 2] = 'h';
				string[i + 3] = '\0';
			}
		}
		else {
			string[i] = 'h';
		}
	}
	else if (i!= 0 && (strlen(string) -1 == i || ispunct(string[i + 1])) && string[i] == 'a') {
		if (ispunct(string[i + 1])) {
			char temp = string[i + 1];
			string[i + 1] = 'r';
			string[i + 1] = temp;
			string[i + 2] = '\0';
		}
		else {
			string[i + 1] = 'r';
			string[i + 2] = '\0';
		}

	}
}

//Pretty self-explanatory
int isVowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		return 1;
	}
	else {
		return 0;
	}
}