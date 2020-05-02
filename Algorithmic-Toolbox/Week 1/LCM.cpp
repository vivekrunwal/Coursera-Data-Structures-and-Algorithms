#include <iostream>
typedef long long ll;
ll gcd(ll a,ll b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}

long long lcm(ll a, ll b) {
    
    long long ans = a*b/gcd(a,b);
    
  return ans;
}


int main() {
  ll a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}
