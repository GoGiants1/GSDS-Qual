// C program to demonstrate the use of different functions of string.h library
// 참고: https://www.geeksforgeeks.org/strings-in-c/?ref=lbp
// 함수별 자세한 사용법은 터미널에 `man 3 function_name`으로 확인 가능 (e.g., `man 3 strcpy`) 도움말 창 종료는 q 눌러서
#include <stdio.h>
#include <string.h>
#define size 50

int main()
{
	char destString[size] = "Geeksfor";
	char sourceString[size] = "Geeks";
	char tempDestString[size];

	printf("Length of Destination String: %lu\n",
		strlen(destString)); // 8

	// copying sourceString to tempDestString using strcpy()
	strcpy(tempDestString, sourceString);
	printf("tempDestString after strcpy(): %s\n",
		tempDestString); // Geeks

	// concatenating source to destination using strcat()
	strcat(destString, sourceString);
	printf("destString after Concatenation: %s\n",
		destString); // GeeksforGeeks

	// comparison using strcmp() - 같으면 0
	printf("Comparing destString with sourceString: %d\n",
		strcmp(destString, sourceString)); // 102 

	printf("Comparing first 5 characters: %d\n",
		strncmp(destString, sourceString, 5)); // 0

	// searching substring using strstr()
	char* result = strstr(destString, sourceString);
	printf("Searching sourceString in destString: %s\n", result); // GeeksforGeeks
	// find index 
	if (result != NULL){
		printf("String '%s' is found at index %ld of '%s'.\n", 
            sourceString, result - destString, destString); // String 'Geeks' is found at index 0 of 'GeeksforGeeks'.
	}

    // tokenize the string with given delimiters
    char str[] = "tokenize,string.like! this"; 
	const char delimiters[] = " ,.!"; 
	char* token = strtok(str, delimiters); 
	while (token != NULL) { 
		printf("Token: %s\n", token); 
		token = strtok(NULL, delimiters); 
	} 
    // Token: tokenize
    // Token: string
    // Token: like
    // Token: this

	return 0;
}