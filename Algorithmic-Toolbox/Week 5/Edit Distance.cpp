#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

using std::string;
int min1(int x,int y,int z){
    if(min(x,y)>z)
        return z;
    else 
        return min(x,y);
}
int edit_distance(const string &str1, const string &str2) {
  //write your code here
  int n = str1.size(),m=str2.size();
  int D[n+1][m+1],ins,mis,mat,del;
  
  for(int i=0;i<n+1;i++)
    D[i][0]=i;
  
  for(int j=0;j<m+1;j++)
    D[0][j]=j;
    
  for(int i=1;i<n+1;i++){
      for(int j=1;j<m+1;j++){
            ins =D[i][j-1]+1;
            del = D[i-1][j]+1;
            mat = D[i-1][j-1];
            mis = D[i-1][j-1]+1;
          if(str1[i-1]==str2[j-1])
            D[i][j]=min1(ins,del,mat);
        else
            D[i][j]= min1(ins,del,mis);
      }
  }
  
  return D[n][m];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
