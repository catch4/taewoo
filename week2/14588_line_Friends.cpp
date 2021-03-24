#include<bits/stdc++.h>
using namespace std;

int n;
const int INF = 1e9;
int dist[300][300];
vector<pair<int, int>> v;
void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int left, right; cin >> left >> right;
        v.push_back({left, right});
    }
    fill(&dist[0][0], &dist[0][0] + 300 * 300, INF);
    for(int i = 0; i < 300; i++) dist[i][i] = 0;
}

bool find_friend(int x, int y) {
    if(v[x].second >= v[y].first && v[y].second >= v[x].first) return true;
    return false;
}

void update() {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void pro() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(find_friend(i, j)) {
                dist[i][j] = 1;
                dist[j][i] = 1;
            }
        }
    }
    update();

    int x; cin >> x;
    for(int i = 0; i < x; i++) {
        int a, b; cin >> a >> b;
        if(dist[a - 1][b - 1] == INF) cout << -1 << '\n';
        else cout << dist[a - 1][b - 1] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    pro();
    return 0;
}