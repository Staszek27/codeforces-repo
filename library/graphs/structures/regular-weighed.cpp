#include "/Users/michal/Documents/codeforces/codeforces-repo/library/global.cpp"

// inject here

struct Graph{
    ll n, m;
    vector<vi2> G;
    bool directed;

    void add_edge(ll x, ll y, ll w) {
        G[x].emplace_back(y, w);
        if (!directed) 
            G[y].emplace_back(x, w);
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

    vi3 get_edges(bool double_edges = false) {
        vi3 res;
        for (int i = 1; i <= n; i ++)
            for (auto [e, val] : G[i])
                if (i <= e || double_edges)
                    res.emplace_back(i, e, val);
        return res;
    }

    const vi2& operator[](int node) {
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
    no_tested();
}