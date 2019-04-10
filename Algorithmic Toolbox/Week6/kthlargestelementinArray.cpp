/* find the kthe biggest number */

#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

std::pair<int,int> partitation(vector<int>& vec, int l, int r) {
	int x = vec[l];
	int low = l;
	int mid = low;
	int high = r;

	while(mid <= high) {

		if(vec[mid] < x) {

			swap(vec[mid++],vec[low++]);
		}
		else if( vec[mid] == x) {

			mid++;
		}
		else {

			swap(vec[mid],vec[high--]);
		}
	}

	return {low,mid};
}


int findKtheElement(vector<int>& vec, int l, int r, int index){
		
	if(l>= r) return -1;

	int k = l + rand() %(r-l+1);

	swap(vec[l],vec[k]);

	auto it= partitation(vec,l,r);

	if(it.first <= index && it.second > index) {

		return vec[it.first];
	}
	else if(it.first > index) {

		return findKtheElement(vec,l,it.first,index);
	}
	else {
		return findKtheElement(vec,it.second,r,index);
	}
}

int main() {
	
	int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }

  cout<<" Enter the index" <<endl;
  int i;
  cin>>i;
  cout<< findKtheElement(a, 0, a.size() - 1, i-1);
}