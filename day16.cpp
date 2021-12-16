#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_map>

std::unordered_map<char, std::string> um = {{'0',"0000"}, {'1',"0001"}, {'2',"0010"}, {'3',"0011"}, 
                                            {'4',"0100"}, {'5',"0101"}, {'6',"0110"}, {'7',"0111"}, 
                                            {'8',"1000"}, {'9',"1001"}, {'A',"1010"}, {'B',"1011"}, 
                                            {'C',"1100"}, {'D',"1101"}, {'E',"1110"}, {'F',"1111"}};
int p1 = 0;

long parse(std::string &str, long &pos) {
  p1 += std::stoll(str.substr(pos,3), 0, 2);
  std::string t = str.substr(pos+3, 3);
  
  if(t == "100") {
    pos += 6;
    std::string val;
    while(str[pos] == '1') {
      val += str.substr(pos+1, 4);
      pos += 5;
    }
    val += str.substr(pos+1, 4);
    pos += 5;
    return std::stoll(val, 0, 2); 
  } else {
    std::vector<long> parsed;
    if(str[pos+6] == '0') {
      pos += 7;
      long count = std::stoll(str.substr(pos, 15), 0, 2) + 15 + pos;
      pos += 15;
      while(pos != count) {
        parsed.push_back(parse(str, pos));
      }
    } else {
      long count = std::stoll(str.substr(pos+7, 11), 0, 2);
      pos += 18;
      for(long i = 0; i < count; i++) parsed.push_back(parse(str, pos));
    }
    if(!parsed.empty() && parsed.back() == -1) parsed.pop_back();
    
    switch(std::stoll(t, 0, 2)) {
      case 0: return std::accumulate(std::begin(parsed), std::end(parsed), 0ll);
      case 1: return std::accumulate(std::begin(parsed), std::end(parsed), 1ll, std::multiplies<long>());
      case 2: return *std::min_element(std::begin(parsed), std::end(parsed));
      case 3: return *std::max_element(std::begin(parsed), std::end(parsed));
      case 5: return parsed[0] > parsed[1];
      case 6: return parsed[0] < parsed[1];
      case 7: return parsed[0] == parsed[1];
    }
  }
  return -1;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  
  long pos = 0, p2 = parse(hex, pos);
  std::string s, hex = ""; std::cin >> s;
  for(char &c : s) {
    hex += um[c];
  }
  std::cout << p1 << " " << p2 << std::endl;
}
