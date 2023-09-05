# include<bits/stdc++.h>
using namespace std;

int main(){
    string s="Kg fcwd qh vin pnzy hjcocnt, cjjwg ku wnth nnyvng kxa cjjwg. Urfjm xwy yjg rbbufqwi vjg_djxn_ofs_dg_rmncbgi yq iq uqtxwlm. Oca zxw qcaj vjg tctnplyj hqs cjn pjcv ejbvdnt. Yt hkpe cjn gcnv, aqv okauy bknn ongm vt zvvgs vcpkh bqtft cjntj.";
    string lower="";
    for(int i=0;i<s.length();i++){
        if(s[i]>='a' && s[i]<='z'){
            lower+=s[i];
        }
        else if(s[i]>='A' && s[i]<='Z'){
            lower+=s[i]+32;
        }
    }
    vector<pair<string,int>> matched_substr;
    for(int i=0;i<lower.length();i++){
        for(int j=3;i+j<lower.length();j++){
            for(int k=i+j;k<lower.length();k++){
                if(lower.substr(i,j)==lower.substr(k,j)){
                    matched_substr.push_back({lower.substr(i,j),k-i});
                }
            }
        }
    }
    // print matched substrings
    for(int i=0;i<matched_substr.size();i++){
        cout<<matched_substr[i].first<<" "<<matched_substr[i].second<<endl;
    }
    int key_len;
    cin>>key_len;
    vector<string> blocks(key_len);
    for(int i=0;i<lower.length();i++){
        blocks[i%key_len]+=lower[i];
    }
    // print blocks
    for(int i=0;i<blocks.size();i++){
        cout<<blocks[i]<<endl;
    }
    // frequenci analysis for each block
    vector<vector<pair<char,int>>> freq_analysis(key_len);
    for(int i=0;i<blocks.size();i++){
        vector<int> freq(26,0);
        for(int j=0;j<blocks[i].length();j++){
            freq[blocks[i][j]-'a']++;
        }
        for(int j=0;j<26;j++){
            freq_analysis[i].push_back({(char)(j+'a'),freq[j]});
        }
        sort(freq_analysis[i].begin(),freq_analysis[i].end(),[](pair<char,int> a,pair<char,int> b){
            return a.second>b.second;
        });
    }
    // print freq analysis
    for(int i=0;i<freq_analysis.size();i++){
        for(int j=0;j<freq_analysis[i].size();j++){
            cout<<freq_analysis[i][j].first<<" "<<freq_analysis[i][j].second<<endl;
        }
        cout<<endl;
    }
    // replace each block's with most frequent letter with 'E'
    for(int i=0;i<blocks.size();i++){
        for(int j=0;j<blocks[i].length();j++){
            blocks[i][j]=((blocks[i][j]-'a')-(freq_analysis[i][0].first-'e')+26)%26+'a';
        }
    }
    // print blocks
    for(int i=0;i<blocks.size();i++){
        cout<<blocks[i]<<endl;
    }
    // print final string
    for(int i=0;i<lower.length();i++){
        cout<<blocks[i%key_len][i/key_len];
    }
    
    

    return 0;
}