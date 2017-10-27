function m {
  cp -r ~/template/ "$1" && cd "$1"
}
alias cc='g++ -pipe -static -Wall -lm -O2 --std=c++11 -x c++ -g -DDEBUG template.cpp'
alias c='g++ -pipe -static -Wall -lm -O2 --std=c++11 -x c++ template.cpp'
alias r='cc && ./a.out'
alias rt='cc && find *.in | xrags -I @ sh -c "echo Test @; ./a.out < @;"'
