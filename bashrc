alias c='g++ -std=c++14 -static -Wall -O2 template.cpp'

function m {
  cp -r ~/template/ "$1" && cd "$1"
}

function rt {
  c && find *"$1".in | xargs -I @ sh -c "echo Test @ >&2; ./a.out < @;"
  # c && find *in*"$1" | xargs -I @ sh -c "echo Test @ >&2; ./a.out < @;" 
}

function rtt {
  c && for a in *"$1".in; do echo "Test $a"; ./a.out < "$a" | diff - "${a%.in}.out" "$2"; done
}

function vg {
  c && find *"$1".in | xargs -I @ sh -c "echo Test @; valgrind ./a.out < @;"
}

function tt {
  c && find *"$1".in | xargs -I @ sh -c "echo Test @; time ./a.out < @;"
}
