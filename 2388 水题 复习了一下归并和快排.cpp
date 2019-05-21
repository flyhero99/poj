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
const int maxn = 10005; // maximum kinds of items

int n;

void quick_sort(int *a, int left, int right) {
    // cout << "left: " << left << " right: " << right << endl;
    if(left > right) return;
    int i = left, j = right, pivot = a[left];
    while(i < j) {
        while(i < j && a[j] >= pivot) j--; // find an element smaller than the pivot from the right
        while(i < j && a[i] <= pivot) i++; // find an element greater than the pivot from the left
        if(i < j) swap(a[i], a[j]); // avoid the circumstance that i==j
    }
    // i is already equal to j
    a[left] = a[i];
    a[i] = pivot;
    // cout << "After sorting: ";
    // for(int i = 1; i <= n; i++) cout << a[i] << ' '; cout << endl;
    quick_sort(a, left, i-1);
    quick_sort(a, i+1, right);
}

void mergeSort(int *a, int *t, int l, int r) {
    if(l >= r) return;
    int mid = (l+r) >> 1;
    mergeSort(a, t, l, mid);
    mergeSort(a, t, mid+1, r);
    int i = l, j = mid+1, cnt = 0;
    while(i <= mid && j <= r) {
        if(a[i] < a[j]) t[cnt++] = a[i++];
        else t[cnt++] = a[j++];
    }
    while(i <= mid) t[cnt++] = a[i++];
    while(j <= r) t[cnt++] = a[j++];
    for(int i = l; i <= r; i++) a[i] = t[i-l];
}

int main() {
    while(~scanf("%d", &n) && n) {
        int a[n+1], t[n+1];
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        mergeSort(a, t, 1, n);
        cout << a[(n+1)/2] << endl;
    }
    return 0;
}