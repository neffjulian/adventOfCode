#include <iostream>
#include <string>
#include <vector>

void funcA() {
  std::string binary; std::cin >> binary;
  int length = binary.length();
  std::vector<int> occurrences(length, 0);
  int counter = 0;

  do {
    counter++;
    for(int i = 0; i < length; i++) {
      occurrences[i] += binary[i] - 48; 
    }
  } while(std::cin >> binary);
  
  int gamma = 0, epsilon = 0;
  for(int i = 0; i < length; i++) {
    if(occurrences[i] >= counter) {
      gamma += 1 << (length - i - 1);
    } else {
      epsilon += 1 << (length - i - 1);
    }
  }

  std::cout << gamma * epsilon << "\n";
}

void funcB() {
  std::string binary; std::cin >> binary;
  int oxygen = 0, co2 = 0;
  int length = binary.length();
  
  std::vector<std::vector<int>> VII;
  
  do {
    std::vector<int> VI(length);
    for(int i = 0; i < length; i++) {
      VI[i] = binary[i] - 48;
    }
    VII.push_back(VI);
  } while(std::cin >> binary);
  
  int numbers = VII.size(), count, index = 0, left = numbers;
  std::vector<bool> still_in(numbers, true);

  while(left > 1) {
    count = 0;
    for(int i = 0; i < numbers; i++) {
      if(still_in[i]) {
        count += VII[i][index];
      }
    }

    if(count*2 >= left) {
      for(int i = 0; i < numbers; i++) {
        if(VII[i][index] == 0  && still_in[i]) {
          still_in[i] = false;
          left--;
        }
      }
    } else { 
      for(int i = 0; i < numbers; i++) {
        if(VII[i][index] == 1 && still_in[i]) {
          still_in[i] = false;
          left--;
        }
      }
    }
    index++;
  }
  
  for(int i = 0; i < numbers; i++) {
    if(still_in[i]) {
      index = i;
    }
  }
  
  oxygen = 0;
  for(int i = 0; i < length; i++) {
    oxygen += (1 << (length - i - 1)) * VII[index][i];
    
  }

  for(int i = 0; i < numbers; i++) {
    still_in[i] = true;
  }
  left = numbers;
  index = 0;
  
  while(left > 1) {
    count = 0;
    for(int i = 0; i < numbers; i++) {
      if(still_in[i]) {
        count += VII[i][index];
      }
    }

    if(count*2 < left) { 
      for(int i = 0; i < numbers; i++) {
        if(VII[i][index] == 0  && still_in[i]) {
          still_in[i] = false;
          left--;
        }
      }
    } else { 
      for(int i = 0; i < numbers; i++) {
        if(VII[i][index] == 1 && still_in[i]) {
          still_in[i] = false;
          left--;
        }
      }
    }
    index++;
  }
  
  for(int i = 0; i < numbers; i++) {
    if(still_in[i]) {
      index = i;
    }
  }
  
  int res = 0;
  for(int i = 0; i < length; i++) {
    res += (1 << (length - i - 1)) * VII[index][i];
  }
  
  std::cout << oxygen * res;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  funcA();
  funcB();
}
