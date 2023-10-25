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

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;

// inject here

void deb(vi X, string pref = "!") {
    cout << pref << " { ";
    for (auto e : X) 
        cout << e << " ";
    cout << " }\n";
}
