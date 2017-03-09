#include <iostream>
using namespace std;

int main() {
  long a, b;
  while (cin >> a >> b) {
    long n = b - a;
    if (n < 0) n *= -1;
    cout << n << endl;
  }
  return 0;
}