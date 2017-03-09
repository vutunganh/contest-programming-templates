#include <iostream>
#include <list>

using namespace std;

char matrix[300][300];
char visited[300][300][4];

struct Point {
  Point(int r, int c, int steps) : r(r), c(c), steps(steps) {};
  Point(): steps(-1) {};
  int r, c;
  int steps;
};

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int c, r;
    Point end;
    cin >> r >> c;

    list<Point> queue;

    for (int ri = 0; ri < r; ++ri) {
      for (int ci = 0; ci < c; ++ci) {
        cin >> matrix[ri][ci];
        for (int j = 0; j < 4; ++j) {
          visited[ri][ci][j] = false;
        }
        if (matrix[ri][ci] == 'S') {
          queue.push_back(Point(ri, ci, 0));
        }
        if (matrix[ri][ci] == 'E') {
          end.c = ci;
          end.r = ri;
        }
      }
    }

    bool found = false;
    while (!queue.empty()) {
      Point cur = queue.front();
      queue.pop_front();
      //cout << cur.r << ", " << cur.c << endl;

      if (cur.c == end.c && cur.r == end.r) {
        cout << cur.steps << endl;
        found = true;
        break;
      }
      // neighbors
      int len = (cur.steps % 3) + 1;

      for (int k = 0; k < 4; ++k) {
        bool canPass = true;
        int dc, dr;
        switch(k) {
          case 0: dc = 0; dr = 1; break;
          case 1: dc = 0; dr = -1; break;
          case 2: dc = 1; dr = 0; break;
          case 3: dc = -1; dr = 0; break;
        }
        for (int j = 1; j <= len; ++j) {
          if (matrix[cur.r + j*dr][cur.c + j*dc] == '#' || cur.r + j*dr < 0 || cur.r + j*dr >= r
              || cur.c + j*dc < 0 || cur.c + j*dc >= c) {
            canPass = false;
            break;
          }
        }

        if (canPass && !visited[cur.r + len*dr][cur.c + len*dc][len]) {
          visited[cur.r + len*dr][cur.c + len*dc][len] = true;
          queue.push_back(Point(cur.r + len*dr, cur.c + len*dc, cur.steps + 1));
        }
      }
    }
    if (!found) cout << "NO" << endl;

  }
  return 0;
}