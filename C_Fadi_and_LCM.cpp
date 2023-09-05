// #include <bits/stdc++.h>
// using namespace std;
 
// #define int long long
// #define endl '\n'
 
// #define sz(a) ((int)(a).size())
// #define all(v) (v).begin(), (v).end()
// #define rall(v) (v).rbegin(), (v).rend()
// #define tr(c, it) for (auto it = (c).begin(); (it) != (c).end(); it++)
// #define pres(c, val) ((c).find(val) != (c).end())      // for sets, multisets, maps etc.
// #define cpres(c, val) (find((c).begin(), (c).end(), val) != (c).end()) // for others
 
// #define pb push_back
// #define fi first
// #define se second
 
// #define forf(i, a, b) for(int i = (a);i < (b); i++)
// #define forb(i, a, b) for(int i = (b); i >= (a); i--)
// #define fo(i, n) forf(i, 0, n)
// #define fob(i, n) forb(i, 0, n - 1)
 
// const int INF = 9e18;
// const int mod = 7+1e9;
 
// void init_code(){
//     ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// }
 
// const auto start_time = std::chrono::high_resolution_clock::now();
 
// void TIME() {
//   #ifndef ONLINE_JUDGE
//     auto end_time = std::chrono::high_resolution_clock::now();
//     std::chrono::duration<double> diff = end_time - start_time;
//     cerr << "Time Taken: " << diff.count() << "s\n";
//   #endif
// }

// bool isprime(int n)
// {
//     if (n <= 1)
//         return false;
//     for (int i = 2; i <= sqrt(n); i++)
//         if (n % i == 0)
//             return false;
 
//     return true;
// }

// void solve(){
//     int n;
//     cin>>n;
//     multiset<int> mp;
//     int x;
//     for(int i=0;i<n;i++){
//         cin>>x;
//         mp.insert(x);
//     }
//     int ans=0;
//     vector<int> arr(10);
//     for(int i=0;i<n;i++){
//         cin>>x;
//         if(mp.find(x) != mp.end()){
//             mp.erase(mp.find(x));
//         }
//         else{
//             if(x>9){
//                 arr[to_string(x).size()]++;
//                 ans++;
//             }
//             else{
//                 arr[x]++;
//             }
//         }
//     }
//     for( auto p:mp){
//         // cout<<p.first<<" "<<p.second<<endl;
//         if(p>9){
//             arr[to_string(p).size()]--;
//             ans++;
//         }
//         else{
//             arr[p]--;
//         }
//     }
//     for(int i=2;i<arr.size();i++){
//         // cerr<<arr[i]<<" ";
//         ans+=abs(arr[i]);
//     }
//     // cerr<<endl;
//     cout<<ans<<endl;
//     // multiset<int> st;
//     // st.insert(2);
//     // st.insert(2);
//     // st.insert(3);
//     // st.insert(6);
//     // st.insert(3);
//     // st.insert(7);
//     // st.insert(2);
//     // st.erase(st.find(2));
//     // for(auto it=st.begin();it!=st.end();it++){
//     //     cout<<*it<<endl;
//     // }
// }

// int32_t main(){
// //     #ifndef ONLINE_JUDGE
// //     freopen("D:/OneDrive - IIT Kanpur/CP/input.txt", "r", stdin);
// //     freopen("D:/OneDrive - IIT Kanpur/CP/input.txt", "w", stdout);
// // #endif
//     init_code();
//     //cout << fixed << setprecision(1);
//     int t=1;
//     cin>>t;
//     while(t--){
//        solve(); 
//     }
 
//     //cout<<"bh"<<endl;
//     //solve();
    
    
        
//     TIME();
//     return 0;
 
 
// }
 
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
    vector<int> prime;
    int temp=1;
    int m=n;
    while(n%2==0){
        n/=2;
        temp*=2;
    }
    if(temp!=1){
        prime.push_back(temp);
    }
    
    for(int i=3;i*i<n;i+=2){
        temp=1;
        while(n>0&&n%i==0){
            n/=i;
            temp*=i;
        }
        if(temp!=1){
            prime.push_back(temp);
        }
    }
    if(n!=1){
        prime.push_back(n);
    }
    if(prime.size()==1){
        cout<<"1 "<<m<<endl;
        return;
    }
    vector<int> s={1};
    for(int i=0;i<prime.size();i++){
        const int v=s.size();
        for(int t=0;t<v;t++){
            s.push_back(s[t]*prime[i]);
        }
    }
    int mn=m;
    for(int i=0;i<s.size();i++){
        // cerr<<" "<<s[i]<<endl;
        mn=min(mn,max(s[i],m/s[i]));
    }
    // cerr<<m<<endl;
    cout<<mn<<" "<<(m/mn)<<endl;

    
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
 
 
 