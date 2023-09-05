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
vvi matrix_mult(vvi &A,vvi &B){
    vvi ans(sz(A),vi (sz(A),0));
    ff(i,0,sz(A)){
        ff(j,0,sz(A)){
            ff(k,0,sz(A)){
                ans[i][j]=(ans[i][j]+A[i][k]*B[k][j]%mod)%mod;
            }
        }
    }
    return ans;
}
vvi matrix_pow(vvi &A,int b){
    if(b==0){
        vvi ans(sz(A),vi (sz(A)));
        ff(i,0,sz(A)){
            ans[i][i]=1;
        }
        return ans;
    }
    if(b==1) return A;
    auto ans=matrix_pow(A,b/2);
    ans=matrix_mult(ans,ans);
    if(b%2){
        return matrix_mult(ans,A);
    }
    else{
        return ans;
    }
}
void solve(){
    int N,k;
    cin>>k>>N;
    vi arr(N);
    take(arr);
    reverse(all(arr));
    arr.insert(arr.end(),arr.begin(),arr.end());
    int n=floor(sqrt(N));
    vector<vvi> mat;
    ff(i,N-1,2*N-1){
        vvi matarr;
        for(int j=0;j<n;j++){
            vi temp;
            for(int k=0;k<n;k++){
                temp.pb(arr[i-j*n-k]);
            }
            matarr.pb(temp);

        }
        mat.pb(matarr);
    }
    // for(auto &a:mat){
    //     show(a);
    // }
    vvi prod1=mat[0];
    ff(i,1,N){
        prod1=matrix_mult(prod1,mat[i]);
    }
    prod1=matrix_pow(prod1,k/N);
    // show(prod1);
    ff(i,0,k%N+1){
        // show(mat[i]);
        prod1=matrix_mult(prod1,mat[i]);
        // show(prod1);
    }
    int ans=0;
    ff(i,0,n){
        ff(j,0,n){
            ans=(ans+prod1[i][j])%mod;
        }
    }
    cout<<ans<<endl;

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
 
 