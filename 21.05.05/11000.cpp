/*
Comment: 시작시간기준으로 정렬을 하게 되면, 시작 시간이 들어오면 강의실 개수 + 1
                                    종료 시간이 되면 강의실 개수 -1

!종료시간기준 시작시간작거나 같으면 강의실 증가
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> vec;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    int N, S, T;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> S >> T;
        vec.push_back({S, T});
    }
    sort(vec.begin(), vec.end());
    pq.push(vec[0].second);

    for(int i = 1; i < N; i++) {
        if(pq.top() > vec[i].first) {
            pq.push(vec[i].second);
        }
        else {
            pq.pop();
            pq.push(vec[i].second);
        }
    }
    cout << pq.size() << "\n";
    return 0;
}