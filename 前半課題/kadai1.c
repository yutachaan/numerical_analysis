#include <stdio.h>
#include <math.h>

double func1(double x);
double func2(double x);
double dfunc2(double x);
void gauss_jordan(int n, double matrix[n][n + 1]);
void gauss_seidel(int n, double matrix[n][n + 1]);
void false_position(double a, double b);
void newton(double x0);
void least_squares(int n, double x[], double y[]);

int main(void) {
  // ガウス・ジョルダン法
  double jmat[4][5] = {{ 1,  2, -3,  2,  3},
                       { 3,  2, -3,  0, -1},
                       { 0, -3,  2,  1,  7},
                       {-3,  4,  1,  2,  9}};
  gauss_jordan(4, jmat);

  // ガウス・ザイデル法
  double smat[5][6] = {{ 4, -1,  0,  0, -1, 3},
                       {-1,  4, -1,  0,  0, 3},
                       { 0, -1,  4, -1,  0, 7},
                       { 0,  0, -1,  4, -1, 9},
                       {-1,  0,  0, -1,  4, 8}};
  gauss_seidel(5, smat);

  // はさみうち法
  false_position(2.5, 3.0);

  // ニュートン法
  newton(1.4);

  // 最小二乗法
  double x[5] = {1, 2, 3, 4, 5};
  double y[5] = {9, 34, 85, 171, 188};
  least_squares(5, x, y);

  return 0;
}

double func1(double x) {
  return 1.25 * sin(0.4 * x) * sin(0.6 * x) - x * sin(x);
}

double func2(double x) {
  return x * x - 2;
}

double dfunc2(double x) {
  return 2 * x;
}

// ガウス・ジョルダン法(n: 次数, matrix: 行列)
// 1つ目の方程式の第一変数の係数は0以外でなければならない
void gauss_jordan(int n, double matrix[n][n + 1]) {
  double pivot, a;

  // 解を求める
  for (int i = 0; i < n; i++) {
    pivot = matrix[i][i];

    for (int j = i; j < n + 1; j++) matrix[i][j] /= pivot;

    for (int k = 0; k < n; k++) {
      if (k - i != 0) {
        a = matrix[k][i];
        for (int j = i; j < n + 1; j++) matrix[k][j] -= a * matrix[i][j];
      }
    }
  }

  // 解を出力
  for (int i = 0; i < n; i++) printf("x%d = %f\n", i + 1, matrix[i][n]);
}

// ガウス・ザイデル法(n: 次数, matrix: 行列)
// 対角要素が非対角要素よりも大きい場合に使用
void gauss_seidel(int n, double matrix[n][n + 1]) {
  double ans_before[n], ans_after[n]; // 計算前と後の解
  int count = 30;                     // 最大計算回数

  // 解の初期値を設定
  for (int i = 0; i < n; i++) ans_before[i] = 1.0;
  for (int i = 0; i < n; i++) ans_after[i]  = 1.0;

  // 最大計算回数回の繰り返しで収束の判定をする
  double sum, q;
  while (count >= 0) {
    // 解を求める
    for (int i = 0; i < n; i++) {
      sum = 0;
      for (int j = 0; j < n; j++) {
        if (i != j) sum += matrix[i][j] * ans_before[j];
      }
      ans_before[i] = (matrix[i][n] - sum) / matrix[i][i];
    }

    q = 0;
    for (int i = 0; i < n; i++) {
      q += fabs(ans_before[i] - ans_after[i]);
      ans_after[i] = ans_before[i];
    }

    // 収束時、解を出力する
    if (q < 0.0001) {
      for (int i = 0; i < n; i++) printf("x%d = %f\n", i + 1, ans_after[i]);
      break;
    }

    count -= 1;
  }

  if (count < 0) printf("収束しない\n");
}

// はさみうち法(a, b: 閉区間の下界と上界)
void false_position(double a, double b) {
  double c;

  // 解を求める
  do {
    c = (a * func1(b) - b * func1(a)) / (func1(b) - func1(a));
    if (func1(c) * func1(b) < 0) a = c;
    else b = c;
  } while (fabs(func1(c)) > 0.000001);

  // 解を出力
  printf("λ = %f\n", c);
}

// ニュートン法(x0: 初期値)
void newton(double x0) {
  double x1, dx;

  // 解を求める
  do {
    x1 = x0 - func2(x0) / dfunc2(x0);
    dx = fabs(x1 - x0);
    x0 = x1;
  } while (dx > 0.000001);

  // 解を出力
  printf("x = %f\n", x0);
}

// 最小二乗法(n: データ個数, x: xの値の配列, y: yの値の配列)
void least_squares(int n, double x[], double y[]) {
  double sx, sx2, sy, sxy;

  sx = sx2 = sy = sxy = 0;

  // それぞれの総和を求める
  for (int i = 0; i < n; i++) {
    sx  += x[i];
    sx2 += x[i] * x[i];
    sy  += y[i];
    sxy += x[i] * y[i];
  }

  // a, bを求める
  double a = (sy * sx2 - sx * sxy) / (n * sx2 - sx * sx);
  double b = ( n * sxy - sy *  sx) / (n * sx2 - sx * sx);

  // 解を出力する
  printf("y = %f + %fx", a, b);
}
