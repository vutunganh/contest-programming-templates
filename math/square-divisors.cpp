int squareDivisors(vector<pair<int, int>> facts) {
  bool confirm = false;
  // set to false if not counting proper divisorsCount
  bool isEvenPerfectSquare = true;

  for (int i = 0; i < facts.size(); ++i) {
    if (facts[i].second % 2 != 0) isEvenPerfectSquare = false;
    if (facts[i].first == 2 && facts[i].second >= 2) {
      confirm = true;
      facts[i].second -= 2;
    }
    facts[i].second /= 2;
  }

  int subtract = (confirm && isEvenPerfectSquare) ? 1 : 0;

  if (confirm)
    return divisorsCount(facts) - subtract;
  else
    return 0;
}

