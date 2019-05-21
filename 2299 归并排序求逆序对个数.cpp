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
const int maxn = 500005; // maximum kinds of items

int n;
ll a[maxn], t[maxn];
ll ans;

void mergeSort(int l, int r) {
    if(l >= r) return;
    int mid = (l+r) >> 1;
    mergeSort(l, mid);
    mergeSort(mid+1, r);
    int i = l, j = mid+1, cnt = l;
    while(i <= mid && j <= r) {
        if(a[i] < a[j]) t[cnt++] = a[i++]; // 在这里赋进去的是正序的
        else {
            ans += j - cnt; // 在这里赋的是逆序的，其在数组中的原位置与最终位置前移了几个单位就需交换几次，也就是有几个逆序对
            t[cnt++] = a[j++];
        }
    }
    while(i <= mid) t[cnt++] = a[i++];
    while(j <= r) t[cnt++] = a[j++];
    for(int i = l; i <= r; i++) a[i] = t[i];
}

int main() {
    while(~scanf("%d", &n) && n) {
        for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        ans = 0;
        mergeSort(1, n);
        // for(int i = 1; i <= n; i++) cout << a[i] << ' '; cout << endl;
        cout << ans << endl;
    }
    return 0;
}