#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <unordered_map>

typedef std::unordered_map<char, int> UM;
typedef std::vector<std::string> VS;

void funcA() {
  int count = 0;
  std::string number;
  
  while (std::cin) {
    std::getline(std::cin, number, '|');
    
    for (int i = 0 ; i < 4 ; i++) {
      std::cin >> number;
      int size = (int)number.size();

      if(size == 2 || size == 3 || size == 4 || size == 7) {
        count++;
      }
      
    }
  }
  std::cout << count << std::endl;
}

void funcB() {
  int count = 0, value, curr;
  std::string number;
  
  for(int i = 0; i < 200; i++) {
    UM map = {{'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0}, {'f', 0}, {'g', 0}};
    
    for(int i = 0; i < 10; i++) {
      std::cin >> number;
      for(char c: number) {
        map[c]++;
      }
    }
    
    std::cin >> number;
    for(int i = 0; i < 4; i++) {
      std::cin >> number;
      curr = 0, value = -1;
      
      for(char c: number) {
        curr += map[c];
      }

      if(curr == 42) value = 0;
      if(curr == 17) value = 1;
      if(curr == 34) value = 2;
      if(curr == 39) value = 3;
      if(curr == 30) value = 4;
      if(curr == 37) value = 5;
      if(curr == 41) value = 6;
      if(curr == 25) value = 7;
      if(curr == 49) value = 8;
      if(curr == 45) value = 9;

      count += value * std::pow(10, 3-i);
    }
  }
  std::cout << count << std::endl;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  
  // funcA();
  funcB();
}
