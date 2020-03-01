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
#define pll pair<ll, ll>
#define pii pair<int, int>

#define MX 30004
bool vis[MX];
int odd1, odd2;
int dist[MX], dsu[MX];
vector <pii> adj[MX];

void dfs(int u)
{
    vis[u] = true;

    if(adj[u].size()%2) {
        if(odd1 == -1) odd1 = u;
        else odd2 = u;
    }

    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i].ff;

        if(!vis[v]) {
            dfs(v);
        }
    }
}

void dfs(int u, int p, int cst)
{
    vis[u] = true;
    dsu[u] = p;
    dist[u] = cst;

    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i].ff, w = adj[u][i].ss;

        if(!vis[v]) {
            dfs(v, u, cst+w);
        }
    }
}

int fnd(int u)
{
    if(u == dsu[u]) return u;
    return dsu[u] = fnd(dsu[u]);
}

void reset(int n)
{
    for(int i = 1; i <= n; i++) {
        adj[i].clear();
        vis[i] = false;
    }
}

int main()
{
    int test;
    scanf("%d", &test);

    int n, e, u, v, w, x, y, q, ans, p1, p2;

    for(int t = 1; t <= test; t++) {
        scanf("%d %d", &n, &e);

        reset(n);
        for(int i = 0; i < e; i++) {
            scanf("%d %d %d", &u, &v, &w);
            adj[u].pb(mk(v, w));
            adj[v].pb(mk(u, w));
        }

        //making non-cyclic cyclic
        for(int i = 1; i <= n; i++) {
            if(!vis[i]) {
                odd1 = odd2 = -1;
                dfs(i);
                if(odd1 != -1 && odd2 != -1) {
                    adj[odd1].pb(mk(odd2, inf));
                    adj[odd2].pb(mk(odd1, inf));
                }
            }
        }

        for(int i = 1; i <= n; i++) vis[i] = false;

        for(int i = 1; i <= n; i++) {
            if(!vis[i]) {
                dfs(i, i, 0);
            }
        }

        printf("Case %d:\n", t);

        scanf("%d", &q);
        while(q--) {
            scanf("%d %d", &u, &v);

            p1 = fnd(u);
            p2 = fnd(v);

            if(p1 != p2) printf("-1\n");
            else {
                x = dist[u];
                y = dist[v];

                ans = abs(x-y);
                ans = min(ans, dist[adj[p1][1].ff]+adj[p1][1].ss-ans);

                printf("%d\n", ans);
            }
        }
    }
}
