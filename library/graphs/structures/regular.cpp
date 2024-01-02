#include "/Users/michal/Documents/codeforces/codeforces-repo/library/global.cpp"

// inject here

struct Graph{
    ll n, m;
    vvi G;
    bool directed;

    void add_edge(ll x, ll y) {
        G[x].emplace_back(y);
        if (!directed) 
            G[y].emplace_back(x);
    }

    Graph(bool directed) {
        this->directed = directed;
        cin >> n >> m;
        G.resize(n + 1);
        for (ll i = 0; i < m; i ++) {
            ll x, y;
            cin >> x >> y;
            add_edge(x, y);
        }
    }

    vi2 get_edges(bool double_edges = false) {
        vi2 res;
        for (int i = 1; i <= n; i ++)
            for (auto e : G[i])
                if (i <= e || double_edges)
                    res.emplace_back(i, e);
        return res;
    }

    const vi& operator[](int node) {
        return G[node];
    }
    
    void debug() {
        cout << "-------------------\n";
        cout << "Graph " << n << " nodes & " << m << " edges\n";
        for (ll i = 1; i <= n; i ++) {
            cout << i << ": { ";
            for (auto x : G[i]) {
                cout << x << " ";
            }
            cout << " }\n";
        }
        cout << "-------------------\n";
    }
};

// inject stop

int main(){
    no_tested();
}