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


int main()
{
    int test;
    scanf("%d", &test);

    ll n, x, ans;
    vector <ll> v;

    for(int t = 1; t <= test; t++) {
		scanf("%lld", &n);

		v.clear();
		for(int i = 0; i < n; i++) {
			scanf("%lld", &x);
			v.pb(x);
		}

		sort(v.begin(), v.end());

		ans = v[0] * v[n-1];

		printf("Case %d: %lld\n", t, ans);
    }
}
