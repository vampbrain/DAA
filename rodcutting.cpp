#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

int cutrod(int price[], int n){
  if (n==0) return 0;
  
  int res = 0;
  
  for (int i = 0; i<n; i++){
    res= max( res, price[i]+cutrod(price, n-i-1));
  }
  
  return res;
}

int main() 
{
    int arr[] = { 0, 5, 8, 9, 10, 17, 17, 20 };
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << cutrod(arr, size);
    return 0;
}
