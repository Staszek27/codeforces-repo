#include "global.cpp"

// inject here

template<typename T>
struct Tree{ // TODO
    // Range [1, n]
    vector<T> arr;
    int n;

    Tree(int _n) {
        n = _n;
        arr.assign(n + 2, T{});
    }

    void upd(int node, const T& val) {
        assert(node > 0 && node <= n);
        for (int i = node; i <= n; i += i & -i)
            arr[i] += val;
    }

    void upd(int beg, int en, const T& val) {
        upd(beg, val);
        upd(en + 1, -val);
    }

    T query(int node) {
        assert(node > 0 && node <= n);
        T res = {};
        for (int i = node; i > 0; i -= i & -i) 
            res += arr[i];
        return res;
    }

    T query(int beg, int en) {
        return query(en) - query(beg - 1);
    }
};

// inject stop


const int S = 2e4;
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
    for (int o = 0; o < TESTS / 2; o ++) {
        Tree<ll> F(S);
        int n = rnd(1, S - 1);
        for (int i = 0; i <= n; i ++) arr[i] = 0;
        for (int i = 0; i <= S; i ++) {
            int beg = rnd(1, n);
            int en = rnd(beg, n);
            int val = rnd(1, 10);
         //   cout << i << " " << beg << " " << en << " " << val << endl;
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
        dot();
    }
    
}

void test2() {
    //timer tim;
    Tree<ll> F(S);
    for (int o = 0; o < TESTS / 2 ; o ++){
        Tree<ll> F(S);
        int n = rnd(1, S - 1);
        for (int i = 0; i <= n; i ++) arr[i] = 0;
        for (int i = 0; i <= S; i ++) {
            int beg = rnd(1, n);
            int en = rnd(beg, n);
            int val = rnd(1, 10);
            // cout << i << " " << beg << " " << en << " " << val << endl;
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
        dot();
    }
}

int main() {
    timer tim;
    test1();
    test2();
    tim.ok(true);
    return 0;
}