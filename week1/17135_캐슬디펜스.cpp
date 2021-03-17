#include<bits/stdc++.h>
using namespace std;

int N, M, D;
int arr[15][15];
vector<pair<int, int>> enemy;
void input() {
    cin >> N >> M >> D;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1) {
                enemy.push_back({i, j});
            }
        }
    }
}

void pro() {
    int result = 0; // 최대 죽일 수 있는 적 저장
    vector<int> archer;
    for(int i = 0; i < 2; i++) archer.push_back(0);
    for(int i = 2; i < M; i++) archer.push_back(1);

    do {
        int cnt = 0;
        // cout << '\n' << "경우의 수" << '\n';
        vector<pair<int,int>> copy = enemy;
        vector<int> v;
        for(int i = 0; i < archer.size(); i++) {
            if(archer[i] == 1) {
                v.push_back(i);
            }
        }

        while(!copy.empty()) {
            
            vector<int> attack;
            for(int i = 0; i < v.size(); i++) {
                int x = v[i]; // 궁수 좌표
                
                // cout << "궁수 좌표 : " << v[i] << " 적 좌표 : " << copy[0].first << ' ' <<copy[0].second << '\n';
                
                int enemy_x = copy[0].second;
                int dist = abs(N - copy[0].first) + abs(x - copy[0].second);
                for(int j = 0; j < copy.size(); j++) {
                    int len = abs(N - copy[j].first) + abs(x - copy[j].second);
                    
                    // 거리가 가까운 적 찾기
                    if(dist > len) {
                        dist = len;
                        enemy_x = copy[j].second;
                    }

                    // 거리가 같은게 여러개면 가장 왼쪽
                    else if(dist == len && enemy_x > copy[j].second) {
                        enemy_x = copy[j].second;
                    }
                    // cout << "거리 : " << dist << '\n';
                    // 거리가 가까운 거리가 여러명이면, 그 중 가장 왼쪽
                }
                if(dist <= D) {
                    // 이러면 적을 죽일 수있다.
                    attack.push_back(enemy_x);
                }

                    // 적과의 거리(dist)가 D이내에 잇다면 죽일 수있다.

                attack.erase(unique(attack.begin(), attack.end()), attack.end());
                sort(attack.begin(), attack.end());
                // for(auto i : attack) cout << i << ' ';
                // cout << '\n';

                int shot = 0;
                for(int i = 0; i < copy.size(); i++) {
                    copy.erase(copy.begin() + (attack[i] - shot++));
                    cnt++;
                }

                if(copy.empty()) {
                    break;
                }

                // 적 내리기
                vector<pair<int, int>> copy2;
                for(int i = 0; i < copy.size(); i++) {
                    if(copy[i].first < N - 1) {
                        copy2.push_back({copy[i].first + 1, copy[i].second});
                    }
                }
                copy = copy2;
            }
        }
        result = max(result, cnt);
    } while(next_permutation(archer.begin(), archer.end()));
    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    pro();
    return 0;
}