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
 


void solve(){
    int ax1,ay1,ax2,ay2;
    int bx1,by1,bx2,by2;
    int vx,vy;
    cin>>ax1>>ay1>>ax2>>ay2;
    cin>>bx1>>by1>>bx2>>by2;
    cin>>vx>>vy;
    int s1=vx*by1-vy*bx1-vx*ay1+vy*ax1;
    int s2=vx*by2-vy*bx2-vx*ay1+vy*ax1;
    int s3=vx*by1-vy*bx1-vx*ay2+vy*ax2;
    int s4=vx*by2-vy*bx2-vx*ay2+vy*ax2;
    // cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<endl;
    if(s1*s2<=0){
        int ref=(ay1+vy-ay1)*(ax2-ax1)-(ax1+vx-ax1)*(ay2-ay1);
        int s5=(by1-ay1)*(ax2-ax1)-(bx1-ax1)*(ay2-ay1);
        int s6=(by2-ay1)*(ax2-ax1)-(bx2-ax1)*(ay2-ay1);
        // cout<<ref<<" "<<s5<<" "<<s6<<endl;
        if(ref*s5>=0||ref*s6>=0){
            cout<<"Yes"<<endl;
            return;
        }
        else{
            cout<<"No"<<endl;
            return;
        }
        // cout<<"Yes"<<endl;
        // return;
    }
    if(s3*s4<=0){
        int ref=(ay2+vy-ay1)*(ax2-ax1)-(ax2+vx-ax1)*(ay2-ay1);
        int s5=(by1-ay1)*(ax2-ax1)-(bx1-ax1)*(ay2-ay1);
        int s6=(by2-ay1)*(ax2-ax1)-(bx2-ax1)*(ay2-ay1);
        // cout<<ref<<" "<<s5<<" "<<s6<<endl;
        if(ref*s5>=0||ref*s6>=0){
            cout<<"Yes"<<endl;
            return;
        }
        else{
            cout<<"No"<<endl;
            return;
        }
        // cout<<"Yes"<<endl;
        // return;
    }
    if(s1*s3>0){
        cout<<"No"<<endl;
        return;
    }
    if(s2*s4>0){
        cout<<"No"<<endl;
        return;
    }
    if(s1*s3<=0){
        int ref=(ay1+vy-ay1)*(ax2-ax1)-(ax1+vx-ax1)*(ay2-ay1);
        int s5=(by1-ay1)*(ax2-ax1)-(bx1-ax1)*(ay2-ay1);
        int s6=(by2-ay1)*(ax2-ax1)-(bx2-ax1)*(ay2-ay1);
        if(ref*s5>=0||ref*s6>=0){
            cout<<"Yes"<<endl;
            return;
        }
        else{
            cout<<"No"<<endl;
            return;
        }
        // cout<<"Yes"<<endl;
        // return;
    }
    if(s2*s4<=0){
        int ref=(ay2+vy-ay1)*(ax2-ax1)-(ax2+vx-ax1)*(ay2-ay1);
        int s5=(by1-ay1)*(ax2-ax1)-(bx1-ax1)*(ay2-ay1);
        int s6=(by2-ay1)*(ax2-ax1)-(bx2-ax1)*(ay2-ay1);
        if(ref*s5>=0||ref*s6>=0){
            cout<<"Yes"<<endl;
            return;
        }
        else{
            cout<<"No"<<endl;
            return;
        }
        // cout<<"Yes"<<endl;
        // return;
    }
    // s1=vx*ay1-vy*ax1-vx*by1+vy*bx1;
    // s2=vx*ay2-vy*ax2-vx*by1+vy*bx1;
    // s3=vx*ay1-vy*ax1-vx*by2+vy*bx2;
    // s4=vx*ay2-vy*ax2-vx*by2+vy*bx2;

    // cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<endl;
    // if(s1*s2<=0){
    //     cout<<"Yes"<<endl;
    //     return;
    // }
    // if(s3*s4<=0){
    //     cout<<"Yes"<<endl;
    //     return;
    // }
    // if(s1*s3>0){
    //     cout<<"No"<<endl;
    //     return;
    // }
    // if(s2*s4>0){
    //     cout<<"No"<<endl;
    //     return;
    // }
    // if(s1*s3<=0){
    //     cout<<"Yes"<<endl;
    //     return;
    // }
    // if(s2*s4<=0){
    //     cout<<"Yes"<<endl;
    //     return;
    // }
}
int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
 
 