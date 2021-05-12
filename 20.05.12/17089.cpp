#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int graph[4001][4001];
int cnt[4001];
int answer = 2e9;
int main() {

    cin >> N >> M;
    
    for(int i = 0 ; i < M; i++) {
        int x, y;
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
        cnt[x]++; cnt[y]++;
    }

    for(int i = 1; i < N + 1; i++) {
        for(int j = 1; j < i; j++) {
            if(graph[i][j]) { // A - B랑 친구이면,  
                for(int k = 1; k < j; k++) {

                    if(graph[i][k] && graph[j][k]) { // A - C 친구이고 B - C 친구이면
                        answer = min(answer, cnt[i] + cnt[j] + cnt[k] - 6);
                    }
                }
            }
        }
    }

    if(answer == 2e9) cout << -1;
    else cout << answer;
    
}