#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>
#include <cassert>
#include <functional>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;

// inject here

// sum / sum by default
template <typename T, typename L>
struct tree{
    T lazy_to_lazy_f(const L &x, const L &y) {
        return x + y; // TODO
    }

    T lazy_to_arr_f(const L &x, const T &y, int subtree_s) {
        return x * subtree_s + y; // TODO
    }

    T query_f(const T &x, const T &y) {
        return x + y; // TODO
    }

    int tree_size, lvl;
    vector<T> arr;
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
        arr.resize(total_capacity(), init_val_arr);
        lazy.resize(total_capacity(), init_val_lazy);
        to_clear.resize(total_capacity(), 0);
    }

    void init_with_array(const vector<T> &v) {
        for (int i = 0; i < v.size(); i ++){
            arr[i + tree_size] = v[i];
        }
        for (int i = lvl - 1; i >= 0; i --) {
            for (int j = (1 << i); j < (1 << (i + 1)); j ++) {
                arr[j] = query_f(arr[j * 2], arr[j * 2 + 1]);
            }
        }
    }

    void clean() {
        for (int i = 0; i < total_capacity(); i ++) {
            arr[i] = init_val_arr;
            lazy[i] = init_val_lazy;
            to_clear[i] = false;
        }
    }

    void push(int v, int seg_size) {
        if (to_clear[v]) {
            arr[v] = lazy_to_arr_f(lazy[v], init_val_arr, seg_size);
            to_clear[v] = false;
            if (v < tree_size) {
                lazy[v * 2] = lazy[v * 2 + 1] = lazy[v];
                to_clear[v * 2] = to_clear[v * 2 + 1] = true;
            }
        } else {
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

    void upd(int beg, int en, T val, bool just_set = false, int v = 1, int t_beg = -1, int t_en = -1) {
        if (prepare_beg_en(beg, en, v, t_beg, t_en)) return;
        if (beg <= t_beg && t_en <= en) {
            lazy[v] = lazy_to_lazy_f(
                (to_clear[v] = just_set) ?
                    init_val_lazy :
                    lazy[v],
                val
            );
            push(v, t_en - t_beg + 1);
            return;
        }
        
        int tm = (t_beg + t_en) / 2;
        upd(beg, en, val, just_set, v * 2,     t_beg,  tm);
        upd(beg, en, val, just_set, v * 2 + 1, tm + 1, t_en);
        arr[v] = query_f(arr[v * 2], arr[v * 2 + 1]);
    }

    T query(int beg, int en, int v = 1, int t_beg = -1, int t_en = -1) {
      //  cout << t_beg << " " << t_en << endl;
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
