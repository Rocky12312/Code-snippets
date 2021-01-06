#include<bits/stdc++.h>
using namespace std;

void generate_segment_tree(vector<int>& v,vector<int>& sgtree,int start,int end,int idx){
    if(start == end){
        sgtree[idx] = v[start];
        return;
    }
    int mid = (start+end)/2;
    generate_segment_tree(v,sgtree,start,mid,2*idx);
    generate_segment_tree(v,sgtree,mid+1,end,2*idx+1);
    sgtree[idx] = sgtree[2*idx]+sgtree[2*idx+1];
}

int main(){
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    vector<int> sgtree(v.size()*2,0);
    int start = 0;
    int end = 8;
    int idx = 1;//Initial
    generate_segment_tree(v,sgtree,start,end,idx);
    for(int i=0;i<v.size()*2;i++){
        cout<<sgtree[i]<<endl;
    }
}