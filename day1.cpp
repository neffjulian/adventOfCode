#include <iostream>

void funcA() {
  int A, B, count = 0;
  std::cin >> B;
  
  while(std::cin >> A) {
    if(A > B) {
      count++;
    }
    B = A;
  }
  
  std::cout << count << "\n";
}

void funcB() {
  int A, B, C, D, count = 0;
  std::cin >> D >> C >> B;

  while(std::cin >> A) {
    if(A > D) {
      count++;
    }

    D = C;
    C = B;
    B = A;
  }
  std::cout << count << "\n";
}

int main() {
  A();
  B();
}
