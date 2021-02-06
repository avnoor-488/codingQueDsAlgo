
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 100005, M = 22;
#define int long long int
vector<int>  gr[N];
vector<int> art_p;
vector<pair<int, int>> bridge;
int disc[N], low[N], tme;


void dfs(int cur, int par) {
	disc[cur] = low[cur] = tme++;
	for (auto child : gr[cur]) {
		//not visited
		if (disc[child]) {
			dfs(child, cur);
			low[cur] = min(low[cur], low[child]);
			if (low[child] >= disc[cur] and par != 0)
			{
				//art point
				art_p.pb(cur);
			}
			if (low[child] > disc[cur])
			{
				//bridge
				bridge.pb({cur, child});
			}
		}

		else if (child != par) {

			//backedge
			//cycle  found
			low[cur] = min(low[cur], disc[child]);
		}
	}

}



int32_t main() {

	int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
	cin >> n >> m;
	for ( i = 0; i < m; i++) {

		int x; int y;
		gr[x].pb(y);
		gr[y].pb(x);

	}
	dfs(1, 0);
}
