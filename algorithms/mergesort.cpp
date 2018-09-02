ll inv;
int mergesortHelp(vector<ll> &src, int left, int right, ll *result) {
  if (right == left) {
    result[0] = src[left];
    return 0;
  }

  int middle = (left + right) / 2;
  //ll resultL[middle - left + 2], resultR[right - middle + 1];
  ll* resultL = new ll[middle - left + 2];
  ll* resultR = new ll[right - middle + 1];
  resultL[middle - left + 1] = INT_MAX;
  resultR[right - middle] = INT_MAX;

  mergesortHelp(src, left, middle, resultL);
  mergesortHelp(src, middle + 1, right, resultR);

  // merge
  int l = 0, r = 0;
  for (int i = 0; i <= right - left; ++i) {
    if (resultL[l] < resultR[r]) {
      result[i] = resultL[l]; ++ l;
    } else {
      result[i] = resultR[r]; ++ r;
      inv += (middle - left + 1) - l;
    }
  }
  delete [] resultL;
  delete [] resultR;
  return 0;
}

/* Mergesort ktery dokaze spocitat pocet inverzi v permutaci.
 * To je, suma(x z Prvky)(f(x))
 * kde f(x) je pocet prvku ktere jsou pred x a jsou vyssi */
ll mergesort(vector<ll> & src) {
  inv = 0;
  ll* result = new ll[src.size()];
  mergesortHelp(src, 0, src.size() - 1, result);
  for (int i = 0; i < src.size(); ++i) src[i] = result[i];
  delete [] result;
  return inv;
}
