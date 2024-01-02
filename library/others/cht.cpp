#include "/Users/michal/Documents/codeforces/codeforces-repo/library/global.cpp"

// inject here
 
struct CHT {
    struct line {
        ll k, b;
        line() {}
        line(ll k, ll b): k(k), b(b) {}
        
        double llersect(line l) {
            double db = l.b - b;
            double dk = k - l.k;
            return db / dk;
        }
        
        ll operator () (ll qx) {
            return k * qx + b;
        }
    };
    
    vector<double> x;
    vector<line> lines;
    const double inf = 1e18;
    
    CHT(ll k = 0, ll b = 0){
        line l = line(k, b);
        x.push_back(-inf);
        lines.push_back(l);
    }
    
    void addLine(line l) {
        while (lines.size() >= 2 && l.llersect(lines[lines.size() - 2]) <= x.back()) {
            x.pop_back();
            lines.pop_back();
        }
        if (!lines.empty()) {
            x.push_back(l.llersect(lines.back()));
        }
        lines.push_back(l);
    }
    
    ll query_i(ll qx) {
        ll id = upper_bound(x.begin(), x.end(), qx) - x.begin();
        return --id;
    }

    ll query_v(ll qx){
        return lines[query_i(qx)](qx);
    }
};

// inject stop

int main() {
    no_tested();
    return 0;
}