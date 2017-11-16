alias cc='g++ -std=c++11 -static -Wall -O2 -DONLINE_JUDGE template.cpp'
alias c='g++ -std=c++11 -static -Wall -O2 -DONLINE_JUDGE -DDEBUG -g template.cpp'

function m {
  cp -r ~/template/ "$1" && cd "$1"
}

function rt {
  c && find *"$1".in | xargs -I @ sh -c "echo Test @ >&2; ./a.out < @;"
}

function rtt {
  c && for a in *$1.in; do echo "Test $a"; ./a.out < $a | diff - ${a:0:-3}.out $2; done
}

function vg {
  c && find *"$1".in | xargs -I @ sh -c "echo Test @; valgrind ./a.out < @;"
}

function tt {
  c && find *"$1".in | xargs -I @ sh -c "echo Test @; time ./a.out < @;"
}
