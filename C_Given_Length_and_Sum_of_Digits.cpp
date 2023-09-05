#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl '\n'
 
#define sz(a) ((ll)(a).size())
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define tr(c, it) for (auto it = (c).begin(); (it) != (c).end(); it++)
#define pres(c, val) ((c).find(val) != (c).end())      // for sets, multisets, maps etc.
#define cpres(c, val) (find((c).begin(), (c).end(), val) != (c).end()) // for others
 
#define pb push_back
#define fi first
#define se second
 
#define forf(i, a, b) for(ll i = (a);i < (b); i++)
#define forb(i, a, b) for(ll i = (b); i >= (a); i--)
#define fo(i, n) forf(i, 0, n)
#define fob(i, n) forb(i, 0, n - 1)
 
const ll INF = 9e18;
const ll mod = 7+1e9;
 
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
ll min(ll a,ll b){
    if(a < b) return a;
    return b;
}
ll max(ll a,ll b){
    if(a < b) return b;
    return a;
}
void solve(){
    int m,s;
    cin>>m>>s;
    if(9*m<s){
        cout<<"-1 -1"<<endl;
        return;
    }
    else if(s==0){
        if(m==1){
            cout<<"0 0"<<endl;
        }
        else{
            cout<<"-1 -1"<<endl;
        }
        return ;
    }
    vector<int> arr(m);
    for(int i=0;i<m;i++){
        if(s>=9){
            arr[i]=9;
            s-=9;
        }
        else{
            arr[i]=s;
            s=0;
        }
    }
    int count=0,j=m-1;
    while((j>=0)&&arr[j]==0){
        count++;
        j--;
    }
    if(count>0){
        cout<<1;
        for(int i=0;i<count-1;i++)
        cout<<0;
        cout<<arr[j]-1;
        j--;
         while(j>=0){
            cout<<arr[j];
            j--;
        }
    }
    else{
        for(int i=m-1;i>=0;i--)
        cout<<arr[i];
    }
   
    cout<<" ";
    for(int i=0;i<m;i++)
    cout<<arr[i];
    
}

int main(){
    init_code();
    //cout << fixed << setprecision(1);
    ll t=1;
    // cin>>t;
    while(t--){
       solve(); 
    }
 
    //cout<<"bh"<<endl;
    //solve();
    
    
        
    // TIME();
    return 0;
 
 
}
 