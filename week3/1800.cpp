/*
Comment : 다익스트라의 경로의 거리를 역추적해서 비싼 k개를 무료로해서 출력 -> 너무 느리다는걸 깨달음에...
        : 인터넷의 도움을 통하여.. 이분탐색을 통해 최단경로의 값을 미리 정함.
          미리 정한 값보다 큰 값은 k개보다 크면 안된다...
*/

#include<bits/stdc++.h>
using namespace std;

struct edge {
    int to, dist;
    bool operator < (const edge &e) const& {
        return dist > e.dist;
    }
};

vector<edge> graph[1002];
int dist[1002], path[1002];
int n, p, k;
int max_cost = 0;
const int INF = 1e9;
void input() {
    cin >> n >> p >> k;
    fill(path, path + 1002, -1);
    for(int i = 0; i < p; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        graph[u].push_back({v, cost});
        graph[v].push_back({u, cost});
        max_cost = max(max_cost, cost);
    }
}

bool isOk(int mid) {
    priority_queue<edge> pq;
    fill(dist, dist+1002, INF);

    dist[1] = 0;
    pq.push({1, 0});

    while(!pq.empty()) {
        edge e = pq.top();
        pq.pop();
        if(dist[e.to] < e.dist) continue;

        for(edge next: graph[e.to]) {
            if(dist[next.to] > dist[e.to] + (mid < next.dist)) {
                dist[next.to] = dist[e.to] + (mid < next.dist);
                path[next.to] = e.to;
                pq.push({next.to, dist[next.to]});
            }
        }
    }
    return dist[n] <= k; // mid보다 큰 간선은 k개 이하;
}

void pro() {
    int answer = -1;
    int left = 0, right = max_cost;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(isOk(mid)) {
            answer = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    pro();
    return 0;
}