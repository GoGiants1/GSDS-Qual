#include <stdio.h>
#include <string.h>

int issubstring(const char* a, const char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);

    // 'a'가 빈 문자열인 경우, 항상 'b'의 부분 문자열로 간주
    if (lenA == 0) return 1;

    for (int i = 0; i <= lenB - lenA; i++) {
        // 'b'에서 'a'와 일치하는 부분을 찾음
        int match = 1; // 일치하는지 여부를 추적
        for (int j = 0; j < lenA; j++) {
            if (b[i + j] != a[j]) {
                match = 0;
                break; // 일치하지 않으면 루프 종료
            }
        }
        if (match) return 1; // 전체 'a' 문자열이 'b' 내에서 일치
    }

    return 0; // 일치하는 부분 문자열이 없음
}

int main() {
    const char* a = "abc";
    const char* b = "abcdbd";

    if (issubstring(a, b)) {
        printf("\"%s\" is a substring of \"%s\".\n", a, b);
    } else {
        printf("\"%s\" is NOT a substring of \"%s\".\n", a, b);
    }

    return 0;
}
