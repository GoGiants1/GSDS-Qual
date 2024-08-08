#include <stdio.h> 
  
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

