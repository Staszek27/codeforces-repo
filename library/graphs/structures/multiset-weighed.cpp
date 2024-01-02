#include "/Users/michal/Documents/codeforces/codeforces-repo/library/global.cpp"

// inject here


struct Graph{
    ll n, m;
    vector<msi2> G;
    bool directed;

    void add_edge(ll x, ll y, ll w) {
        G[x].insert({y, w});
        if (!directed) 
            G[y].insert({x, w});
    }

    Graph(bool directed) {
        this->directed = directed;
        cin >> n >> m;
        G.resize(n + 1);
        for (ll i = 0; i < m; i ++) {
            ll x, y, w;
            cin >> x >> y >> w;
            add_edge(x, y, w);
        }
    }

    bool delete_edge(ll x, ll y, ll w) {
        for (int o = 0; o < 1 + !directed; o ++) {
            ti2 p = {y, w};
            auto it = G[x].lower_bound(p);
            if (it == G[x].end()) return false;
            if (*it != p) return false; 
            G[x].erase(it);
            swap(x, y);
        }
        return true;
    }

    vi3 edges(bool double_edges = false) {
        vi3 res;
        for (int i = 0; i <= n; i ++) {
            for (auto [neib, val] : G[i]) {
                if (i <= neib || double_edges)
                    res.emplace_back(i, neib, val);
            }
        }
        return res;
    }

    const msi2& operator[](int node) {
        return G[node];
    }

    void debug() {
        cout << "-------------------\n";
        cout << "Graph " << n << " nodes & " << m << " edges\n";
        for (ll i = 1; i <= n; i ++) {
            cout << i << ": { ";
            for (auto [x, y] : G[i]) {
                cout << x << "(" <<  y << ") ";
            }
            cout << " }\n";
        }
        cout << "-------------------\n";
    }
};

// inject stop

int main(){
    timer t;
    t.ok(false, "https://codeforces.com/contest/449/submission/232664299");
}