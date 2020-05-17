#include <iostream>
#include <vector>

using std::vector;

int maxi(vector<double> A,vector<double> weights){
    double max=0;
    int j;
    
    for(int i=0;i<A.size();i++){
        if(max<A[i] && weights[i]>0){
            max= A[i];
            j = i;
        }
    }
    return j;
}
double min(double a,double b){
    if(a<b)
        return a;
    return b;
}
double get_optimal_value(double capacity, vector<double> weights, vector<double> values) {
  double value = 0.0000,a;

  // write your code here
    int n = weights.size(),ind;
    vector<double> A(n);
    
    for(int i=0;i<n;i++)
        A[i]=values[i]/weights[i];
    
    for(int i=0;i<n;i++){
        if(capacity==0)
            return value;
        ind = maxi(A,weights);
            
        a = min(weights[ind],capacity);
        value+=a*values[ind]*1.0/weights[ind];
        weights[ind]-=a;
        capacity-=a;
    }
   
    
  return value;
}

int main() {
  int n;
  double capacity;
  std::cin >> n >> capacity;
  vector<double> values(n);
  vector<double> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  //std::cout.precision(1);
  printf("%.4lf",optimal_value);
  return 0;
}
