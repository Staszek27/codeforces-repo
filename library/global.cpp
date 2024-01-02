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
#include <iomanip>
#include <deque>
#include <sys/time.h>
using namespace std;
typedef long long ll;
typedef tuple<ll, ll> ti2;
typedef tuple<ll, ll, ll> ti3;
typedef tuple<ll, ll, ll, ll> ti4;

typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ti2> vi2;
typedef vector<ti3> vi3;

typedef set<ll> si;
typedef set<ti2> si2;
typedef set<ti3> si3;

typedef multiset<ll> msi;
typedef multiset<ti2> msi2;
typedef multiset<ti3> msi3;

typedef deque<ll>  dqi;
typedef deque<ti2> dqi2;
typedef deque<ti2> dqi3;

template<typename T> using PQS = priority_queue<T, vector<T>, greater<T> >;
template<typename T> using PQG = priority_queue<T>;

int log_floor(ll x) { return 64 - __builtin_clzll(max(1LL, x)); } // PLUS ONE!
int bit_cnt(ll x) { return __builtin_popcountll(x); }

const int TESTS = 50;

void empty_line(char c = '.') {
    for (int i = 0; i < TESTS; i ++) {
        cout << c;
    }
}

struct timer{
    int start;

    double get_time() {
        struct timeval tp;
        gettimeofday(&tp, NULL);
        return (double) tp.tv_sec + tp.tv_usec / 1e6;
    }

    timer() {
        srand(1);
        start = get_time();
    }

    void record() {
        cout << setprecision(3) << fixed;
        cout << " | time: " << get_time() - start << endl;;
    }

    void ok(bool tests_exist = false, string additional_com = "no need for testing") {
        if (!tests_exist) {
            empty_line();
        }
        cout << " [OK]";
        if (!tests_exist) {
            cout << " | " << additional_com << endl;
        } else  record();
        exit(0);
    }
};

void dot() {
    cout << "#";
    fflush(stdout);
}


void nok() {
    cout << " [NOK !!!]" << endl;
    exit(0);
}

void no_tested() {
    empty_line('?');
    cout << " [TO BE TESTED]\n";
    exit(0);
}

int rnd(int poc, int kon) {
    return poc + rand() % (kon - poc + 1);
}