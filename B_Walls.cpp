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
#define trav(x) for(auto& i:x)
#define sz(a) ((int)(a).size())
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define tr(c, it) for (auto it = (c).begin(); (it) != (c).end(); it++)
#define pres(c, val) ((c).find(val) != (c).end())      // for sets, multisets, maps etc.
#define cpres(c, val) (find((c).begin(), (c).end(), val) != (c).end()) // for others
 
#define pb push_back
#define F first
#define S second
 
#define ff(i, a, b) for(int i = (a);i < (b); i++)
#define fb(i, a, b) for(int i = (b); i >= (a); i--)
#define fo(i, n) forf(i, 0, n)
#define fob(i, n) forb(i, 0, n - 1)
 
template <class T> void show(vector<vector<T>> &a) {for (auto &i : a) { for (T &j : i) cout << j << ' ' ; cout << endl; } }
template <class T> void show(vector<T> &a) {for (T i : a) cout << i << ' ' ; cout << endl; }
template <class T> void show(vector<pair<T, T>>&a) {trav(a) {cout << i.F << ' ' << i.S << endl;}}
template <class T> void show(pair<T, T>p) {cout << p.F << ' ' << p.S << endl;}
void show(vector<string>&a) {trav(a) cout << i << endl;}
template<class T> void take(vector<T>&a) {trav(a) cin >> i;}

const int INF = 9e18;
const int mod = 7+1e9;
 
void init_code(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int f(vi &arr,int x){
    int ans=0;
    for(auto &i:arr){
        ans+=ceil((double)i/x);
    }
    return ans;
}
void solve(){
    int n;
    cin>>n;
    vi arr(n);
    take(arr);
    if(n<=2){
        cout<<0<<endl;
        return;
    }
    vi mxl(n),mxr(n);
    mxl[0]=arr[0];
    ff(i,1,n){
        if(arr[i]>mxl[i-1]){
            mxl[i]=arr[i];
        }
        else{
            mxl[i]=mxl[i-1];
        }
    }
    mxr[n-1]=arr[n-1];
    fb(i,0,n-2){
        if(arr[i]>mxr[i+1]){
            mxr[i]=arr[i];
        }
        else{
            mxr[i]=mxr[i+1];
        }
    }
    vi hist(n);
    hist[0]=0;
    hist[n-1]=0;
    ff(i,1,n-1){
        
        hist[i]=min(mxl[i-1],mxr[i+1]);
    }
    // show(hist);
    stack<int> stk;
    ff(i,0,n){
        while(!stk.empty()&&hist[stk.top()]>=hist[i]){
            stk.pop();
        }
        if(stk.empty()){
            mxl[i]=0;

        }
        else{
            mxl[i]=stk.top();
        }
        stk.push(i);
    }
    while(!stk.empty()){
        stk.pop();
    }
    fb(i,0,n-1){
        while(!stk.empty()&&hist[stk.top()]>=hist[i]){
            stk.pop();
        }
        if(stk.empty()){
            mxr[i]=n-1;

        }
        else{
            mxr[i]=stk.top();
        }
        stk.push(i);
    }
    // show(mxl);
    // show(mxr);
    int ans=0;
    ff(i,0,n){
        ans=max(ans,(mxr[i]-mxl[i]-1)*hist[i]);
    }
    cout<<ans<<endl;
    
    
}
int32_t main(){
    init_code();
    //cout << fixed << setprecision(1);
    int t=1;
    cin>>t;
    while(t--){
       solve(); 
    }
 
    //cout<<"bh"<<endl;
    //solve();
    
    
        
    // TIME();
    return 0;
 
 
}
 
 