#include <stdio.h>
#include <math.h>

double func(double x, double y) {
  return x + y;
}

int main(void) {
  int a = 0;         // 区間の下限
  int b = 2;         // 区間の上限
  double n, h, x, y;
  for (int i = 1; i <= 10; i++) {
    n = pow(2, i);   // 分割数
    h = (b - a) / n; // 分割後の1区間の大きさ
    x = a;
    y = 1;

    while (x < b) {
      y += h * func(x, y);
      x += h;
    }

    printf("n = 2^%d: %f\n", i, y);
  }

  return 0;
}
