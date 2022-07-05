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
const int N = 110;
int f[N][N];
int T;
int n,m; 

int main() {
	ios;
	cin >> T;
	while(T --) {
		cin >> n >> m;
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++) {
				int t;
				cin >> t;
				f[i][j] = max(f[i - 1][j],f[i][j - 1]) + t;
			}
		cout << f[n][m] << endl;
	}
	
	return 0;
} 
