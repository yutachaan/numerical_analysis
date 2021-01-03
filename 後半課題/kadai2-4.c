#include <stdio.h>
#include <math.h>

double func(double x, double y) {
  return x + y;
}

int main(void) {
  int a = 0;         // 区間の下限
  int b = 2;         // 区間の上限
  double n, h, x, k1, k2, k3, k4, y;
  for (int i = 1; i <= 7; i++) {
    n = pow(2, i);   // 分割数
    h = (b - a) / n; // 分割後の1区間の大きさ
    x = a;
    y = 1;

    while (x < b) {
      k1 = func(x, y);
      k2 = func(x + h / 2.0, y + k1 * h / 2.0);
      k3 = func(x + h / 2.0, y + k2 * h / 2.0);
      k4 = func(x + h, y + k3 * h);

      y += h * (k1 + 2 * k2 + 2 * k3 + k4) / 6;
      x += h;
    }

    printf("n = 2^%d: %f\n", i, y);
  }

  return 0;
}
