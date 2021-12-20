#include <iostream>
#include <string>
#include <set>

typedef std::pair<int, int> PI;
typedef std::set<PI> SPI;

auto enhance(const SPI &pixels, const std::string &iea, int &infinite) {
  SPI next;
  int lx = INT32_MAX, ly = INT32_MAX, ux = INT32_MIN, uy = INT32_MIN;
  for(const auto &[x, y] : pixels){
    lx = std::min(lx, x); ly = std::min(ly, y);
    ux = std::max(ux, x); uy = std::max(uy, y);
  }

  for (int y = ly - 1; y <= uy + 1; y++)
    for (int x = lx - 1; x <= ux + 1; x++) {
      int coord = 0;
      for (int j = y - 1; j <= y + 1; j++)
        for (int i = x - 1; i <= x + 1; i++)
          if (lx <= i && i <= ux && ly <= j && j <= uy)
            coord = coord << 1 | pixels.count({i, j});
          else
            coord = coord << 1 | infinite;
      if (iea[coord] == '#')
        next.insert({x, y});
    }

  infinite = (iea[infinite * (iea.size() - 1)] == '#');
  return next;
}

int func(int steps) {
  std::string iea; std::cin >> iea;
  SPI pixels;
  for (auto [y, line] = std::pair<int, std::string>{0, std::string{}}; std::cin >> line; y++)
    for (int x = 0; x < line.length(); x++)
      if (line[x] == '#') pixels.insert({x, y});
  int infinite = 0;
  for (int i = 0; i < steps; i++)
    pixels = enhance(pixels, iea, infinite);
  return pixels.size();
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cout << func(50) << std::endl;
}
