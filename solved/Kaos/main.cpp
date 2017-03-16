#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <algorithm>

using namespace std;

long long inv;

int inversions(vector<int> & src, int left, int right, int* result) {
  if (right == left) {
    result[0] = src[left];
    return 0;
  }

  int middle = (left + right) / 2;
  int resultL[middle - left + 2], resultR[right - middle + 1];
  resultL[middle - left + 1] = INT_MAX;
  resultR[right - middle] = INT_MAX;

  inversions(src, left, middle, resultL);
  inversions(src, middle + 1, right, resultR);

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
//char reverse[100001][10];

struct Word {
  char word[11];
  int index;
};

struct {
  bool operator() (const Word & l, const Word & r) {
    return strcmp(l.word, r.word) < 0;
  }
} CustomCmp;

int main() {
  vector<int> input;
  vector<Word> reverse;
  vector<Word> words;
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    words.push_back(Word());
    cin >> words[i].word;
    reverse.push_back(Word());
    int l = (int) strlen(words[i].word);
    for (int j = 0; j < l; ++j) {
      reverse[i].word[j] = words[i].word[l - j - 1];
    }
    reverse[i].index = i;
    words[i].index = i;
  }

  sort(words.begin(), words.end(), CustomCmp);
  for (int i = 0; i < N; ++i) {
    reverse[words[i].index].index = i;
  }

  // sort reversed
  sort(reverse.begin(), reverse.end(), CustomCmp);
  for (int i = 0; i < N; ++i) {
    input.push_back(reverse[i].index);
  }

  /*for (int k = 0; k < N; ++k) {
    cout << words[k].word << ":" << reverse[k].word << "i : " << reverse[k].index << endl;
  }*/

  inversions(input, 0, input.size() - 1, result);
  
  cout << inv << endl;

  return 0;
}