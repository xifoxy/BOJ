#include <cstdio>
int n;
const int MAX = 1 << 7;
char board[MAX][MAX];

int check_range(int x, int y, int r, int c) {
  for (int i = x; i < x + r; ++i)
    for (int j = y; j < y + r; ++j)
      if (board[i][j] != c) return 0;
  return 1;
}

int devide_conquer(int x, int y, int r, int c) {
  if (r == 1) return board[x][y] == c;
  if (check_range(x, y, r, c)) return 1;

  int ret = 0;
  int half = r / 2;
  ret += devide_conquer(x + half, y + half, half, c);
  ret += devide_conquer(x + half, y, half, c);
  ret += devide_conquer(x, y + half, half, c);
  ret += devide_conquer(x, y, half, c);
  return ret;
}

int main() {
  scanf("%d ", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%c ", &board[i][j]);
      board[i][j] -= '0';
    }
  }

  int zero = devide_conquer(0, 0, n, 0);
  int one = devide_conquer(0, 0, n, 1);
  printf("%d\n%d\n", zero, one);
}