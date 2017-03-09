#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int bestI = -1;
    int N;
    cin >> N;
    int *array = new int[N];
    int *need = new int[N];

    for (int j = 0; j < N; ++j) {
      int t;
      cin >> t;
      array[j] = t;
    }

    for (int j = 0; j < N; ++j) {
      int t;
      cin >> t;
      need[j] = t;
    }

    int cur = 0;
    bestI = 0;
    bool success = false;
    int totalCount = 0;
    bool secondRound = false;
    for (int j = 0; true; ++ j) {
      totalCount ++;
      if (j == N) {
        j = 0;
        secondRound = true;
      }
      cur += array[j] - need[j];
      //cout << cur << endl;
      if (cur <= 0) {
        bestI = j + 1;
        cur = 0;
      }
      if (j == bestI && cur > 0 && secondRound) {
        success = true;
        break;
      }
      if (totalCount > 2*N) break;

    }

    cout << "Case " << i + 1 << ": ";
    if (!success)
      cout << "Not possible" << endl;
    else
      cout << "Possible from station " << bestI + 1 << endl;

    delete [] array;
    delete [] need;
  }
  return 0;
}