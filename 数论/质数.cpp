#include<iostream>
#include<algorithm>
#include<cstring>
#define fi first
#define se second
#define rep(i,a,b) for(int i = (a); i < (b); i ++)
#define ios ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int N = 1000010;
int n;
int a[N],f[N];
int prime[N],cnt;
bool st[N];
// 判断质数 
bool is_prime(int n) {
	if(n < 2) return false;
	for(int i = 2; i <= n / i; i ++)
		if(n %i == 0)
			return false;
	return true;
}
//判断质因数 
void divide(int n) {
	for(int i = 2; i <= n / i; i ++) {	
		int s = 0;
		while(n % i == 0) {
			s ++;
			n /= i;
		}
		cout << i << " " << s << endl;
	}
	if(n > 1) cout << n << " " << 1 << endl;
}

//质数筛
void get_primes(int n) {
	for(int i = 2; i <= n; i ++) {
		if(!st[i]) {
			prime[cnt ++] = i;
			for(int j = i + i; j <= n; j += i)
				st[j] = true;
		}
	}
	/*for(int i = 0; i < cnt; i ++)
		cout << prime[i] << " ";
	cout << endl;*/
}

int main() {
	ios;
	cin >> n;
	get_primes(n);
	cout << cnt << endl;
	
	return 0;
}
