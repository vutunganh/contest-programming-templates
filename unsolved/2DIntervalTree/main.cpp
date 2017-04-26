
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct Tree {
  Tree* sons[4];
  int value;
};


#define MINS true
#define MAXS false
bool op;
int* arr;
int N;

int Build(int i) {
  if (i >= N) return arr[i];
  if (op == MINS) {
    return arr[i] = min(min(min(Build(i * 4), Build(i * 4 - 1)), Build(i * 4 - 2)), Build(i * 4 - 3));
  } else {
    return arr[i] = max(max(max(Build(i * 4), Build(i * 4 - 1)), Build(i * 4 - 2)), Build(i * 4 - 3));
  }
}

int Qx1, Qy1, Qx2, Qy2;
int QueryMin(int x1, int y1, int x2, int y2, int i) {
  if (x1 >= Qx1 && x2 <= Qx2 && y1 >= Qy1 && y2 <= Qy2) {
    return arr[i];
  }
  int q[4];
  q[0] = QueryMin(x1, y1, (x1 + x2) / 2, (y1 + y2) / 2, i*4 - 3);
  q[1] = QueryMin(x1, y1, (x1 + x2) / 2, (y1 + y2) / 2, i*4 - 2);
  q[2] = QueryMin(x1, y1, (x1 + x2) / 2, (y1 + y2) / 2, i*4 - 1);
  q[3] = QueryMin(x1, y1, (x1 + x2) / 2, (y1 + y2) / 2, i*4 - 0);
  min()
}

int main() {
  scanf("%d", &N);

  int M = N - 1;
  if (!M) M = 1;
  int c = 1;
  while (M != 1) {
    M /= 2;
    c ++;
  }
  printf("%d", 1 << c);
  N = 1 << c;

  int mins[N*N*2 + 1];
  int maxs[N*N*2 + 1];

  for (int y = 0; y < N; ++y) {
    for (int x = 0; x < N; ++x) {
      int v;
      scanf("%d", &v);
      mins[1 + x + y*N] = v;
      maxs[1 + x + y*N] = v;
    }
  }

  arr = mins;
  op = MINS;
  Build(1);

  arr = maxs;
  op = MAXS;
  Build(1);

  int Q;
  scanf("%d", &Q);

  for (int i = 0; i < Q; ++i) {
    char m;
    int x1, y1, x2, y2;
    scanf("%c %d %d %d %d", &m, &x1, &y1, &x2, &y2);

  }

  return 0;
}