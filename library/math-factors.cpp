#include "global.cpp"


// inject here

struct Factors{
    vvi factors;
    ll n;

    Factors(ll n) {
        this->n = n;
        factors.resize(n + 1);

        for (ll i = 1; i <= n; i ++) {
            for (ll j = i; j <= n; j += i) {
                factors[j].emplace_back(i);
            }
        }
    }
};


// inject stop

int main() {
    timer tim;
    tim.ok();
    return 0;
}
