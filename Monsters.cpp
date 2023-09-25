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
    vvi monst(n,vi(m,INF));
    queue<pii> q;
    pii start;
    ff(i,0,n){
        ff(j,0,m){
            if(arr[i][j]=='M'){
                monst[i][j] =1;
                q.push({i,j});
            }
            else if(arr[i][j]=='A'){
                start={i,j};
            }
        }
    }
    if(start.F==0||start.F==n-1||start.S==0||start.S==m-1){
        cout<<"YES"<<endl;
        cout<<0<<endl;
        return;
    }
    while(!q.empty()){
        int i=q.front().F,j=q.front().S;
        q.pop();
        ff(k,0,4){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=0&&x<n&&y>=0&&y<m&&monst[x][y]==INF&&arr[x][y]=='.'){
                monst[x][y]=1+monst[i][j];
                q.push({x,y});
            }
        }
    }
    // show(monst);
    vvi vis(n,vi(m,0));
    q.push(start);
    vis[start.F][start.S]=1;
    // int t=10;
    while(!q.empty()){
        int i=q.front().F,j=q.front().S;
        // cout<<i<<" "<<j<<endl;
        q.pop();
        ff(k,0,4){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && arr[x][y]=='.' && monst[x][y]>vis[i][j]+1){
                // cout<<vis[i][j]<<endl;
                vis[x][y]=1+vis[i][j];
                q.push({x,y});
                if(x==0||x==n-1||y==0||y==m-1){
                    string ans="";
                    while(arr[x][y]!='A'){
                        // cout<<x<<" "<<y<<endl;
                        ff(l,0,4){
                            int a=x+dx[l];
                            int b=y+dy[l];
                            if(a>=0&&a<n&&b>=0&&b<m&&vis[a][b]==vis[x][y]-1){
                                x=a;
                                y=b;
                                ans+=ds[l];
                                break;
                            }
                        }
                    }
                    reverse(all(ans));
                    cout<<"YES"<<endl;
                    cout<<sz(ans)<<endl;
                    cout<<ans<<endl;
                    return ;
                }
            }
        }
    }
    // show(vis);
    cout<<"NO"<<endl;
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
 
 