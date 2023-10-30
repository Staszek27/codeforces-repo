#include "global.cpp"


// inject here

const ll MOD = 998244353; // TODO
const ll MAX_SIL = 1e6 + 3; // TODO

ll mult(ll x, ll y) {
    return ((x % MOD) * (y % MOD)) % MOD;
}

ll add(ll x, ll y) {
    return ((x % MOD) + (y % MOD)) % MOD;
}

ll pow(ll x, ll y){
    if (y == 0) return 1LL;
    if (y % 2 == 1) return mult(pow(x, y - 1), x);
    return pow(mult(x, x), y >> 1);
}

ll inv(ll x){
    return pow(x, MOD - 2);
}

ll SIL[MAX_SIL];
ll sil(int x) {
    if (SIL[2] == 0){
        SIL[0] = 1;
        for (int i = 1; i < MAX_SIL; i ++){
            SIL[i] = mult(i, SIL[i - 1]);
        }
    }
    return SIL[x];
}

ll newton(ll x, ll y){
    if (x < y || y < 0) 
        return 0;
    return mult(
        sil(x), 
        inv(mult(sil(x - y), sil(y)))
    );
}

// inject stop

int main() {
    timer tim;
    tim.ok();
    return 0;
}
