#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

//입력받기
int main() {
    // 정수형 변수 선언 및 입력 받기
    int integerVar;
    printf("정수를 입력하세요: ");
    scanf("%d", &integerVar);
    printf("입력한 정수: %d\n", integerVar);

    // 문자형 변수 선언 및 입력 받기
    char charVar;
    printf("문자를 입력하세요: ");
    scanf(" %c", &charVar);  // 주의: %c 포맷 스페이스바를 포함하여 공백을 처리합니다.
    printf("입력한 문자: %c\n", charVar);

    // 문자열(배열) 입력 받기
    char stringVar[50];  // 최대 49글자까지 입력 받을 수 있도록 설정
    printf("문자열을 입력하세요: ");
    scanf("%s", stringVar);  // 공백을 포함하지 않는 문자열 입력
    printf("입력한 문자열: %s\n", stringVar);

    // 동적으로 메모리 할당하여 배열 입력 받기
    int arraySize;
    printf("배열의 크기를 입력하세요: ");
    scanf("%d", &arraySize);

    int* dynamicArray = (int*)malloc(arraySize * sizeof(int));
    printf("%d개의 정수를 입력하세요: ", arraySize);
    for (int i = 0; i < arraySize; ++i) {
        scanf("%d", &dynamicArray[i]);
    }

    printf("입력한 배열: ");
    for (int i = 0; i < arraySize; ++i) {
        printf("%d ", dynamicArray[i]);
    }
    printf("\n");

    // 동적으로 할당한 메모리 해제
    free(dynamicArray);

    return 0;
}


//string 관련

int main() {
    char str1[20] = "Hello";
    char str2[20] = "World";

    // 문자열 길이
    int len = strlen(str1);
    printf("문자열 길이: %d\n", len);

    // 문자열 복사
    strcpy(str1, str2);
    printf("복사된 문자열: %s\n", str1);

    return 0;
}



// 문자

int main() {
    char ch = 'A';

    // 알파벳인지 확인
    if (isalpha(ch)) {
        printf("%c는 알파벳입니다.\n", ch);
    }

    // 숫자인지 확인
    if (isdigit(ch)) {
        printf("%c는 숫자입니다.\n", ch);
    }

    return 0;
}


// 수학
int main() {
    double num = 25.0;

    // 제곱근 구하기
    double sqrtResult = sqrt(num);
    printf("제곱근: %lf\n", sqrtResult);

    // 삼각함수 계산
    double sinResult = sin(num);
    printf("사인 값: %lf\n", sinResult);

    return 0;
}

