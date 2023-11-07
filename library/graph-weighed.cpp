#include "global.cpp"

// inject here


struct GraphWeighed{
    int n, m;
    vector<vl2> G;

    void input(bool directed) {
        cin >> n >> m;
        G.resize(n + 1);
        for (int i = 0; i < m; i ++) {
            int x, y;
            ll val;
            cin >> x >> y >> val;
            G[x].emplace_back(y, val);
            if (directed) G[y].emplace_back(x, val);
        }
    }

    GraphWeighed(bool directed, bool with_input = true) {
        if (with_input) input(directed);
    }
};

void dfs(int node) {
    
}


int main(){
    timer().ok();
}