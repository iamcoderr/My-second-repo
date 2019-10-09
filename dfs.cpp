#include<iostream>
using namespace std;
void dfs(int **graph,int v,int start,int *visited){
	if(visited[start]==1){
		return ;
	}
	visited[start]=1;
	cout<<start+1<<" ";
	for(int i=0;i<v;i++){
		if(graph[start][i] ==1){
			dfs(graph,v,i,visited);
		}
	}
}
int main(){
	int v,e,i,a,b,d;
	i=0;e=0;
	cout<<"Number of vertices & edges :";
	cin>>v>>e;
	cout<<"Is graph directed or not (1/0) :";
	cin>>d;
	int **graph = new int*[v];
	int *visited= new int[v];
	for(i=0;i<v;i++){
		graph[i] = new int[v];
		visited[i]=0;
		for(int j=0;j<v;j++){
			graph[i][j]=0;
		}
	}
	for(i=0;i<e;i++){
		cin>>a>>b;
		graph[a-1][b-1]=1;
		if(d==0)
		   graph[b-1][a-1]=1;
	}
	dfs(graph,v,0,visited);
}
