#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<iostream>
#include<unordered_map>
#include<map>
#define x first
#define y second

using namespace std;
typedef pair<int,int> PII;
typedef pair<int,char> PIC;

const int N = 100010;
int n;
int a[N];

void quick_sort(int l,int r) {
    if(l >= r) return;
    int i = l - 1, j = r + 1;
    int x = a[l + r >> 1];
    while(i < j) {
        do i ++; while(a[i] < x);
        do j --; while(a[j] > x);
        if(i < j) swap(a[i],a[j]);
    }
    quick_sort(l,j);
    quick_sort(j + 1, r);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> a[i];
    quick_sort(0, n - 1);
    for(int i = 0; i < n; i ++) cout << a[i] << " ";
    cout << endl;
    return 0;
}
