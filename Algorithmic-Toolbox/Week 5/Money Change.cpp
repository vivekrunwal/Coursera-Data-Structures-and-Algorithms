#include <iostream>

int get_change(int m) {
  //write your code here
  int coin[3] = {1,3,4},minN[m+1],numCoin;
    minN[0]=0;
  for(int i=1;i<=m;i++){
      minN[i] = 10001;
      for(int j=0;j<3;j++){
          if(i>=coin[j]){
           numCoin = minN[i-coin[j]]+1;
           if(numCoin<minN[i])
            minN[i]=numCoin;
          }
      }
  }    
    
  
  return minN[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
