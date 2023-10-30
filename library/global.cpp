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
#include <sys/time.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;

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

    void ok(bool tests_exist = false) {
        if (!tests_exist) {
            empty_line();
        }
        cout << " [OK]";
        if (!tests_exist) {
            cout << " | no need for testing\n";
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