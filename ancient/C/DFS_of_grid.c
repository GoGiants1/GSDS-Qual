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

// C에는 stack STL이 없기 때문에 구현
typedef struct {
    pair data[MAX_SIZE * MAX_SIZE];
    int top;
} Stack;

void init(Stack* s) {
    s->top = -1;
}

int empty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, pair p) {
    s->data[++s->top] = p;
}

pair top(Stack* s) {
    return s->data[s->top];
}

void pop(Stack* s) {
    s->top--;
}

int main(void) {
    Stack s;
    init(&s);
    vis[0][0] = 1; // (0, 0)을 방문했다고 명시
    push(&s, (pair){0, 0}); // 스택에 시작점인 (0, 0)을 삽입.
    while (!empty(&s)) {
        pair cur = top(&s);
        pop(&s);
        printf("(%d, %d) -> ", cur.X, cur.Y);
        for (int dir = 0; dir < 4; dir++) { // 상하좌우 칸을 살펴볼 것이다.
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
            if (vis[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
            vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
            push(&s, (pair){nx, ny});
        }
    }
    return 0;
}
