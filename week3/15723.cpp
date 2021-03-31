#include<bits/stdc++.h>
using namespace std;

int n, m;
int u, v;
int graph[27][27];
// 입력받기
void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s; // a
        u = s[0] - 'a';
        cin >> s; // is
        cin >> s; // b
        v = s[0] - 'a';
        graph[u][v] = 1;
    }
}

// n단 논법을 이용하기 위한 플로이드 와샬 이용
void floyd() {
    for(int k = 0; k < 26; k++) {
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++) {
                if(graph[i][k] == 1 && graph[k][j] == 1)
                    graph[i][j] = 1;
            }
        }
    }
}

void pro() {
    floyd();
    // 논법이 성공되는지 확인하기
    cin >> m;
    for(int i = 0; i < m; i++) {
        string s;
        cin >> s;
        u = s[0] - 'a';
        cin >> s;
        cin >> s;
        v = s[0] - 'a';
        if(graph[u][v] == 1) {
            cout << 'T' << '\n';
        }
        else {
            cout << 'F' << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    pro();
    return 0;
}