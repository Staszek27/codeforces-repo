#include "/Users/michal/Documents/codeforces/codeforces-repo/library/global.cpp"

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
struct Tree{
    inline L lazy_to_lazy_f(const L &x, const L &y) {
        // TODO: only if upd
        return x + y;
    }

    inline T lazy_to_arr_f(const L &x, const T &y, int subtree_s) { 
        // TODO: only if upd
        T res = {};
        for (int i = S - 1; i >= 0; i --) {
            int take_from = i - x;
            if (take_from < 0) continue;
            res.cnt[i] = y.cnt[take_from];
        }
        return res; 
    }

    inline T query_f(const T &x, const T &y) {
        // TODO: ALWAYS
        return x + y;
    }
    
    inline T set_to_arr_f(const T& x, int subtree_s) {
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

    Tree(int n, const T &init_val_arr = 0, const L &init_val_lazy = 0, const T &query_default_val = 0) {
        this->lvl = log_floor(n);
        this->tree_size = (1 << lvl);
        this->init_val_arr = init_val_arr;
        this->init_val_lazy = init_val_lazy;
        this->query_default_val = query_default_val;
        arr.clear();
        lazy.clear();
        to_clear.clear();
        to_set.clear();
        arr.resize(tree_size * 2, init_val_arr);
        lazy.resize(tree_size * 2, init_val_lazy);
        to_clear.resize(tree_size * 2, false);
        to_set.resize(tree_size * 2);
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

    inline bool prepare_beg_en(int& beg, int& en, int v, int& t_beg, int& t_en) {
        push(v, t_en - t_beg + 1);
        return t_beg > en || t_en < beg; // returns true if miss
    }

    void _upd(int beg, int en, const L& val, int v, int t_beg, int t_en) {
        if (prepare_beg_en(beg, en, v, t_beg, t_en)) return;
        if (beg <= t_beg && t_en <= en) {
            lazy[v] = lazy_to_lazy_f(lazy[v], val);
            push(v, t_en - t_beg + 1);
            return;
        }
        int tm = (t_beg + t_en) / 2;
        _upd(beg, en, val, v * 2,     t_beg,  tm);
        _upd(beg, en, val, v * 2 + 1, tm + 1, t_en);
        arr[v] = query_f(arr[v * 2], arr[v * 2 + 1]);
    }

    void _set(int beg, int en, const T& val, int v = 1, int t_beg = -1, int t_en = -1) {
        if (prepare_beg_en(beg, en, v, t_beg, t_en)) return;
        if (beg <= t_beg && t_en <= en) {
            to_clear[v] = true;
            to_set[v] = val;
            push(v, t_en - t_beg + 1);
            return;
        }
        int tm = (t_beg + t_en) / 2;
        _set(beg, en, val, v * 2,     t_beg,  tm);
        _set(beg, en, val, v * 2 + 1, tm + 1, t_en);
        arr[v] = query_f(arr[v * 2], arr[v * 2 + 1]);
    }

    T _query(int beg, int en, int v = 1, int t_beg = -1, int t_en = -1) {
        if (prepare_beg_en(beg, en, v, t_beg, t_en)) return query_default_val;
        if (beg <= t_beg && t_en <= en) { return arr[v]; }
        int tm = (t_beg + t_en) / 2;
        return query_f(
            _query(beg, en, v * 2,     t_beg,  tm),
            _query(beg, en, v * 2 + 1, tm + 1, t_en)
        );
    }

    inline void set(int beg, int en, const T& val) {
        _set(beg, en, val, 1, 0, tree_size - 1);
    }

    inline void upd(int beg, int en, const L& val) {
        _upd(beg, en, val, 1, 0, tree_size - 1);
    }

    inline T query(int beg, int en) {
        return _query(beg, en, 1, 0, tree_size - 1);
    }
};

// inject stop



TT init_TT() {
    TT res = {};
    res.cnt[0] = 1;
    return res;
}

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
    Tree<TT, int> T(n, init_TT(), 0, TT{});
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
    dot();
}

int main() {
    timer tim;
    for (int i = 0; i < TESTS; i ++) test();
    tim.ok(true);
    return 0;
}