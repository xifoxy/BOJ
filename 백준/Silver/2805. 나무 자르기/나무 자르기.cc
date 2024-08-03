#include <cstdio>

const int MAX = 1e6 + 1;
int n, m;
int a[MAX];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);

  int l = 0, r = 2e9;

  while (l + 1 < r) {
    int mid = (l + r) / 2;
    long long sum = 0;

    for (int i = 0; i < n; ++i) {
      if (a[i] > mid) sum += (a[i] - mid);
      if (sum >= m) break;
    }
    if (sum >= m)
      l = mid;
    else
      r = mid;
  }
  printf("%d\n", l);
}