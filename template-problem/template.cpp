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
typedef tuple<int, int> ti2;
typedef tuple<int, int, int> ti3;
typedef tuple<int, int, int, int> ti4;
typedef tuple<ll, ll> tl2;
typedef tuple<ll, ll, ll> tl3;
typedef tuple<ll, ll, ll, ll> tl4;

typedef vector<int> vi;
typedef vector<ti2> vi2;
typedef vector<ll> vl;
typedef vector<tl2> vl2;

typedef set<int> si;
typedef set<ti2> si2;
typedef set<ll> sl;
typedef set<tl2> sl2;

template<typename T> using PQS = priority_queue<T, vector<T>, greater<T> >;
template<typename T> using PQG = priority_queue<T>;

// inject here

// TODO: Test Library

const int S = 1e6 + 7;
int n, m;

void solve(){

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    while (t --)
        solve();

    return 0;
}
