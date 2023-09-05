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
 
void init_code(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
 
// const auto start_time = std::chrono::high_resolution_clock::now();
 
// void TIME() {
//   #ifndef ONLINE_JUDGE
//     auto end_time = std::chrono::high_resolution_clock::now();
//     std::chrono::duration<double> diff = end_time - start_time;
//     cerr << "Time Taken: " << diff.count() << "s\n";
//   #endif
// }


void solve(){
    int k,n;
    cin>>k>>n;
    vector<pii > arr(n);
    ff(i,0,n){
        int x;
        cin>>x;
        arr[i].F=x-1;
    }
    cin>>n;
    ff(i,0,n){
        int x;
        cin>>x;
        arr[i].S=x-1;
    }
    sort(all(arr));
    
    // show(arr);
    // cout<<"arr"<<endl;
    vi load(k);
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    set<int> av;
    ff(i,0,k){
        av.insert(i);
    }
    pq.push({arr[0].F+arr[0].S-1,0});
    load[0]+=arr[0].S;
    av.erase(0);
    int j=0;
    ff(i,1,n){
        int endtime=arr[i].F+arr[i].S-1;
        while(!pq.empty()){
            auto temp=pq.top();
            // show(temp);
            if(temp.F<=arr[i].F){
                av.insert(temp.S);
                pq.pop();
            }
            else{
                break;
            }
        }
        if(av.empty()){
            continue;
        }
        if(av.upper_bound(j)!=av.end()){
            // cout<<j<<" ";
            j=*(av.upper_bound(j));
            // cout<<j<<endl;
            av.erase(j);
            pq.push({endtime,j});
            load[j]+=arr[i].S;
        }
        else{
            j=*(av.begin());
            // cout<<ind<<endl;
            pq.push({endtime,j});
            load[j]+=arr[i].S;
            av.erase(j);
        }
            

    }
    // show(load);
    // cout<<"load"<<endl;
    int mx=*max_element(all(load));
    ff(i,0,k){
        if(load[i]==mx){
            cout<<i+1<<endl;   
        }
    }
    

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
 
 