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
 
const auto start_time = std::chrono::high_resolution_clock::now();
 
void TIME() {
  #ifndef ONLINE_JUDGE
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end_time - start_time;
    cerr << "Time Taken: " << diff.count() << "s\n";
  #endif
}
struct Node{
    Node* arr[10];
    bool isEnd;
    Node(){
        isEnd=false;
        for(int i=0;i<10;i++){
            arr[i]=NULL;
        }
    }
};
void insert(Node* root,string s){
    Node* temp=root;
    for(int i=0;i<sz(s);i++){
        int x=s[i]-'0';
        if(temp->arr[x]==NULL){
            temp->arr[x]=new Node();
        }
        temp=temp->arr[x];
    }
    temp->isEnd=true;
}
bool search(Node* root,string s){
    Node* temp=root;
    for(int i=0;i<sz(s);i++){
        int x=s[i]-'0';
        if(temp->arr[x]==NULL) return false;
        temp=temp->arr[x];
    }
    return temp->isEnd;
}
void generate(int i,Node* root,string &s,string &path){
    if(i==sz(s)){
        // cout<<path<<endl;
        insert(root,path);
        return;
    }
    path+=s[i];
    generate(i+1,root,s,path);
    path.pop_back();
    generate(i+1,root,s,path);
}
void generate2(Node* root1,Node* root2,int &ans){
    if(root1->isEnd && root2->isEnd){
        ans++;
    }
    for(int i=0;i<10;i++){
        if(root1->arr[i]!=NULL && root2->arr[i]!=NULL){
            generate2(root1->arr[i],root2->arr[i],ans);
        }
    }

}


void solve(){
    string x,y;
    cin>>x>>y;
    Node* r1=new Node();
    Node* r2=new Node();
    string path="";
    generate(0,r1,x,path);
    path="";
    generate(0,r2,y,path);
    int ans=0;
    if(search(r1,"0")&&search(r2,"0")){
        ans++;
    }
    ff(i,1,10){
        if(r1->arr[i]!=NULL && r2->arr[i]!=NULL){
            generate2(r1->arr[i],r2->arr[i],ans);
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
 
 