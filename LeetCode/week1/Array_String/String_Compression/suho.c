int compress(char* chars, int charsSize) {
    char * s = (char*)malloc(sizeof(char)*charsSize);
    int i, j, k=0, count = 0;
    for(i=0;i<charsSize;i++){
        count++;
        if(i==charsSize-1 || chars[i+1]!=chars[i]){
            s[k] = chars[i];
            k++;
            if(count!=1.){
                char * strcnt = (char*)malloc(sizeof(char)*((int)log10(count)+1));
                int cnt = count;
                for(j=0;j<(int)log10(count)+1;j++){
                    strcnt[j] = cnt%10+'0';
                    cnt = (cnt-cnt%10)/10;
                }

                for(j=(int)log10(count);j>=0;j--){
                    s[k] = strcnt[j];
                    k++;
                }
            }  
            count = 0.;
        }
    } 
    for(i=0;i<k;i++) chars[i] = s[i];
    return k;
}
