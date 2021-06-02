/*
Proble : 학교 탐방하기
Comment : MST문제인 것 한번에 파악이 완료되었다.
          최대스패닝트리를 어떻게만들까라는 고민이.. 정렬!!
          우선순위 큐 이용하면 시간이 빨라질듯한...
*/
#include <iostream>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
int uf[1001];
struct node {
    int a, b, c;
};

vector<node> v;

bool compare1(const node &a, const node &b) {
    return a.c < b.c;
}
bool compare2(const node &a, const node &b) {
    return a.c > b.c;
}

int uf_find(int x) {
    return uf[x] == -1 ? x : uf[x] = uf_find(uf[x]);
}

bool uf_union(int x, int y) {
    int X = uf_find(x), Y = uf_find(y);
    if(X == Y) return false;
    uf[X] = Y;
    return true;
}

int go() {
    memset(uf, -1, sizeof(uf));

    int cnt = 0; int ret = 0;
    for(int i = 0; i < v.size(); i++) {
        if(uf_union(v[i].a , v[i].b)) {
            if(v[i].c == 0) ret ++;
            if(++cnt == N) break;
        }
    }
    return ret * ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i <= M; i++) {
        int a, b, c; cin >> a >> b >> c;
        v.push_back({a, b, c}); 
    }
    sort(v.begin(), v.end(), compare1);
    int answer  = go();

    sort(v.begin(), v.end(), compare2);
    answer -= go();
    cout << answer << "\n";
}