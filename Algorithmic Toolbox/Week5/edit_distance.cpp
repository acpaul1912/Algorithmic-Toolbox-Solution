#include <iostream>
#include <string>
#include<vector>
using std::vector;

using std::string;

int edit_distance(const string &str1, const string &str2) {
 
     vector<vector<int>> matrix;
     matrix.resize(str1.length()+1);
     for(int i = 0; i < matrix.size(); i ++){
     	matrix[i].resize(str2.length()+1);
     }

     for(int i = 0; i < matrix.size(); i++ ){
     	for(int j = 0; j < matrix[i].size(); j++) {

     		if(i ==0 ) matrix[i][j] = j;
     		else if(j == 0) matrix[i][j] = i;
     		else {

	     		int min1 = std::min((1+matrix[i][j-1]),(1+matrix[i-1][j]));

	     		int min2 =  1 + matrix[i-1][j-1];

	     		if(str1[i-1] == str2[j-1]) {

	               min2 = matrix[i-1][j-1];
	     		}
     		
                matrix[i][j] = std::min(min1,min2);

           }
     			
     	}

     }
     
    return (matrix[str1.length()][str2.length()]);

}


int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}