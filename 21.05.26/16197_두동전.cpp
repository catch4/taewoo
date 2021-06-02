#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char graph[21][21];
vector<pair<int, int> > coins;
int answer = 2e9;
void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if(graph[i][j] == 'o') coins.push_back({i, j});
        }
    }
}

bool isOk(int x, int y) {
    if(x < 0 || y < 0 || x >= n || y >= m) return true;
    return false;
}

void move(int x, int y, int xx, int yy, int cnt, int dir) {
    // 종료 조건
    if(answer < cnt) return;
    if(cnt > 10) return;

    int nx = x + dx[dir]; int ny = y + dy[dir];
    int nxx = xx + dx[dir]; int nyy = yy + dy[dir];

    // 동전 두개가 떨어진 경우, 필요없는 경우라서 넘기자...
    if(isOk(nx, ny) && isOk(nxx, nyy)) return;
    // 한 동전만 떨어진 경우 카운터를 정답으로 최신화하자
    else if((isOk(nx, ny) && !isOk(nxx, nyy)) || (!isOk(nx, ny) && isOk(nxx, nyy))) {
        answer = min(answer, cnt);
        return;
    }

    if(graph[nx][ny] == '#') {
        nx = x;
        ny = y;
    }
    if(graph[nxx][nyy] == '#') {
        nxx = xx;
        nyy = yy;
    }
    for(int i = 0; i < 4; i++) move(nx, ny, nxx, nyy, cnt + 1, i);
}

void pro() {
    for(int i = 0; i < 4; i++) {
        int x = coins[0].first; int y = coins[0].second;
        int xx = coins[1].first; int yy = coins[1].second;
        move(x, y, xx, yy, 1, i);
    }
    if(answer > 10) answer = -1;
    cout << answer << "\n";
}

int main() {
    input();
    pro();
}