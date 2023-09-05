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
 
bool check(vi &arr,vi &months){
    if(arr[1]>12) return 0;
    if(arr[0]>months[arr[1]-1]) return 0;
    return 1;
}

void solve(){
    int n;
    cin>>n;
    vi months={31,28,31,30,31,30,31,31,30,31,30,31};
    while(n--){
        string s;
        cin>>s;
        int dot=0,flag=0;
        vi arr(3);
        string temp="";
        ff(i,0,sz(s)){
            if(s[i]=='.'||s[i]=='/'){
                if(s[i]=='.'){
                    flag=1;
                }
                arr[dot++]=stoi(temp);
                temp="";
            }
            else{
                temp+=s[i];
            }
        }
        arr[dot]=stoi(temp);
        if(!flag){
            swap(arr[0],arr[1]);
        }
        if(arr[2]%4==0&&(arr[2]%100!=0||arr[2]%400==0)){
            months[1]=29;
        }
        else{
            months[1]=28;
        }
        // if(check(arr,months)){
            if(arr[0]<10){
                cout<<0;
            }
            cout<<arr[0]<<".";
            if(arr[1]<10){
                cout<<0;
            }
            cout<<arr[1]<<".";
            if(arr[2]<1000){
                cout<<0;
            }
            if(arr[2]<100){
                cout<<0;
            }
            if(arr[2]<10){
                cout<<0;
            }
            cout<<arr[2]<<" ";


            if(arr[1]<10){
                cout<<0;
            }
            cout<<arr[1]<<"/";
            if(arr[0]<10){
                cout<<0;
            }
            cout<<arr[0]<<"/";
            if(arr[2]<1000){
                cout<<0;
            }
            if(arr[2]<100){
                cout<<0;
            }
            if(arr[2]<10){
                cout<<0;
            }
            cout<<arr[2]<<endl;

        // }
        // else{
        //     cout<<"incorrect"<<endl;
        // }
    }
}
int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
 
 