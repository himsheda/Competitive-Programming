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
template <class T> void show(vector<pair<T, T>>&a) {trav(a) {cout << i.ff << ' ' << i.ss << endl;}}
template <class T> void show(pair<T, T>p) {cout << p.ff << ' ' << p.ss << endl;}
void show(vector<string>&a) {trav(a) cout << i << endl;}
template<class T> void take(vector<T>&a) {trav(a) cin >> i;}

const int INF = 9e18;
const int mod = 7+1e9;
 
void init_code(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
 
const auto start_time = std::chrono::high_resolution_clock::now();
 
void TIME() {
  #ifndef ONLINE_JUDGE
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end_time - start_time;
    cerr << "Time Taken: " << diff.count() << "s\n";
  #endif
}
void solve(){
    int n,k,q;
    cin>>n>>k>>q;
    vi arr(n);
    take(arr);
    vvi pref(101,vi(n+1,0));
    ff(i,1,101){
        ff(j,1,n+1){
            pref[i][j] = pref[i][j-1];
            if(arr[j-1]==i) pref[i][j]++;
        }
    }
    // show(pref);
    while(q--){
        int l,r;
        cin>>l>>r;
        int cnt=0;
        int k1=0;
        
        int x1=(l-1)/n;
        int x2=r/n;
        int rem1=(l-1)%n;
        int rem2=r%n;
        // cout<<x1<<" "<<x2<<" "<<rem1<<" "<<rem2<<endl;
        int ans=0;
        vi temp(101);
        ff(i,1,101){
            temp[i]=pref[i][rem2]-pref[i][rem1] +(x2-x1)*pref[i][n];
        }
        // show(temp);
        int mx=0,ind=0;
        ff(i,1,101){
            if(temp[i]>=mx){
                mx=temp[i];
                ind=i;
            }
        }
        cout<<ind<<endl;
    }
}
int32_t main(){
    init_code();
    //cout << fixed << setprecision(1);
    int t=1;
    // cin>>t;
    while(t--){
       solve(); 
    }
 
    //cout<<"bh"<<endl;
    //solve();
    
    
        
    // TIME();
    return 0;
 
 
}
 
 