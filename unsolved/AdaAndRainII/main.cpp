#include <cstdio>
#include <cstdint>

int main() {
  int N, M, L;
  scanf("%d %d %d", &N, &M, &L);
  L += 2;

  int *queryMap = new int[L*L];
  int *map = new int[L*L];
  for (int i = 0; i < L*L; ++ i) {
    queryMap[i] = 0;
    map[i] = 0;
  }

  for (int i = 0; i < N; ++i) {
    int x, y, X, Y;
    scanf("%d %d %d %d", &x, &y, &X, &Y);
    queryMap[x + y*L] ++;
    queryMap[X + Y*L] ++;
    queryMap[x + Y*L] --;
    queryMap[X + y*L] --;
  }

  int d = 0;
  for (int y = 0; y < L; ++ y) {
    for (int x = L - 1; x >= 0; -- x) {
      d += queryMap[x + y*L];
      map[x + y*L] = d;
    }
  }

  for (int i = 0; i < M; ++ i) {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d\n", map[x + y*L]);
  }

  delete [] map;

  return 0;
}

