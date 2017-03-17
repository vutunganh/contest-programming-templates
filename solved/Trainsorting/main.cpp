#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t --) {
    int n;
    cin >> n;
    if (n == 0) { cout << 0 << endl; continue; }
    vector<int> inc(n);
    vector<int> dec(n);
    vector<int> input(n);

    for (int i = 0; i < n; ++i) {
      int c;
      cin >> c;
      input[i] = c;
    }
    for (int i = n - 1; i >= 0; i --) {
      int cur = input[i];
      inc[i] = dec[i] = 1;
      for (int j = i + 1; j < n; ++j) {
        if (input[j] > cur)
          inc[i] = max(inc[i], inc[j] + 1);

        if (input[j] < cur)
          dec[i] = max(dec[i], dec[j] + 1);
      }
    }

    int best = 0;
    for (int i = 0; i < n; ++i) {
      best = max(best, inc[i] + dec[i]);
    }
    cout << best - 1 << endl;
  }
}
