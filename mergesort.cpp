#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int> &arr, int l, int mid, int h){
  vector <int> temp;
  int left = l;
  int right = mid+1;
  int i=0;
  
  while(left<=mid && right<=h){
    if (arr[left]<arr[right]){
      temp.push_back(arr[left]);
      left++;
    } else if (arr[right]<arr[left]){
      temp.push_back(arr[right]);
      right++;
    }
  }
  while (left<=mid){
    temp.push_back(arr[left]);
    left++;
  }
  while (right<=h){
    temp.push_back(arr[right]);
    right++;
  }
  
  for (int i = l; i <= h; i++) {
    arr[i] = temp[i - l];
    }
}

void mergesort(vector<int> &arr, int l, int h){
  if (l<h){
    int m = (l+h)/2;
    mergesort(arr, l, m);
    mergesort(arr, m+1, h);
    merge(arr,l, m, h);
  }
}



int main(){
  vector<int> arr = {9, 4, 7, 6, 3, 1, 5}  ;
    int n = 7;

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    mergesort(arr, 0, n-1);
    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    return 0 ;
}
