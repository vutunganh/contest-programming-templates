//
// Created by maty on 7/14/17.
//
#include <vector>
#include <string>

using namespace std;


// nejdelsi souvisly retezec O(n*m)
int LongestCommonSubstringLen(string & p, string & q) {
  int result = 0;
  vector<vector<int>> dp(p.size()+1, vector<int>(q.size()+1, 0));
  for (int i = 1; i <= p.size(); ++i) {
    for (int j = 1; j <= q.size(); ++j) {
      if (p[i - 1] == q[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        result = max(result, dp[i][j]);
      }
    }
  }
  return result;
}

// nejdelsi nesouvisla posloupnost O(n*m)
int LongestCommonSubsubsequenceLen(string & p, string & q) {
  int result = 0;
  vector<vector<int>> dp(p.size()+1, vector<int>(q.size()+1, 0));
  for (int i = 1; i <= p.size(); ++i) {
    for (int j = 1; j <= q.size(); ++j) {
      if (p[i - 1] == q[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        result = max(result, dp[i][j]);
      }
      dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
    }
  }
  return result;
}
