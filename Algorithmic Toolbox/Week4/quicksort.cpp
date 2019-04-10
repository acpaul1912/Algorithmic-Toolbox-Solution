#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std; 


std::pair<int,int>  partitaion(vector<int>& v , int l ,int r) {

	int x = v[l];

	int low = l;
	int mid = low;
	int high = r;

	while(mid <= high) {

		if(v[mid] < x) {
			swap(v[mid++], v[low++]);
		}
		else if(v[mid] == x) 
			mid++;
		else if(v[mid] > x) {
			swap(v[mid],v[high--]);
		}
	}

	return make_pair(low,mid);

}



void random_QuickSort(vector<int>& v , int l , int r) {

     if(l >= r) return ;

     int k = l + rand() % r -l +1 ;

      swap(v[l], v[k]);

      std::pair<int,int> p = partitaion(v,l,r);
      
      random_QuickSort(v,l,p.first);
      random_QuickSort(v,p.second,r);


 }

 int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  random_QuickSort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}








