#include <stdio.h>
#include <math.h>

double func(double x) {
  return 1 / x;
}

int main(void) {
  int a = 1;               // 積分区間の下限
  int b = 2;               // 積分区間の上限
  double n, h, s1, s2, s, x;
  for (int i = 1; i <= 5; i++) {
    n = pow(2, i);         // 分割数
    h = (b - a) / (2 * n); // 分割後の1区間の大きさ

    s1 = 0;
    for (int j = 1; j <= 2 * n - 1; j += 2) {
      x = a + h * j;
      s1 += 4 * func(x);
    }

    s2 = 0;
    for (int j = 2; j <= 2 * n - 2; j += 2) {
      x = a + h * j;
      s2 += 2 * func(x);
    }

    // 積分値
    s = (s1 + s2 + func(a) + func(b)) * h / 3;
    printf("n = 2^%d: %f\n", i, s);
  }

  return 0;
}
