#include <stdio.h>
#include <math.h>

double func(double x) {
  return 1 / x;
}

int main(void) {
  double n, h, s1, s2, s, x;
  for (int i = 1; i <= 5; i++) {
    n = pow(2, i);
    h = (2 - 1) / (2 * n);

    s1 = 0;
    for (int j = 1; j <= 2 * n - 1; j += 2) {
      x = 1 + h * j;
      s1 += 4 * func(x);
    }

    s2 = 0;
    for (int j = 2; j <= 2 * n - 2; j += 2) {
      x = 1 + h * j;
      s2 += 2 * func(x);
    }

    s = (s1 + s2 + func(1) + func(2)) * h / 3;
    printf("n = 2^%d: %f\n", i, s);
  }

  return 0;
}
