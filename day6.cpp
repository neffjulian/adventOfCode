#include <iostream>
#include <sstream>
#include <string>
#include <vector>


typedef std::vector<long> VI;
typedef std::vector<VI> VII;

void func() {
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
  
  VI fishOld(9, 0), fishNew(9, 0);
  for(size_t i = 0; i < numbers.size(); i++) {
    fishNew[numbers[i]]++;
  }

  for(int i = 0; i < 256; i++) {
    fishOld = fishNew;
    for(int j = 0; j < 8; j++) {
      fishNew[j] = fishOld[j+1];
    }
    fishNew[6] += fishOld[0];
    fishNew[8] = fishOld[0];
  }
  
  long sum = 0;
  for(size_t i = 0; i < fishNew.size(); i++) {
    sum += fishNew[i];
  }
  
  std::cout << sum << "\n";
}

int main() {
  std::ios_base::sync_with_stdio(false);
  func();
}
