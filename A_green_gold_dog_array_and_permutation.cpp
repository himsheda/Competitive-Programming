#include<bits/stdc++.h>
using namespace std;

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

typedef long long ll;
#define endl "\n"

// #define ordered_multiset tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
// #define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>

const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];
int lazy[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i << 1] + t[i << 1 | 1];
  memset(lazy, 0, sizeof(lazy)); // Initialize the lazy array
}

void push(int v) {
  t[v] += lazy[v] * (v < n ? v - (v >> 1) : 1);
  if (v < n) {
    lazy[v << 1] += lazy[v];
    lazy[v << 1 | 1] += lazy[v];
  }
  lazy[v] = 0;
}

void modify(int l, int r, int value) {
  l += n;
  r += n;
  while (l < r) {
    if (l & 1) {
      lazy[l] += value;
      push(l);
      l++;
    }
    if ((r & 1)) {
      r--;
      lazy[r] += value;
      push(r);
    }
    l >>= 1;
    r >>= 1;
  }
}

int query(int l, int r) {
  l += n;
  r += n;
  int res = 0;
  while (l < r) {
    if (l & 1) {
      push(l);
      res += t[l];
      l++;
    }
    if ((r & 1)) {
       r--;
      push(r);
      res += t[r];
    }
    l >>= 1;
    r >>= 1;
  }
  return res;
}

void solve()
{
   ll n;
   cin>>n;
   vector<pair<ll,ll>> v(n);
   //map<ll,ll> ind;
   for(ll i=0; i<n; i++)
   {
        cin>>v[i].first;
        v[i].second = i;
   }
   vector<ll> ans(n);
   sort(v.begin(), v.end());
   //set<ll> st;
   for(ll i=0; i<n; i++)
   {
        ans[v[n-i-1].second] = i+1;
        //st.insert(v[n-1-i]-v[i]);
   }
   for(auto x: ans) cout<<x<<" ";
   cout<<endl;
  return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}