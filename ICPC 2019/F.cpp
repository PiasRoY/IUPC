/* Solution Idea: https://codeforces.com/blog/entry/69922?#comment-544748 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long llu;
#define filein freopen("input.txt", "r", stdin)
#define fileout freopen("output.txt", "w", stdout)
#define inf 1000000000000000018
#define ff first
#define ss second
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>

ll bigmod(ll b, ll p, ll m) {
	ll res = 1, x = b%m;
	while(p > 0) {
        if(p&1) res = (res*x)%m;
        x = (x*x)%m;
        p >>= 1;
	}
	return res;
}

#define MX 100005
const ll mod = 132021913;

ll f[MX], num[MX], mx;

ll g(ll d) {
    ll x_sm = 0, x2_sm = 0, ret;

    for(ll i = d; i <= mx; i+=d) {
        if(num[i]) {
            x_sm = ( x_sm + (i*num[i])%mod )%mod;
            x2_sm = (x2_sm + (i*i*num[i])%mod)%mod;
        }
    }
    ret = ((((x_sm*x_sm)%mod)-x2_sm+mod)%mod * bigmod(2, mod-2, mod)) % mod;
    return ret;
}

int main()
{
	int test;
	scanf("%d", &test);

	ll n, x, sm, ans;

	for(int t = 1; t <= test; t++) {
		scanf("%lld", &n);

		mx = 0;
		memset(num, 0, sizeof num);
		for(ll i = 0; i < n; i++) {
			scanf("%lld", &x);
			num[x]++;
			mx = max(mx, x);
		}

		ans = 0;
		for(ll d = mx; d >= 1; d--) {
			sm = 0;
			for(ll k = 2*d; k <= mx; k+=d) {
				sm = (sm+f[k])%mod;
			}

			f[d] = (g(d)-sm+mod)%mod;
			ans = (ans+(f[d]*bigmod(d, mod-2, mod))%mod)%mod;
		}

		printf("Case %d: %lld\n", t, ans);
	}
}