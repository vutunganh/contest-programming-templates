alias _c='g++ -std=c++14 -static -Wall -O2 -g'
function c {
  for f in *.cpp; do
    _c "${f}"
  done
}

function m {
  cp -r ~/template/ "$1" && cd "$1" && mv *.cpp "$1".cpp
}

function rt {
  c && find *"$1".in | xargs -I @ sh -c "echo Test @ >&2; ./a.out < @;"
}

function rtt {
  c && for a in *"$1".in; do echo "Test $a"; diff <(./a.out < "$a") "${a%.in}.ref"; done
}

function vg {
  c && find *"$1".in | xargs -I @ sh -c "echo Test @; valgrind ./a.out < @;"
}

function tt {
  c && find *"$1".in | xargs -I @ bash -c "echo Test @; time ./a.out < @;"
}
