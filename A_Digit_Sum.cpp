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
bool IsPowerOfTwo(int x)
{
    return (x != 0) && ((x & (x - 1)) == 0);
}
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int sum1=0,sum2=0;
    for(int i=0;i<n;i++){
        sum1+=s[i]-'0';
    }
    for(int i=0;i<n;i++){
        sum2+=s[n+i]-'0';
    }
    if(sum1>sum2){
        reverse(s.begin(),s.end());
        swap(sum1,sum2);

    }
    sort(s.begin(),s.begin()+n);
    sort(s.begin()+n,s.end());
    int i=0,j=2*n-1;
    int ans=0;
    while(sum1<sum2){
        if(9-s[i]+'0'>=s[j]-'0'){
            sum1=sum1+9-s[i]+'0';
            ans++;
            i++;
        }
        else{
            sum2=sum2-s[j]+'0';
            ans++;
            j--;
        }
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
 
 
