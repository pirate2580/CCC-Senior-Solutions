#include<bits/stdc++.h>
using namespace std;

int N,M;
int p,q;
vector<vector<int>>adj;
vector<bool>visited;

void DFS(int node){
    visited[node]=true;

    for (auto neighbour:adj[node]){
        if (!visited[neighbour]){
            DFS(neighbour);
        }
    }
    return;
}


int main(){
    cin>>N>>M;
    vector<int>temp;
    adj.resize(100010,temp);
    visited.resize(100010);

    for (int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
    }
    cin>>p>>q;
    DFS(p);
    int flag = 0;
    if (visited[q]){
        cout<<"yes"<<endl;
        flag = 1;
    }
    visited=vector<bool>(100010,false);
    DFS(q);
    if (visited[p]){
        cout<<"no"<<endl;
        flag = 2;
    }
    if (flag ==0){
        cout<<"unknown"<<endl;
    }

    return 0;
}
