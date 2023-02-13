#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

int R,C,K;
vector<pii>cat;
vector<vector<int>>grid;

int main(){

    cin>>R>>C>>K;

    vector<int>sub(C+1,0);
    grid.resize(R+1,sub);

    cat.resize(K);
    grid[1][1]=1;

    for (int i=0;i<K;i++){
        cin>>cat[i].first>>cat[i].second;
        grid[cat[i].first][cat[i].second]=-1;
    }
    /*
    for (int i=0;i<=R;i++){
        for (int j=0;j<=C;j++){
            cout<<grid[i][j]<<' ';
        }
        cout<<endl;
    }
    */
    for (int i=1;i<=R;i++){
        for (int j=1;j<=C;j++){
            int val1=0;
            int val2=0;
            if (i==1&&j==1){
                continue;
            }
            if (grid[i][j]!=-1){
                //cout<<'a'<<endl;
                if (grid[i-1][j]!=-1){
                    val1 = grid[i-1][j];
                }
                if (grid[i][j-1]!=-1){
                    val2 = grid[i][j-1];
                }
                //cout<<val1<<' '<<val2<<endl;
                grid[i][j]= val1+val2;
            }
        }
    }
    cout<<grid[R][C]<<endl;
    return 0;
}
