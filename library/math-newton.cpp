#include "global.cpp"


// inject here

struct Factorials{
    vi fac;
    ll n;

    Factorials(ll n) {
        this->n = n;
        fac.assign(n + 1, 0);
        fac[0] = 1;
        for (int i = 1; i <= n; i ++){
            fac[i] = mult((ll) i, fac[i - 1]);
        }
    }

    ll newton(ll x, ll y){
        if (x < y || y < 0) 
            return 0;
        return mult(
            fac[x], 
            inv(mult(fac[x - y], fac[y]))
        );
    }
}

// inject stop

int main() {
    timer tim;
    tim.ok();
    return 0;
}
