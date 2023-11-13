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
#include <deque>

using namespace std;
typedef long long ll;
typedef tuple<ll, ll> ti2;
typedef tuple<ll, ll, ll> ti3;
typedef tuple<ll, ll, ll, ll> ti4;

typedef vector<bool>   vb;
typedef vector<vb>     vvb;
typedef vector<string> vs;

typedef vector<ll>  vi;
typedef vector<ti2> vi2;
typedef vector<ti3> vi3;
typedef vector<vi>  vvi;

typedef set<ll>  si;
typedef set<ti2> si2;
typedef set<ti3> si3;

typedef multiset<ll>  msi;
typedef multiset<ti2> msi2;
typedef multiset<ti3> msi3;

typedef deque<ll>  dqi;
typedef deque<ti2> dqi2;
typedef deque<ti3> dqi3;


ostream& operator<<(ostream& os, ti2 x)  { os << "{ "; auto [a, b] = x;       os << a << ", " << b;                            os << " }"; return os; }
ostream& operator<<(ostream& os, ti3 x)  { os << "{ "; auto [a, b, c] = x;    os << a << ", " << b << ", " << c;               os << " }"; return os; }
ostream& operator<<(ostream& os, ti4 x)  { os << "{ "; auto [a, b, c, d] = x; os << a << ", " << b << ", " << c << ", " << d;  os << " }"; return os; }

ostream& operator<<(ostream& os, vi x)   { os << "{ "; for (auto e : x) os << e << " "; os << "}"; return os; }
ostream& operator<<(ostream& os, vs x)   { os << "{ "; for (auto e : x) os << e << " "; os << "}"; return os; }
ostream& operator<<(ostream& os, vb x)   { os << "{ "; for (auto e : x) os << e << " "; os << "}"; return os; }
ostream& operator<<(ostream& os, vvb x)  { os << "{ "; for (auto e : x) os << e << " "; os << "}"; return os; }
ostream& operator<<(ostream& os, vi2 x)  { os << "{ "; for (auto e : x) os << e << " "; os << "}"; return os; }
ostream& operator<<(ostream& os, vi3 x)  { os << "{ "; for (auto e : x) os << e << " "; os << "}"; return os; }
ostream& operator<<(ostream& os, vvi x)  { os << "{ "; for (auto e : x) os << e << " "; os << "}"; return os; }

ostream& operator<<(ostream& os, msi x)  { os << "{ "; for (auto e : x) os << e << " "; os << "}"; return os; }
ostream& operator<<(ostream& os, msi2 x) { os << "{ "; for (auto e : x) os << e << " "; os << "}"; return os; }
ostream& operator<<(ostream& os, msi3 x) { os << "{ "; for (auto e : x) os << e << " "; os << "}"; return os; }

ostream& operator<<(ostream& os, dqi x)  { os << "{ "; for (auto e : x) os << e << " "; os << "}"; return os; }
ostream& operator<<(ostream& os, dqi2 x) { os << "{ "; for (auto e : x) os << e << " "; os << "}"; return os; }
ostream& operator<<(ostream& os, dqi3 x) { os << "{ "; for (auto e : x) os << e << " "; os << "}"; return os; }


template<typename T> using PQS = priority_queue<T, vector<T>, greater<T> >;
template<typename T> using PQG = priority_queue<T>;

int log_floor(ll x) { return 64 - __builtin_clzll(max(1LL, x)); } // PLUS ONE!
int bit_cnt(ll x) { return __builtin_popcountll(x); }

// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣆⠀⢀⣀⣀⣤⣤⣤⣦⣦⣤⣤⣄⣀⣀⠀⢠⣾⣿⣿⣿⣿⣿⣷⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠛⠿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⢿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣿⣿⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣿⣿⣿⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⢿⣿⠟⠀⠀⠀⠀⠀⣀⣤⣤⣤⡀⠀⠀⠀⠀⠀⢀⣤⣤⣤⣄⡀⠀⠀⠀⠀⠘⣿⡿⠿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡟⠀⠀⠀⠀⣠⣾⣿⣿⣟⣿⡇⠀⠀⠀⠀⠀⢸⣿⣿⣻⣿⣿⣦⠀⠀⠀⠀⠸⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠁⠀⠀⠀⠀⣿⣿⣿⣿⣿⡟⢠⣶⣾⣿⣿⣷⣤⢽⣿⣿⣿⣿⣿⡇⠀⠀⣀⣤⣿⣷⣴⣶⣦⣀⡀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⣤⣠⣇⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⠀⠘⠻⣿⣿⣿⡿⠋⠀⢹⣿⣿⣿⣿⡇⠀⣿⣿⣿⡏⢹⣿⠉⣿⣿⣿⣷⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣿⣶⣄⠀⠀⠹⣿⣿⠿⠋⠀⢤⣀⢀⣼⡄⠀⣠⠀⠈⠻⣿⣿⠟⠀⢸⣿⣇⣽⣿⠿⠿⠿⣿⣅⣽⣿⡇⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠁⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣿⣟⠁⠀⠀⠀⠈⣿⣿⣿⡇⠀⠀⠀⠀⢀
// ⠛⠛⠛⠛⠛⠛⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛
// ⠀⠀⠀⠀⠀⠀⠘⠛⠻⢿⣿⣿⣿⣿⣿⠟⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠈⠉⠀⠀⠀⠀                          [ STASZEK ]                   
//

// inject here

void solve(){
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    while (t --) solve();
    return 0;
}
