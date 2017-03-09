#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

// http://codeforces.com/problemset/problem/727/A

using namespace std;

vector<uint64_t> result;
long finish;

bool dfs(uint64_t start) {
  if (start > finish) return false;
  else if (start*2 == finish) {
    result.push_back(start*2);
    return true;
  } else if (start*10 + 1 == finish) {
    result.push_back(start*10 + 1);
    return true;
  }

  if(start <= finish/2 + 1 && dfs(start * 2)) {
    result.push_back(start * 2);
    return true;
  }
  if (start <= finish/10 + 1 && dfs(start * 10 + 1)) {
    result.push_back(start * 10 + 1);
    return true;
  }
  return false;
}

int main() {
  uint64_t start;
  cin >> start >> finish;

  if (dfs(start)) {
    result.push_back(start);
    cout << "YES" << endl;
    cout << result.size() << endl;
    for (int i = result.size() - 1; i > 0; --i) {
      cout << result[i] << " ";
    }
    cout << result[0] << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
