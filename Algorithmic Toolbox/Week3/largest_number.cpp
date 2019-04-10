#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

string largest_number(vector<string> a) {
  //write your code here
  std::stringstream ret;
  sort(a.begin(),a.end(), [](string& b , string& c) {

        if(b.size() == c.size()) {

            for(int i = 0; i < b.size(); i++) {
              
               if(b[i] == c[i]){
                   continue;
               }
              return b[i] > c[i];
            }
        }
        else if(b.size() > c.size()){

           int j = 0;
            for(int i = 0 ; i < c.size() ;j++, i++) {
                if(b[i] == c[i]){
                   continue;
               }
               return b[i] > c[i];
            }
           
           return b[j] > c[j-1] ;
        }

      else {

            int j = 0;
            for(int i = 0 ; i < b.size() ;j++, i++) {
                if(b[i] == c[i]){
                   continue;
               }
               return b[i] > c[i];
            }
           
           return b[j-1] > c[j] ;

      }
  });
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
