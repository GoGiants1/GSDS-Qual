/*
1. reverse_string() - 문자열 뒤집기
2. has_duplicates() - 중복 문자 확인하기
removeDuplicates() 중목 문자 제거
3. extract_numbers() - 숫자만 추출하기
4. extract_words() - 단어 추출하기
5. find_pattern() - 패턴 찾기
6. remove_pattern() - 패턴 제거하기
7. count_pattern() - 패턴의 등장 횟수 세기
8. replace_string() - 부분 문자열 교체하기
9. split_string() - 문자열 분리하기
10. concatenate_strings() - 문자열 연결하기
11. capitalize_first() - 첫 글자 대문자로 변환하기
12. trim_string() - 문자열 앞뒤 공백 제거하기
13. to_lowercase() - 문자열을 소문자로 변환하기
14. to_uppercase() - 문자열을 대문자로 변환하기
15. string_length() - 문자열의 길이 반환하기
16. remove_inner_spaces() - 문자열 중간의 공백 제거하기
17. extract_alphabets() - 알파벳만 추출하기
18. remove_special_characters() - 특수 문자 제거하기
19. is_alpha() - 문자열이 알파벳으로만 이루어져 있는지 확인하기
20. is_numeric() - 문자열이 숫자로만 이루어져 있는지 확인하기
21. find_position() - 문자나 단어의 위치 찾기
22. get_middle_characters() - 문자열의 중앙 문자(들) 반환하기
23. remove_word() - 문자열에서 주어진 단어 제거하기
24. remove_all_spaces() - 문자열에서 모든 공백 제거하기
25. get_character_at() - 문자열의 특정 위치의 문자 반환하기
26. swap_case() - 대문자는 소문자로, 소문자는 대문자로 변환하기

*/





///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>

// 문자열 뒤집기
void reverse_string(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}

/*
int main() {
    char str[] = "Hello";
    reverse_string(str);
    printf("%s\n", str);  // olleH
    return 0;
}
*/

///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// 문자열에 중복된 문자가 있는지 확인
bool has_duplicates(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (s[i] == s[j]) {
                return true;
            }
        }
    }
    return false;
}

/*
int main() {
    char str[] = "Hello";
    bool result = has_duplicates(str);
    printf("%s\n", result ? "True" : "False");  // True
    return 0;
}
*/
///////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* removeDuplicates(const char* input) {
    if (input == NULL) {
        return NULL;
    }

    int inputLength = strlen(input);
    if (inputLength <= 1) {
        // 문자열의 길이가 1 이하인 경우 중복이 없으므로 복사하여 반환
        char* result = (char*)malloc(inputLength + 1);
        strcpy(result, input);
        return result;
    }

    // 중복을 제거한 문자열을 생성
    char* result = (char*)malloc(inputLength + 1);
    int resultIndex = 0;

    for (int i = 0; i < inputLength; ++i) {
        int isDuplicate = 0;
        for (int j = 0; j < resultIndex; ++j) {
            if (input[i] == result[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            result[resultIndex++] = input[i];
        }
    }
    result[resultIndex] = '\0';

    return result;
}

int main() {
    const char* input = "aaabbcde";
    char* result = removeDuplicates(input);

    printf("Original: %s\n", input);
    printf("Duplicates Removed: %s\n", result);

    free(result);  // 메모리 해제

    return 0;
}

///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// 문자열에서 숫자만 추출
void extract_numbers(char *s, int *result, int *len) {
    int index = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (isdigit(s[i])) {
            result[index++] = s[i] - '0';
        }
    }
    *len = index;
}

/*
int main() {
    char str[] = "Hello123World45";
    int numbers[15];
    int len;
    extract_numbers(str, numbers, &len);
    for (int i = 0; i < len; i++) {
        printf("%d ", numbers[i]);
    }
    return 0;
}
*/

///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 문자열에서 단어만 추출
void extract_words(char *s, char result[][50], int *len) {
    int index = 0;
    char *token = strtok(s, " ");
    while (token) {
        strcpy(result[index++], token);
        token = strtok(NULL, " ");
    }
    *len = index;
}

/*
int main() {
    char str[] = "Hello World";
    char words[10][50];
    int len;
    extract_words(str, words, &len);
    for (int i = 0; i < len; i++) {
        printf("%s ", words[i]);
    }
    return 0;
}
*/


///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <regex.h>

// 문자열에서 패턴 찾기 (간단한 예로 최대 10개의 패턴만 검색)
void find_pattern(char *s, char *pattern, char result[][100], int *len) {
    regex_t regex;
    regmatch_t matches[10];

    regcomp(&regex, pattern, REG_EXTENDED);
    char *cursor = s;
    int index = 0;

    while (regexec(&regex, cursor, 1, matches, 0) == 0) {
        int start = matches[0].rm_so;
        int end = matches[0].rm_eo;
        strncpy(result[index], cursor + start, end - start);
        result[index][end - start] = '\0';
        cursor += end;
        index++;
    }
    *len = index;

    regfree(&regex);
}

/*
int main() {
    char str[] = "cat bat mat rat";
    char pattern[] = "a.";
    char matches[10][100];
    int len;
    find_pattern(str, pattern, matches, &len);
    for (int i = 0; i < len; i++) {
        printf("%s ", matches[i]);  // 출력: at at at at
    }
    return 0;
}
*/

//////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <regex.h>

// 문자열에서 패턴 제거
void remove_pattern(char *s, char *pattern, char *result) {
    regex_t regex;
    regmatch_t match;
    
    regcomp(&regex, pattern, REG_EXTENDED);
    int offset = 0;
    char *cursor = s;
    while (regexec(&regex, cursor, 1, &match, 0) == 0) {
        int start = match.rm_so;
        int end = match.rm_eo;
        strncpy(result + offset, cursor, start);
        offset += start;
        cursor += end;
    }
    strcpy(result + offset, cursor);

    regfree(&regex);
}

/*
int main() {
    char str[] = "abcXXXdefXXXghi";
    char pattern[] = "XXX";
    char result[100];
    remove_pattern(str, pattern, result);
    printf("%s\n", result);  // 출력: abcdefghi
    return 0;
}
*/

//////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>

// 문자열에서 패턴의 등장 횟수 세기
int count_pattern(char *s, char *pattern) {
    int count = 0;
    char *pos = s;
    while ((pos = strstr(pos, pattern)) != NULL) {
        count++;
        pos += strlen(pattern);
    }
    return count;
}

/*
int main() {
    char str[] = "abcabcabc";
    char pattern[] = "abc";
    int count = count_pattern(str, pattern);
    printf("%d\n", count);  // 출력: 3
    return 0;
}

*/

///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>

// 문자열 내의 부분 문자열 교체
void replace_string(char *s, char *old, char *new, char *result) {
    char *pos;
    int old_len = strlen(old);
    int new_len = strlen(new);
    int index = 0;

    while ((pos = strstr(s, old)) != NULL) {
        strncpy(result + index, s, pos - s);
        index += pos - s;
        strcpy(result + index, new);
        index += new_len;
        s = pos + old_len;
    }
    strcpy(result + index, s);
}

/*
int main() {
    char str[] = "Hello world, world!";
    char result[100];
    replace_string(str, "world", "Earth", result);
    printf("%s\n", result);  // 출력: Hello Earth, Earth!
    return 0;
}
*/

///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>

// 문자열 분리
void split_string(const char *s, char delimiter, char result[][100], int *len) {
    char temp[1000];  // 임시 문자열에 원본을 복사하여 작업합니다.
    strcpy(temp, s);
    
    char delim[2] = {delimiter, '\0'};  // strtok() 함수에 전달하기 위해 delimiter를 문자열로 변환합니다.
    char *token = strtok(temp, delim);
    int index = 0;

    while (token) {
        strcpy(result[index++], token);
        token = strtok(NULL, delim);
    }
    *len = index;
}

int main() {
    char s[] = "Hello,World,How,Are,You";
    char result[100][100];
    int len = 0;

    split_string(s, ',', result, &len);
    
    for (int i = 0; i < len; i++) {
        printf("%s ", result[i]);
    }
    // 예상 출력: Hello World How Are You 
    return 0;
}



///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

// 여러 문자열 연결
void concatenate_strings(char *result, int num, ...) {
    va_list args;
    va_start(args, num);

    result[0] = '\0';
    for (int i = 0; i < num; i++) {
        strcat(result, va_arg(args, char *));
    }
    va_end(args);
}

/*
int main() {
    char result[100];
    concatenate_strings(result, 3, "Hello", " ", "World!");
    printf("%s\n", result);  // 출력: Hello World!
    return 0;
}
*/

///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <ctype.h>

// 문자열의 첫 글자를 대문자로 변환
void capitalize_first(char *s) {
    if (s[0] != '\0') {
        s[0] = toupper(s[0]);
    }
}

/*
int main() {
    char str[] = "hello";
    capitalize_first(str);
    printf("%s\n", str);  // 출력: Hello
    return 0;
}
*/

///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 문자열 앞뒤 공백 제거
void trim_string(char *s) {
    int start = 0, end = strlen(s) - 1;

    while (isspace(s[start])) {
        start++;
    }
    while (end > start && isspace(s[end])) {
        end--;
    }

    memmove(s, &s[start], end - start + 1);
    s[end - start + 1] = '\0';
}

/*
int main() {
    char str[] = "   Hello World!   ";
    trim_string(str);
    printf("'%s'\n", str);  // 출력: 'Hello World!'
    return 0;
}
*/
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <ctype.h>

// 문자열을 소문자로 변환
void to_lowercase(char *s) {
    for (int i = 0; s[i]; i++) {
        s[i] = tolower(s[i]);
    }
}

/*
int main() {
    char str[] = "HELLO";
    to_lowercase(str);
    printf("%s\n", str);  // 출력: hello
    return 0;
}
*/
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <ctype.h>

// 문자열을 대문자로 변환
void to_uppercase(char *s) {
    for (int i = 0; s[i]; i++) {
        s[i] = toupper(s[i]);
    }
}

/*
int main() {
    char str[] = "hello";
    to_uppercase(str);
    printf("%s\n", str);  // 출력: HELLO
    return 0;
}
*/
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>

// 문자열의 길이 반환
int string_length(char *s) {
    return strlen(s);
}

/*
int main() {
    char str[] = "Hello";
    printf("%d\n", string_length(str));  // 출력: 5
    return 0;
}
*/
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>

// 문자열 중간의 공백 제거
void remove_inner_spaces(char *s) {
    int index = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] != ' ') {
            s[index++] = s[i];
        }
    }
    s[index] = '\0';
}

/*
int main() {
    char str[] = "H e l l o";
    remove_inner_spaces(str);
    printf("%s\n", str);  // 출력: Hello
    return 0;
}
*/
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <ctype.h>

// 문자열에서 알파벳만 추출
void extract_alphabets(char *s, char *result) {
    int index = 0;
    for (int i = 0; s[i]; i++) {
        if (isalpha(s[i])) {
            result[index++] = s[i];
        }
    }
    result[index] = '\0';
}

/*
int main() {
    char str[] = "1a2b3c";
    char result[100];
    extract_alphabets(str, result);
    printf("%s\n", result);  // 출력: abc
    return 0;
}
*/
////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <ctype.h>

// 문자열에서 특수 문자 제거
void remove_special_characters(char *s, char *result) {
    int index = 0;
    for (int i = 0; s[i]; i++) {
        if (isalnum(s[i]) || s[i] == ' ') {
            result[index++] = s[i];
        }
    }
    result[index] = '\0';
}

/*
int main() {
    char str[] = "Hello@#! World!";
    char result[100];
    remove_special_characters(str, result);
    printf("%s\n", result);  // 출력: Hello World
    return 0;
}
*/
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

// 문자열이 오직 알파벳으로만 이루어져 있는지 확인
bool is_alpha(char *s) {
    for (int i = 0; s[i]; i++) {
        if (!isalpha(s[i])) {
            return false;
        }
    }
    return true;
}

/*
int main() {
    char str[] = "Hello";
    printf("%s\n", is_alpha(str) ? "True" : "False");  // 출력: True
    return 0;
}
*/
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// 문자열이 오직 숫자로만 이루어져 있는지 확인
bool is_numeric(char *s) {
    for (int i = 0; s[i]; i++) {
        if (!isdigit(s[i])) {
            return false;
        }
    }
    return true;
}

/*
int main() {
    char str[] = "12345";
    printf("%s\n", is_numeric(str) ? "True" : "False");  // 출력: True
    return 0;
}
*/
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>

// 문자열에서 주어진 단어나 문자의 첫 번째 위치 찾기
int find_position(char *s, char *word) {
    char *pos = strstr(s, word);
    return pos ? pos - s : -1;
}

/*
int main() {
    char str[] = "Hello World";
    printf("%d\n", find_position(str, "World"));  // 출력: 6
    return 0;
}
*/
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>

// 문자열의 중앙 문자(들) 반환
void get_middle_characters(char *s, char *result) {
    int len = strlen(s);
    int mid = len / 2;
    if (len % 2 == 0) {
        result[0] = s[mid - 1];
        result[1] = s[mid];
        result[2] = '\0';
    } else {
        result[0] = s[mid];
        result[1] = '\0';
    }
}

/*
int main() {
    char str[] = "Hello";
    char result[3];
    get_middle_characters(str, result);
    printf("%s\n", result);  // 출력: l
    return 0;
}
*/
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>

// 문자열에서 주어진 단어 제거
void remove_word(char *s, char *word, char *result) {
    char *start = s, *end;
    int index = 0;
    while ((end = strstr(start, word)) != NULL) {
        int len = end - start;
        strncpy(result + index, start, len);
        index += len;
        start = end + strlen(word);
    }
    strcpy(result + index, start);
}

/*
int main() {
    char str[] = "Hello World";
    char result[100];
    remove_word(str, "World", result);
    printf("%s\n", result);  // 출력: Hello 
    return 0;
}
*/
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
#include <stdio.h>

// 문자열에서 모든 공백 제거
void remove_all_spaces(char *s) {
    int index = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] != ' ') {
            s[index++] = s[i];
        }
    }
    s[index] = '\0';
}

/*
int main() {
    char str[] = "Hello World";
    remove_all_spaces(str);
    printf("%s\n", str);  // 출력: HelloWorld
    return 0;
}

*/
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>

// 문자열의 특정 위치의 문자 반환
char get_character_at(char *s, int position) {
    return s[position];
}

/*
int main() {
    char str[] = "Hello";
    printf("%c\n", get_character_at(str, 2));  // 출력: l
    return 0;
}

*/
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <ctype.h>

// 문자열에서 대문자는 소문자로, 소문자는 대문자로 변환
void swap_case(char *s) {
    for (int i = 0; s[i]; i++) {
        if (isupper(s[i])) {
            s[i] = tolower(s[i]);
        } else if (islower(s[i])) {
            s[i] = toupper(s[i]);
        }
    }
}

/*
int main() {
    char str[] = "Hello WORLD";
    swap_case(str);
    printf("%s\n", str);  // 출력: hELLO world
    return 0;
}*/

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ANAGRAMS 1000

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

int index = 0;
char* anagrams[MAX_ANAGRAMS];

void generate_anagrams(char *s, int start, int end) {
    if (start == end) {
        anagrams[index] = strdup(s);
        index++;
    } else {
        for (int i = start; i <= end; i++) {
            swap((s+start), (s+i));
            generate_anagrams(s, start+1, end);
            swap((s+start), (s+i));  // 원래 상태로 돌리기
        }
    }
}

int main() {
    char str[] = "abc";
    generate_anagrams(str, 0, strlen(str)-1);
    for (int i = 0; i < index; i++) {
        printf("%s\n", anagrams[i]);
        free(anagrams[i]);
    }
    return 0;
}
///////////////////////////////////////////////////////////////////////


// Palindrome

// #1 숫자 palindrome
#include <iostream>
bool isPalindrome(int x) {
    int originalNum = x;
    long long reversedNum = 0;

    // 숫자 뒤집기
    while (x > 0) {
        int digit = x % 10;
        reversedNum = reversedNum * 10 + digit;
        x /= 10;
    }

    // 원래 숫자와 뒤집힌 숫자 비교
    if (originalNum == reversedNum) {
        return true; // 팰린드롬인 경우
    } else {
        return false; // 팰린드롬이 아닌 경우
    }
}

int main() {
    int number;

    // 사용자로부터 숫자 입력 받기
    std::cout << "숫자를 입력하세요: ";
    std::cin >> number;

    // 팰린드롬 여부 확인
    if (isPalindrome(number)) {
        std::cout << number << "는 팰린드롬입니다." << std::endl;
    } else {
        std::cout << number << "는 팰린드롬이 아닙니다." << std::endl;
    }

    return 0;
}

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Compare function for qsort to sort strings based on length
int compareStrings(const void* a, const void* b) {
    return (strlen(*(const char**)b) - strlen(*(const char**)a));
}

char** sortByLength(char** originalArray, int arraySize) {
    // Allocate memory for a copy of the original array
    char** newArray = (char**)malloc(sizeof(char*) * arraySize);
    
    // Copy each string in the original array to the new array
    for (int i = 0; i < arraySize; i++) {
        newArray[i] = strdup(originalArray[i]);
    }

    // Sort the new array based on string length using qsort
    qsort(newArray, arraySize, sizeof(char*), compareStrings);

    return newArray;
}

int main() {
    // Example usage
    char* strings[] = {"apple", "banana", "orange", "kiwi", "grape"};

    int arraySize = sizeof(strings) / sizeof(strings[0]);

    char** sortedArray = sortByLength(strings, arraySize);

    // Print the sorted array
    printf("Sorted Array by Length:\n");
    for (int i = 0; i < arraySize; i++) {
        printf("%s\n", sortedArray[i]);
    }

    // Free allocated memory
    for (int i = 0; i < arraySize; i++) {
        free(sortedArray[i]);
    }
    free(sortedArray);

    return 0;
}


void removeIntByIndex(int* arr, int pos, int* arrSize) {
    // use for loop to delete the element and update the index  
    for (int i = pos; i < *arrSize - 1; i++) {  
        arr[i] = arr[i+1]; // assign arr[i+1] to arr[i]  
    }  
    *arrSize = *arrSize -1; // remove last index of array
}

int removeIntByValue(int* arr, int value, int* arrSize) {
    int index = -1;
    for (int i = 0; i < *arrSize; i++) {  
        if(arr[i] == value) {
            index = i;
        }
    }  
    if(index != -1) {
        for (int i = index; i < *arrSize - 1; i++) {
            arr[i] = arr[i+1];
        }
        *arrSize = *arrSize -1; 
        return 1;
    }
    else {
        return 0;
    }
}

void removeCharByIndex(char* arr, int pos, int* arrSize) {
    for (int i = pos; i < *arrSize - 1; i++) {  
        arr[i] = arr[i+1]; // assign arr[i+1] to arr[i]  
    }  
    *arrSize = *arrSize -1; // remove last index of array
}

int removeCharByValue(char* arr, char value, int* arrSize) {
    int index = -1;
    for (int i = 0; i < *arrSize; i++) {  
        if(arr[i] == value) {
            index = i;
        }
    }  
    if(index != -1) {
        for (int i = index; i < *arrSize - 1; i++) {
            arr[i] = arr[i+1];
        }
        *arrSize = *arrSize -1; 
        return 1;
    }
    else {
        printf("Element Not Found\n");
        return 0;
    }
}


void removeCharByIdxRange(char* arr, int start, int end, int* arrSize) {
    int range = end - start + 1; 
    for (int i = start; i < *arrSize - range; i++) {
        arr[i] = arr[i + range];
    }
    *arrSize -= range; 
    arr[*arrSize - 1] = '\0'; 
}


int main ()  
{  
    // // remove array from int array
    // int intArr[] = {0,1,2,3,4,5,6,7,8,9,8,1,3,8,1,8};  
    // int intArrSize = sizeof(intArr) / sizeof(int);
    // int pos = 3; // index of the element to be deleted  
    // int val = 8;

    // // removeIntByIndex(intArr, pos, &intArrSize);

    // while (removeIntByValue(intArr, val, &intArrSize)) {
    //     removeIntByValue(intArr, val, &intArrSize); // 있는 value 모두 삭제
    // }

    // for (int i = 0; i < intArrSize; i++) {  
    //     printf (" arr[%d] = ", i);  
    //     printf (" %d \n", intArr[i]);  
    // }  

    // remove array from char array
    char charArr[] = "abcasdfbccc";  
    int charArrSize = sizeof(charArr) / sizeof(char);
    int pos = 3; // index of the element to be deleted  
    char val = 'c';

    int start = 2, end = 4; // 제거할 범위

    // 배열 크기에서 널 문자 제외
    removeCharByIdxRange(charArr, start, end, &charArrSize);

    printf("Result: %s\n", charArr);

    // removeCharByIndex(charArr, pos, &charArrSize);

    // while (removeCharByValue(charArr, val, &charArrSize)) {
    //     removeCharByValue(charArr, val, &charArrSize); // 있는 value 모두 삭제
    // }

    // for (int i = 0; i < charArrSize - 1; i++) {  // 마지막 '\0' 빼고 프린트
    //     printf (" arr[%d] = ", i);  
    //     printf (" %c \n", charArr[i]);  
    // }  

    return 0;  
}  

char* sliceString(const char* str, int start, int end) {
    int len = strlen(str);
    
    // 음수 인덱스 처리
    if (start < 0) start = len + start;
    if (end < 0) end = len + end;

    if (start > end || start < 0 || end > len) return NULL;

    int sliceLen = end - start;
    char* result = (char*)malloc(sliceLen + 1); 

    if (!result) return NULL; 

    strncpy(result, str + start, sliceLen); 
    result[sliceLen] = '\0';

    return result;
}

char* concatStrings(const char* first, const char* second) {
    int firstLen = strlen(first);
    int secondLen = strlen(second);
    char* result = (char*)malloc(firstLen + secondLen + 1); // +1 for the null-terminator

    if (!result) return NULL;

    memcpy(result, first, firstLen);
    memcpy(result + firstLen, second, secondLen + 1); // +1 to include the null-terminator

    return result;
}

int main() {
    const char* s = "abcde";
    char* firstSlice = sliceString(s, 1, -2); // Equivalent to Python's s[1:-2]
    char* secondSlice = sliceString(s, 2, -1); // Another slice for demonstration

    if (firstSlice && secondSlice) {
        char* combined = concatStrings(firstSlice, secondSlice);
        if (combined) {
            printf("Combined string: %s\n", combined);
            free(combined);
        }
        free(firstSlice); 
        free(secondSlice);
    } else {
        printf("Invalid slice\n");
    }

    return 0;
}