#include <bits/stdc++.h>
using namespace std;

//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//template <typename T> using orderSet =
//tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef unsigned long long llu;
#define filein freopen("input.txt", "r", stdin)
#define fileout freopen("output.txt", "w", stdout)
#define inf 1000000000000000018
#define mod 1000000007
#define ff first
#define ss second
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>

#define MX 1050006
ll cnt[MX], dp[MX][21], F[MX];
vector <ll> masks[MX];
vector <pll> v;

void SOS(ll n)
{
	for(ll mask = 0; mask < (1<<n); mask++) {
		dp[mask][0] = cnt[mask];

		for(ll i = 1; i <= n; i++) {
			if(mask & (1<<(i-1)))
				dp[mask][i] = dp[mask][i-1] + dp[mask^(1<<(i-1))][i-1];
			else
				dp[mask][i] = dp[mask][i-1];
		}

		F[mask] = dp[mask][n];

		//sorting 'masks' vector
		if(cnt[mask] > 0)
			sort(masks[mask].begin(), masks[mask].end());
	}
}

int main()
{
	int test;
	scanf("%d", &test);

	string str;
	ll n, m, x, time, mask;

	for(int t = 1; t <= test; t++) {
        scanf("%lld %lld", &n, &m);

        for(int i = 0; i < n; i++) {
			cin>>str>>time;

			mask = 0;
			if(str[0] == '?') {
                for(int j = 1; j < str.size(); j++) {
                    x = str[j]-'A';
                    mask |= (1<<x);
                }
			}
			else {
				for(int j = 1; j < str.size(); j++) {
                    x = str[j]-'A';
                    mask |= (1<<x);
				}
                mask = mask ^ ((1<<(m))-1);
			}

			v.pb(mk(mask, time));
            masks[mask].pb(time);
            cnt[mask]++;
        }

		SOS(m);

		printf("Case %d:", t);
        for(int i = 0; i < n; i++) {
            x = lower_bound(masks[v[i].ff].begin(), masks[v[i].ff].end(), v[i].ss) - masks[v[i].ff].begin();

            x = F[v[i].ff] - cnt[v[i].ff] + x + 1;

            printf(" %lld", x);
        }
        printf("\n");


		//clearing purpose
        for(auto a : v) {
            masks[a.ff].clear();
            cnt[a.ff] = 0;
        }
        v.clear();
	}
}
