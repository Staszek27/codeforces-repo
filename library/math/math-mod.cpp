#include "/Users/michal/Documents/codeforces/codeforces-repo/library/global.cpp"


// inject here

const ll mod = 998244353;

ll gcd(ll x, ll y) {
    return y == 0 ? x : gcd(y, x % y);
}

ll norm(ll x) {
    return (x + mod) % mod;
}

ll mult(ll x, ll y) {
    return (norm(x) * norm(y)) % mod;
}

ll add(ll x, ll y) {
    return (norm(x) + norm(y)) % mod;
}

ll pow(ll x, ll y){
    if (y == 0) return 1LL;
    if (y % 2 == 1) return mult(pow(x, y - 1), x);
    return pow(mult(x, x), y >> 1);
}

ll inv(ll x){
    return pow(x, mod - 2);
}

ll divv(ll x, ll y) {
    return mult(x, inv(y));
}

// inject stop

int main() {
    timer tim;
    tim.ok();
    return 0;
}
