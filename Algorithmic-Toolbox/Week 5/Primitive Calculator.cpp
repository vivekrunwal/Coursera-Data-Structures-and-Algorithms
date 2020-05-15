#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  std::vector<int> count(n+1,0);
  
  for(int i=1;i<=n;i++){
      count[i]=count[i-1]+1;
      if(i%2==0)
            count[i]=min(count[i/2]+1,count[i]);
      if(i%3==0)
            count[i]=min(count[i/3]+1,count[i]);
            
  }
  
  int i = n;
  while(i>=1){
      sequence.push_back(i);
      if(count[i]==count[i-1]+1)
        i-=1;
    else if(i%3==0 && count[i]==count[i/3]+1)
        i/=3;
    else if(i%2==0 && count[i]==count[i/2]+1)
        i/=2;

  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
