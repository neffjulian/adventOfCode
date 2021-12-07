#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

typedef std::vector<int> VI;

int calcMedian(std::vector<int> v) {
    size_t n = v.size() / 2;
    std::nth_element(v.begin(), v.begin()+n, v.end());
    return v[n];
}

int calcMean(std::vector<int> v) {
    int sum = 0;
    for(size_t i = 0; i < v.size(); i++) {
      sum += v[i];
    }
    return sum / v.size();
}

int distPartB(int n) {
  return (n*(n+1))/2;
}

void funcA(VI numbers) {
  int median = calcMedian(numbers);
  int sum = 0;
  
  for(size_t i = 0; i < numbers.size(); i++) {
    sum += std::abs(numbers[i] - median);
  }
  
  std::cout << sum << "\n";
}

void funcB(VI numbers) {
  int mean = calcMean(numbers);
  int sum = 0;
  
  for(size_t i = 0; i < numbers.size(); i++) {
    sum += distPartB(std::abs(numbers[i] - mean));
  }
  
  std::cout << sum << "\n";
}

int main() {
  std::ios_base::sync_with_stdio(false);
  
  VI numbers;
  std::string input;
  while(std::cin >> input) {
    std::stringstream ss(input);
    for(int i; ss >> i;) {
      numbers.push_back(i);    
      if (ss.peek() == ',') {
        ss.ignore();
      }
    } 
  }
  
  funcA(numbers);
  funcB(numbers);
}
