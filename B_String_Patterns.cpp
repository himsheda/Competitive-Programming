// #include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// #define int long long
// #define endl '\n'
// #define pii pair<int,int>
// #define pip pair<int,pii>
// #define ppi pair<pii,int>
// #define ppp pair<p,p> 
// #define vpi vector<pii>
// #define vi vector<int>
// #define vvi vector<vi>
// #define vs vector<string>

// #define trav(i,x) for(auto& i:x)
// #define sz(a) ((int)(a).size())
// #define all(v) (v).begin(), (v).end()
// #define rall(v) (v).rbegin(), (v).rend()
// #define tr(c, it) for (auto it = (c).begin(); (it) != (c).end(); it++)
// #define check(c, val) ((c).find(val) != (c).end())      // for sets, multisets, maps etc.
// #define ccheck(c, val) (find((c).begin(), (c).end(), val) != (c).end()) // for others
 
// #define pb push_back
// #define F first
// #define S second
 
// #define ff(i, a, b) for(int i = (a);i < (b); i++)
// #define fF(i, a, b, c) for(int i = (a);i < (b); i+=(c))
// #define fb(i, a, b) for(int i = (b); i >= (a); i--)
// #define fB(i, a, b, c) for(int i = (b); i >= (a); i-=(c))
// #define fo(i, n) forf(i, 0, n)
// #define fob(i, n) forb(i, 0, n - 1)
 
// template <class T> void show(vector<vector<T>> &a) {for (auto &i : a) { for (T &j : i) cout << j << ' ' ; cout << endl; } }
// template <class T> void show(vector<vector<vector<T>>> &a) {for (auto &i : a) {show(i); } }
template <class T> void show(vector<T> &a) {for (T i : a) cout << i << ' ' ; cout << endl; }
// template <class T> void show(vector<pair<T, T>>&a) {trav(i,a) {cout << i.F << ' ' << i.S << endl;}}
// template <class T> void show(pair<T, T>p) {cout << p.F << ' ' << p.S << endl;}
// void show(vector<string>&a) {trav(i,a) cout << i << endl;}
// template<class T> void take(vector<T>&a) {trav(i,a) cin >> i;}

// const int INF = 9e18;
// const int mod = 7+1e9;
// const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};
void init_code(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

bool cmp(const pair<int,int> &a,const pair<int,int> &b){
    return a.first>b.first;
}
bool comp(int a,int b){
    return a>=b;
}
vector<int> solution(vector<int>  &A){
    // vector<pair<int,int> >  pairs;
    // for(int i=0;i<(int)A.size();i++){
    //     pairs.push_back({A[i],i});
    // }
    // sort(pairs.begin(),pairs.end(),cmp);
    // vector<int> result;
    // for(auto p:pairs){
    //     result.push_back(p.second);
    // }
    sort(A.begin(),A.end(),comp);
    return A;
}
void solve(){
    vector<int> v;
    for(int i=0;i<1e5;i++){
        v.push_back(1);
    }
    vector<int> ans=solution(v);
    show(ans);
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
 
 