#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int bestI = 0;
    int N;
    cin >> N;
    int *fuel = new int[N];
    int *need = new int[N];

    for (int j = 0; j < N; ++j) {
      cin >> fuel[j];
    }

    for (int j = 0; j < N; ++j) {
      cin >> need[j];
    }

    int cur = 0;
    bool success = false;
    for (int j = 0; j < 2 * N; ++j) {
      cur += fuel[j % N] - need[j % N];
      //cout << cur << endl;
      if (cur < 0 && j < N) {
        bestI = j + 1;
        cur = 0;
      }
      if (j >= N && bestI == j % N && cur >= 0) {
        success = true;
        break;
      }
    }

    cout << "Case " << i + 1 << ": ";
    if (!success)
      cout << "Not possible" << endl;
    else
      cout << "Possible from station " << bestI + 1 << endl;

    delete [] fuel;
    delete [] need;
  }
  return 0;
}