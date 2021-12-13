#include <iostream>
#include <set>

typedef std::set<std::pair<int, int>> SP;

SP fold(const SP &P, char a, int v) {
  SP result;
  for (const auto &p : P)
    if (a == 'x')
      result.insert({v - std::abs(p.first - v), p.second});
    else
      result.insert({p.first, v - std::abs(p.second - v)});
  return result;
}

void part1(SP &P) {
  char a; int v;
  std::scanf("fold along %c=%d\n", &a, &v);
  std::cout << fold(P, a, v).size() << std::endl;
}

void part2(SP &P) {
  char a; int v;
  int lim[2] = {INT32_MAX, INT32_MAX};
  while (std::scanf("fold along %c=%d\n", &a, &v) > 0) {
    P = fold(P, a, v);
    lim[(a - 'x')] = std::min(lim[(a - 'x')], v);
  }
  for (int y = 0; y < lim[1]; y++) {
    for (int x = 0; x < lim[0]; x++) {
      std::cout << (P.count({x, y}) ? '#' : ' ');
    }
    std::cout << std::endl;
  }
}

int main() {
  int x, y, v;
  char a;
  SP P;
  while(std::cin >> x >> a >> y) {
    P.insert({x, y});
  }

  // part1(P);
  part2(P);
}
