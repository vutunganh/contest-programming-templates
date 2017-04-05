#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> notebook((unsigned long) n);

  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    notebook[i].first = a;
    notebook[i].second = b;
  }

  sort(notebook.begin(), notebook.end(), [ ]( const pair< int, int >& a, const pair< int, int >& b )
  {
    return a.first < b.first;
  });

  bool happy = false;
  for (int j = 1; j < n; ++j) {
    if (notebook[j - 1].second > notebook[j].second) {
      happy = true;
      break;
    }
  }
  if (happy) {
    cout << "Happy Alex" << endl;
  } else {
    cout << "Poor Alex" << endl;
  }
  return 0;
}