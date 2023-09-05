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
    int n,m;
    cin>>n>>m;
    vector<string> arr(n);
    ff(i,0,n){
        cin>>arr[i];
    }
    int j=0;
    int flag=0;
    while(j<m){
        ff(i,0,n){
            if(arr[i][j]=='v'){
                flag=1;
                break;
            }
        }
        if(flag==1){
            j++ ;
            break;
        }
        j++;
    }
    if(flag==0){
        cout<<"NO"<<endl;
        return;
    }
    // cout<<j<<endl;
    flag=0;
    while(j<m){
        ff(i,0,n){
            if(arr[i][j]=='i'){
                flag=1;
                break;
            }
        }
        if(flag==1){
            j++ ;
            break;
        }
        j++;
    }
    if(flag==0){
        cout<<"NO"<<endl;
        return;
    }

    flag=0;
    while(j<m){
        ff(i,0,n){
            if(arr[i][j]=='k'){
                flag=1;
                break;
            }
        }
        if(flag==1){
            j++ ;
            break;
        }
        j++;
    }
    if(flag==0){
        cout<<"NO"<<endl;
        return;
    }
    flag=0;
    while(j<m){
        ff(i,0,n){
            if(arr[i][j]=='a'){
                flag=1;
                break;
            }
        }
        if(flag==1){
            j++ ;
            break;
        }
        j++;
    }
    if(flag==0){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    
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
 
 