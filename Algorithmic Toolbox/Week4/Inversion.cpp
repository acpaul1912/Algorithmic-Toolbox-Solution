#include <iostream>
#include <vector>

using std::vector;

int merge(vector<int> &arr , vector<int> &temp, size_t left, size_t mid, size_t right) 
{ 
  size_t i, j, k; 
  size_t inv_count = 0; 
  
  i = left; /* i is index for left subarray*/
  j = mid;  /* j is index for right subarray*/
  k = left; /* k is index for resultant merged subarray*/
  while ((i <= mid - 1) && (j <= right)) 
  { 
    if (arr[i] <= arr[j]) 
    { 
      temp[k++] = arr[i++]; 
    } 
    else
    { 
      temp[k++] = arr[j++];  
     
      inv_count = inv_count + (mid - i); 
    } 
  } 
  
  /* Copy the remaining elements of left subarray 
   (if there are any) to temp*/
  while (i <= mid - 1) 
    temp[k++] = arr[i++]; 
  
  /* Copy the remaining elements of right subarray 
   (if there are any) to temp*/
  while (j <= right) 
    temp[k++] = arr[j++]; 
  
  /*Copy back the merged elements to original array*/
  for (i=left; i <= right; i++) 
    arr[i] = temp[i]; 
  
  return inv_count; 
} 

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right > left) {
    size_t ave = (left + right ) / 2;
    number_of_inversions += get_number_of_inversions(a, b, left, ave);
    number_of_inversions += get_number_of_inversions(a, b, ave+1, right);
    //write your code here

    number_of_inversions += merge(a,b,left,ave+1,right);
  }
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()-1) << '\n';
}
