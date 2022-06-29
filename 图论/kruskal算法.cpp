#include<iostream>
#include<algorithm>
#include<cstring>
#include<unordered_map>
#include<cmath> 
#include<vector> 
#define fi first
#define se second
#define ios ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int N = 200010;
int n,m;
int p[N];
struct Edge{
    int a,b,w;
    
    bool operator< (const Edge& W) const {
        return w < W.w;
    }
}edges[N];

int find(int x) {
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i ++) {
        int a,b,w;
        cin >> a >> b >> w;
        edges[i] = {a,b,w};
    }
    sort(edges,edges + m);
    for(int i = 1; i <= n; i ++) p[i] = i;
    int res = 0, cnt = 0;
    for(int i = 0; i < m; i ++) {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if(a != b) {
            res += w;
            cnt ++;
            p[a] = b;
        }
    }
    if(cnt != n - 1) puts("impossible");
    else cout << res << endl;
    
    return 0;
}
