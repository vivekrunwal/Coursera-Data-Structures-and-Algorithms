#include <iostream>
#include <vector>
using namespace std;

long long maxPair(vector<long int> &numbers,int n){
    long max=-1,max1=-1;
    int j;
    
    for(int i=0;i<n;i++){
        if(max<numbers[i]){
            max=numbers[i];
            j=i;
        }
    }
    
    numbers.erase(numbers.begin()+j);
    
     for(int i=0;i<n-1;i++){
        if(max1<numbers[i])
            max1=numbers[i];
    }
    
    long long ans = max*max1;
    return ans;
    
}
int main() {
	int n;
	cin>>n;
	vector<long int> numbers(n);
	
	for(int i=0;i<n;i++)
	    cin>>numbers[i];
	
	cout<<maxPair(numbers,n);
	    
	return 0;
	
}