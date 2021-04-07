/*
Comment: 어려워서 검색을 통해 해결!
중위탐색을 하면 좌 -> 중 -> 우 순서로 방문하게 되는데, 이 방문 순서가 표로 만들었을 때의 인덱스이다. 즉, 행이된다.
어렵네요..
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int tree[10001][2];
vector<int> tree_height[10001];
int N, cnt = 1;
bool is_child[10001];

void inorder(int idx, int height) {
    if(tree[idx][0] != -1) inorder(tree[idx][0], height + 1);
    tree_height[height].push_back(cnt++);
    if(tree[idx][1] != -1) inorder(tree[idx][1], height + 1);
}

void input() {
    cin >> N;
    for(int i = 0 ; i < N; i++) {
        int x, y, z; cin >> x >> y >> z;
        tree[x][0] = y;
        tree[x][1] = z;
        is_child[y] = 1, is_child[z] = 1;
    }
}

void pro() {
    int root;
    for(int i = 1; i <= N; i++) {
        if(!is_child[i]) {
            root = i;
            break;
        }
    }

    inorder(root, 1);
    
    int answer = 0, answer_idx = 1;
    for(int i = 1; i < 10001; i++) {
        if(!tree_height[i].size()) break;
        sort(tree_height[i].begin(), tree_height[i].end());
        int tmp = tree_height[i].back() - tree_height[i].front();
        if(tmp > answer) {
            answer = tmp;
            answer_idx = i;
        }
    }
    cout << answer_idx << ' ' << answer + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    pro(); 
    return 0;
}