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
#include <iomanip>
#include <tuple>
#include <stack>

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

template<typename T> using PQS = priority_queue<T, vector<T>, greater<T> >;
template<typename T> using PQG = priority_queue<T>;

int log_floor(ll x) { return 64 - __builtin_clzll(max(1LL, x)); } // PLUS ONE!
int bit_cnt(ll x) { return __builtin_popcountll(x); }

int rnd(int poc, int kon){
    return poc + rand() % (kon - poc + 1);
}

int main(int argc, char* argv[]){
    srand(atoi(argv[1]));
    int n = 10;
    cout << "1\n" << n << endl;
    for (int i = 0; i < n; i ++){
        cout << rnd(0, 3) << " ";
    }

    return 0;
}