#include<bits/stdc++.h>
using namespace std;

int M,N;
vector<vector<pair<int,int>>>adj;
vector<vector<bool>>visited;
vector<vector<int>>grid;

//-1 the indices because you +1 earlier

void DFS(pair<int,int>node){
    visited[node.first][node.second]=true;
    for (auto neighbour:adj[grid[node.first][node.second]]){
        if (!visited[neighbour.first][neighbour.second]){
            //cout<<neighbour.first<<' '<<neighbour.second<<endl;
            DFS(neighbour);
        }
    }
}


int main(){
    cin>>M>>N;
    adj.resize(1000001);
    vector<bool>temp(N,false);
    visited.resize(M,temp);

    for (int i=0;i<M;i++){
        vector<int>row;
        row.resize(N);
        for (int j=0;j<N;j++){
            cin>>row[j];
        }
        grid.push_back(row);
    }

    /* print statement for grid
    for (int i=0;i<M;i++){
        for (int j=0;j<N;j++){
            cout<<grid[i][j]<<' ';
        }
        cout<<endl;
    }
    */

    for (int i=0;i<M;i++){
        for (int j=0;j<N;j++){
            adj[(i+1)*(j+1)].push_back({i,j});
        }
    }

    DFS({0,0});
    if (visited[M-1][N-1]){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
    return 0;
}
