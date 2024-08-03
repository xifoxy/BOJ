#include <cstdio>
#include <queue>

using namespace std;

int n;

int abs(int x) { return x < 0 ? -x : x; }

struct node {
  int val;
  int absolute;
};
struct compare {
  bool operator()(const node &a, const node &b) {
    if (a.absolute == b.absolute) return a.val > b.val;
    return a.absolute > b.absolute;
  }
};

int main() {
  priority_queue<node, vector<node>, compare> pq;

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x;

    scanf("%d", &x);
    if (x == 0) {
      if (pq.empty())
        printf("0\n");
      else {
        printf("%d\n", pq.top().val);
        pq.pop();
      }
    } else {
      pq.push({x, abs(x)});
    }
  }
}