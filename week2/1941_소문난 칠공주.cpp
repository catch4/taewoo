#include<bits/stdc++.h>
using namespace std;

int _map[5][5];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int answer = 0;
string s;
vector<int> candid;
void input(){
    for(int i = 0; i < 5; i++) {
        cin >> s;
        for(int j = 0; j < 5; j++) {
            _map[i][j] = s[j];
        }
    }
}

int visited[5][5];
int checked[5][5];
bool isAdj(){
    queue<pair<int, int>> q;
    memset(visited, 0, sizeof(visited));
    memset(checked, 0, sizeof(checked));
    for(int i = 0; i < candid.size(); i++) {
        int x = candid[i] / 5;
        int y = candid[i] % 5;
        checked[x][y] = 1;
        if(i == 0) {
            q.push({x, y});
            visited[x][y] = 1;
        }
    }
    
    // adj확인하기
    int count = 1;
    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int x = p.first + dx[i];
            int y = p.second + dy[i];
            if(x < 0 || x == 5 || y < 0 || y == 5) continue;
            if(checked[x][y] == 0 || visited[x][y]) continue;
            count++;
            visited[x][y] = 1;
            q.push({x, y});
        }
    }

    if(count == 7) return true;
    else return false;
}

bool find_four(){
    int count = 0;
    for(int i = 0; i < candid.size(); i++) {
        int x = candid[i] / 5;
        int y = candid[i] % 5;
        if(_map[x][y] == 'S') {
            count++;
        }
    }
    if(count >= 4) return true;
    else return false;
}

void selected(){
    if(candid.size() == 7) {
        if(find_four() == true) {
            if(isAdj() == true) answer++;
        }
        return;
    }

    int back = candid.empty() ? -1 : candid.back();

    for(int i = back + 1; i < 25; i++) {
        candid.push_back(i);
        selected();
        candid.pop_back();
    }
}

void pro() {
    selected();
    cout << answer;    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    pro();
    return 0;
}