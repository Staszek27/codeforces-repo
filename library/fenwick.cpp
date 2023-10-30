#include "global.cpp"

// inject here

template<typename T>
struct Fenwick{ // TODO
    // Range [1, n]
    vector<T> arr;
    int n;

    Fenwick(int _n) {
        n = _n;
        arr.assign(n + 1, T{});
    }

    void clean(int m) {
        for (int i = 0; i <= m; i ++) {
            arr[i] = T{};
        }
    }

    void upd(int node, const T& val) {
        for (int i = node; i <= n; i += i & -i)
            arr[i] = arr[i] + val;
    }

    void upd(int beg, int en, const T& val) {
        upd(beg, val);
        upd(en + 1, -val);
    }

    T query(int node) {
        T res = 0;
        for (int i = node; i > 0; i -= i & -i) 
            res = res + arr[i];
        return res;
    }

    T query(int beg, int en) {
        return query(en) - query(beg - 1);
    }
};

// inject stop

const int S = 1e4 + 3;
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
    Fenwick<int> F(S);
    for (int o = 0; o < TESTS / 2; o ++) {
        for (int i = 0; i < S; i ++) arr[i] = 0;
        for (int i = 0; i <= S; i ++) {
            int beg = rnd(1, S - 1);
            int en = rnd(beg, S - 1);
            int val = rnd(1, 10);
            // cout << i << " " << beg << " " << en << " " << val << endl;
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
        F.clean(S);
        dot();
    }
    
}

void test2() {
    //timer tim;
    Fenwick<int> F(S);
    for (int o = 0; o < TESTS / 2; o ++){
        for (int i = 0; i < S; i ++) arr[i] = 0;
        for (int i = 0; i <= S; i ++) {
            int beg = rnd(1, S - 1);
            int en = rnd(beg, S - 1);
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
        F.clean(S);
        dot();
    }
   // tim.record();
    
}

int main() {
    timer tim;
    test1();
    test2();
    tim.ok(true);
    return 0;
}