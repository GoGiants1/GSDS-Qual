#include <string.h>

char * mergeAlternately(char * word1, char * word2){
    int m = strlen(word1);
    int n = strlen(word2);
    int l = 0;
    int r = 0;
    int curr = 0;
    char* out = malloc((m + n + 1) * sizeof(char));


    while (l < m || r < n) {
        if (l < m){
            out[curr] = word1[l];
            l++;
            curr++;
        }

        if (r < n) {
            out[curr] = word2[r];
            r++;
            curr++;
        }
    }
    out[curr] = '\0';
    

    return out;
    
}