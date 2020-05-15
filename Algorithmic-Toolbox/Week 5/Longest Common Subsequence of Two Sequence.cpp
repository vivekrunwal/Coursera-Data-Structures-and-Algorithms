#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;
using std::vector;



long int lcs2(vector<long int> &a, vector<long int> &b) {
  //write your code here
  int n = a.size(),m=b.size();
  long int D[n+1][m+1];
  
  for(int i=0;i<n+1;i++)
    D[i][0]=0;
  
  for(int j=0;j<m+1;j++)
    D[0][j]=0;
    
  for(int i=1;i<n+1;i++){
      for(int j=1;j<m+1;j++){
          if(a[i-1]==b[j-1])
            D[i][j]=D[i-1][j-1]+1;
        else
            D[i][j]= max(D[i-1][j],D[i][j-1]);
      }
  }
  
  return D[n][m];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<long int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<long int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
