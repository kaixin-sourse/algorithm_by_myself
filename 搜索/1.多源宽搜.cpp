#include <iostream>
#include <algorithm>
#include <cstring>
#define fi first
#define se second

using namespace std;

typedef pair<int,int> PII;

const int N = 1010, M = N * N;
char g[N][N];
int n,m;
int dis[N][N];
PII q[M];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
void bfs() {
    memset(dis,-1,sizeof dis);
    int hh = 0, tt = -1;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            if(g[i][j] == '1') {
                q[++tt] = {i, j};
                dis[i][j] = 0;
            }
    while(hh <= tt) {
        PII t = q[hh ++];
        for(int i = 0; i < 4; i ++) {
            int nx = t.fi + dx[i], ny = t.se + dy[i];
            if(nx < 0 || nx > n || ny < 0 || ny > m) continue;
            if(g[nx][ny] == '1') continue;
            if(dis[nx][ny] == -1) {
                dis[nx][ny] = dis[t.fi][t.se] + 1;
                q[++tt] = {nx, ny};
            }
        }
    }

}


int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i ++) cin >> g[i];
    bfs();
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++)
            cout << dis[i][j] << " ";
        puts("");
    }
    return 0;
}
