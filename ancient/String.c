#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define REP(i,a,b) for (int i = (a); i < (b); ++i)

bool isSubstring(char *s, char *t); // t가 s의 substring 인가?
bool isSameString(char *str1, char *str2);
int** palindromeDpWithLength(char* s); // Palindrome board + 길이 포함 (free)
int** palindromeDp(char* s); // Palindrome board (free)
void longestSubstringPalindrome(char* s); // 문자열의 substring 중 길이가 가장 긴 palindroem substring 
int isPalindrome_str(char *str, int start, int end); // string palindrome 체크
int isPalindrome_int(int n); // 숫자 palindrome 체크
bool isPalindrome(char *s); // string palindrome 체크

char* reverseString(char* s); // 문자열 뒤집기 (free)
int startsWith(char* string, char* prefix); // prefix 로 시작하는지 체크
void shortestPalindrome(char* s); // 문자를 앞에 몇개 추가해서 만들 수 있는 가장 짧은 palindrome

char* sliceString(char* input, int start, int end); // string slicing
void maxPalindromeSubsets(char* s); //substring 중 최대길이 palidrome 분할 출력 

void minInsertionPalindrome(char* s); //최소한의 문자를 중간에 추가하여 palindrome 만들기

char *cloneString(char *str);
void swap(char *x, char *y);
void sortString(char* s); // 알파뱃순으로 정렬
void appendStringToArray(char ***array, int *size, char *str);

void getSubstrings(char *s, int start, char ***results, int *size, int k); // 길이가 k인 substring = subset(연속x)
void getDivisions(char *s, int start, char **path, int pathSize, char ****results, int **resultsSizes, int *resultsCount);

char** getSubsets(char* s, int* numSubsequences); // 모든 subset (free) 1<<l

int factorial(int n);
void generatePermutations(char *s, int len, char **output, int *index, char *current, int pos, int *visited);
char **getPermutations(char *s, int *sizeOfOutput);

void palindromePartitions(char *s);
void longestPalindrome(char *s); // 문자열에서 최소한 제거하여 펠린드롬 (저번기출)


/*동적할당 부분*/
char** mallocStringArray1D(int numberOfStrings, int maxLength); 
void printStringArray1D(char** stringArray, int numberOfStrings);
void freeStringArray1D(char** stringArray, int numberOfStrings);

char*** mallocStringArray2D(int numberOfStringArrays, int numberOfStrings, int maxLength);
void printStringArray2D(char*** stringArray2D, int numberOfStringArrays, int numberOfStrings);
void freeStringArray2D(char*** stringArray2D, int numberOfStringArrays, int numberOfStrings);

int* mallocIntArray1D(int size);
void printIntArray1D(int *array, int size);
void freeIntArray1D(int* array);

int** mallocIntArray2D(int n, int m);
void printIntArray2D(int **array, int n, int m);
void freeIntArray2D(int** array, int n);

void freeDivisions(char ***results, int *resultsSizes, int resultsCount);

// memset(array, 0, length * sizeof(int)); (설정메모리 시작 주소, 메모리 설정 값, 설정할 byte 수) 

int main(){
    // char scanf_s[100];
    // scanf("%s",scanf_s);

    /*Test "isSubstring"*/
    char* s1 = "tenet";
    char* s2 = "tenet is pullup";
    printf("%d\n",isSubstring(s2,s1));

    /*Test "longestSubstringPalindrome"*/
    char* s3 = "tenetispalindrome";
    longestSubstringPalindrome(s3);
    // longestSubstringPalindrome(scanf_s);
    
    /*Test "shortestPalindrome"*/
    shortestPalindrome(s3);
    // shortestPalindrome(scanf_s);

    /*Test "minInsertionPalindrome"*/
    minInsertionPalindrome(s3);
    // minInsertionPalindrome(scanf_s);

    /*Test "StringArray1D"*/
    int numberOfStrings = 5;
    int maxLength = 100;
    char** stringArray = mallocStringArray1D(numberOfStrings, maxLength);
    strcpy(stringArray[0],"0 row");
    strcpy(stringArray[1],"1 row");
    strcpy(stringArray[2],"2 row");
    strcpy(stringArray[3],"3 row");
    strcpy(stringArray[4],"4 row");
    printStringArray1D(stringArray, numberOfStrings);
    freeStringArray1D(stringArray, numberOfStrings);


    /*Test "maxPalindromeSubsets"*/
    char* s4 = "maxpalsubsets";
    maxPalindromeSubsets(s4);
    // maxPalindromeSubsets(scanf_s);
    
    /*Test "getDivision"*/
    char* s5 = "div";
    char **path = NULL;
    int pathSize = 0;
    char ***results = NULL;
    int *resultsSizes = NULL; //각 partition 의 길이를 array로
    int resultsCount = 0; //division 집합 개수
    getDivisions(s5, 0, path, pathSize, &results, &resultsSizes, &resultsCount);
    freeDivisions(results,resultsSizes,resultsCount);

    /*Test "palindromePartitions"*/
    char* s6 = "partition";
    palindromePartitions(s6);
    // palindromePartitions(scanf_s);
    
    /*Test "getSubstrings"*/
    char *s7 = "abc";
    char **substrings = NULL; //여기에 담김
    int substringsLen = 0; //substring 개수

    getSubstrings(s7, 0, &substrings, &substringsLen, 2);
    printStringArray1D(substrings,substringsLen);
    freeStringArray1D(substrings, substringsLen);
    
    /*Test "longestPalindrome"*/
    char *s8 = "unique";
    longestPalindrome(s8); // 문자열에서 최소한 제거하여 펠린드롬
    // longestPalindrome(scanf_s); // 문자열에서 최소한 제거하여 펠린드롬
    
    /*Test "getSubsets"*/
    char *s9 = "abc";
    int l ;
    char** subsets = getSubsets(s9,&l);
    printStringArray1D(subsets,l);
    freeStringArray1D(subsets,l);
    
    /*Test "getPermutations"*/
    char *s10 = "123";
    int sizeOfOutput ;
    char** permutations = getPermutations(s10,&sizeOfOutput);
    printStringArray1D(permutations,sizeOfOutput);
    freeStringArray1D(permutations,sizeOfOutput);
    
    return 0;
}


bool isSubstring(char *s,char *t) {
    
    int lenS = strlen(s);
    int lenT = strlen(t);

    if (lenS < lenT) {
        return false;
    }

    for (int i = 0; i <= lenS - lenT; i++) {
        bool match = true;
        for (int j = 0; j < lenT; j++) {
            if (s[i + j] != t[j]) {
                match = false;
                break; // No need to continue if any character doesn't match
            }
        }
        if (match) {
            return true; // Found a match
        }
    }
    return false; // No match found
}

int** palindromeDpWithLength(char* s){
    int l = strlen(s);
    int** board = mallocIntArray2D(l,l);

    for (int i = 0; i < l; i++) {
        memset(board[i], 0, l * sizeof(int));
        board[i][i] = 1;
    }

    for (int i = 0; i < l - 1; i++) {
        int j = i + 1;
        if (s[i] == s[j]) {
            board[i][j] = 2;
        }
    }

    for (int k = 2; k < l; k++) {
        for (int i = 0; i < l - k; i++) {
            int j = i + k;
            if (s[i] == s[j] && board[i + 1][j - 1] > 0) {
                board[i][j] = board[i + 1][j - 1] + 2;
            } else {
                board[i][j] = 0;
            }
        }
    }
    return board;
}

int** palindromeDp(char* s) {
    int l = strlen(s);
    int** board = mallocIntArray2D(l,l);

    for (int i = 0; i < l; i++) {
        memset(board[i], 0, l * sizeof(int));
        board[i][i] = 1; 
    }

    for (int i = 0; i < l - 1; i++) {
        int j = i + 1;
        if (s[i] == s[j]) {
            board[i][j] = 1; 
        }
    }

    for (int k = 2; k < l; k++) {
        for (int i = 0; i < l - k; i++) {
            int j = i + k;
            if (s[i] == s[j] && board[i + 1][j - 1]) {
                board[i][j] = 1; 
            } else {
                board[i][j] = 0; 
            }
        }
    }

    return board;
}

void longestSubstringPalindrome(char* s) {
    int l = strlen(s);
    
    int** board = palindromeDpWithLength(s);

    int m = -1;
    int start = 0;
    int end = 0;

    for (int i = 0; i < l; i++) {
        for (int j = i; j < l; j++) {
            if (board[i][j] > m) {
                m = board[i][j];
                start = i;
                end = j;
            }
        }
    }
    
    freeIntArray2D(board,l);

    char* output = (char*)malloc(l * sizeof(char));
    strncpy(output, s + start, end - start + 1);
    output[end - start + 1] = '\0'; // Null-terminate the substring
    printf("Longest Palindrome : %s\n",output);
    printf("Length : %lu\n",strlen(output));
    
    free(output);
    
}

int isPalindrome_str(char *str, int start, int end) {
    while (start < end) {
        if (str[start++] != str[end--]) return 0;
    }
    return 1;
}

int isPalindrome_int(int n) {
    int reverse = 0, temp = n;

    while (temp != 0) {
        reverse = reverse * 10 + temp % 10;
        temp /= 10;
    }
    return n == reverse;
}

bool isPalindrome(char *s) {
    int length = strlen(s);
    int start = 0;
    int end = length - 1;

    while(start < end) {
        if(s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

char* reverseString(char* s) {
    int length = strlen(s);
    char* reversed = (char*)malloc((length + 1) * sizeof(char));
    
    for (int i = 0; i < length; i++) {
        reversed[i] = s[length - 1 - i];
    }
    reversed[length] = '\0';
    
    return reversed;
}

int startsWith(char* string,char* prefix) {
    while (*prefix) {
        if (*prefix++ != *string++) return 0;
    }
    return 1;
}

void shortestPalindrome(char* s) {
    char* t = reverseString(s);
    int length = strlen(s);
    char* result = NULL;

    for (int i = 0; i <= length; i++) {
        if (startsWith(s, t + i)) {
            int resultLength = length + i;
            result = (char*)malloc((resultLength + 1) * sizeof(char));
            memcpy(result, t, i);
            memcpy(result + i, s, length + 1); 
            break;
        }
    }
    free(t); 
    printf("shortest Palindrome : %s\n",result);
    printf("number of appended chars : %lu\n",strlen(result) - strlen(s));
    free(result);
}

char* sliceString(char* input, int start, int end) {
    if (input == NULL || start < 0 || end <= start) {
        return NULL; 
    }

    int sliceLength = end - start; 

    char* slice = malloc(sliceLength + 1); 
    if (slice == NULL) {
        return NULL; 
    }

    strncpy(slice, input + start, sliceLength);
    slice[sliceLength] = '\0'; 

    return slice;
}


void maxPalindromeSubsets(char* s) {
    int l = strlen(s);
    int** board = palindromeDp(s);

    int max_len = 1<<l;
    
    char** output = mallocStringArray1D(max_len,l);
    
    int total = 0;
    
    REP(i,0,l){
        REP(j,0,l){
            if (board[i][j] == 1){
                output[total] = sliceString(s,i,j+1);
                total+=1;
            }
        }
    }

    // printStringArray1D(output,total);

    int* Delete = mallocIntArray1D(total);
    memset(Delete, 0, total * sizeof(int));
    
    REP(i,0,total){
        REP(j,0,total){
            if (output[i]!=output[j] && isSubstring(output[i],output[j])){
                Delete[j] = 1;
            }
        }
    }

    REP(i,0,total){
        if (Delete[i] != 1){
            printf("%s\n",output[i]);
        }
    }

    freeIntArray2D(board,l);
    freeIntArray1D(Delete);
    freeStringArray1D(output,max_len);
}

char *cloneString(char *str) {
    char *clone = (char *)malloc(strlen(str) + 1);
    strcpy(clone, str);
    return clone;
}

void appendStringToArray(char ***array, int *size, char *str) {
    (*size)++;
    *array = (char **)realloc(*array, (*size) * sizeof(char *));
    (*array)[(*size) - 1] = cloneString(str);
}

// Recursive function to generate all substrings
void getSubstrings(char *s, int start, char ***results, int *size, int k) {

    int len = strlen(s);
    if (len == k) {
        appendStringToArray(results, size, s);
        return;
    }

    for (int end = start; end < len; end++) {
        char *substring = (char *)malloc(len); // len instead of len + 1 because we're removing a char
        int j = 0;
        for (int i = 0; i < len; i++) {
            if (i != end) {
                substring[j++] = s[i];
            }
        }
        substring[j] = '\0'; // Null-terminate the new string
        getSubstrings(substring, end, results, size, k);
        free(substring);
    }
}

// Recursive function to get all divisions
void getDivisions(char *s, int start, char **path, int pathSize, char ****results, int **resultsSizes, int *resultsCount) {
    
    int len = strlen(s);
    if (start == len) {
        // Clone path and add to results
        (*resultsCount)++;
        *results = realloc(*results, (*resultsCount) * sizeof(char **));
        (*resultsSizes) = realloc(*resultsSizes, (*resultsCount) * sizeof(int));
        (*results)[*resultsCount - 1] = malloc(pathSize * sizeof(char *));
        (*resultsSizes)[*resultsCount - 1] = pathSize;
        for (int i = 0; i < pathSize; i++) {
            (*results)[*resultsCount - 1][i] = cloneString(path[i]);
        }
        return;
    }

    for (int end = start + 1; end <= len; end++) {
        // Create a new segment of the string
        char *segment = cloneString(s + start);
        segment[end - start] = '\0'; // Properly terminate the new segment

        // Append segment to path and call recursively
        char **newPath = malloc((pathSize + 1) * sizeof(char *));
        for (int i = 0; i < pathSize; i++) {
            newPath[i] = path[i]; // Copy existing path
        }
        newPath[pathSize] = segment; // Add new segment

        getDivisions(s, end, newPath, pathSize + 1, results, resultsSizes, resultsCount);

        // Free the allocated memory for newPath except the last element
        free(segment);
        free(newPath);
    }
}

char** getSubsets(char* s, int* numSubsequences){
    int length = strlen(s);
    int totalSubsequences = 1 << length;  // 2^length

    char** allSubsequences = (char**)malloc(sizeof(char*) * totalSubsequences);

    for (int i = 0; i < totalSubsequences; i++) {
        allSubsequences[i] = (char*)malloc(sizeof(char) * (length + 1));
        int k = 0;

        for (int j = 0; j < length; j++) {
            if ((i >> j) & 1) {
                allSubsequences[i][k++] = s[j];
            }
        }

        allSubsequences[i][k] = '\0';
    }

    *numSubsequences = totalSubsequences;
    return allSubsequences;
}

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

void generatePermutations(char *s, int len, char **output, int *index, char *current, int pos, int *visited) {
    if (pos == len) {
        current[pos] = '\0';
        output[*index] = strdup(current);
        (*index)++;
        return;
    }
    for (int i = 0; i < len; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            current[pos] = s[i];
            generatePermutations(s, len, output, index, current, pos + 1, visited);
            visited[i] = 0;
        }
    }
}

char **getPermutations(char *s, int *sizeOfOutput) {
    int len = strlen(s);
    *sizeOfOutput = factorial(len);
    char **output = (char **)malloc(sizeof(char *) * (*sizeOfOutput));
    char *current = (char *)malloc(sizeof(char) * (len + 1));
    int *visited = (int *)calloc(len, sizeof(int));
    int index = 0;

    generatePermutations(s, len, output, &index, current, 0, visited);

    free(current);
    free(visited);
    *sizeOfOutput = index; // Adjust the output size to the actual number of permutations generated
    return output;
}


void palindromePartitions(char *s){
    char **path = NULL;
    int pathSize = 0;

    char ***results = NULL;
    int *resultsSizes = NULL; //각 partition 의 길이를 array로
    int resultsCount = 0; //division 집합 개수

    getDivisions(s, 0, path, pathSize, &results, &resultsSizes, &resultsCount);
    
    for (int i = 0; i < resultsCount; i++) {
        int count = 0;
        
        for (int j = 0; j < resultsSizes[i]; j++) {
            count = count + isPalindrome(results[i][j]); 
        }
        
        if (count == resultsSizes[i]){//partition 의 모든 분할이 palindrome인지 체크.
            for (int j = 0; j < resultsSizes[i]; j++) {
                printf("%s ", results[i][j]);
            }
            printf("\n");
        }
    }
    
    freeDivisions(results,resultsSizes,resultsCount);
}


void minInsertionPalindrome(char* s) {
    int n = strlen(s);
    
    char* result = (char*)malloc((2 * n + 1)*sizeof(char));
    
    int** dp = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; ++i) {
        dp[i] = (int*)malloc(n * sizeof(int));
        memset(dp[i], 0, n * sizeof(int));
    }

    for (int i = n - 2; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1];
            } else {
                dp[i][j] = (dp[i + 1][j] < dp[i][j - 1] ? dp[i + 1][j] : dp[i][j - 1]) + 1;
            }
        }
    }

    int minInsertions = dp[0][n - 1];

    int i = 0, j = n - 1, k = 0;

    while (i <= j) {
        if (s[i] == s[j]) {
            result[k] = s[i];
            result[n + minInsertions - k - 1] = s[i];
            ++i;
            --j;
        } else if (dp[i][j] == dp[i + 1][j] + 1) {
            result[k] = s[i];
            result[n + minInsertions - k - 1] = s[i];
            ++i;
        } else {
            result[k] = s[j];
            result[n + minInsertions - k - 1] = s[j];
            --j;
        }
        ++k;
    }

    result[n + minInsertions] = '\0';

    // Free allocated memory
    for (int i = 0; i < n; ++i) {
        free(dp[i]);
    }
    free(dp);

    // Return the minimum insertions
    printf("Palindrome String: %s\n", result);
    printf("Minimum Insertions: %d\n", minInsertions);
    
    free(result);
}

void longestPalindrome(char *s){
    int l = strlen(s);
    int k = l;
    
    char **substrings = NULL; 
    int substringsLen = 0; //substring 개수

    int stop = 0;

    while (k){
        substrings = NULL;
        substringsLen = 0;
        
        getSubstrings(s, 0, &substrings, &substringsLen, k);
        
        REP(i,0,substringsLen){
            if (isPalindrome(substrings[i])) {
                printf("Logest substring : %s\n",substrings[i]);
                printf("the number of removed chars : %d\n",l-k);
                stop = 1;
                break;
                }
                
        }
        freeStringArray1D(substrings, substringsLen);
        if (stop)break;
        k -= 1;
    }
}
void swap(char *x, char *y){
    char temp = *x;
    *x = *y;
    *y = temp;
}

void sortString(char* s) {
    int length = strlen(s);
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (s[i] > s[j]) {
                swap(&s[i], &s[j]);
            }
        }
    }
}

bool isSameString(char *str1, char *str2) {
    return strcmp(str1, str2) == 0;
}




//---------------------------------------<MALLOC,PRINT,FREE>---------------------------------------------------//

void printIntArray1D(int *array, int size) {
    printf("\n[");
    for(int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void printIntArray2D(int **array, int n, int m) {
    printf("\n[");
    for(int i = 0; i < n; i++) {
        printf("[");
        for(int j = 0; j < m; j++) {
            printf("%d", array[i][j]);
            if (j < m - 1) {
                printf(", ");
            }
        }
        printf("]");
        if (i < n - 1) {
            printf(",\n");
        } else {
            printf("");
        }
    }
    printf("]\n");
}

int* mallocIntArray1D(int size){
    int* array = (int*)malloc(sizeof(int)*size);
    return array;
}

void freeIntArray1D(int* array){
    free(array);
}

int** mallocIntArray2D(int n, int m){
    int **array = (int **)malloc(n * sizeof(int *));
    for(int i = 0; i < n; i++) {
        array[i] = (int *)malloc(m * sizeof(int)); 
    }
    return array; 
}

void freeIntArray2D(int** array, int n){
    for(int i = 0; i < n; i++) {
        free(array[i]); 
    }
    free(array); 
}

char** mallocStringArray1D(int numberOfStrings, int maxLength) {
    char** stringArray = (char**)malloc(numberOfStrings * sizeof(char*));
    for (int i = 0; i < numberOfStrings; i++) {
        stringArray[i] = (char*)malloc((maxLength + 1) * sizeof(char)); // +1 for the null terminator
    }
    
    return stringArray;
}

void printStringArray1D(char** stringArray, int numberOfStrings) {
    for (int i = 0; i < numberOfStrings; i++) {
        printf("%s\n", stringArray[i]);
    }
}

void freeStringArray1D(char** stringArray, int numberOfStrings) {
    for (int i = 0; i < numberOfStrings; i++) {
        free(stringArray[i]); // Free each string
    }
    free(stringArray); // Free the array of pointers
}

char*** mallocStringArray2D(int numberOfStringArrays, int numberOfStrings, int maxLength) {
    char*** stringArray2D = (char***)malloc(numberOfStringArrays * sizeof(char**));
    for (int i = 0; i < numberOfStringArrays; i++) {
        stringArray2D[i] = (char**)malloc(numberOfStrings * sizeof(char*));
        for (int j = 0; j < numberOfStrings; j++) {
            stringArray2D[i][j] = (char*)malloc((maxLength + 1) * sizeof(char)); // +1 for the null terminator
        }
    }
    return stringArray2D;
}

void printStringArray2D(char*** stringArray2D, int numberOfStringArrays, int numberOfStrings) {
    for (int i = 0; i < numberOfStringArrays; i++) {
        printf("Array %d:\n", i);
        for (int j = 0; j < numberOfStrings; j++) {
            printf("  %s\n", stringArray2D[i][j]);
        }
    }
}

void freeStringArray2D(char*** stringArray2D, int numberOfStringArrays, int numberOfStrings) {
    for (int i = 0; i < numberOfStringArrays; i++) {
        for (int j = 0; j < numberOfStrings; j++) {
            free(stringArray2D[i][j]); // Free each string
        }
        free(stringArray2D[i]); // Free the array of string pointers
    }
    free(stringArray2D); // Free the outer array
}

void freeDivisions(char ***results, int *resultsSizes, int resultsCount) {
    for (int i = 0; i < resultsCount; i++) {
        for (int j = 0; j < (resultsSizes)[i]; j++) {
            free((results)[i][j]); // Free each string
        }
        free((results)[i]); // Free the path array itself
    }
    free(results); // Free the array of paths
    free(resultsSizes); // Free the sizes array
}
