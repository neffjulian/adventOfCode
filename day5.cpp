#include <iostream>
#include <sstream>
#include <string>
#include <vector>


typedef std::vector<int> VI;
typedef std::vector<VI> VII;

void funcA() {
  int maxX = 0, maxY = 0;
  VI X1, Y1, X2, Y2;
  
  std::string c1, trash, c2;
  VI numbers;
  std::string input;
  while(std::cin >> input) {
    std::stringstream ss(input);
    for(int i; ss >> i;) {
      numbers.push_back(i);    
      if (ss.peek() == ',' || ss.peek() == '-' || ss.peek() == '>') {
        ss.ignore();
      }
    } 
  }
  
  for(size_t i = 0; i < numbers.size(); i+= 4) {
    Y1.push_back(numbers[i]);
    X1.push_back(numbers[i+1]);
    Y2.push_back(numbers[i+2]);
    X2.push_back(numbers[i+3]);
    
    maxY = std::max(maxX, std::max(numbers[i], numbers[i+2]) + 1);
    maxX = std::max(maxY, std::max(numbers[i+1], numbers[i+3]) + 1);
  }
  
  VII mat(maxX, VI(maxY, 0));
  int x1, y1, x2, y2;
  for(size_t curr = 0; curr < X1.size(); curr++) {
    
    if(X1[curr] == X2[curr]) {
      y1 = std::min(Y1[curr], Y2[curr]);
      y2 = std::max(Y1[curr], Y2[curr]);
      
      for(int i = y1; i <= y2; i++) {
        mat[X1[curr]][i]++;
      }
      
    } else if (Y1[curr] == Y2[curr]) {
      x1 = std::min(X1[curr], X2[curr]);
      x2 = std::max(X1[curr], X2[curr]);

      for(int i = x1; i <= x2; i++) {
        mat[i][Y1[curr]]++;
      }
    } else if (X1[curr] < X2[curr]) {
      int diff = X2[curr] - X1[curr];
      if(Y1[curr] <= Y2[curr]) {
        for(int i = 0; i <= diff; i++) {
          mat[X1[curr]+i][Y1[curr]+i]++;
        }
      } else {
        for(int i = 0; i <= diff; i++) {
          mat[X1[curr]+i][Y1[curr]-i]++;
        }
      }
    } else if (X1[curr] > X2[curr]) {
      int diff = X1[curr] - X2[curr];
      if(Y1[curr] <= Y2[curr]) {
        for(int i = 0; i <= diff; i++) {
          mat[X1[curr]-i][Y1[curr]+i]++;
        }
      } else {
        for(int i = 0; i <= diff; i++) {
          mat[X1[curr]-i][Y1[curr]-i]++;
        }
      }
    }
  }
  
  int count = 0;
  for(int i = 0; i < maxY; i++) {
    for(int j = 0; j < maxX; j++) {
      if(mat[i][j] > 1) {
        count++;
      }
    }
  }
  std::cout << count << "\n";
}

int main() {
  std::ios_base::sync_with_stdio(false);
  
  funcA();
  // funcB();
}
