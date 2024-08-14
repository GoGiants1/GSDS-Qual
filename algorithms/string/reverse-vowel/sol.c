// optimized two pass

char* reverseVowels(char* s) {
    int n = strlen(s);

    int pos[n];
    int cur = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            pos[cur] = i;
            cur++;
        }
    }
    int loop_count = cur / 2;

    for (int i = 0; i < loop_count; i++) {
        char tmp = s[pos[i]];
        s[pos[i]] = s[pos[--cur]];
        s[pos[cur]] = tmp;
    }

    return s;

}

/* 다른 풀이. (one pass)
int vowel(char c){
    c=tolower(c);
    return(c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}

char* reverseVowels(char* s) {
    int start=0;
    int end=strlen(s)-1;
    while(start<end){
        while(start<end && !vowel(s[start])){
            start++;
        }
        while(start<end && !vowel(s[end])){
            end--;
        }

        char temp=s[start];
        s[start]=s[end];
        s[end]=temp;

        start++;
        end--;
    }
    return s;
}
*/