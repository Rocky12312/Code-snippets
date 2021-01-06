#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>& v,int k){
    vector<int> ans;
    int i=0,j=0;
    list<int> l;
    while(j<v.size()){
        //Condition
        while(l.size() > 0 && l.back() < v[j]){
            l.pop_back();
        }
        l.push_back(v[j]);
        if(j-i+1<k){
            j++;
        }
        else if(j-i+1==k){
            //Calculating answer
            ans.push_back(l.front());
            //Sliding window
            if(v[i] == l.front()){
                l.pop_front();
            }
            i++;
            j++;
        }
    }
    return ans;
}

int main () {
    vector<int> v = {1,2,3,4,5,6};
    int k = 3;
    vector<int> ans;
    ans = solve(v,k);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}