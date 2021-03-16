#include <bits/stdc++.h>
using namespace std;


string s;
const int INF = 1e9;
int n;
int graph[51][51];
int length[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct edge {
    int x;
    int y;
    int dist;

    bool operator < (const edge &e) const&{
        return dist < e.dist;
    }
};

priority_queue<edge> pq;

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < n; j++) {
            graph[i][j] = s[j] - '0';
            length[i][j] = INF;
        }
    }
}

int find_dist(int x, int y) {
    length[x][y] = 0;
    pq.push({x, y, 0});

    while(!pq.empty()) {
        edge e = pq.top();
        pq.pop();
        if(e.dist > length[e.x][e.y]) continue;

        for(int i = 0; i < 4; i++) {
            int nx = e.x + dx[i];
            int ny = e.y + dy[i];
            if(nx < 0 || nx == n || ny < 0 || ny == n) continue;
            
            if(graph[nx][ny] == 0 && length[nx][ny] > e.dist + 1) {
                length[nx][ny] = e.dist + 1;
                pq.push({nx, ny, length[nx][ny]});
            }
            if(graph[nx][ny] == 1 && length[nx][ny] > e.dist) {
                length[nx][ny] = e.dist;
                pq.push({nx, ny, length[nx][ny]});
            }
        }
    }
    return length[n - 1][n - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    cout << find_dist(0, 0);
}