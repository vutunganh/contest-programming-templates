//
// Created by maty on 3/3/17.
//

#include <iostream>
#include <queue>

/* BFS spustene nad matici reprezentujici nejake bludiste.
 * Pamatuje si pocet kroku do vrcholu.
 * */

#define MAX_ROWS 300
#define MAX_COLUMNS 300
#define WALL '#'
#define START 'S'
#define END 'E'
#define NO_WAY_MESSAGE "NO"

using namespace std;


char matrix[MAX_ROWS][MAX_COLUMNS];
char visited[MAX_ROWS][MAX_COLUMNS];

struct Point {
  Point(int r, int c, int steps) : r(r), c(c), steps(steps) {};
  Point(): steps(-1) {};
  int r, c;
  int steps;
};

// spusti se pri dorazeni do cile a jako parametr bere koncovy vrchol
void foundTarget(Point & point) {
  cout << point.steps << endl;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int c, r;
    Point end;
    cin >> r >> c;

    queue<Point> queue;

    for (int ri = 0; ri < r; ++ri) {
      for (int ci = 0; ci < c; ++ci) {
        cin >> matrix[ri][ci];
        visited[ri][ci] = false;
        if (matrix[ri][ci] == START) {
          queue.push(Point(ri, ci, 0));
        }
        if (matrix[ri][ci] == END) {
          end.c = ci;
          end.r = ri;
        }
      }
    }

    bool found = false;
    while (!queue.empty()) {
      Point cur = queue.front();
      queue.pop();

      if (cur.c == end.c && cur.r == end.r) {
        foundTarget(cur);
        found = true;
        break;
      }

      // sousedi
      for (int dr = -1; dr <= 1; dr ++) {
        for (int dc = -1; dc <= 1; dc ++) {
          if (dr*dr + dc*dc == 1) {
            if (cur.r + dr >= 0 && cur.r + dr < r
              && cur.c + dc >= 0 && cur.c + dc < c
              && matrix[cur.r + dr][cur.c + dc] != WALL
                && !visited[cur.r + dr][cur.c + dc]) {
              visited[cur.r + dr][cur.c + dc] = true;
              queue.push(Point(cur.r + dr, cur.c + dc, cur.steps + 1));
            }
          }
        }
      }
    }
    if (!found) cout << NO_WAY_MESSAGE << endl;
  }

  return 0;
}
