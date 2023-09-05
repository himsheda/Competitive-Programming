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
vi fact(1001);
int powmod(int a, int b, int p){
    a %= p;
    if (a == 0) return 0;
    int product = 1;
    while(b > 0){
        if (b&1){    // you can also use b % 2 == 1
            product *= a;
            product %= p;
            --b;
        }
        a *= a;
        a %= p;
        b /= 2;    // you can also use b >> 1
    }
    return product;
}
int  inv(int a,int p){
    return powmod(a, p-2, p);
}
int nCk(int n, int k, int p){
    return ((fact[n] * inv(fact[k], p) % p) * inv(fact[n-k], p)) % p;
}
int dist(int n,int p,int k){
    if(p>n||k*p<n) return 0;
    if(p==n) return 1;
    if(p==0) return 0;
    int ans=0,sign=1;
    for(int i=0;i<=n-p;i+=k){
        ans=(mod+ans+sign*nCk(p,i/k,mod)*nCk(n-i-1,n-p-i,mod)%mod)%mod;
        sign*=-1;
    }
    return ans;
}
void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    int ans=0;
    for(int i=1;i<=n;i++){
        // cout<<dist(n,i,k)<<" "<<dist(m,i,k)<<" "<<dist(m,i+1,k)<<" "<<dist(m,i-1,k)<<endl;
        // cout<<dist(n,i,k)*(dist(m,i+1,k)+dist(m,i-1,k)+2*dist(m,i,k))<<" ";
        ans=(ans+dist(n,i,k)*(dist(m,i+1,k)+dist(m,i-1,k)+2*dist(m,i,k)))%mod;
    }
    cout<<ans<<endl;

}

int32_t main(){
    init_code();
    //cout << fixed << setprecision(1);
    int t=1;
    cin>>t;
    fact[0]=fact[1]=1;
    for(int i=2;i<=1000;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    // show(fact);
    while(t--){
       solve(); 
    }
 
    //cout<<"bh"<<endl;
    //solve();
    
    
        
    // TIME();
    return 0;
 
 
}
 
 