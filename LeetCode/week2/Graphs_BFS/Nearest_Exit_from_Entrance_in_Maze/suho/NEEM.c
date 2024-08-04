int nearestExit(char** maze, int mazeSize, int* mazeColSize, int* entrance, int entranceSize) {
    int visit[10000][2];
    int queue[10000][2];
    int step_queue[10000];
    int nvisit = 0, n_q = 0;

    queue[n_q][0] = entrance[0];
    queue[n_q][1] = entrance[1];
    step_queue[n_q] = 0;
    n_q++;

    int sstep = 100000000;
    while(n_q>0){
        int pos[2];
        pos[0] = queue[n_q-1][0];
        pos[1] = queue[n_q-1][1];
        int step = step_queue[n_q-1];
        n_q--;

        if((pos[0]!= entrance[0] || pos[1]!=entrance[1]) && (pos[0]==0 || pos[0]==mazeSize-1 || pos[1]==0 || pos[1]==mazeColSize-1)){
            if (sstep > step) sstep = step;
        }

        int visit_temp = 0;
        for(int i=0; i<nvisit; i++){
            if(visit[i][0]==pos[0] && visit[i][1]==pos[1]) visit_temp = 1;
        }

        if(visit_temp==0){
            visit[nvisit][0] = pos[0];
            visit[nvisit][1] = pos[1];
            nvisit++;

            int v_t = 0;
            for(int i=0; i<nvisit; i++){
                if(visit[i][0]==pos[0]+1 && visit[i][1]==pos[1]) v_t = 1;
            }
            if(pos[0]+1<mazeSize && maze[pos[0]+1][pos[1]]=='.' && (v_t==0)){
                queue[n_q][0] = pos[0]+1;
                queue[n_q][1] = pos[1];
                step_queue[n_q]=(step+1);
                n_q++;
            }
            v_t = 0;
            for(int i=0; i<nvisit; i++){
                if(visit[i][0]==pos[0] && visit[i][1]==pos[1]+1) v_t = 1;
            }
            if(pos[1]+1<mazeColSize && maze[pos[0]][pos[1]+1]=='.' && (v_t==0)){
                queue[n_q][0] = pos[0];
                queue[n_q][1] = pos[1]+1;
                step_queue[n_q]=(step+1);
                n_q++;
            }
            v_t = 0;
            for(int i=0; i<nvisit; i++){
                if(visit[i][0]==pos[0]-1 && visit[i][1]==pos[1]) v_t = 1;
            }
            if(pos[0]-1>=0 && maze[pos[0]-1][pos[1]]=='.' && (v_t==0)){
                queue[n_q][0] = pos[0]-1;
                queue[n_q][1] = pos[1];
                step_queue[n_q]=(step+1);
                n_q++;
            }
            v_t = 0;
            for(int i=0; i<nvisit; i++){
                if(visit[i][0]==pos[0] && visit[i][1]==pos[1]-1) v_t = 1;
            }
            if(pos[1]-1>=0 && maze[pos[0]][pos[1]-1]=='.' && (v_t==0)){
                queue[n_q][0] = pos[0];
                queue[n_q][1] = pos[1]-1;
                step_queue[n_q]=(step+1);
                n_q++;
            }
        }
    }

    return sstep==100000000 ? -1 : sstep;
}
