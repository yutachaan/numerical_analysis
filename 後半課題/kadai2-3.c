#include <stdio.h>
#include <math.h>

double func(double x, double y) {
  return x + y;
}

int main(void) {
  double n, h, x, y;
  for (int i = 1; i <= 10; i++) {
    n = pow(2, i);
    h = (2 - 0) / n;
    x = 0;
    y = 1;

    while (x < 2) {
      y += h * func(x, y);
      x += h;
    }

    printf("n = 2^%d: %f\n", i, y);
  }

  return 0;
}
