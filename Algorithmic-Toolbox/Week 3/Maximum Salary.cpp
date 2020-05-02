#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

using std::vector;
using std::string;

string maxs(string a,string b){
    
    string XY = a+b;
    string YX = b+a;
    if(XY>YX)
        return a;
    else 
        return b;
    
}
int maxi(vector<string> a){
    string temp =a[0];
    if(a.size()==1)
        return 0;
        
        int j=0;
    for(int i=1;i<a.size();i++){
        temp=maxs(temp,a[i]);
    if(temp==a[i])
        j=i;
}
    return j;
}
string largest_number(vector<string> a) {
  //write your code here
 // std::stringstream ret;
  string result="",temp;
    
while(a.size()!=0){
    result+=a[maxi(a)];
    a.erase(a.begin()+maxi(a));
}
  //ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) 
    std::cin >> a[i];
  
 //cout<<maxs("980","98");
  std::cout << largest_number(a);
 
}
