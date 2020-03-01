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

#define MX 50004
ll A[MX], B[MX];
ll n, dp1[MX][15], dp2[MX][15], maxi[MX];

ll dfs0(ll pos, ll k) {
    ll &ret = dp1[pos][k];
	if(ret != -1) return ret;

	ret = 0;
	for(ll i = pos+1; i <= min(n-1, pos+k+1); i++) {
		if(A[i] <= A[pos]) {
			ret = max(ret, dfs0(i, k-(i-pos-1)));
		}
	}

	return ret += 1;
}

ll dfs1(ll pos, ll k) {
    ll &ret = dp2[pos][k];
	if(ret != -1) return ret;

	ret = 0;
	for(ll i = pos+1; i <= min(n-1, pos+k+1); i++) {
		if(B[i] >= B[pos]) {
			ret = max(ret, dfs1(i, k-(i-pos-1)));
		}
	}

	return ret += 1;
}

void reset() {
	for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < 15; j++) {
            dp1[i][j] = -1;
            dp2[i][j] = -1;
        }
	}
}

int main()
{
	int test;
    scanf("%d", &test);

    vector <pll> v1, v2;
    ll k, La, Lb, x, mx;

    for(int t = 1; t <= test; t++) {
        scanf("%lld %lld", &n, &k);

        for(ll i = n-1; i >= 0; i--) scanf("%lld", &A[i]);
        for(ll i = 0; i < n; i++) scanf("%lld", &B[i]);

        reset();

        La = Lb = 0;
        for(ll i = 0; i < n; i++) {
            La = max(La, dfs0(i, k));
            Lb = max(Lb, dfs1(i, k));
        }

		//merging two array
		v1.clear(), v2.clear();
        for(int i = 0; i < n; i++) {
            v1.pb(mk(A[i], dp1[i][k]));
            v2.pb(mk(B[i], dp2[i][k]));
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        maxi[n-1] = v2[n-1].ss;
        for(int i = n-2; i >=0; i--) {
			maxi[i] = max(maxi[i+1], v2[i].ss);
        }

        mx = max(La, Lb);
        for(int i = 0, j = 0; i < n;) {
            if(v2[j].ff >= v1[i].ff) {
                mx = max(mx, v1[i].ss + v2[j].ss);
                i++;
            }
            else j++;
        }

        printf("Case %d: %lld\n", t, mx);
    }
}
