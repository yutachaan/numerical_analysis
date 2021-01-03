#include <stdio.h>
#include <math.h>

double func(double x) {
  return 1 / x;
}

int main(void) {
  int a = 1;         // 積分区間の下限
  int b = 2;         // 積分区間の上限
  double n, h, s, x;
  for (int i = 1; i <= 10; i++) {
    n = pow(2, i);   // 分割数
    h = (b - a) / n; // 分割後の1区間の大きさ
    s = 0;           // 積分値

    for (int j = 1; j < n; j++) {
      x = a + h * j;
      s += 2 * func(x);
    }

    s = 0.5 * (s + func(a) + func(b)) * h;
    printf("n = 2^%d: %f\n", i, s);
  }

  return 0;
}
