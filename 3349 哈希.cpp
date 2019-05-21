#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <cmath>
#include <string>
#define fi first
#define se second
#define MAXN 99
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const int inf = 0x3f3f3f3f;
const int maxn = 100005; // maximum kinds of items

const int mod = 99983; // 1e5附近的一个大质数，用来对key取模得到index

int n;

vector<int> hash_table[maxn];
int a[maxn][6];

bool same(int l, int r) {
    for(int i = 0; i < 6; i++) {
        if((a[l][0] == a[r][i] && a[l][1] == a[r][(i+1)%6]
            && a[l][2] == a[r][(i+2)%6] && a[l][3] == a[r][(i+3)%6]
            && a[l][4] == a[r][(i+4)%6] && a[l][5] == a[r][(i+5)%6])
        || (a[l][0] == a[r][i] && a[l][1] == a[r][(i+5)%6]
            && a[l][2] == a[r][(i+4)%6] && a[l][3] == a[r][(i+3)%6]
            && a[l][4] == a[r][(i+2)%6] && a[l][5] == a[r][(i+1)%6]))
            return true;
    }
    return false;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 6; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    bool flag = 0;
    for(int i = 1; i <= n; i++) {
        int sum = 0;
        for(int j = 0; j < 6; j++) sum += a[i][j];
        int key = sum % mod;
        for(int j = 0; j < hash_table[key].size(); j++) {
            if(same(i, hash_table[key][j])) {
                cout << "Twin snowflakes found." << endl;
                flag = 1;
                break;
            }
        }
        hash_table[key].push_back(i);
    }
    if(!flag) cout << "No two snowflakes are alike." << endl;
    return 0;
}