#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


void sortv(vector<int> &a){
    int temp;
    for(int i=0;i<a.size();i++)
        for(int j=i+1;j<a.size();j++){
            if(a[i]>a[j]){
                temp = a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
    
}

long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here
  
  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
   cin >> b[i];
  }
  sortv(a);
    sortv(b);
 
 cout << max_dot_product(a, b) << endl;
    
  }
 

