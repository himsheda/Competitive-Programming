#include <iostream>
#include <vector>
using namespace std;


int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int a,b;
	    cin>>a>>b;
	    vector<vector<int> > ans(8,vector<int>(8,0));
	    ans[a-1][b-1]=1;
	    if(a==1&&b==1){
	        ans[2][1]=2;
	    }
	    else if(a==1&&b==8){
	        ans[1][5]=2;
	    }
	    else if(a==8&&b==8){
	        ans[5][6]=2;
	    }
	    else if(a==8&&b==1){
	        ans[5][1]=2;
	    }
	    else if(b==1){
	        ans[a][2]=2;
	        ans[a-2][2]=2;
	    }
	    else if(b==8){
	        ans[a][5]=2;
	        ans[a-2][5]=2;
	    }
	    else if(a==1){
	        ans[2][b]=2;
	        ans[2][b-2]=2;
	    }
	    else if(a==8){
	        ans[5][b]=2;
	        ans[5][b-2]=2;
	    }
	    else if(a==2&&b==2){
	        ans[0][3]=2;
	        ans[4][0]=2;
	    }
	    else if(a==2&&b==7){
	        ans[0][3]=2;
	        ans[3][7]=2;
	    }
	    else if(a==7&&b==2){
	        ans[3][0]=2;
	        ans[7][3]=2;
	    }
	    else if(a==7&&b==7){
	        ans[7][4]=2;
	        ans[3][7]=2;
	    }
	    else if(a==2){
	        ans[0][b-3]=2;
	        ans[2][b+1]=2;
	    }
	    else if(a==7){
	        ans[7][b-3]=2;
	        ans[5][b+1]=2;
	    }
	    else{
	        ans[a-3][b-2]=2;
	        ans[a+1][b]=2;
	    }
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
	}
	return 0;
}
