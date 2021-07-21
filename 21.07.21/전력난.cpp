#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v, dist;
    edge(int u, int v, int dist) : u(u), v(v), dist(dist) {}
    bool operator < (const edge &e) const {
        if(dist == e.dist) return u < e.u;
        return dist < e.dist;
    }
};

int N, M, uf[200001];
vector<edge> Edges;

int uf_find(int x) {
    return (uf[x] == x ) ? x : uf[x] = uf_find(uf[x]);
}

void uf_union(int x, int y) {
    int px = uf_find(x);
    int py = uf_find(y);
    uf[py] = px;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(true) {
        int ans = 0, total = 0, cnt = 0;
        cin >> N >> M;
        if(N == 0) return 0;
        Edges.clear();

        for(int i = 0; i < N; i++) uf[i] = i;
        for(int i = 0; i < M; i++) {
            int u, v, dist;
            cin >> u >> v >> dist;
            total += dist;
            Edges.push_back(edge(u, v, dist));
        }
        sort(Edges.begin(), Edges.end());

        for(int i = 0; i < Edges.size(); i++) {
            edge e = Edges[i];
            
            if(uf_find(e.u) == uf_find(e.v)) continue;
            ans += e.dist;
            cnt++;
            uf_union(e.u, e.v);
            if(cnt == N - 1) break;
        }
        cout << total - ans << '\n';
    }
}
