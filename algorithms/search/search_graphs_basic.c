#include <stdio.h>
#include <stdlib.h>

// 백준 1260번을 상정하고 만들었습니다 : https://www.acmicpc.net/problem/1260

#define NUM_VERTEX 10

int Graph[NUM_VERTEX][NUM_VERTEX] = {0};
int visited_dfs[NUM_VERTEX] = {0};
int visited_bfs[NUM_VERTEX] = {0};
int queue[NUM_VERTEX] = {0};

void DFS(int currNode, int N){
    int i;
    if(visited_dfs[currNode] == 1){
        return;
    }
    visited_dfs[currNode] = 1;
    printf("%d", currNode);
    for(i=1; i<=N; i++){
        if (Graph[currNode][i] == 1 && visited_dfs[i] == 0){
            DFS(i, N); // currNode->i가 연결, i가 unvisited면 
        }
    }
}

void BFS(int start, int N){
    int front=0, rear=0, popped, i;
    if(visited_bfs[start]==1){
        return; // edge case handling
    }
    queue[0] = start;
    printf("%d", start);
    visited_bfs[start] = 1;
    rear++; // next position to insert

    while(front<rear){
        popped = queue[front];
        front++; // 앞의 것을 pop했으니 다음 인덱스부터 봐야 함

        for(i=1;i<=N;i++){
            if(Graph[popped][i]==1 && visited_bfs[i]==0){
                printf("%d", i);
                visited_bfs[i] = 1;
                queue[rear] = i;
                rear++;
                // front = pop position, rear = insert position
            }
        }
    }
    return;
}

int main(){
    int N, M, Start;
    int i, x, y;
    // {V, E} 갯수, 시작 노드
    scanf("%d %d %d", &N, &M, &Start);
    // graph construction
    for(i=0; i<M; i++){
        scanf("%d %d", &x, &y);
        Graph[x][y] = 1;
        Graph[y][x] = 1; // undirected
    }
    //DFS result
    DFS(Start, N);
    printf("\n");
    //BFS result
    BFS(Start, N);
    return 0;
}

