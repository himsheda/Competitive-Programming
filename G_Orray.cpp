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
// struct node{
//     int val=0;
//     struct node* left;
//     struct node* right;
//     node(int val) : val(val),left(NULL),right(NULL) {}
// };
// void print(struct node* N){
//     if(N==NULL)
//     return;
//     print(N->left);
//     if(N->left==NULL&&N->right==NULL)
//         cout<<N->val<<" ";
//     print(N->right);
// }
void solve(){
    int n;
    cin>>n;
    vector<string > arr(n);
    int x;
    string s;
    for(int i=0;i<n;i++){
        cin>>x;
        s="";
        for(int j=31;j>=0;j--){
            s+=to_string(x%2);
            x/=2;
        }
        reverse(s.begin(),s.end());
        arr[i]=s;
    }
    sort(arr.begin(),arr.end(),greater<string>());
    // for(int i=0;i<arr.size();i++){
    //     cout<<arr[i]<<" ";
    // }
    for(int i=0;i<=n-1;i++){
        int a=0;
        for(int j=0;j<32;j++){
            a+=(arr[i][j]-'0')*(1<<(31-j));
        }
        cout<<a<<" ";
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<32;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // struct node* T=new node(0);
    // for(int i=0;i<n;i++){
    //     auto p=T;
    //     int x=0;
    //     for(int j=0;j<32;j++){
    //         if(arr[i][j]==0){
    //             p->left=new node(x*2);
    //             p=p->left;
    //         }
    //         else{
    //             p->right=new node(x*2+1);
    //             p=p->right;
    //         }
    //     }
    // }
    // print(T);
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
 
 