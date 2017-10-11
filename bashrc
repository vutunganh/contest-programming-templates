function m {
  cp -r ~/template/ "$1"
}
alias r='./run.sh'
alias c='g++ -pipe -static -Wall -lm -O2 --std=c++11 -x c++'
