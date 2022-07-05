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
const int N = 15, INF = 0x3f3f3f3f;
int w[N][N];
int f[2 * N][N][N];
int T;
int n,m; 

int main() {
	ios;
	cin >> n;
	int a,b,c;
	while(cin >> a >> b >> c, a && b && c) {
		w[a][b] = c;
	}
	for(int k = 2; k <= 2 * n; k ++)
		for(int i1 = 1; i1 <= n; i1 ++)
			for(int i2 = 1; i2 <= n; i2 ++) {
				int j1 = k - i1, j2 = k - i2;
				if(j1 < 1 || j1 > n || j2 < 1 || j2 > n) continue;
				int&x = f[k][i1][i2];
				int t = w[i1][j1];
				if(i1 != i2) t += w[i2][j2];
				x = max(x,f[k - 1][i1 - 1][i2] + t);
				x = max(x,f[k - 1][i1][i2 - 1] + t);
				x = max(x,f[k - 1][i1 - 1][i2 - 1] + t);
				x = max(x,f[k - 1][i1][i2] + t);
			}
	cout << f[2 * n][n][n] << endl;
	
	return 0;
} 
