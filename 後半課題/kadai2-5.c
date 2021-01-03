#include <stdio.h>
#include <stdlib.h>

int main(void) {
  double n, x, y, z;

  n = 100000;
  z = 0;

  for (int i = 1; i <= n; i++) {
    x = (double)rand() / RAND_MAX;
    y = (double)rand() / RAND_MAX;
    z += x + y;

    if (i % 5000 == 0) {
      printf("%d回目: %f\n", i, z / i);
    }
  }

  return 0;
}
