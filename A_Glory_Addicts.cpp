
 
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
int fac[61];

void solve(){
    int n;
    cin>>n;
    int one=0,zero=0;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
        if(a[i])
        one++;
        else
        zero++;
    }
    vector<int> bone,bzero;
    int x;
    for(int i=0; i<n; i++){
        cin>>x;
        if(a[i]){
            bone.push_back(x);
        }
        else{
            bzero.push_back(x);
        }
    }
    sort(bone.begin(),bone.end(),greater<int>());
    sort(bzero.begin(),bzero.end(),greater<int>());
    int sum=0;
    for(int i=0;i<min(one,zero);i++){
        sum+=2*bzero[i]+2*bone[i];
    }
    for(int i=min(one,zero);i<one;i++){
        sum+=bone[i];
    }
    for(int i=min(one,zero);i<zero;i++){
        sum+=bzero[i];
    }
    if(one==zero)
    sum-=min(bone.back(),bzero.back());
    cout<<sum<<endl;
}
int power(int x,int y, int p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
int modInverse(int n, int p)
{
    return power(n, p - 2, p);
}
int ncrmod(int n,int r, int p)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    return (fac[n] * modInverse(fac[r], p) % p* modInverse(fac[n - r], p) % p)% p;
}

int32_t main(){
    init_code();
    //cout << fixed << setprecision(1);
    int t=1;
    vector<int> win(31,0);
    vector<int> lose(31,0);
    int m=998244353 ;
    fac[0] = 1;
    for (int i = 1; i <= 60; i++)
        fac[i] = (fac[i - 1] * i) % m;
    win[1]=1;
    for(int i=2;i<61;i++){
        if(i%2==0){
            lose[i]=ncrmod(2*i-3,i-2,m);
            // win[i]=(ncrmod(2*i,i,m)-lose[i]-1)%m;
        }
        else{
            win[i]=ncrmod(2*i-1,i-1,m);
            // lose[i]=(ncrmod(2*i,i,m)-win[i]-1)%m;
        }
    }
    for(int i=2;i<61;i++){
        if(i%2==0){
            lose[i]=(lose[i]+win[i-1])%m;
            win[i]=(ncrmod(2*i,i,m)-lose[i]-1)%m;
        }
        else{
            win[i]=(lose[i-1]+win[i])%m;
            lose[i]=(ncrmod(2*i,i,m)-win[i]-1)%m;
        }
    }
    cin>>t;
    while(t--){
       solve(); 
    }
 
    //cout<<"bh"<<endl;
    //solve();
    
    
        
    // TIME();
    return 0;
 
 
}
 
 
 