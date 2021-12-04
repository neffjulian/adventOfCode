#include <iostream>
#include <sstream>
#include <string>
#include <vector>

typedef std::vector<int> VI;
typedef std::vector<VI> VII;
typedef std::vector<VII> VIII;

void funcA() {
  std::vector<int> numbers;

  std::string input; std::cin >> input;
  std::stringstream ss(input);
  for (int i; ss >> i;) {
    numbers.push_back(i);    
    if (ss.peek() == ',')
      ss.ignore();
  }
  
  VIII cards;
  int bingo;
  while(std::cin >> bingo) {
    VII card(6, VI(6, 0));
    card[0][0] = bingo;
    for(int i = 0; i < 5; i++) {
      for(int j = 0; j < 5; j++) {
        if(i > 0 || j > 0) {
          std::cin >> card[i][j]; 
        }
      }
    }
    cards.push_back(card);
  }
  
  VIII marked(cards.size(), VII(6, VI(6, 0)));
  for(auto &number : numbers) {
    for(int i = 0; i < cards.size(); i++) {
      for(int j = 0; j < 5; j++) {
        for(int k = 0; k < 5; k++) {
          if(number == cards[i][j][k] && marked[i][j][k] == 0) {
            cards[i][j][5]++;
            cards[i][5][k]++;
            
            marked[i][j][k] = 1;
            
            if(cards[i][5][k] == 5 || cards[i][j][5] == 5) {
              int sum = 0;
              for(int l = 0; l < 5; l++) {
                for(int m = 0; m < 5; m++) {
                  if(marked[i][l][m] == 0) {
                    sum += cards[i][l][m];
                  }
                }
              }
              std::cout << sum * cards[i][j][k];
              return;
            }
          }
        }
      }
    }
  }
}

void funcB() {
  std::vector<int> numbers;

  std::string input; std::cin >> input;
  std::stringstream ss(input);
  for (int i; ss >> i;) {
    numbers.push_back(i);    
    if (ss.peek() == ',')
      ss.ignore();
  }
  
  VIII cards;
  int bingo;
  while(std::cin >> bingo) {
    VII card(6, VI(6, 0));
    card[0][0] = bingo;
    for(int i = 0; i < 5; i++) {
      for(int j = 0; j < 5; j++) {
        if(i > 0 || j > 0) {
          std::cin >> card[i][j]; 
        }
      }
    }
    cards.push_back(card);
  }
  
  VI won(cards.size()); int nr_won = 0;
  VIII marked(cards.size(), VII(6, VI(6, 0)));
  for(auto &number : numbers) {
    for(int i = 0; i < cards.size(); i++) {
      for(int j = 0; j < 5; j++) {
        for(int k = 0; k < 5; k++) {
          if(number == cards[i][j][k] && marked[i][j][k] == 0) {
            cards[i][j][5]++;
            cards[i][5][k]++;
            
            marked[i][j][k] = 1;
            
            if(cards[i][5][k] == 5 || cards[i][j][5] == 5) {
              if(won[i] == 0) {
                won[i] = ++nr_won;
                if(nr_won == cards.size()) {
                   int sum = 0;
              for(int l = 0; l < 5; l++) {
                for(int m = 0; m < 5; m++) {
                  if(marked[i][l][m] == 0) {
                    sum += cards[i][l][m];
                  }
                }
              }
              std::cout << sum * cards[i][j][k];
              return;
                }
              }
            }
          }
        }
      }
    }
  }
  
  for(int i = 0; i < cards.size(); i++) {
    std::cout << won[i] << " ";
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  // funcA();
  funcB();
}
