#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

typedef long long ll;

#define endl "\n"


using namespace __gnu_pbds;

#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>

ll md = 1000000007;

ll query(ll n, ll m, ll cost)
{
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(m+1, vector<ll>(cost+1,0)));
    vector<vector<ll>> pref(cost+1, vector<ll>(m+1,0));
    for(ll i=1; i<=m; i++)
    {
        dp[0][i][0] = 1;
        if(i==1) pref[0][i] = 0;
        else pref[0][i] = ((pref[0][i-1]%md) + (dp[0][i-1][0])%md)%md;
    }
    // for(ll i=1; i<=m; i++)
    // {
    //     cout<<pref[0][i]<<endl;
    // }
    for(ll i=1; i<n; i++)
    {
        for(ll k = 0; k<=cost; k++)
        {
            for(ll j=1; j<=m; j++)
            {
                if(k!=0)
                {
                    dp[i][j][k] = ((dp[i][j][k]%md) + (pref[k-1][j]%md))%md;
                }
                    dp[i][j][k] = ((dp[i][j][k]%md) + ((dp[i-1][j][k]%md)*(j%md))%md)%md;
            }
        }
        for(ll k = 0; k<=cost; k++)
        {
            for(ll j=1; j<=m; j++)
            {
                //dp[0][j][0] = 1;
                if(j==1) pref[k][j] = 0;
                else pref[k][j] = ((pref[k][j-1]%md) + (dp[i][j-1][k]%md))%md;
            }
        }

    }
    ll sum = 0;
    for(ll i=1; i<=m; i++) sum = ((sum%md) + (dp[n-1][i][cost]%md))%md;
    return sum;
}

void solve()
{
    ll q;
    cin>>q;
    vector<ll> n(q);
    for(ll i=0; i<q; i++) cin>>n[i];
    cin>>q;
    vector<ll> m(q);
    for(ll i=0; i<q; i++) cin>>m[i];
    cin>>q;
    vector<ll> cost(q);
    for(ll i=0; i<q; i++) cin>>cost[i];
    for(ll i=0; i<q; i++)
    {   
        //cout<<n[i]<<" "<<m[i]<<" "<<cost[i]<<endl;
        cout<<query(n[i], m[i], cost[i])<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ll t;
    // cin>>t;
    // while(t--)
    solve();
}