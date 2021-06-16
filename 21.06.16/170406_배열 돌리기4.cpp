#include <bits/stdc++.h>
#define MAX 52
using namespace std;

struct Info { int x, y, cnt; };
int N, M, K;
int sx, sy, ex, ey;
int dir;
int answer = 987654321;
int arr[MAX][MAX], arr_copy[MAX][MAX];
int visited[MAX][MAX];
int dx[] = {0, 1, 0, -1}; 
int dy[] = {1, 0, -1, 0};
vector<Info> v;
vector<int> vIdx;

void input() {
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> arr[i][j];

    for(int i = 0; i < K; i++) {
        int c, r, s; 
        cin >> r >> c >> s;
        c--; r--;
        v.push_back({r, c, s});
        vIdx.push_back(i);
    }
}

vector<pair<int, int>> vv;
// 회전할 좌표찾기
void move(int x, int y, int first) {
    if(!first && x == sx && y == sy) dir++;
    if(!first && x == sx && y == ey) dir++;
    if(!first && x == ex && y == ey) dir++;
    if(!first && x == ex && y == sy) dir++;

    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(visited[nx][ny]) return;

    visited[nx][ny] = 1;
    vv.push_back({nx, ny});
    move(nx, ny, 0);
}

// 회전하기
void rotateAll(int x, int y, int cnt) {
    for(int i = 1; i <= cnt; i++) {
        sx = x - 1 * i; sy = y - 1 * i;
        ex = x + 1 * i; ey = y + 1 * i;
        // cout << sx << ' ' << sy << "\n";
        // cout << ex << ' ' << ey << "\n" << "\n";
        vv.clear();
        dir = 0;
        memset(visited, 0, sizeof(visited));
        visited[sx][sy] = 1;
        vv.push_back({sx, sy});
        move(sx, sy, 1);

        vector<int> vvv;
        for(auto c : vv) vvv.push_back(arr_copy[c.first][c.second]);
        rotate(vvv.begin(), vvv.begin() + vvv.size() - 1, vvv.end());
        for(int i = 0; i < vv.size(); i++) arr_copy[vv[i].first][vv[i].second] = vvv[i];
    }
}
// 2 3 2
// 1 2 / 3 4
// 0 1 / 4 5
int go() {
    for(auto i : vIdx) rotateAll(v[i].x, v[i].y, v[i].cnt);
    
    int ret = 987654321;
    for(int i = 0; i < N; i++) {
        int cnt = 0;
        for(int j = 0; j < M; j++) {
            cnt += arr_copy[i][j];
        }
        ret = min(ret, cnt);
    }
    return ret;
}

void pro() {
    // 경우의 수 구하기..
    do {
        for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) arr_copy[i][j] = arr[i][j];
        answer = min(answer, go());
    } while(next_permutation(vIdx.begin(), vIdx.end()));
    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    pro();
    return 0;
}
