#include <cstdio>

using namespace std;

int n, r, c, cnt;

void sol(int x, int y, int sz) {
  if (x == r && y == c) {
    printf("%d\n", cnt);
    return;
  }

  if (x <= r && x + sz > r && y <= c && y + sz > c) {
    sz >>= 1;
    sol(x, y, sz);
    sol(x, y + sz, sz);
    sol(x + sz, y, sz);
    sol(x + sz, y + sz, sz);
  } else
    cnt += (sz * sz);
}

int main() {
  scanf("%d%d%d", &n, &r, &c);
  sol(0, 0, 1 << n);
}