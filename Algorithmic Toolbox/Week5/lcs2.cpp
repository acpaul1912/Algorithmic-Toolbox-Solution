#include <iostream>
#include <vector>

using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
  vector<vector<int>> matrix;
     matrix.resize(a.size()+1);
     for(int i = 0; i < matrix.size(); i ++){
      matrix[i].resize(b.size()+1);
     }

     for(int i = 0; i < matrix.size(); i++ ){
      for(int j = 0; j < matrix[i].size(); j++) {

        if(i ==0 || j == 0 ) matrix[i][j] = 0;
        else if(a[i-1] == b[j-1]) matrix[i][j] = 1+ matrix[i-1][j-1] ;
        else {

              matrix[i][j] =  std::max((matrix[i][j-1]),(matrix[i-1][j])); 
         }
          
      }

     }
     
    return (matrix[a.size()][b.size()]);
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
