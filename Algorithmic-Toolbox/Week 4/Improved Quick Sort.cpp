#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;
struct Point{
    int m1,m2;
};

Point partition3(vector<long int> &a, int l, int r) {
  long int x = a[l];
  int j=l,j1;
  Point m;
  
  for (int i = l + 1; i <= r; i++) {
    if (a[i] < x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  
  swap(a[l], a[j]);
  j1=j;
  
  for(int i=j+1;i<=r;i++){
      if(a[i]==x){
          j1++;
         swap(a[i], a[j1]);
      }
  }
  swap(a[j],a[j1]);
  
    m.m1 =j;
    m.m2 =j1;

return m;
}

void randomized_quick_sort(vector<long int> &a, int l, int r) {
    
  if (l >= r) {
    return;
  }
Point m;
  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
 // int m[2]={0,0};
  m = partition3(a, l, r);

  randomized_quick_sort(a, l, m.m1 - 1);
  randomized_quick_sort(a, m.m2 + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<long int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
