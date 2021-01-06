#include<bits/stdc++.h>
using namespace std;

int main () {
    string s = "abcab";
    string ptr = "abc";
    int k = ptr.length();
    int i=0,j=0;
    map<char,int> mp;
    for(int m=0;m<k;m++){
        mp[ptr[m]]++;

    }
    int count = mp.size();
    int ans = 0;
    while(j<s.length()){
        if(mp[s[j]]){
            mp[s[j]]--;
            if(mp[s[j]] == 0){
                count--;
            }
        }
        if(j-i+1<k){
            j++;
        }
        else if(j-i+1==k){
            if(count==0){
                ans++;
                //cout<<s.substring(i,j+1)<<endl;
            }
            if(mp.find(s[i]) != mp.end()){
                mp[s[i]]++;
                if(mp[s[i]] == 1){
                    count++;
                }
            }
            i++;
            j++;
        }
    }
    cout<<ans<<endl;
}