vector<int> getPrimes(int upTo) {
  vector<int> result = {2, 3, 5};
  for (int i = 6; i <= upTo; ++i) {
    bool isPrime = true;
    for (int j = 0; j < result.size() && result[j] * result[j] <= i; ++ j) {
      if (i % result[j] == 0) {
        isPrime = false;
      }
    }
    if (isPrime)
      result.push_back(i);
  }
  return result;
}

vector<int> eratosthenes(int upTo) {
  vector<bool> sieve(upTo + 1, false);
  for (int i = 2; i <= upTo; ++i) {
    if (!sieve[i]) {
      for (int j = 2*i; j <= upTo; j += i) {
        sieve[j] = true;
      }
    }
  }

  vector<int> result;
  for (int i = 2; i <= upTo; ++i) {
    if (!sieve[i])
      result.push_back(i);
  }
  return result;
}

vector<int> eratosthenesExt(int upTo) {
  vector<bool> v(upTo + 1, false);
  vector<int> sp(upTo + 1, 0);
  for (int i = 2; i <= upTo; ++i) {
    if (!v[i]) {
      for (int j = 2*i; j <= upTo; j += i) {
        if (!v[j]) {
          v[j] = true;
          sp[j] = i;
        }
      }
      sp[i] = i;
    }
  }
  sp[1] = 1;
  return sp;
}

