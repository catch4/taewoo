/*
Comment: ���۽ð��������� ������ �ϰ� �Ǹ�, ���� �ð��� ������ ���ǽ� ���� + 1
                                    ���� �ð��� �Ǹ� ���ǽ� ���� -1

!����ð����� ���۽ð��۰ų� ������ ���ǽ� ����
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