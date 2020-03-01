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

int main()
{
    int test;
    scanf("%d", &test);

    ll total, sm, x;
    for(int t = 1; t <= test; t++) {
        scanf("%lld %lld", &total, &x);

        sm = 0;
        for(int i = 0; i < 7; i++) {
			scanf("%lld", &x);
			sm += x;
        }

        printf("Case %d: %lld\n", t, total-sm);
    }
}
