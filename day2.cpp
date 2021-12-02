#include <iostream>
#include <string>

void funcA() {
  std::string instruction;
  int amount;
  
  int x = 0;
  int z = 0;
  
  while(std::cin>>instruction) {
    std::cin>>amount;
    
    if(instruction == "forward") {
      x += amount;
    } else if (instruction == "down") {
      z += amount;
    } else {
      z -= amount;
    }
  }
  
  std::cout << x*z << "\n";
}

void funcB() {
  std::string instruction;
  int amount;
  
  int x = 0;
  int z = 0;
  int aim = 0;
  
  while(std::cin>>instruction) {
    std::cin>>amount;
    
    if(instruction == "forward") {
      x += amount;
      z += aim * amount;
    } else if (instruction == "down") {
      aim += amount;
    } else {
      aim -= amount;
    }
  }
  
  std::cout << x*z << "\n";
}

int main() {
  funcA();
  funcB();
}
