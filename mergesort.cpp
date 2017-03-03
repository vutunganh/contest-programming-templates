//
// Created by maty on 3/3/17.
//

#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <algorithm>

/* Mergesort ktery dokaze spocitat pocet inverzi v permutaci.
 * To je, suma(x z Prvky)(f(x))
 * kde f(x) je pocet prvku ktere jsou pred x a jsou vyssi */

using namespace std;

long long inv;

int mergesort(vector<int> &src, int left, int right, int *result) {
  if (right == left) {
    result[0] = src[left];
    return 0;
  }

  int middle = (left + right) / 2;
  int resultL[middle - left + 2], resultR[right - middle + 1];
  resultL[middle - left + 1] = INT_MAX;
  resultR[right - middle] = INT_MAX;

  mergesort(src, left, middle, resultL);
  mergesort(src, middle + 1, right, resultR);

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
  return 0;
}

int result[200000];

int main() {
  vector<int> input;

  // nacitani vstupu. Prvni na vstupu je pocet hodnot
  int N;
  cin >> N;

  for (int i = 0; i < N; ++i) {
    int n;
    cin >> n;
    input.push_back(n);
  }

  // pred zavolanim nad novou posloupnosti potreba nastavit inv = 0
  mergesort(input, 0, input.size() - 1, result);


  cout << "inversions: " << inv << endl;
  cout << "sorted output: " << endl;
  for (int i = 0; i < N - 1; ++i) {
    cout << result[i] << " ";
  }
  cout << result[N-1] << endl;


  return 0;
}
