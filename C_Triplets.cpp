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
    vi a(n),b(n);
    take(a);
    take(b);
    if(n<=2){
        cout<<0<<endl;
        return;
    }
    vi mp(n+1);
    ff(i,0,n){
        mp[b[i]]=i;
    }
    // show(mp);
    segtree sg1(n);
    vi arr(n);
    ff(i,0,n){
        arr[i]=sg1.query(0,mp[a[i]]-1);
        sg1.update(mp[a[i]],1);
    }
    // show(arr);
    // show(sg1.tree);
    vi arr2(n);
    segtree sg2(n);
    fb(i,0,n-1){
        arr[i]*=sg2.query(mp[a[i]]+1,n-1);
        sg2.update(mp[a[i]],1);
    }
    // show(arr2);
    cout<<accumulate(arr.begin()+1,arr.end()-1,0LL)<<endl;


//   vi mp1(n+1,0),mp2(n+1,0),mp(n+1);
//   ff(i,0,n){
//     mp[a[i]]=i+1;
//   }
//   ff(i,0,n){
//     mp[b[i]]=min(mp[b[i]],i+1);
//   }
//   vi mp4(n+1);
//   ff(i,0,n){
//     mp4[a[i]]=i+1;
//   }
//   ff(i,0,n){
//     mp4[b[i]]=max(mp4[b[i]],i+1);
//   }
//   segtree sg1(n+1),sg2(n+1);
  
//   mp1[a[0]]=1;
//   mp2[b[0]]=1;
//   if(a[0]==b[0]){
//     sg1.update(a[0],1);
//   }
//   vi ans(n,0),ans2(n,0);
//   ff(i,1,n-1){
//     ans[i]=sg1.query(1,n);
//     if(mp2[a[i]]){
//         sg1.update(a[i],1);
//     }
//     mp1[a[i]]=1;
//     if(mp1[b[i]]){
//         sg1.update(b[i],1);
//     }
//     mp2[b[i]]=1;
//   }
//   show(ans);
//   mp1.assign(sz(mp1),0);
//   mp2.assign(sz(mp2),0);
//   mp1[a[n-1]]=1;
//   mp2[b[n-1]]=1;
//   if(a[n-1]==b[n-1]){
//     sg2.update(a[n-1],1);
//   }
//   fb(i,1,n-2){
//     ans[i]*=sg2.query(1,n);
//     ans2[i]=sg2.query(1,n);
//     if(mp2[a[i]]){
//         sg2.update(a[i],1);
//     }
//     mp1[a[i]]=1;
//     if(mp1[b[i]]){
//         sg2.update(b[i],1);
//     }
//     mp2[b[i]]=1;
//   }
//   show(ans2);
//   cout<<accumulate(all(ans),0LL)<<endl;

}
int32_t main(){
    init_code();
    //cout << fixed << setprecision(1);
    int t=1;
    cin>>t;
    while(t--){
       solve(); 
    }
    // TIME();
    return 0;
}
 