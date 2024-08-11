#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

//knapsack

struct Item{
  int weight;
  int profit;
  double ratio;
};

bool compare(Item a, Item b){
  return a.ratio>b.ratio;
}

double fractionalknapsack(int w[], int p[], int m, int n){
  vector<Item> items(n);
  int load = 0; double maxprofit = 0;
  
  for (int i=0; i<n; i++){
    items[i] = {w[i], p[i], (double)p[i]/w[i]};
  }
  
  sort(items.begin(), items.end(), compare);
  
  for (int i=0; i<n && load<m; i++){
    if (items[i].weight<m-load){
      load+= items[i].weight;
      maxprofit+= items[i].profit;
    }
    else{
      double fraction = (double) (m-load)/items[i].weight;
      load= m;
      maxprofit+= items[i].profit*fraction;
      break;
    }
  }
  
  return maxprofit;
}


int main() {
    int weights[] = {10, 20, 30};
    int profits[] = {60, 100, 120};
    int capacity = 50;
    int n = sizeof(weights) / sizeof(weights[0]);

    double maxProfit = fractionalknapsack(weights, profits, capacity, n);
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}
