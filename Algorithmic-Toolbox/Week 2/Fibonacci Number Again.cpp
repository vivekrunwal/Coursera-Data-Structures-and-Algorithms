#include <iostream>
#include<vector>

using namespace std;
typedef long long int ll;

ll fibonacci(ll n,int m){
    vector<int> F;
    int l;
    int ans;
    F.push_back(0);
    F.push_back(1);
    
    for(ll i=2;i<=n;i++){
        F.push_back((F.at(i-1)+F.at(i-2))%m);
    
        if(F.at(i)==1 && F.at(i-1)==0){
            l = i-1;
            return F.at(n%l)%m;
        }
    }
    return F.at(n)%m;
}

int main() {
    ll n;
    int m;
    
    cin>>n>>m;
    cout<<fibonacci(n,m)<<"\n";
    return 0;
}
