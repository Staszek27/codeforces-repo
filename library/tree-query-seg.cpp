#include "global.cpp"

// inject here

template <typename T>
struct Tree{
    T oper(T x, T y) {
        return x + y; // TODO
    }
    int tree_size, init_val;
    vector<T> tree_arr;

    Tree(int lvl, T init_val) {
        this->tree_size = (1 << lvl);
        this->init_val = init_val;
        tree_arr.assign(tree_size * 2 + 7, init_val);
    }

    void clear(int m){
        int beg = tree_size; 
        int en = tree_size + m;
        while (beg) {
            for (int i = beg; i <= en; i ++)
                tree_arr[i] = init_val;
            beg /= 2; en /= 2;
        }
    }

    void upd(int pos, T val) {
        for (int i = tree_size + pos; i >= 1; i /= 2) {
            tree_arr[i] += val;
        }
    }

    T query(int beg, int en) {
        T res = init_val;
        beg += tree_size; en += tree_size;
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

const int S = 1e4;
int arr[S];

void upd(int x, int y, int val) {
    for (int i = x; i <= y; i ++) {
        arr[i] += val;
    }
}

int query(int x, int y) {
    int res = 0;
    for (int i = x; i <= y; i ++) {
        res += arr[i];
    }
    return res;
}


void test2() {
    Tree<int> F(20, 0);
    for (int o = 0; o < TESTS; o ++){
        int n = rnd(1, S - 1);
        for (int i = 0; i <= n; i ++) arr[i] = 0;
        for (int i = 0; i <= S; i ++) {
            int beg = rnd(1, n);
            int en = rnd(beg, n);
            int val = rnd(1, 10);
            //cout << i << " " << beg << " " << en << " " << val << endl;

            if (i & 1) {
                upd(beg, beg, val);
                F.upd(beg, val);
            }
            else {
                if (query(beg, en) != F.query(beg, en)) {
                    nok();
                }
            }
        }
        F.clear(n);
        dot();
    }
}

int main() {
    timer tim;
    test2();
    tim.ok(true);
    return 0;
}