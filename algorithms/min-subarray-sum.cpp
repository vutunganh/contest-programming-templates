// nalezne nejkratsi usek pole, jehoz soucet se rovna k.
// smi obsahovat pouze kladna cisla!
// O(n)
int minSubarraySum(vector<int> ar, int k) {
  if (k == 0) return 0;
  int minLen = INT_MAX;
  int start = 0, end = 0;
  int curSum = ar[0];
  while (end != ar.size() - 1 || start != ar.size() - 1) {
    if (curSum == k) minLen = min(minLen, end - start + 1);

    if (curSum >= k && start < end) {
      curSum -= ar[start];
      start++;
    } else {
      if (end < ar.size() - 1) {
        end++;
        curSum += ar[end];
      } else {
        break;
      }
    }
  }
  if (curSum == k) minLen = min(minLen, end - start + 1);
  return minLen;
}
