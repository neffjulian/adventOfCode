#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <algorithm>

std::map<char, int> pointsA = {{')', 3}, {']', 57}, {'}', 1197}, {'>', 25137}};
std::map<char, int> pointsB = {{')', 1}, {']', 2}, {'}', 3}, {'>', 4}};
std::map<char, char> map = {{'(', ')'}, {'[', ']'}, {'{', '}'}, {'<', '>'}};

void funcA() {
  std::string input;
  int amount = 0;
  
  while(std::cin >> input) {
    std::stack<char> stack;
    for(char& c : input) {
      if (c == '(' || c == '[' || c == '<' || c == '{') {
        stack.push(c);
      } else if(stack.top() == '(' && c == ')') {
        stack.pop();
      } else if(stack.top() == '[' && c == ']') {
        stack.pop();
      } else if(stack.top() == '{' && c == '}') {
        stack.pop();
      } else if(stack.top() == '<' && c == '>') {
        stack.pop();
      } else {
        amount += pointsA[c];
        break;
      }
    }
  }
  std::cout << amount << "\n";
}

void funcB() {
  std::string input;
  long amount = 0;
  std::vector<long> amounts;
  
  while(std::cin >> input) {
    std::stack<char> stack;
    for(char& c : input) {
      if (c == '(' || c == '[' || c == '<' || c == '{') {
        stack.push(c);
      } else if(stack.top() == '(' && c == ')') {
        stack.pop();
      } else if(stack.top() == '[' && c == ']') {
        stack.pop();
      } else if(stack.top() == '{' && c == '}') {
        stack.pop();
      } else if(stack.top() == '<' && c == '>') {
        stack.pop();
      } else {
        stack = std::stack<char>();
        break;
      }
    }
    
    amount = 0;
    while(!stack.empty()) {
      amount *= 5;
      amount += pointsB[map[stack.top()]];
      stack.pop();
    }
     
    if(amount > 0) {
      amounts.push_back(amount);
    }
  }
  
  std::sort(amounts.begin(), amounts.end());
  std::cout << amounts[amounts.size()/2] << "\n";
}


int main() {
  std::ios_base::sync_with_stdio(false);
  funcB();
}
