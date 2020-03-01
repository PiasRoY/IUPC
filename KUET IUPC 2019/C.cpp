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

const ll mod = 1000000007;

ll power(ll b, ll p, ll mod) {
    if(p == 0) return 1;
    if(p%2==0) {
        ll ret = power(b, p/2, mod);
        return (ret*ret)%mod;
    }
    return (b*power(b, p-1, mod))%mod;
}

#define MX 100005
ll arr[MX];
ll tree[4*MX];

void build(ll pos, ll tl, ll tr) {
    if(tl == tr) {
        tree[pos] =  arr[tl];
        return;
    }

    ll mid = (tl+tr)/2;
    build(pos*2, tl, mid);
    build(pos*2+1, mid+1, tr);

    tree[pos] = tree[pos*2] | tree[pos*2+1];
}

ll query(ll pos, ll tl, ll tr, ll l, ll r)
{
    if(tl > r || tr < l) return 0;
    if(tl >= l && tr <= r) return tree[pos];

    ll mid = (tl+tr)/2;
    ll Lch = query(pos*2, tl, mid, l, r);
    ll Rch = query(pos*2+1, mid+1, tr, l, r);

    return (Lch | Rch);
}

int main()
{
    ll n, q, OR, ans, l, r;
    scanf("%lld %lld", &n, &q);

    for(ll i = 1; i <= n; i++) scanf("%lld", &arr[i]);

    build(1, 1, n);

    while(q--) {
        scanf("%lld %lld", &l, &r);

        OR = query(1, 1, n, l, r);

        ans = (OR * power(2, r-l, mod) ) % mod;

        printf("%lld\n", ans);
    }
}
