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
const int mod = 998244353;
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};
void init_code(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
vi fact(2e5+1);
int power(int a,int b){
    int ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}
int modInverse(int a){
    return power(a,mod-2);
}
int ncr(int n,int r){
    int ans=fact[n];
    ans=(ans*modInverse(fact[r]))%mod;
    ans=(ans*modInverse(fact[n-r]))%mod;
    return ans;
}
int npr(int n,int r){
    int ans=fact[n];
    ans=(ans*modInverse(fact[n-r]))%mod;
    return ans;
}
void solve(){
    string s;
    cin>>s;
    int n=sz(s);
    int ans=1,len=0;
    int i=0;
    while(i<n){
        int c=0;
        if(s[i]=='0'){
            while(i<n&&s[i]=='0'){
                c++;
                i++;
            }
            ans=(ans*ncr(c,c-1))%mod;
        }
        else{
            while(i<n&&s[i]=='1'){
                c++;
                i++;
            }
            ans=(ans*ncr(c,c-1))%mod;
        }
        len++;
    }
    ans=(ans*fact[n-len])%mod;
    cout<<n-len<<" "<<ans<<endl;
}
int32_t main(){
    init_code();
    //cout << fixed << setprecision(1);
    
    fact[0]=1;
    ff(i,1,2e5+1){
        fact[i]=(fact[i-1]*i)%mod;
    }
    int t=1;
    cin>>t;
    while(t--){
       solve(); 
    }
    // TIME();
    return 0;
}
 
 