#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define forT(t) for(int i=0;i<t;i++)
#define forN(n) for(int j=1;j<=n;j++)
#define MOD 1000000007


typedef pair<int, int> pii;
typedef vector<string> vs;
typedef set<int> seti;
typedef long long ll;
typedef vector<ll> vi;


void fastscan( ll &number)
{
    bool negative = false;
    register int c;

    number = 0;

    c = getchar();
    if (c == '-')
    {
        negative = true;

        c = getchar();
    }

    for (; (c > 47 && c < 58); c = getchar())
        number = number * 10 + c - 48;


    if (negative)
        number *= -1;
}

ll gcd (ll a, ll b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int solve(int n, int ans[])
{

    if (n == 1)
    {
        ans[n] = 0;
        return 0;
    }

    int x = INT_MAX;
    if (ans[n - 1] == -1)
    {
        ans[n - 1] = solve(n - 1, ans);
        x = ans[n - 1];
    }


    int y = INT_MAX;
    if (n % 2 == 0)
    {
        if (ans[n / 2] == -1)
            ans[n / 2] = solve(n / 2, ans);
        y = ans[n / 2];
    }

    int z = INT_MAX;
    if (n % 3 == 0)
    {
        if (ans[n / 3] == -1)
            ans[n / 3] = solve(n / 3, ans);
        z = ans[n / 3];


    }
    return min(x, min( y, z)) + 1;
}
int minCount(int n)
{
    int arr[n + 1] ;
    for (int i = 0; i <= n; i++)arr[i] = -1;
    return solve(n, arr);
}
int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    forT(1)
    {

        // int n;
        // cin>>n;
        cout << minCount(10);


    }

}


// coded with the ❤️ Avnoor;
