#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, answer;
vector<pair<int, int>> v;
bool visited[10001];

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first > b.first;
}

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int pay, day; cin >> pay >> day;
        v.push_back({pay, day});
    }
    sort(v.begin(), v.end(), compare);
}

void pro() {
    for(int i = 0; i < n; i++) {
        for(int j = v[i].second; j >= 1; j--) {
            if(visited[j] == false) { // 아직 선택하지 않았다면,
                visited[j] = true;
                answer += v[i].first;
                break;
            }
        } 
    }
    cout << answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    pro();
    return 0;
}