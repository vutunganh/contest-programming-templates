// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2387
#include <iostream>
#include <list>

using namespace std;

bool finished;

struct Item {
  Item(int threes, int zeroes, bool addingZeroes, int num) : threes(threes), zeroes(zeroes), addingZeroes(addingZeroes),
                                                             num(num) {}
  int threes, zeroes;
  bool addingZeroes;
  int num;
};
bool visited[1000000][2];

int main() {
  list<Item> queue;
  int n;
  while (cin >> n) {
    queue.push_back(Item(1, 0, false, 3 % n));
    for (int j = 0; j < n; ++j) {
      visited[j][0] = false;
      visited[j][1] = false;
    }

    while (!queue.empty()) {
      Item i = queue.front();
      queue.pop_front();
      //cout << i.num << endl;

      if (i.num == 0) {
        cout << i.threes + i.zeroes << " " << i.threes << " " << i.zeroes << endl;
        queue.clear();
        break;
      }

      if (!i.addingZeroes) {
        if (!visited[(i.num*10 + 3) % n][0]) {
          visited[(i.num*10 + 3) % n][0] = true;
          queue.push_back(Item(i.threes + 1, i.zeroes, false, (i.num * 10 + 3) % n));
        }
      }
      if (!visited[(i.num*10) % n][1]) {
        visited[(i.num*10) % n][1] = true;
        queue.push_back(Item(i.threes, i.zeroes + 1, true, ((i.num*10) % n) ));
      }
    }
  }
  return 0;
}