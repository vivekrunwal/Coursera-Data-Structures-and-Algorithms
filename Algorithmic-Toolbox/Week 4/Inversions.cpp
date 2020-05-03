#include <iostream>
#include <vector>

using std::vector;

int merge(vector<long int> &a,vector<long int> &b,int left,int mid,int right){
   int i=left,j=mid,k=left;
   int inv=0;
   
   while(i<=mid-1 && j<right){
       if(a[i]<=a[j])
        b[k++]=a[i++];
    else{
        b[k++]=a[j++];
        inv+=mid-i;   
    }
   }
   
   while(i<=mid-1)
    b[k++]=a[i++];
    while(j<right)
    b[k++]=a[j++];
    
    for(int i=left;i<right;i++)
        a[i]=b[i];
    
    return inv;    
}

long long get_number_of_inversions(vector<long int> &a, vector<long int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left+1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  //write your code here
    number_of_inversions+=merge(a,b,left,ave,right);
  
  
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<long int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<long int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
