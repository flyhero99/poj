#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <string>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 505;
// const int maxm = 1005;
const int inf = 0x3f3f3f3f;

struct Edge {
    int to, nxt;
} e[10005];

int n, m, num;
int tot; // 节点id
int cnt; // 缩点后点的个数
int head[maxn];
stack<int> st;
int in[maxn], out[maxn]; // 缩点后的入度和出度
int belong[maxn]; // 表示原图中的点属于缩点后的哪个点
int dfn[maxn]; // tarjan算法中用到，表示节点i出现的次序（时间戳）
int low[maxn]; // tarjan算法中用到，表示u或u的子树能追溯到的最早的栈中节点的编号（百度百科说法）/当前树中最小的<子树的根>（博客说法）
bool vis[maxn]; // 表示是否在栈中
// vector<vector<int> > vec; // 存储连通分量

void init() { // 用链式前向星记得init
    num = 0;
    cnt = 0;
    memset(head, -1, sizeof head);
}

void addEdge(int u, int v) {
    e[num].to = v;
    e[num].nxt = head[u];
    head[u] = num++;
}

void tarjan(int u) {
    dfn[u] = low[u] = ++tot;
    vis[u] = 1;
    st.push(u);
    for(int i = head[u]; ~i; i = e[i].nxt) {
        int v = e[i].to;
        if(!dfn[v]) { // dfn[i]==0表示未访问
            tarjan(v); // 继续向下dfs
            low[u] = min(low[u], low[v]); // 递归回来后比较谁是父亲/儿子（节点小的为父）
        }
        else if(vis[v]) { // 访问过并且在栈中
            low[u] = min(low[u], dfn[v]); // 直接比较父亲/儿子关系
        }
    }
    if(low[u] == dfn[u]) { // 当前节点是整个强连通分量子树中编号最小的根节点
        // vector<int> tmp;
        int x;
        ++cnt;
        while(1) {
            x = st.top(); st.pop();
            vis[x] = 0;
            // tmp.push_back(x);
            belong[x] = cnt;
            if(x == u) break;
        }
        // vec.push_back(tmp);
    }
    return;
}

void solve() {
    memset(dfn, 0, sizeof dfn);
    memset(low, 0, sizeof low);
    memset(vis, 0, sizeof vis);
    memset(in, 0, sizeof in);
    memset(out, 0, sizeof out);
    while(!st.empty()) st.pop();
    for(int i = 1; i <= n; i++) {
        if(!dfn[i]) tarjan(i);
    }
    // for(int i = 0; i < vec.size(); i++) {
    //     for(int j = 0; j < vec[i].size(); j++) cout << vec[i][j] <<' '; cout << endl;
    // }
    for(int u = 1; u <= n; u++) {
        for(int k = head[u]; ~k; k = e[k].nxt) {
            int v = e[k].to;
            if(belong[u] != belong[v]) { // 这条边属于缩点后的两个不同的点
                out[belong[u]]++;
                in[belong[v]]++;
            }
        }
    }
    int ans1 = 0, ans2 = 0;
    for(int i = 1; i <= cnt; i++) {
        if(in[i] == 0) ans1++;
        if(out[i] == 0) ans2++;
    }
    ans2 = max(ans1, ans2);
    if(cnt == 1) cout << 1 << endl << 0 << endl;
    else cout << ans1 << endl << ans2 << endl;
}

int main() {
    while(~scanf("%d", &n)) {
        init();
        int x;
        for(int i = 1; i <= n; i++) {
            while(~scanf("%d", &x) && x) addEdge(i, x);
        }
        solve();
    }
    return 0;
}