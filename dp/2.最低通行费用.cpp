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
const int N = 110, INF = 0x3f3f3f3f;
int w[N][N];
int f[N][N];
int T;
int n,m; 

int main() {
	ios;
	cin >> n;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			cin >> w[i][j];
	for(int i = 1; i <= n; i ++)
		for(int j = 1;j <= n; j ++)
			if(i == 1 && j == 1) f[i][j] = w[i][j];
			else {
				f[i][j] = INF;
				if(i > 1) f[i][j] = min(f[i][j],f[i - 1][j] + w[i][j]);
				if(j > 1) f[i][j] = min(f[i][j],f[i][j - 1] + w[i][j]);
			}
	cout << f[n][n] << endl;
	
	return 0;
} 
