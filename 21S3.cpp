#include<bits/stdc++.h>
using namespace std;

int N;
vector<vector<long long>>arr;

long long check(long long c){//returns the time it takes
    long long time = 0;
    for (int i=0;i<N;i++){
        if (arr[i][0]<=c&&(c-arr[i][0]-arr[i][2]>0)){
            time+=arr[i][1]*(c-arr[i][0]-arr[i][2]);
        }
        else if (arr[i][0]>c&&(arr[i][0]-arr[i][2]-c)>0){
            time+=arr[i][1]*(arr[i][0]-arr[i][2]-c);
        }
    }
    //cout<<time<<endl;
    return time;
}

int main(){
    cin>>N;
    vector<long long>temp;
    temp.resize(3);
    arr.resize(N,temp);

    for (int i=0;i<N;i++){//position, speed, acceptable distance
        long long a,b,c;
        cin>>a>>b>>c;
        arr[i][0]=a;
        arr[i][1]=b;
        arr[i][2]=c;
    }

    long long c = 0;

    for (int jump=1e9-1;jump>0;jump/=2){
        //cout<<"new val: "<<check(c+jump)<<endl;
        while (c+jump<=1e9&&(check(c+jump-1)>=check(c+jump)&&check(c+jump)>=check(c+jump+1))){
            //cout<<"L+ratio"<<endl;
            c+=jump;
            //cout<<"c is: "<<c<<' '<<check(c)<<endl;
        }
    }
    //cout<<c<<endl;
    cout<<min(check(c+1),check(c))<<endl;

    /*
    for (int i=1;i<=14;i++){
        cout<<check(i)<<endl;
    }*/

    return 0;
}
