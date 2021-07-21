#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int graph[16][16], visited[16][16][3], N;

int cal(int x, int y, int prev) {
    if(x == N-1 && y == N-1) return 1;
    if(visited[x][y][prev] != -1) return visited[x][y][prev];
    int &ret = visited[x][y][prev];
    ret = 0;
    if(prev != 1 && y != N-1 && !graph[x][y + 1]) {
        ret += cal(x, y + 1, 0);
    }
    if(prev != 0 && x != N-1 && !graph[x + 1][y]) {
        ret += cal(x + 1, y, 1);
    }
    if(x != N-1 && y != N-1 && !graph[x + 1][y] && !graph[x][y + 1] && !graph[x+1][y+1]) {
        ret += cal(x + 1, y + 1, 2);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> graph[i][j];
            for(int k = 0; k < 3; k++) visited[i][j][k] = -1;
        }
    }
    cout << cal(0, 1, 0);
    return 0;
}
