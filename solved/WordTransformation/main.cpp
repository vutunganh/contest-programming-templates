#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <sstream>

using namespace std;

struct Vertex {
  Vertex(string &word) : word(word) {}

  vector<Vertex*> links;
  string & word;
  bool visited;
};

int diffLetter(const string & a, const string & b) {
  int n = 0;
  if (a.size() != b.size()) return 1000;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] != b[i]) n ++;
  }
  return n;
}

int main() {
  int n;
  cin >> n;
  string line;
  getline(cin, line);

  for (int i = 0; i < n; ++i) {
    unordered_map<string, Vertex*> vertex;
    vector<Vertex*> vertexList;

    vector<string> words(205);
    for (int j = 0; true; ++ j) {
      cin >> words[j];
      if (words[j][0] == '*') break;

      Vertex* tempV = new Vertex(words[j]);
      //tempV->word = words[j];
      // find all the links
      for (int k = 0; k < j; ++k) {
        // compare
        if (diffLetter(vertexList[k]->word, tempV->word) == 1) {
          tempV->links.push_back(vertexList[k]);
          vertexList[k]->links.push_back(tempV);
        }
      }

      vertexList.push_back(tempV);
      vertex.insert({words[j], tempV});
    }

    string s;
    getline(cin, s);

    // read the queries
    while (true) {
      string line;
      string word1, word2;

      getline(cin, line);
      //cout << "{" << line << "}" << endl;
      if (line.empty() || line[0] == '\n' || cin.bad() || cin.eof()) {
        if (i != n -1)
          cout << endl;
        break;
      }

      stringstream stream;
      stream << line;
      stream >> word1 >> word2;

      // run BFS
      // clear visited
      for (int k = 0; k < vertexList.size(); ++k) vertexList[k]->visited = false;

      Vertex* vertexStart = vertex[string(word1)];
      Vertex* endVertex = vertex[string(word2)];
      list<pair<Vertex*, int>> queue;
      queue.push_back(make_pair(vertexStart, 0));

      while (!queue.empty()) {
        Vertex* curV = queue.front().first;
        int n = queue.front().second;
        if (curV == endVertex) {
          cout << word1 << " " << word2 << " " << n << endl;
          break;
        }
        queue.pop_front();

        for (int j = 0; j < curV->links.size(); ++ j) {
          if (!curV->links[j]->visited) {
            queue.push_back(make_pair(curV->links[j], n + 1));
            curV->links[j]->visited = true;
          }
        }
      }

    }
    for (int l = 0; l < vertexList.size(); ++l) {
      //delete vertexList[l];
    }
  }
  return 0;
}