#include <stdio.h>

#define MAX_SIZE 502
#define X first
#define Y second

int board[MAX_SIZE][MAX_SIZE] = {
    {1,1,1,0,1,0,0,0,0,0},
    {1,0,0,0,1,0,0,0,0,0},
    {1,1,1,0,1,0,0,0,0,0},
    {1,1,0,0,1,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
}; // 1은 파란 칸, 0은 빨간 칸에 대응

int vis[MAX_SIZE][MAX_SIZE];
int n = 7, m = 10;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

// C에는 pair STL이 없기 때문에 구현
typedef struct {
    int first;
    int second;
} pair;

// C에는 queue STL이 없기 때문에 구현
typedef struct {
    pair data[MAX_SIZE * MAX_SIZE];
    int front;
    int rear;
} Queue;

void init(Queue* q) {
    q->front = q->rear = 0;
}

int empty(Queue* q) {
    return q->front == q->rear;
}

void push(Queue* q, pair p) {
    q->data[q->rear++] = p;
}

pair front(Queue* q) {
    return q->data[q->front];
}

void pop(Queue* q) {
    q->front++;
}

int main(void) {
    Queue q;
    init(&q);
    vis[0][0] = 1; // (0, 0)을 방문했다고 명시
    push(&q, (pair){0, 0}); // 큐에 시작점인 (0, 0)을 삽입.
    while (!empty(&q)) {
        pair cur = front(&q);
        pop(&q);
        printf("(%d, %d) -> ", cur.X, cur.Y);
        for (int dir = 0; dir < 4; dir++) { // 상하좌우 칸을 살펴볼 것이다.
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
            if (vis[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
            vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
            push(&q, (pair){nx, ny});
        }
    }
    return 0;
}
