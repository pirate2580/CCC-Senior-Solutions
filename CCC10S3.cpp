#include <bits/stdc++.h>
using namespace std;

vector<int> arr;//this is the array holding the positions of the houses
int H;// number of houses
int K;// number of firehoses to use

bool check(int dist, int K, int index) {
  int startIndex = index;
  int pos = arr[index]+dist;

  while (index<startIndex+H&&K>=0){
    //cout<<pos<<' '<<pos+dist<<' '<<index<<endl;
    if (pos+dist>=arr[index])
    {
      index++;
    }
    else if (K>0){
      K--;
      pos = dist+arr[index];
    }
    else{
      return false;
    }
  }
  return true;
}

int main() {
  cin >> H;
  arr.resize(H);
  for (int i = 0; i < H; i++) {
    cin >> arr[i];
  }
  cin >> K;
  sort(arr.begin(), arr.end());

  for (int i=0;i<H;i++){
    arr.push_back(1000000+arr[i]);
  }

  vector<int>ansList;

  for (int index =0;index<H;index++){
    int left = 0;
    int right = 1000001;

    while(left<right){
      int mid = (left+right)/2;
      //cout<<"distance checked: "<<mid<<endl;
      if (check(mid, K-1, index)){
        right = mid;
        //cout<<"best ans "<<ans<<endl;
      }
      else {
        left = mid+1;
      }
    }
    ansList.push_back(left);
  }
  cout << *min_element(ansList.begin(), ansList.end()) << endl;
  return 0;
}
