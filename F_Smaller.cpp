#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n'
 
#define sz(a) ((int)(a).size())
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define tr(c, it) for (auto it = (c).begin(); (it) != (c).end(); it++)
#define pres(c, val) ((c).find(val) != (c).end())      // for sets, multisets, maps etc.
#define cpres(c, val) (find((c).begin(), (c).end(), val) != (c).end()) // for others
 
#define pb push_back
#define fi first
#define se second
 
#define forf(i, a, b) for(int i = (a);i < (b); i++)
#define forb(i, a, b) for(int i = (b); i >= (a); i--)
#define fo(i, n) forf(i, 0, n)
#define fob(i, n) forb(i, 0, n - 1)
 
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
bool compare(vector<int> &a,vector<int> &b) {
    for(int i=1; i<a.size(); i++){
        if(b[i]>0)
        return 1;
    }
    for(int i=1;i<a.size();i++){
        if(a[i]>0)
        return 0;
    }
    if(a[0]<b[0])
    return 1;
    return 0;
}
void solve(){
    vector<int> s(26),t(26);
    s[0]=1;
    t[0]=1;
    int q;
    cin>>q;
    int d,k;
    string x;
    for(int i=0;i<q;i++){
        cin >> d>> k>> x;
        if(d==1){
            for(auto c:x){
                s[c-'a']+=k;
            }
        }
        else{
            for(auto c:x){
                t[c-'a']+=k;
            }
        }
        if(compare(s,t)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

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
 
 