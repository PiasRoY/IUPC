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

#define MX 20004
ll sz[MX];
bool vis[MX];
vector <pll> adj[MX];
vector <pair<pll, ll> > edges;

ll dfs(ll u) {
	vis[u] = 1;

	sz[u] = 1;
	for(ll i = 0; i < adj[u].size(); i++) {
		ll v = adj[u][i].ff, w = adj[u][i].ss;

		if(!vis[v]) {
			edges.pb(mk(mk(u, v), w));
            sz[u] += dfs(v);
		}
	}

	return sz[u];
}

void reset(ll n) {
	for(ll i = 1; i <= n; i++) {
		edges.clear();
		adj[i].clear();
		vis[i] = false;
	}
}

int main()
{
	int test;
	scanf("%d", &test);

	ll n, u, v, w, x, y,  sm, ans;
	vector <pll> neg;

	for(int t = 1; t <= test; t++) {
		scanf("%lld", &n);

		reset(n);
		for(ll i = 1; i < n; i++) {
			scanf("%lld %lld %lld", &u, &v, &w);
			adj[u].pb(mk(v, w));
			adj[v].pb(mk(u, w));
		}

        dfs(1);

        sm = 0;
		neg.clear();
        for(ll i = 0; i+1 < n; i++) {
            u = edges[i].ff.ff, v = edges[i].ff.ss, w = edges[i].ss;
            sm += w*(sz[v]*(n-sz[v]));

            if(w < 0) neg.pb(mk(sz[v]*(n-sz[v]), -w));
        }

        if(sm >= 0) printf("Case %d: 0\n", t);
        else {
            sort(neg.rbegin(), neg.rend());

            ans = 0;
            for(ll i = 0; i < neg.size(); i++) {
                x = neg[i].ff, y = neg[i].ss;

                if(sm + (x*y) < 0) sm += x*y, ans += y;
                else {
					ans += (-sm+x-1)/x;
					break;
                }
            }

            printf("Case %d: %lld\n", t, ans);
        }
	}
}
