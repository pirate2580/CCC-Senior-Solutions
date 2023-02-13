#include<bits/stdc++.h>
using namespace std;

int M,N,K;
vector<int>paintRow;
vector<int>paintCol;

int main(){
    cin>>M>>N>>K;
    paintRow.resize(M+1);
    paintCol.resize(N+1);

    //painting an entirely unpainted row increases by M
    //painting an entirely unpainted col increases by N

    int ans = 0;
    int rowPainted = 0;
    int colPainted = 0;
    for (int i=0;i<K;i++){
        char RowCol;int num;
        cin>>RowCol>>num;
        //cout<<'a'<<endl;
        //cout<<ans<<endl;
        if (RowCol=='R'){
            paintRow[num]=(paintRow[num]+1)%2;
            if (paintRow[num]==1){
                rowPainted++;
                ans +=N-(2*colPainted);
            }
            else{
                rowPainted--;
                ans+=(2*colPainted)-N;
            }
        }
        else if (RowCol=='C'){
            paintCol[num]= (paintCol[num]+1)%2;
            if (paintCol[num]==1){
                colPainted++;
                ans+=M-(2*rowPainted);
            }
            else{
                colPainted--;
                ans+=(2*rowPainted)-M;
            }
        }
        //cout<<ans<<endl;
    }

    cout<<ans<<endl;
    return 0;
}
