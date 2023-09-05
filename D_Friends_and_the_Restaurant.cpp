
 
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
 
bool isprime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
 
    return true;
}

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    int x=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cin>>x;
        arr[i]=x-arr[i];
    }
    sort(arr.begin(), arr.end());
    int i=0, j=n-1;
    int count=0,left=0;
    while(arr[i]<0&&arr[j]>0&&i<=j){
        int idx=lower_bound(arr.begin()+i,arr.begin()+j,-arr[j])-arr.begin();
        if((idx<j)&&arr[idx]<0){
            count++;
            i=idx+1;
            j--;
        }
        else{
            j--;
            left++;
        }
    }
    while(arr[i]<0){
        i++;
    }
    // cout<<i<<" "<<j<<endl;
    if(arr[j]>=0)
        count+=(left+j-i+1)/2;
    else{
        count+=left/2;
    }
    cout<<count<<endl;
    
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
 
 
 