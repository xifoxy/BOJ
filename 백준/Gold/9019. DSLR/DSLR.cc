#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 1e4;

long long visited[MAX], A, B, N;
char *ans{"DSLR"};

int D(int x) { return (x * 2) % MAX; }
int S(int x) { return x - 1 < 0 ? 9999 : x - 1; }
int L(int x) { return x % 1000 * 10 + x / 1000; }
int R(int x) { return x % 10 * 1000 + x / 10; }

void print(long long x) {
  if (x == 1) return;
  print(x / 10);
  putchar(ans[x % 10 - 1]);
}

int main() {
  scanf("%*d");

  while (scanf("%d%d", &A, &B) != EOF) {
    queue<int> Q;

    memset(visited, 0, sizeof(visited));
    visited[A] = 1;
    Q.push(A);

    while (1) {
      int cur = Q.front();
      Q.pop();

      if (cur == B) {
        print(visited[B]);
        puts("");
        break;
      }

      N = D(cur);
      if (!visited[N]) {
        visited[N] = visited[cur] * 10 + 1;
        Q.push(N);
      }
      N = S(cur);
      if (!visited[N]) {
        visited[N] = visited[cur] * 10 + 2;
        Q.push(N);
      }
      N = L(cur);
      if (!visited[N]) {
        visited[N] = visited[cur] * 10 + 3;
        Q.push(N);
      }
      N = R(cur);
      if (!visited[N]) {
        visited[N] = visited[cur] * 10 + 4;
        Q.push(N);
      }
    }
  }
}