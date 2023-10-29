#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;

// inject here

struct point{
    double x, y;

    double dist(point other){
        double diff_x = other.x - x;
        double diff_y = other.y - y;
        return sqrt(diff_x * diff_x + diff_y * diff_y);
    }
};

// inject stop

int main() {
    cout << "[NOT TESTED]\n";
    return 0;
}