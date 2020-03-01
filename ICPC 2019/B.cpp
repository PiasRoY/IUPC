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

#define MX 10004
ll dp[MX], sm[MX][14], n, p, k;

void gen(ll n)
{
	for(ll i = 1; i <= n; i++) sm[i][0] = dp[i];

    for(ll j = 1; (1<<j) <= n; j++) {
		for(ll i = 1; (i+(1<<j)-1) <= n; i++) {
            sm[i][j] = sm[i][j-1] + sm[i+(1<<(j-1))][j-1];
			if(sm[i][j] > 1e17) sm[i][j] = inf;
		}
    }
}

ll query(ll l, ll r) {
	ll sum = 0;

	for(ll j = log2(r-l+1); j >= 0; j--) {
		if(l+(1<<j)-1 <= r) {
			sum += sm[l][j];
			if(sum > 1e17) sum = inf;

			l += (1<<j);
		}
	}

	return sum;
}


ll bn(ll l, ll r, ll kth) {
	ll rx = l, ry = r, mid, tmp;

	while(rx < ry) {
		mid = (rx+ry)>>1;

        tmp = query(l, mid);

        if(tmp < kth) rx = mid+1;
        else ry = mid;
	}

	return rx;
}

pll f(ll u, ll par, ll kth)
{
	if(kth == 0) return mk(par, u);

	ll x = bn(n-u+1, n-u+p+1, kth);

    if(x == n-u+p+1) return mk(-1, -1);
    else return f(n-x, u, kth-query(n-u+1, x-1)-1);
}

int main()
{
	int test;
	scanf("%d", &test);

	llu cm;
	pll ans;

	for(int t = 1; t <= test; t++) {
        scanf("%lld %lld %lld", &n, &p, &k);

        if(n < p) printf("Case %d: Invalid\n", t);
        else {
			for(ll i = 0; i <= n; i++) dp[i] = 1;

			cm = p;

			ll i;
			for(i = p; i <= n; i++) {
				if(cm > 1e17) dp[i] = inf;
				else {
					dp[i] += cm;
					cm = cm-dp[i-p]+dp[i];
					if(cm > 1e17) cm = inf;
				}
			}

			reverse(dp, dp+i);

			gen(n);

			ans = f(n, -1, k);

			if(ans.ff == -1) printf("Case %d: Invalid\n", t);
			else printf("Case %d: %lld %lld\n", t, ans.ff, ans.ss);
        }
	}
}

/*
3
64 10 8
10000 1000 1000000000
10000 1000 100000000000000000

ans: (57 56), (1000 0), (1000, 0)
*/
