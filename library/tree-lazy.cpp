
#include "global.cpp"

const int S = 100 + 7;
int arr[S];

struct TT{
    int cnt[S];

    bool operator==(const TT& other) const {
        for (int i = 0; i < S; i ++)
            if (other.cnt[i] != cnt[i])
                return false;
        return true;
    }

    TT operator+(const TT& other) const {
        TT res = {};
        for (int i = 0; i < S; i ++)
            res.cnt[i] = (other.cnt[i] + cnt[i]);
        return res;
    }
};

ostream& operator<<(ostream& os, const TT& o) {
    os << "{ " ;
    for (int i = 0; i < S; i ++) {
        os << o.cnt[i] << " ";
    }
    os << "}\n";
    return os;
}

// inject here

template <typename T, typename L>
struct tree{
    L lazy_to_lazy_f(const L &x, const L &y) {
        // TODO: only if upd
        return x + y;
    }

    T lazy_to_arr_f(const L &x, const T &y, int subtree_s) { 
        // TODO: only if upd
        TT res = {};
        for (int i = S - 1; i >= 0; i --) {
            int take_from = i - x;
            if (take_from < 0) continue;
            res.cnt[i] = y.cnt[take_from];
        }
        return res; 
    }

    T query_f(const T &x, const T &y) {
        // TODO: ALWAYS
        return x + y;
    }
    
    T set_to_arr_f(const T& x, int subtree_s) {
        // TODO: only if set
        TT res = {};
        for (int i = 0; i < S; i ++) {
            res.cnt[i] = x.cnt[i] * subtree_s;
        }
        return res;
    }


    int tree_size, lvl;
    vector<T> arr, to_set;
    vector<L> lazy;
    vector<bool> to_clear;
    T init_val_arr;
    T query_default_val;
    L init_val_lazy;

    int total_capacity() {
        return tree_size * 2;
    }

    void init_values(int lvl, const T &init_val_arr, const L &init_val_lazy, const T &query_default_val) {
        this->lvl = lvl;
        this->tree_size = (1 << lvl);
        this->init_val_arr = init_val_arr;
        this->init_val_lazy = init_val_lazy;
        this->query_default_val = query_default_val;
        arr.clear();
        lazy.clear();
        to_clear.clear();
        to_set.clear();
        arr.resize(total_capacity(), init_val_arr);
        lazy.resize(total_capacity(), init_val_lazy);
        to_clear.resize(total_capacity(), false);
        to_set.resize(total_capacity());
    }

    void init_with_array(const vector<T> &v) {
        for (int i = 0; i < v.size(); i ++){
            arr[i + tree_size] = v[i];
        }
        int beg = tree_size;
        int en = tree_size + v.size() - 1;
        while (beg > 1) {
            beg /= 2; en /= 2;
            for (int i = beg; i <= en; i ++) {
                arr[i] = query_f(arr[i * 2], arr[i * 2 + 1]);
            }
        }
    }

    void clean(int n) {
        int beg = tree_size;
        int en = tree_size + n;
        while (beg >= 1) {
            for (int i = beg; i <= en; i ++) {
                lazy[i] = init_val_lazy;
                arr[i] = init_val_arr;
                to_clear[i] = 0;
            }
            beg /= 2;
            en /= 2;
        }
    }

    void push(int v, int seg_size) {
        if (to_clear[v]) {
            arr[v] = set_to_arr_f(to_set[v], seg_size);
            to_clear[v] = false;
            if (v < tree_size) {
                lazy[v * 2] = lazy[v * 2 + 1] = init_val_lazy;
                to_clear[v * 2] = to_clear[v * 2 + 1] = true;
                to_set[v * 2] = to_set[v * 2 + 1] = to_set[v];
            }
        } 
        if (lazy[v] != init_val_lazy) {
            arr[v] = lazy_to_arr_f(lazy[v], arr[v], seg_size);
            if (v < tree_size) {
                lazy[v * 2] = lazy_to_lazy_f(lazy[v * 2], lazy[v]);
                lazy[v * 2 + 1] = lazy_to_lazy_f(lazy[v * 2 + 1], lazy[v]);
            }
        }
        lazy[v] = init_val_lazy;
    }

    // returns true if miss
    bool prepare_beg_en(int& beg, int& en, int v, int& t_beg, int& t_en) {
        if (v == 1) {
            t_beg = 0;
            t_en = tree_size - 1;
        }
        push(v, t_en - t_beg + 1);
        return t_beg > en || t_en < beg;
    }

    void upd(int beg, int en, L val, int v = 1, int t_beg = -1, int t_en = -1) {
        if (prepare_beg_en(beg, en, v, t_beg, t_en)) return;
        if (beg <= t_beg && t_en <= en) {
            lazy[v] = lazy_to_lazy_f(lazy[v], val);
            push(v, t_en - t_beg + 1);
            return;
        }
        
        int tm = (t_beg + t_en) / 2;
        upd(beg, en, val, v * 2,     t_beg,  tm);
        upd(beg, en, val, v * 2 + 1, tm + 1, t_en);
        arr[v] = query_f(arr[v * 2], arr[v * 2 + 1]);
    }

    void set(int beg, int en, T val, int v = 1, int t_beg = -1, int t_en = -1) {
        if (prepare_beg_en(beg, en, v, t_beg, t_en)) return;
        if (beg <= t_beg && t_en <= en) {
            to_clear[v] = true;
            to_set[v] = val;
            push(v, t_en - t_beg + 1);
            return;
        }
        int tm = (t_beg + t_en) / 2;
        set(beg, en, val, v * 2,     t_beg,  tm);
        set(beg, en, val, v * 2 + 1, tm + 1, t_en);
        arr[v] = query_f(arr[v * 2], arr[v * 2 + 1]);
    }

    T query(int beg, int en, int v = 1, int t_beg = -1, int t_en = -1) {
        if (prepare_beg_en(beg, en, v, t_beg, t_en)) return query_default_val;
        if (beg <= t_beg && t_en <= en) { return arr[v]; }
        int tm = (t_beg + t_en) / 2;
        return query_f(
            query(beg, en, v * 2,     t_beg,  tm),
            query(beg, en, v * 2 + 1, tm + 1, t_en)
        );
    }

    void debug() {
        for (int o = 0; o < 2; o ++) {
            cout << (o == 0 ? "Lazy:\n" : "Arr:\n");
            for (int i = 0; i < lvl + 1; i ++) {
                cout << "lvl(" << i << "): ";
                for (int j = (1 << i); j < (1 << (i + 1)); j ++){
                    if (o == 0) cout << lazy[j] << " ";
                    else cout << arr[j] << " ";
                }
                cout << endl;
            }
        }
    }
};

// inject stop



TT init_TT() {
    TT res = {};
    res.cnt[0] = 1;
    return res;
}
tree<TT, int> T;

void clean() {
    for (int i = 0; i < S; i ++) {
        arr[i] = 0;
    }
}

void upd(int x, int y, int val) {
    for (int i = x; i <= y; i ++) arr[i] += val;
}

void sett(int x, int y, int val) {
    for (int i = x; i <= y; i ++) arr[i] = val;
}

TT query(int x, int y) {
    TT res = {};
    for (int i = x; i <= y; i ++) {
        if (arr[i] < S) res.cnt[arr[i]] ++;
    }
    return res;
}



void test() {
    int n = 50;
    int m = 10000;
    vector<TT> v = {TT{}};
    for (int i = 1; i <= n; i ++) {
        int x = rnd(0, 10);
        arr[i] = x;
        TT to_push = {};
        if (x < S) to_push.cnt[x] ++;
        v.push_back(to_push);
    }
    T.init_with_array(v);

    for (int i = 0; i < m; i ++) {
        int opt = rnd(1, 3);
        int x = rnd(1, n);
        int y = rnd(x, n);
        int val = rnd(1, 10);
        // cout << opt << " " << x << " " << y << " " << val << endl;
        if (opt == 1) {
            if (!(query(x, y) == T.query(x, y))) {
                nok();
            }
        }
        if (opt == 2) {
            TT to_add = {};
            to_add.cnt[val] = 1;
            T.set(x, y, to_add);
            sett(x, y, val);
        }
        if (opt == 3) {
            T.upd(x, y, val);
            upd(x, y, val);
        }
    }
    clean();
    T.clean(n);
    dot();
}

int main() {
    timer tim;
    T.init_values(10, init_TT(), 0, TT{});
    for (int i = 0; i < TESTS; i ++) test();
    tim.ok(true);
    return 0;
}