#include<iostream>
#include<vector>

using namespace std; 

void Merge(vector<int>& v, int low, int middle, int end)
{
	
	int p = low;
	int q = middle+1;
    int k = 0; 
    vector<int> arr;
    arr.reserve(end-low+1);

   while(p <= end) {
    
    if(p > middle) {

        arr[k++] = v[q++];
    }
    else if(q > end) {
    	 arr[k++]  = v[p++];
    }
    else if (v[p] > v[q]) {

    	 arr[k++]  = v[q++] ;

    }
    else {

    	 arr[k++]  = v[p++];
    }
}

 for(int i =0 ;p < k  ; i++) {         

 		v[low++] = arr[i++];

 		//cout<< arr[i] ;
 }
}

void MergeSort(vector<int>& v , int low, int high) {
	
	if(low >= high) return ;

	int middle = (low + high ) /2 ; 

	MergeSort(v,low,middle);
	MergeSort(v,middle+1,high);

	Merge(v,low,middle,high);
}


int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  MergeSort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}