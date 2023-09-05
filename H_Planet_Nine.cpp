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
 
int power(int a,int b){
    if(a==0) return 0;
    if(b==1) return a;
    if(b==0) return 1;
    int x=power(a,b/2);
    if(b%2) return x*x*a;
    return x*x;
}

void solve(){
    int a,b;
    cin>>a>>b;
    if(a==b){
        cout<<"Stable"<<endl;
        cout<<0<<endl;
        return;
    }
    // cout<<a<<endl;
    string s=to_string(b);
    reverse(all(s));
    int i=0;
    vi arr={0,9,8,7,6,5,4,3,2,1};
    int count=0;
    while(i<sz(s)){
        string s2=to_string(a);
        reverse(all(s2));
        if(i==sz(s2)) s2+='0';
        if(s2[i]!=s[i]){
            int x=(s[i]-s2[i]+10)%10;
            
            a+=9*arr[x]*power(10,i);
            count+=arr[x]*power(10,i);
            // cout<<a<<endl;
        }
        i++;
    }
    if(a==b){
        cout<<"Stable"<<endl;
        cout<<"+ "<<count<<endl;
        return;
    }
   
    string s2=to_string(a);
    reverse(all(s2));
    while(!(i==sz(s2)-1&&s2.back()=='1')){
        if(s2[i]!='1'){
            int x=(1-(s2[i]-'0')+10)%10;
            // cout<<(int)9*arr[x]*power(10,i)<<" "<<a<<endl;
            a+=9*arr[x]*(int)power(10,i);
            s2=to_string(a);
            reverse(all(s2));
            count+=arr[x]*power(10,i);
            
        }
        
        // cout<<a<<endl;
        i++;
    }
    int ans=sz(s2)-sz(s);
    cout<<"Stable"<<endl;
    cout<<2<<endl;
    cout<<"+ "<<count<<endl;
    cout<<"- "<<ans<<endl;


}
int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
 
 