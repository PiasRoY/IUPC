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

int main()
{
	ll a, n, mx;
	scanf("%lld %lld", &a, &n);

	mx = abs(__gcd(a, 0ll));
	for(ll b = 1; b <= n; b++) {
        mx = max(mx, abs(__gcd(a, b)));
	}

	printf("%lld\n", mx);
}
