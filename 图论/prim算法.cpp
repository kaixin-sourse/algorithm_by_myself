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
const int N = 510, INF = 0x3f3f3f3f;
int g[N][N];
int dis[N];
bool st[N];
int n,m;

int prim() {
    memset(dis,0x3f,sizeof dis);
    int res = 0;
    for(int i = 0; i < n; i ++) {
        int t = -1;
        for(int j = 1; j <= n; j ++) {
            if(!st[j] && (t == -1 || dis[t] > dis[j]))
                t = j;
        }
        if(i && dis[t] == INF) return INF;
        if(i) res += dis[t]; //一定要先更新res，避免被负自环影响，更新dis【t】
        st[t] = true; //或者直接在输入的时候舍弃自环，因为最小生成树一共只有n-1条边
        for(int j = 1; j <= n; j ++) { // 不可能包含自环
            dis[j] = min(dis[j],g[t][j]);
        }
    }
    return res;
}

int main() {
    cin >> n >> m;
    memset(g,0x3f,sizeof g);
    while(m --) {
        int a,b,c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b],c);
    }
    int t = prim();
    if(t == INF) cout << "impossible" << endl;
    else cout << t << endl;
    return 0;
}
