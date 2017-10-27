m() {
  cp -r ~/template/ "$1" && cd "$1"
}
alias cc='g++ -pipe -static -Wall -lm -O2 --std=c++11 -x c++ template.cpp'
alias c='g++ -pipe -static -Wall -lm -O2 --std=c++11 -x c++ -g -DDEBUG template.cpp'
r() {
  c
  for f in *.in; do
    ./a.out < "$f"
    echo "=================================================="
  done
}
rt() {
  c && find *"$1".in | xargs -I @ sh -c "echo Test @ >&2; ./a.out < @;"
}
rtt() {
  c && for a in *$1.in; do echo "Test $a"; ./a.out < $a | diff - ${a:0:-3}.out $2; done
}
