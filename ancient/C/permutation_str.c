#include <stdio.h>
#include <string.h>

void swap(char* x, char* y) {
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char* str, int l, int r) {
    int i;
    if (l == r)
        printf("%s\n", str);
    else {
        for (i = l; i <= r; i++) {
            if (l != i && str[i] == str[i-1]) continue;
            swap((str + l), (str + i));
            permute(str, l + 1, r);
            swap((str + l), (str + i)); //backtrack
        }
    }
}

int compare(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

int main() {
    char str[] = "acc";
    int n = strlen(str);
    qsort(str, n, sizeof(char), compare);  // Sort the string
    permute(str, 0, n - 1);
    return 0;
}
