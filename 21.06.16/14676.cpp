#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int N, M, K;
vector<int> graph[MAX];
int in[MAX];
int building[MAX];
void input() {
    cin >> N >> M >> K;
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        in[v]++;
    }
}

void pro() {
    // 1 a (a번 건물을 1개 건설)
    // 2 a (a번 건물을 1개 파괴)
    bool flag = true;
    for(int i = 0; i < K; i++) {
        int oper, a;
        cin >> oper >> a;
        if(oper == 1) {
            if(in[a] == 0) {
                building[a]++;
                if(building[a] == 1) {
                    for(int j = 0; j < graph[a].size(); j++) in[graph[a][j]]--;
                }
            }
            else flag = false;
        }
        else {
            if(building[a] > 0) {
                building[a]--;
                if(building[a] == 0) {
                    for(int j = 0; j < graph[a].size(); j++) in[graph[a][j]]++;
                }
            }
            else flag = false;
        }
    }

    if(flag) cout << "King-God-Emperor" << "\n";
    else cout << "Lier!" << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    pro();
    return 0;
}