#include "../../template.cpp"
#include "../../structs/fenwick_tree.cpp"

int main(void) {
    ios_base::sync_with_stdio(false);

    Ft<100> ft;
    F(100) ft.upd(i+1, 1);
    dbg(ft.get(100));

    return 0;
}
