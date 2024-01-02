#include "/Users/michal/Documents/codeforces/codeforces-repo/library/global.cpp"

// inject here

template<typename T>
struct Table{
    // range [0, n - 1]
    int n, k, idx;
    T init_val;
    vector<vector<T> > arr;

    inline T oper(const T& x, const T& y) {
        return min(x, y); // TODO
    }

    Table(int n, const T& init_val) {
        this->idx = 0;
        this->n = n;
        this->init_val = init_val;
        this->k = log_floor(n);
        this->arr.assign(n, vector<T>(this->k, init_val));
    }

    void push(const T& el) {
        arr[idx][0] = el;
        for (int jump = 1;; jump ++) {
            int i = idx - (1 << jump) + 1;
            if (i < 0) break;
            arr[i][jump] = oper(
                arr[i][jump - 1], 
                arr[i + (1 << (jump - 1))][jump - 1]
            );
        }
        idx ++;
    }

    T query_fast(int beg, int en) {
        int i = log_floor(en - beg + 1) - 1;
        return oper(arr[beg][i], arr[en - (1 << i) + 1][i]); 
    }

    T query_slow(int beg, int en) {
        T res = init_val;
        for (int i = 0, l = en - beg + 1; beg <= en; i ++) {
            if (l & (1 << i)) {
                res = oper(res, arr[beg][i]);
                beg += (1 << i);
            } 
        }
        return res;
    }
};

// inject stop


const int S = 2e4;
int arr[S];

int query(int x, int y) {
    int res = 1e9;
    for (int i = x; i <= y; i ++) {
        res = min(res, arr[i]);
    }
    return res;
}


int main() {
    timer tim;
    for (int i = 0; i < TESTS; i ++) {
        vi v = {1, 2, 3, 4, 1023, 1024, 1025, 4000, (int) 1e4, (int) 1e4};
        int n = v[i % (int) v.size()] * 2;
        Table<int> T(n, 1e9);

        int cnt = 0;
        for (int o = 0; o < n; o ++) {
            if (o & 1 ^ 1) {
                int val = rnd(1, 1000);
                arr[cnt ++] = val;
                T.push(val);
            } else {
                int beg = rnd(0, cnt - 1);
                int en = rnd(beg, cnt - 1);
                if (query(beg, en) != T.query_slow(beg, en)) nok();
                if (T.query_slow(beg, en) != T.query_fast(beg, en)) nok();
            }
        }
        dot();
    }
    tim.ok(true);
    return 0;
}