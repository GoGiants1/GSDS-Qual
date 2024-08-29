/* Move a disc */
void move(vector<int> &src, vector<int> &tar) {
  // Take out a disc from the top of src
  int pan = src.back();
  src.pop_back();
  // Place the disc on top of tar
  tar.push_back(pan);
}

/* Solve the Tower of Hanoi problem f(i) */
void dfs(int i, vector<int> &src, vector<int> &buf, vector<int> &tar) {
  // If only one disc remains on src, move it to tar
  if (i == 1) {
    move(src, tar);
    return;
  }
  // Subproblem f(i-1): move the top i-1 discs from src with the help of tar to
  // buf
  dfs(i - 1, src, tar, buf);
  // Subproblem f(1): move the remaining one disc from src to tar
  move(src, tar);
  // Subproblem f(i-1): move the top i-1 discs from buf with the help of src to
  // tar
  dfs(i - 1, buf, src, tar);
}

/* Solve the Tower of Hanoi problem */
void solveHanota(vector<int> &A, vector<int> &B, vector<int> &C) {
  int n = A.size();
  // Move the top n discs from A with the help of B to C
  dfs(n, A, B, C);
}