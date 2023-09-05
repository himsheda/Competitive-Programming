#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// #define endl "\n"
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// #define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>

ll m = 1000000007;

void solve()
{
    ll n;
    cin>>n;
    ll m;
    cin>>m;
    vector<pair<ll,ll>> vp(m);
    for(ll i=0; i<m; i++)
    {
        cin>>vp[i].second;
    }
    cin>>m;
    for(ll i=0; i<m; i++)
    {
        cin>>vp[i].first;
    }
    //cout<<"kihi"<<endl;
    //set<pair<ll,ll>> sp;
    for(ll i=0; i<m; i++)
    {
        if(vp[i].first<vp[i].second) swap(vp[i].first, vp[i].second);
        //sp.insert(vp[i]);
    }
    //vp.clear();
    //for(auto x: sp) vp.push_back(x);
    //sp.clear();
    sort(vp.begin(), vp.end());
    ll ct = 0;
    ll start = 1;
    for(auto x: vp)
    {
        // if(x.second<start) continue;
        ll end = x.first-1;
        ll num = end - start +1;
        ct+=(num*(num+1))/2;
        start = x.second+1;
        // if(end>=start)
        // {
            ll num1 = end - start + 1;
            ct-=(num1*(num1+1))/2;
        // }
    }
    ll end = n;
    ll num = end - start + 1;
    ct+=(num*(num+1))/2;
    cout<<ct<<endl;
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