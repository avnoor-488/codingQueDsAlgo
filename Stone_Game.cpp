#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define forT(t) for(int i=0;i<t;i++)
#define forN(n) for(int i=0;i<n;i++)
#define MOD 1000000007


typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef set<int> seti;
typedef long long ll;



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




int main() {

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif


    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        vi vec;
        int n;
        cin>>n;
        forN(n)
        {
            int no;
            cin>>no;
            vec.pb(no);
        }

        int mini= *min_element(vec.begin(),vec.end());
        int maxi= *max_element(vec.begin(),vec.end());
        vi::iterator it;
        vi::iterator it1;
        it = find (vec.begin(), vec.end(), mini);
        it1 = find (vec.begin(), vec.end(), maxi);

        // cout<<it<<" "<<it2;
        // cout<<endl;

        int a=it-vec.begin();
        int b=it1-vec.begin();

        if(a<b)swap(a,b);
        cout<<min({vec.size()-(a-b-1),vec.size()-b+1,a})<<endl;


    }


}


// coded with the ❤️ Avnoor;
