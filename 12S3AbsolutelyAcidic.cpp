#include<bits/stdc++.h>
using namespace std;


int N;
vector<int>arr;
vector<int>freqArr;
vector<pair<int,int>>freq;

int main(){
    cin>>N;
    arr.resize(N);
    freqArr.resize(1001);

    vector<int>top;
    vector<int>scnd;

    for (int i=0;i<N;i++){
        cin>>arr[i];
        freqArr[arr[i]]++;
    }

    for (int i = 1;i<=1000;i++){
        freq.push_back({freqArr[i],i});
    }

    sort(freq.begin(),freq.end());

    /*
    for (int i=0;i<freq.size();i++){
        cout<<freq[i].first<<' '<<freq[i].second<<endl;
    }
    */
    int i = freq.size()-1;
    int maxim = freq[i].first;

    while (freq[i].first==maxim&&i>=0){
        top.push_back(freq[i].second);
        i--;
    }

    int sndMaxim = freq[i].first;
    while (freq[i].first==sndMaxim&&i>=0){
        scnd.push_back(freq[i].second);
        i--;
    }
    sort(top.begin(),top.end());
    sort(scnd.begin(),scnd.end());

    /*
    for (int i=0;i<top.size();i++){
        cout<<top[i]<<' ';
    }
    cout<<endl;
    for (int i=0;i<scnd.size();i++){
        cout<<scnd[i]<<' ';
    }
    cout<<endl;
    */

    if (top.size()==1){
        cout<<max(abs(scnd[0]-top[0]),abs(scnd[scnd.size()-1]-top[0]))<<endl;
    }
    else{
        cout<<(abs(top[top.size()-1]-top[0]))<<endl;
    }
    return 0;
}
