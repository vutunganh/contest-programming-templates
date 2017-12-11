#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=double;
using pll=pair<ll,ll>;
using vll=vector<ll>;
using vpll=vector<pll>;
using vvll=vector<vll>;
#define FOR(i,a,b) for(ll i=a;i<(ll)b;++i)
#define ROF(i,a,b) for(ll i=a;i>=(ll)b;--i)
#define F(n) FOR(i,0,n)
#define FF(n) FOR(j,0,n)
#define aa first
#define bb second
#define PB push_back
#define EQ(a,b) (fabs(a-b)<=(fabs(a+b)*EPS))

struct Token {
  char op;
  ll val;
};

bool isOp(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/');
}
bool isOp(Token c) { return isOp(c.op); }
map<char,int> opPrecedence = {{'+', 10}, {'-', 10}, {'*', 20}, {'/', 20}};
int opPrec(Token n) {
  return opPrecedence[n.op];
}

vector<Token> lexan(const string & in, map<char,ll> & replace) {
  ll num = 0;
  vector<Token> res;
  F(in.size()) {
    if (in[i] == ' ') continue;
    if (isOp(in[i]) || in[i] == '(' || in[i] == ')') {
      res.push_back(Token({in[i], 0}));
    } else if (in[i] >= '0' && in[i] <= '9') {
      while (i < in.size() && in[i] >= '0' && in[i] <= '9') {
        num *= 10;
        num += in[i] - '0';
        i ++;
      }
      res.push_back({' ', num});
      if (i == in.size()) return res;
      i --;
      num = 0;
    } else {
      res.push_back({' ', (ll)replace[(char)in[i]]});
    }
  }
  return res;
}

vector<Token> infixToPostfix(const vector<Token> & in) {
  vector<Token> res;
  vector<Token> st;
  F(in.size()) {
    if (in[i].op == '(') st.push_back(in[i]);
    else if (in[i].op == ')') {
      while (st.back().op != '(') {
        res.push_back(st.back());
        st.pop_back();
      }
      st.pop_back();
    } else if (!isOp(in[i])) {
      res.push_back(in[i]);
    } else if (st.empty() || opPrec(st.back()) < opPrec(in[i])) {
      st.push_back(in[i]);
    } else {
      while (!st.empty() && opPrec(st.back()) >= opPrec(in[i])) {
        res.push_back(st.back());
        st.pop_back();
      }
    }
  }
  while (!st.empty()) {
    res.push_back(st.back());
    st.pop_back();
  }
  return res;
}

Token doOp(Token a, Token b, char op) {
  ll res = 0;
  switch(op) {
    case '+': res = b.val + a.val; break;
    case '-': res = b.val - a.val; break;
    case '*': res = b.val * a.val; break;
    case '/': res = b.val / a.val; break;
  }
  return {' ', res};
}

ll evalPostfix(const vector<Token> & in) {
  Token op1, op2;
  vector<Token> st;
  F(in.size()) {
    if (isOp(in[i])) {
      op1 = st.back(); st.pop_back();
      op2 = st.back(); st.pop_back();
      Token result = doOp(op1, op2, in[i].op);
      st.push_back(result);
    } else {
      st.push_back(in[i]);
    }
  }
  return st.back().val;
}

int main(){
  ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
  //cout << infixToPostfix("1+2") << endl;
  //cout << infixToPostfix("(4*5) + 4*6") << endl;
  //
  map<char,ll> trash;
  while (true) {
    int n;
    cin >> n;
    vector<int> val(n);
    if (!n) break;
    F(n) cin >> val[i];
    int res;
    cin >> res;
    string exp;
    cin >> exp;
    vector<char> usedVars;
    F(exp.size()) {
      if (exp[i] >= 'a' && exp[i] <= 'z') usedVars.push_back(exp[i]);
    }
    bool flag = false;
    sort(val.begin(), val.end());
    do {
      /*F(n) cout << val[i] << " ";
      cout << endl;*/

      map<char,ll> subs;
      F(usedVars.size()) {
        subs.insert({usedVars[i], val[i]});
      }
      //cout << evalPostfix(infixToPostfix(lexan(exp, subs))) << endl;

      if (evalPostfix(infixToPostfix(lexan(exp, subs))) == res) {
        cout << "YES" << endl;
        flag = true;
        break;
      }
    } while (next_permutation(val.begin(), val.end()));
    if (!flag) cout << "NO" << endl;

  }
  return 0;
}
