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

//k=using knapsack

struct rod{
  int len;
  int price;
  double profit;
};
bool compare(rod a, rod b){
  return a.profit>b.profit;}

double cutrod(int l[], int p[], int n, int m){
  vector<rod> rods(n);
  int length = 0;
  if (n==0) return 0;
  
  double maxprofit = 0;
  
  for (int i = 0; i<n; i++){
    rods[i] = {l[i], p[i], (double)p[i]/l[i]};
  }
  
  sort(rods.begin(), rods.end(), compare);
  
  for (int i=0; i<n; i++){
    if (rods[i].len<= m - length){
      length+=rods[i].len;
      maxprofit+=rods[i].price;
    } else{
      double fraction = (double)(m-length)/rods[i].len;
      length = m;
      maxprofit+= fraction * rods[i].price;
    }
      
  }
  
  return maxprofit;
}


// now using rodcutting dp

double cutrod(int l[], int p[], int n, int m) {
    vector<double> dp(m + 1, 0); // dp[i] will store the maximum profit for rod length i
    
    for (int i = 1; i <= m; i++) {
        double maxProfit = 0;
        for (int j = 0; j < n; j++) {
            if (i >= l[j]) {
                maxProfit = max(maxProfit, p[j] + dp[i - l[j]]);
            }
        }
        dp[i] = maxProfit;
    }
    
    return dp[m];
}
