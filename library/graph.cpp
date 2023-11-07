#include "global.cpp"

// inject here

struct Graph{
    int n, m;
    vvi G;

    void input(bool directed) {
        cin >> n >> m;
        G.resize(n + 1);
        for (int i = 0; i < m; i ++) {
            int x, y;
            cin >> x >> y;
            G[x].emplace_back(y);
            if (directed) G[y].emplace_back(x);
        }
    }

    Graph(bool directed, bool with_input = true) {
        if (with_input) input(directed);
    }
};

// stop here

int main(){
    timer().ok();
}