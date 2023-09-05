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


void solve(){
    string  s="mxSrN03uwdd";
    for(int i=0;i<s.size();i++){
        if(s[i]>='a'&&s[i]<='z')
        s[i]=(s[i]-'a'+8)%26+'a';
        else if(s[i]>='A'&&s[i]<='Z')
        s[i]=(s[i]-'A'+8)%26+'A';
        else{
            s[i]=(s[i]-'0'+8)%10+'0';
        }
    }
    cout<<s<<endl;
    // int n;
    // cin>>n;
    // vector<vector<int>> triangle;
    // for(int i=0;i<n;i++){
    //     vector<int> temp(i+1);
    //     // cerr<<temp.size()<<endl;
    //     for(int j=0;j<=i;j++){
    //         cin>>temp[j];
    //     }
    //     // cerr<<"fuck"<<endl;
    //     triangle.push_back(temp);
    // }
    // // for(auto &a:triangle){
    // //     for(auto &b:a){
    // //         cout<<b<<" ";
    // //     }
    // //     cout<<endl;
    // // }
    // minimumPathSum(triangle,n);
    // cout<<minimumPathSum(triangle,n)<<endl;
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
 
 