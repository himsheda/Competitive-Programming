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
#define vs vector<string>

#define trav(i,x) for(auto& i:x)
#define sz(a) ((int)(a).size())
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define tr(c, it) for (auto it = (c).begin(); (it) != (c).end(); it++)
#define check(c, val) ((c).find(val) != (c).end())      // for sets, multisets, maps etc.
#define ccheck(c, val) (find((c).begin(), (c).end(), val) != (c).end()) // for others
 
#define pb push_back
#define F first
#define S second
 
#define ff(i, a, b) for(int i = (a);i < (b); i++)
#define fF(i, a, b, c) for(int i = (a);i < (b); i+=(c))
#define fb(i, a, b) for(int i = (b); i >= (a); i--)
#define fB(i, a, b, c) for(int i = (b); i >= (a); i-=(c))
#define fo(i, n) forf(i, 0, n)
#define fob(i, n) forb(i, 0, n - 1)
 
template <class T> void show(vector<vector<T>> &a) {for (auto &i : a) { for (T &j : i) cout << j << ' ' ; cout << endl; } }
template <class T> void show(vector<vector<vector<T>>> &a) {for (auto &i : a) {show(i); } }
template <class T> void show(vector<T> &a) {for (T i : a) cout << i << ' ' ; cout << endl; }
template <class T> void show(vector<pair<T, T>>&a) {trav(i,a) {cout << i.F << ' ' << i.S << endl;}}
template <class T> void show(pair<T, T>p) {cout << p.F << ' ' << p.S << endl;}
void show(vector<string>&a) {trav(i,a) cout << i << endl;}
template<class T> void take(vector<T>&a) {trav(i,a) cin >> i;}

const int INF = 9e18;
const int mod = 7+1e9;
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};
const char ds[4]{'U','L','D','R'};
void init_code(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
void solve(){
    int n,m;
    cin>>n>>m;
    vs arr(n);
    take(arr);
    queue<pair<int,pair<int,int> > > q;
    vvi vis(n,vi(m,0));
    ff(i,0,n){
        ff(j,0,m){
            if(arr[i][j]=='A'){
                vis[i][j]=1;
                q.push({i,{j,1}});
                while(!q.empty()){
                    int a=q.front().F;
                    int b=q.front().S.F;
                    int c=q.front().S.S;
                    q.pop();
                    ff(r,0,4){
                        int x=a+dx[r];
                        int y=b+dy[r];
                        if(x>=0&&x<n&&y>=0&&y<m&&!vis[x][y]&&(arr[x][y]=='.'||arr[x][y]=='B')){
                            if(arr[x][y]=='B'){
                                vis[x][y]=c+1;
                                cout<<"YES"<<endl;
                                cout<<c<<endl;
                                string ans="";
                                int prev=c+1;
                                while(vis[x][y]!=1){
                                    ff(k,0,4){
                                        int p=x+dx[k];
                                        int q=y+dy[k];
                                        if(p>=0&&p<n&&q>=0&&q<m&&vis[p][q]==vis[x][y]-1){
                                            ans+=ds[k];
                                            x=p;
                                            y=q;
                                            prev--;
                                            break;
                                        }
                                    }
                                }
                                reverse(all(ans));
                                cout<<ans<<endl;
                                return;
                            }
                            vis[x][y]=c+1;
                            q.push({x,{y,c+1}});
                        }
                    }
                }
                cout<<"NO"<<endl;
                return;
            }
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
    // TIME();
    return 0;
}
 
 