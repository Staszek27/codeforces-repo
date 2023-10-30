#include "global.cpp"

// inject here

const int TREE_SIZE = (1 << 20); // TODO
const int INIT_QUERY_VAL = 0; // TODO
struct tree{
    ll oper(ll x, ll y) {
        return x + y; // TODO
    }

    ll tree_arr[TREE_SIZE * 2 + 7];

    void clear(){
        for (int i = 0; i < TREE_SIZE * 2 + 7; i ++) {
            tree_arr[i] = 0;
        }
    }

    void upd(ll pos, ll val) {
        pos += TREE_SIZE;
        tree_arr[pos] = val;
        do {
            pos >>= 1;
            tree_arr[pos] = tree_arr[pos * 2] + tree_arr[pos * 2 + 1];
        } while (pos > 1);
    }

    ll query(ll beg, ll en) {
        ll res = INIT_QUERY_VAL;
        beg += TREE_SIZE; en += TREE_SIZE;
        while (beg < en) {
            if (beg % 2 == 1) res = oper(res, tree_arr[beg ++]);
            if (en % 2 == 0) res = oper(res, tree_arr[en --]);
            beg /= 2; en /= 2;
        }
        if (beg == en) res = oper(res, tree_arr[beg]);
        return res;
    }
};

// inject stop

int main() {
    no_tested();
    return 0;
}