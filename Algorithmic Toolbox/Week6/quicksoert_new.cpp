/* Three way partitation  in array */

#include<iostream>
#include<vector>
#include<cstdlib>

using namespace  std; 

std::pair<int,int> partitation(vector<int> &vec, int l , int r) {
	
	int x = vec[l];

	int low = l;
	int mid = low;
	int high = r;

	while(mid <= high){

		if(vec[mid] < x){

			swap(vec[mid++],vec[low++]);
		}

		else if (vec[mid] == x) {
			mid++;
		}
		else {
			swap(vec[mid],vec[high--]);
		}

	}

    cout<< low << "    " << mid	 <<endl;

	return std::make_pair(low-1,mid);
}

void quieckSort(vector<int> &vec, int l, int r){
	if(l >= r) return ;

	int k = l + rand() % (r-l+1);

	swap(vec[l],vec[k]);

	auto it= partitation(vec,l,r);

	quieckSort(vec,l,it.first);
	quieckSort(vec,it.second,r);
}

int main() {
	
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  quieckSort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }

}



