#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isStringInArray(char* str, char** array, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        if (strcmp(array[i], str) == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    char* array[] = {"aa", "ab", "bb"};
    int arraySize = sizeof(array) / sizeof(array[0]);

    char* target = "aa";

    if (isStringInArray(target, array, arraySize)) {
        printf("'%s' is in the array.\n", target);
    } else {
        printf("'%s' is not in the array.\n", target);
    }

    return 0;
}
