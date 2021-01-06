//Detecting cycle in a directed graph 
/*#include<bits/stdc++.h>
using namespace std;

void add_edges(int a,int b,vector<vector<int>>& v){
	v[a].push_back(b);
}

bool helper_cycle(int adj_node,vector<vector<int>>& v,vector<bool>& visited){
	if(visited[adj_node] == true){
		return true;
	}
	visited[adj_node] = true;
	for(int k=0;k<v[adj_node].size();k++){
		if(helper_cycle(v[adj_node][k],v,visited)){
			return true;
		}
	}
	visited[adj_node] = false;
	return false;
}

bool solve(vector<vector<int>>& v,int n){
	vector<bool> visited(n,false);
	for(int i=0;i<v.size();i++){
		if(visited[i] == false){
			visited[i] = true;
			for(int j=0;j<v[i].size();j++){
				if(helper_cycle(v[i][j],v,visited)){
					return true;
				}
			}
			visited[i] = false;
		}
	}
	return false;
}

int main(){
	int n = 6;
	//cout<<"No of vertices"<<endl;
	//cin>>n;
	vector<vector<int>> v(n,vector<int>());
	add_edges(0,1,v);
	add_edges(1,2,v);
	add_edges(2,3,v);
	add_edges(3,4,v);
	add_edges(4,5,v);
	//add_edges(5,0,v);
	bool cycle_present;
	cycle_present = solve(v,n);
	if(cycle_present){
		cout<<"There is a cycle in graph"<<endl;
	}else{
		cout<<"There is no cycle in graph"<<endl;
	}
	return 0;
}*/


//Detecting cycle in a undirected graph
/*#include<bits/stdc++.h>
using namespace std;

void add_edges(int a,int b,vector<vector<int>>& v){
	v[a].push_back(b);
	v[b].push_back(a);
}

bool cycle_helper(int node,int parent,vector<vector<int>>& v,vector<bool>& visited){
	visited[node] = true;
	for(int j=0;j<v[node].size();j++){
		if(visited[v[node][j]] == false){
			if(cycle_helper(v[node][j],node,v,visited)){
				return true;
			}
		}else{
			if(v[node][j]!=parent){
				return true;
			}
		}
	}
	return false;
}

bool solve(vector<vector<int>>& v,int n){
	vector<bool> visited(v.size(),false);
	int parent;
	for(int i=0;i<v.size();i++){
		if(visited[i] == false){
			if(cycle_helper(i,-1,v,visited)){
				return true;
			}
		}
	}
	return false;
}

int main(){
	int n = 6;
	vector<vector<int>> v(n,vector<int> ());
	add_edges(0,1,v);
	add_edges(1,2,v);
	add_edges(2,3,v);
	add_edges(3,4,v);
	add_edges(4,5,v);
	//add_edges(5,1,v);
	//add_edges(5,0,v);
	bool cycle_present;
	cycle_present = solve(v,n);
	if(cycle_present){
		cout<<"There is a cycle in graph"<<endl;
	}else{
		cout<<"There is no cycle in graph"<<endl;
	}
	return 0;
}*/

//Printing cycles in undirected graph
/*#include<bits/stdc++.h>
using namespace std;

void add_edges(int a,int b,vector<vector<int>>& v){
	v[a].push_back(b);
	v[b].push_back(a);
}

void cycle_helper(int node,int par,vector<vector<int>>& v,vector<bool>& visited,vector<vector<int>>& cycles,int& cycle_number,vector<int>& parent){
	visited[node] = true;
	for(int j=0;j<v[node].size();j++){
		//parent[v[node][j]] = node;
		if(visited[v[node][j]] == false){
			parent[v[node][j]] = node;
			cycle_helper(v[node][j],node,v,visited,cycles,cycle_number,parent);
		}else{
			if(v[node][j]!=par){
				cycle_number++;
				int temp_par = v[node][j];
				int c = 0;
				while(temp_par != node){
					temp_par = parent[temp_par];
					cycles[cycle_number].push_back(temp_par);
				}
				cycles[cycle_number].push_back(v[node][j]);
				parent[v[node][j]] = node;
			}
		}
	}
}

void solve(vector<vector<int>>& v,int n,vector<vector<int>>& cycles,int& cycle_number,vector<int>& parent){
	vector<bool> visited(v.size(),false);
	for(int i=0;i<v.size();i++){
		if(visited[i] == false){
			parent[i] = -1;
			cycle_helper(i,-1,v,visited,cycles,cycle_number,parent);
		}
	}
}

int main(){
	int n = 6;
	vector<vector<int>> v(n,vector<int> ());
	add_edges(0,1,v);
	add_edges(1,2,v);
	add_edges(2,3,v);
	add_edges(3,4,v);
	add_edges(4,5,v);
	add_edges(5,1,v);
	add_edges(5,0,v);
	vector<vector<int>> cycles;
	vector<int> parent;
	int cycle_number = 0;
	solve(v,n,cycles,cycle_number,parent);
	for(int i=0;i<cycles.size();i++){
		cout<<"Cycle"<<endl;
		for(int j=0;j<cycles[i].size();j++){
			cout<<cycles[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}*/


#include<bits/stdc++.h>
using namespace std;

void add_edges(int a,int b,vector<vector<int>>& v){
	v[a].push_back(b);
	//v[b].push_back(a);
}

void cycle_helper(int i,int par,int n,vector<vector<int>>& v,vector<int>& parent,vector<int>& mark,vector<int>& visited,int& cycle_number){
	if(visited[i] == 2){
		return;
	}
	if(visited[i] == 1){
		cycle_number++;
		int curr = par;
		mark[curr] = cycle_number;
		while(curr != i){
			curr = parent[curr];
			mark[curr] = cycle_number;
		}
		return;
	}

	parent[i] = par;
	visited[i] = 1;

	for(int j=0;j<v[i].size();j++){
		if(v[i][j] == parent[i]){
			continue;
		}
		cycle_helper(v[i][j],i,n,v,parent,mark,visited,cycle_number);
	}

	visited[i] = 2;
}

void solve(int n,vector<vector<int>>& v){
	vector<int> parent(n);
	int cycle_number = 0;
	vector<int> mark(n);
	vector<int> visited(n);
	for(int i=0;i<v.size();i++){
		cycle_helper(i,-1,n,v,parent,mark,visited,cycle_number);
	}

	vector<vector<int>> cycles(n,vector<int> ());
	for(int i=0;i<mark.size();i++){
		cycles[mark[i]].push_back(i);
	}
	for(int i=0;i<cycles.size();i++){
		if(cycles[i].size() > 1){
			cout<<"Cycle"<<endl;
			for(int j=0;j<cycles[i].size();j++){
				cout<<cycles[i][j]<<" ";
			}
			cout<<endl;
		}
	}
}

int main(){
	int n = 12;
	vector<vector<int>> v(n,vector<int> ());
	add_edges(0,1,v);
	add_edges(1,2,v);
	add_edges(2,3,v);
	add_edges(3,4,v);
	add_edges(3,5,v);
	add_edges(5,6,v);
	add_edges(6,0,v);
	add_edges(4,7,v);
	add_edges(7,8,v);
	add_edges(8,4,v);
	add_edges(8,9,v);
	add_edges(9,10,v);
	add_edges(10,11,v);
	add_edges(11,9,v);
	solve(n,v);
}

