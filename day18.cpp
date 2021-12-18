#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

struct Node {
  bool isnum;
  int num;
};

typedef std::vector<Node> VN;

void push(VN& num, const VN& num2) {
  num.insert(num.begin(), { false, '[' });
  num.push_back({ false, ',' });
  for (auto& n : num2) {
      num.push_back(n);
  }
  num.push_back({ false, ']' });
}

bool explode(VN& num) {
  int count = 0;
  for (auto it = num.begin(); it != num.end(); ++it) {
    if (!it->isnum) {
      if (it->num == '[') {
        if (++count > 4) {
          if ((it + 1)->isnum && !(it + 2)->isnum && (it + 2)->num == ',' && (it + 3)->isnum &&!(it + 4)->isnum && (it + 4)->num == ']') {
            int n1 = (it + 1)->num;
            int n2 = (it + 3)->num;
            for (auto it2 = it; it2 != num.begin(); --it2) {
              if (it2->isnum) {
                it2->num += n1;
                break;
              }
            }
            for (auto it2 = (it+5); it2 != num.end(); ++it2) {
              if (it2->isnum) {
                it2->num += n2;
                break;
              }
            }
            it = num.erase(it, it + 4);
            it->isnum = true;
            it->num = 0;
            return true;
          }
        }
      } else if (it->num == ']') {
          count--;
      }
    }
  }
  return false;
}

bool split(VN& num) {
  for (auto it = num.begin(); it != num.end(); ++it) {
    if (it->isnum && it->num > 9) {
      int n = it->num;
      it = num.erase(it);
      num.insert(it, { {false, '['}, {true, n / 2}, {false, ','}, {true, n / 2 + n % 2}, {false, ']'} });
      return true;
    }
  }
  return false;
}

int mag(VN num) {
  bool loop = true;
  while (loop && num.size() > 4) {
    loop = false;
    for (auto it = num.begin(); it+4 != num.end(); ++it) {
      if (!it->isnum && it->num == '[' && (it + 1)->isnum && !(it + 2)->isnum && (it + 2)->num == ',' && (it + 3)->isnum && !(it + 4)->isnum && (it + 4)->num == ']') {
        int n1 = (it + 1)->num;
        int n2 = (it + 3)->num;
        it = num.erase(it, it + 4);
        it->isnum = true;
        it->num = 3 * n1 + 2 * n2;
        loop = true;
        break;
      }
    }
  }
  return num[0].num;
}

int sum(const std::vector<VN>& nums) {
  VN acc;
  for (auto num : nums) {
    if (!acc.empty()) {
      push(acc, num);
      while (true) {
        if (!explode(acc) && !split(acc)) {
          break;
        }
      }
    } else {
      swap(acc, num);
    }
  }
  return mag(acc);
}

int main() {
  std::vector<VN> nums;
  std::string s;
  while (getline(std::cin, s)) {
    VN num;
    for (char x : s) {
      Node n;
      if (isdigit(x)) {
        n.num = x - 48;
        n.isnum = true;
      } else {
        n.num = x;
        n.isnum = false;
      }
      num.push_back(n);
    }
  nums.push_back(num);
  }
  std::cout << sum(nums) << " ";
  int sol2 = 0;
  for (int i = 0; i < nums.size(); ++i) {
    for (int j = 0; j < nums.size(); ++j) {
      if (i != j) sol2 = std::max(sol2, sum({ nums[i], nums[j] }));
    }
  }
  std::cout << sol2 << "\n";
}
