#include <stdio.h>
#include <math.h>

double func(double x) {
  return 1 / x;
}

int main(void) {
  double n, h, s, x;
  for (int i = 1; i <= 10; i++) {
    n = pow(2, i);
    h = (2 - 1) / n;
    s = 0;

    for (int j = 1; j < n; j++) {
      x = 1 + h * j;
      s += 2 * func(x);
    }

    s = 0.5 * (s + func(1) + func(2)) * h;
    printf("n = 2^%d: %f\n", i, s);
  }

  return 0;
}
