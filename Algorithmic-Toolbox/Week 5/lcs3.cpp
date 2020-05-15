#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

using std::vector;


int lcs3(vector<long int> &a, vector<long int> &b, vector<long int> &c) {
  //write your code here
  
    int n = a.size(),m=b.size(),l = c.size();

  long int D[n+1][m+1][l+1];
  
  for(int i=0;i<n+1;i++){
      for(int k=0;k<l+1;k++)
        D[i][0][k]=0;
  }
  
  for(int i=0;i<n+1;i++){
      for(int j=0;j<m+1;j++)
        D[i][j][0]=0;
  }
  
  for(int j=0;j<m+1;j++){
      for(int k=0;k<l+1;k++)
        D[0][j][k]=0;
  }
  
  for(int i=1;i<n+1;i++){
      for(int j=1;j<m+1;j++){
            for(int k=1;k<l+1;k++){
          if(a[i-1]==b[j-1] && b[j-1]==c[k-1])
            D[i][j][k]=D[i-1][j-1][k-1]+1;
        else
            D[i][j][k]= max(max(D[i-1][j][k],D[i][j-1][k]),D[i][j][k-1]);
            }
      }
  }
  
  return D[n][m][l];

}

int main() {
  size_t an;
  std::cin >> an;
  vector<long int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<long int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<long int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
