int xGCD(int a, int b, int &x, int &y) {
  if(b == 0) return x = 1, y = 0, a;

  int x1, y1, res = xGCD(b, a % b, x1, y1);
  return res = xGCD(b, a % b, x1, y1), x = y1, y = x1 - (a / b) * y1, res;
}
