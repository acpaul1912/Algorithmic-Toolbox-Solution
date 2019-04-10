#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  
  int max = 0;
  vector<vector<int>> maxWeight(w.size()+1,vector<int>((W+1),0));  

  for(int i = 1 ; i< w.size()+1 ; i++) {       
  
  for(int j = 1; j < W+1  ; j++)
    {
       maxWeight[i][j] = maxWeight[i-1][j] ;     
      int val = 0;
      if(w[i-1] <= j) {

          val = maxWeight[i-1][j-w[i-1]] + w[i-1];
       
       } 

       if(val > maxWeight[i][j]) {
          maxWeight[i][j] = val;
       }
      
        
    }

  }

 return maxWeight[w.size()][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
