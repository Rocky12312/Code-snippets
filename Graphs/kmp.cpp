#include<bits/stdc++.h>
using namespace std;

vector<int> compute_lps(string patt){
	vector<int> lps(patt.size(),0);
	for(int i=1;i<lps.size();i++){
		int j = lps[i-1];
		while(j > 0 && patt[i] != patt[j]){
			j = lps[j-1];
		}
		if(patt[i] == patt[j]){
			lps[i] = j+1;
		}
	}
	return lps;
}

void run_kmp(string txt,string patt){
	int len_txt = txt.length()-1;
	int len_patt = patt.length()-1;

	vector<int> lps;
	lps = compute_lps(patt);
	int i=0;
	int j=0;
	while(i<len_txt){
		if(txt[i] == patt[j]){
			i++;
			j++;
		}
		if(j == len_patt){
			cout<<"The pattern start from the index: "<<i-j<<endl;
			j = lps[j-1];
		}
		else if(i < len_txt && txt[i] != patt[i]){
			if(j != 0){
				j = lps[j-1];
			}else{
				i = i+1;
			}
		}
	}
}

int main(){
	string txt = "abcdedcd"; 
    string patt = "cd"; 
    run_kmp(txt, patt); 
    return 0; 
}