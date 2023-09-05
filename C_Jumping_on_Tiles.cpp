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
    string s;
    cin>>s;
    int n=s.size();
    vector<vector<int> > alph(26);
    alph[s[0]-'a'].push_back(0);
    alph[s[n-1]-'a'].push_back(n-1);
    if(s[0]<=s[n-1]){
        for(int i=1;i<s.size()-1;i++){
            if(s[i]<=s[n-1]&&s[i]>=s[0]){
                alph[s[i]-'a'].push_back(i);
            }
        }
    }
    else{
        for(int i=1;i<s.size()-1;i++){
            if(s[i]>=s[n-1]&&s[i]<=s[0]){
                alph[s[i]-'a'].push_back(i);
            }
        }
    }
    vector<int> arr;
    int m=0;
    for(int i=0;i<26;i++){
        if(alph[i].size()>0){
            sort(alph[i].begin(),alph[i].end());
            m+=alph[i].size();
            arr.push_back(i);
        }
    }
    // sort(arr.begin()+1, arr.end());
    int ans=0;
    for(int i=1;i<arr.size();i++){
        ans+=abs(arr[i]-arr[i-1]);
    }
    cout<<ans<<" "<<m<<endl;
    if(s[0]<=s[n-1]){
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<alph[arr[i]].size();j++){
                cout<<alph[arr[i]][j]+1<<" ";
            }
        }
    }
    else{
        for(int i=arr.size()-1;i>=0;i--){
            for(int j=0;j<alph[arr[i]].size();j++){
                cout<<alph[arr[i]][j]+1<<" ";
            }
        }
    }
    
    cout<<endl;
    
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
 
 
 