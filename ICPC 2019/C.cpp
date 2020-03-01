#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long llu;
#define filein freopen("input.txt", "r", stdin)
#define fileout freopen("output.txt", "w", stdout)
#define inf 1000000009
#define ff first
#define ss second
#define pb push_back
#define mk make_pair
#define pii pair<int, int>

ll arr[1003];

ll f(ll num, ll pos, ll m)
{
	if(pos == m) {
        set <ll> s;
        for(ll i = 0; i < m; i++) {
			s.insert(arr[i]);
        }
        if(s.size() == num) return 1;
        return 0;
	}

	ll ret = 0;
	for(ll i = 0; i < num; i++) {
        arr[pos] = i;
        ret += f(num, pos+1, m);
	}

	return ret;
}

const ll mod = 1000000007;
#define MX 10004
ll nCr[MX][MX];

ll gen()
{
	for(int i = 0; i < MX; i++) {
		for(int j = 0; j <= i; j++) {
            if(i == j) nCr[i][j] = 1;
            else nCr[i][j] = (nCr[i-1][j] + nCr[i-1][j-1]) % mod;
		}
	}
}

ll bigmod(ll b, ll p, ll m)
{
	if(p == 0) return 1;
	if(p%2 == 0) {
		ll ret = bigmod(b, p/2, m);
		return (ret*ret)%mod;
	}
	return (b*bigmod(b, p-1, m))%m;
}

ll solve(ll n, ll m)
{
	ll x = 0, y, ans;

	for(ll i = 1; i <= n; i++) {
        x = (x + (i*nCr[n][i]*f(i, 0, m))) % mod;
	}

	y = bigmod(bigmod(m, mod-2, mod), n, mod);

	ans = (x*y)%mod;

	cout<<x<<" ";
	if(x%n==0) cout<<(x/n)<<endl;
	else cout<<-1<<endl;;

//	cout<<x<<" "<<y<<endl;
//	cout<<ans<<endl;
}

int main()
{
	gen();

	ll n, m;

	while(cin>>n>>m) {

		for(int i = 1; i <= 20; i++) {
			solve(n, i);
		}cout<<endl;

	}

}

/*

*/
