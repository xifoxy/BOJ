#include <cstdio>
#include <cstdlib>

char cmd[10];
int set, num;

int main() {
  scanf("%*d");
  while (fgets(cmd, sizeof(cmd), stdin) != NULL) {
    if (cmd[0] == 'a' && cmd[1] == 'l')
      set = (1 << 21) - 1;
    else if (cmd[0] == 'e')
      set = 0;
    else if (cmd[0] == 'r')
      set &= ~(1 << (atoi(cmd + 7)));
    else if (cmd[0] == 't')
      set ^= 1 << (atoi(cmd + 7));
    else if (cmd[0] == 'c')
      printf("%d\n", (set & (1 << atoi(cmd + 6)) ? 1 : 0));
    else if (cmd[0] == 'a')
      set |= 1 << (atoi(cmd + 4));
  }
}