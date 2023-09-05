#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    vector<bool> prime(1e6+2,1);

    for (int p = 2; p * p <= 1e6+1; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= 1e6+1; i += p)
                prime[i] = false;
        }
    }
    vector<int> prime_list;
    prime_list.push_back(2);
    for(int i=3;i<=1e6;i+=2){
        if(prime[i]){
            prime_list.push_back(i);
        }
    }
    while(t--){
        int x,y,m;
        cin>>x>>y>>m;
        int floor=__gcd(x,y);
        int x_factor = x/floor;
        int y_factor = y/floor;
        int time=0;
        for(int i=0;i<m;i++){
            int prime_number=prime_list[i];
            if(prime_number>=m){
                break;
            }
            while(x_factor%prime_number==0){
                x_factor=x_factor/prime_number;
                time++;
            }
            while(y_factor%prime_number==0){
                y_factor=y_factor/prime_number;
                time++;
            }
            if(x_factor==1 && y_factor ==1){
                break;
            }
        }
        if(x_factor==1 && y_factor==1){
            cout<<time<<" "<<floor<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
}