char* kthDistinct(char** arr, int arrSize, int k) {

    for (int i = 0; i < arrSize; i++){
        bool is_distinct = true;
        for (int j = 0; j < arrSize; j++){
            if (i == j){
                continue;
            }

            if (strcmp(arr[i], arr[j]) == 0) {
                is_distinct = false;
                break;
            }
        }
        if (is_distinct) {
            k--;
            if (k == 0){
                return arr[i];
            }
        }
    }

    return "";
}

// Improved method: Add Visited arr

/*
char* kthDistinct(char** arr, int arrsize, int k) {
    
    int *visited = (int*)malloc(arrsize * sizeof(int));

    int found=0;
    int count=0;

    for(int i=0 ;i < arrsize ; i++){
        visited[i] = 0;
    }

    for(int i=0; i < arrsize ;i++){
        if(visited[i]==0){
            found=1;

            for(int j= i+1 ;j < arrsize ;j++){
                if(strcmp(arr[i],arr[j])==0){
                    found=0;
                    visited[j]=1;
                }
            }

            if(found){
                count++;
                if(count == k){
                    return arr[i];
                }
            }
        }
 
    }
    return "";
}

*/