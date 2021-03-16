#include <bits/stdc++.h>
using namespace std;

string s;
int n;
int graph[51][51];
int visited[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < n; j++) {
            graph[i][j] = s[j] - '0';
        }
    }
}

int bfs(int x, int y) {
    memset(visited, -1, sizeof(visited));
    q.push({0, 0});
    visited[x][y] = 0;

    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int X = p.first + dx[i];
            int Y = p.second + dy[i];

            if(X < 0 || X == n || Y < 0 || Y == n) continue;
            if(graph[X][Y] == 1) {
                if(visited[X][Y] == -1 || visited[X][Y] > visited[p.first][p.second]) {
                    visited[X][Y] = visited[p.first][p.second];
                    q.push({X, Y});
                }
            }
            else {
                if(visited[X][Y] == -1 || visited[X][Y] > visited[p.first][p.second] + 1) {
                    visited[X][Y] = visited[p.first][p.second] + 1;
                    q.push({X, Y});
                }
            }
        }
    }
    return visited[n - 1][n - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    cout << bfs(0, 0);
}