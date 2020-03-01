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


#define MX 100005
int A[MX], B[MX];

int main()
{
    int test;
    scanf("%d", &test);

    int n;
    for(int t = 1; t <= test; t++) {
		scanf("%d", &n);

		for(int i = 0; i < n; i++) scanf("%d", &A[i]);
		for(int i = 0; i < n; i++) scanf("%d", &B[i]);

		int i, j = 0;
        stack <int> st;
        for(i = 0; i < n; i++) {
            if(st.empty()) {
                for(; j < n; j++) {
                    if(A[j] == B[i]) {
						j++;
						break;
                    }
					st.push(A[j]);
                }
            }
            else if(st.top() == B[i]) st.pop();
            else {
				bool tf = false;
                for(; j < n; j++) {
                    if(A[j] == B[i]) {
                        j++;
                        tf = true;
                        break;
                    }
                    st.push(A[j]);
                }
                if(!tf) break;
            }
        }

        if(i == n) printf("Case %d: POSSIBLE\n", t);
        else printf("Case %d: IMPOSSIBLE\n", t);
    }
}
/*
4
1 2 3 4
3 4 2 1
*/
