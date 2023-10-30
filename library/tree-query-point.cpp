#include "global.cpp"

// inject here

const int TREE_SIZE = (1 << 20); // TODO
const int INIT_QUERY_VAL = 0; // TODO

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
                tree_arr[i] = INIT_QUERY_VAL;
            beg /= 2; en /= 2;
        }
    }
 
    T query(int pos) {
        T res = init_val;
        for (int i = tree_size + pos; i >= 1; i /= 2) {
            res = oper(res, tree_arr[i]);
        }
        return res;
    }
 
    void upd(int beg, int en, T val) {
        beg += tree_size; en += tree_size;
        while (beg < en) {
            if (beg % 2 == 1) tree_arr[beg ++] = oper(val, tree_arr[beg]);
            if (en % 2 == 0) tree_arr[en --] = oper(val, tree_arr[en]);
            beg /= 2; en /= 2;
        }
        if (beg == en) tree_arr[beg] = oper(val, tree_arr[beg]);
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

void test1() {
    Tree<int> F(20, 0);
    for (int o = 0; o < TESTS; o ++) {
        int n = rnd(1, S - 1);
        for (int i = 0; i < S; i ++) arr[i] = 0;
        for (int i = 0; i <= S; i ++) {
            int beg = rnd(1, n);
            int en = rnd(beg, n);
            int val = rnd(1, 10);
            //cout << beg << " " << en << " " << val << endl;
            if (i & 1) {
                upd(beg, en, val);
                F.upd(beg, en, val);
            }
            else {
                if (query(beg, beg) != F.query(beg)) {
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
    test1();
    tim.ok(true);
    return 0;
}