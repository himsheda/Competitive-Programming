#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n'
#define pii pair<int,int>
#define pip pair<int,pii>
#define ppi pair<pii,int>
#define ppp pair<p,p> 
#define vpi vector<pii>
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define trav(i,x) for(auto& i:x)
#define sz(a) ((int)(a).size())
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define tr(c, it) for (auto it = (c).begin(); (it) != (c).end(); it++)
#define check(c, val) ((c).find(val) != (c).end())      // for sets, multisets, maps etc.
#define ccheck(c, val) (find((c).begin(), (c).end(), val) != (c).end()) // for others
 
#define pb push_back
#define F first
#define S second
 
#define ff(i, a, b) for(int i = (a);i < (b); i++)
#define fF(i, a, b, c) for(int i = (a);i < (b); i+=(c))
#define fb(i, a, b) for(int i = (b); i >= (a); i--)
#define fB(i, a, b, c) for(int i = (b); i >= (a); i-=(c))
#define fo(i, n) forf(i, 0, n)
#define fob(i, n) forb(i, 0, n - 1)
 
template <class T> void show(vector<vector<T>> &a) {for (auto &i : a) { for (T &j : i) cout << j << ' ' ; cout << endl; } }
template <class T> void show(vector<vector<vector<T>>> &a) {for (auto &i : a) {show(i); } }
template <class T> void show(vector<T> &a) {for (T i : a) cout << i << ' ' ; cout << endl; }
template <class T> void show(vector<pair<T, T>>&a) {trav(i,a) {cout << i.F << ' ' << i.S << endl;}}
template <class T> void show(pair<T, T>p) {cout << p.F << ' ' << p.S << endl;}
void show(vector<string>&a) {trav(i,a) cout << i << endl;}
template<class T> void take(vector<T>&a) {trav(i,a) cin >> i;}

const int INF = 9e18;
const int mod = 7+1e9;
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};
void init_code(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

class segtree{
public:
    vi tree;
    int n;
    segtree(int _n){
        n = _n;
        tree.resize(2*n);
    }
    void build(vi &arr){
        for(int i=0; i<n; i++){
            tree[i+n] = arr[i];
        }
        for(int i=n-1; i>0; i--){
            tree[i] = tree[2*i] + tree[2*i+1];
        }
    }
    segtree(vi &arr){
        n = arr.size();
        tree.resize(2*n);
        build(arr);
    }
    int query(int a, int b) {
        a += n; b += n;
        int s = 0;
        while (a <= b) {
            if (a%2 == 1) s += tree[a++];
            if (b%2 == 0) s += tree[b--];
            a /= 2; b /= 2;
        }
        return s;
    }
    void update(int k,int x){
        k += n;
        tree[k] += x;
        for (k /= 2; k >= 1; k /= 2) {
            tree[k] = tree[2*k]+tree[2*k+1];
        }
    }
};
void solve(){
    
    int n;
    cin>>n;
    vi arr(n);
    take(arr);
    vi arr2=arr;
    sort(all(arr2));
    map<int,int> mp;
    int ind=1;
    mp[arr2[0]]=1;
    ff(i,1,n){
        if(arr2[i]==arr2[i-1]) continue;
        mp[arr2[i]]=++ind;
    }
    // cout<<ind<<endl;
    segtree sg(ind+1);
    vi ans(n);
    sg.update(mp[arr[0]],1);
    ff(i,1,n-1){
        ans[i]=sg.query(mp[arr[i]]+1,ind);
        sg.update(mp[arr[i]],1);
    }
    // show(ans);
    vi ans2(n);
    segtree sg2(ind+1);
    sg2.update(mp[arr[n-1]],1);
    fb(i,1,n-2){
        ans[i]=abs(ans[i]-sg2.query(1,mp[arr[i]]-1));
        // ans2[i]=sg2.sum(1,mp[arr[i]]-1);
        sg2.update(mp[arr[i]],1);
    }
    // show(ans2);
    cout<<*max_element(ans.begin()+1,ans.end()-1)<<endl;

    
    
}
int32_t main(){
    init_code();
    //cout << fixed << setprecision(1);
    int t=1;
    // cin>>t;
    while(t--){
       solve(); 
    }
    // TIME();
    return 0;
 
 
}
 
 