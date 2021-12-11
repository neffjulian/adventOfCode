#include <iostream>
#include <vector>
#include <unordered_set>

void inc(int index, std::vector<int> &oct, std::unordered_set<int> &flashed) {
  if (++oct[index] < 10 || flashed.count(index)) return;

  flashed.insert(index);

  int x = index % 10, y = index / 10;
  for (int nx = x - 1; nx <= x + 1; nx++)
    for (int ny = y - 1; ny <= y + 1; ny++)
      if ((nx != x || ny != y) && 0 <= nx && nx < 10 && 0 <= ny && ny < 10)
        inc(ny * 10 + nx, oct, flashed);
}

int ite(std::vector<int> &oct) {
    std::unordered_set<int> flashed;
    for (size_t i = 0; i < oct.size(); i++)
      inc(i, oct, flashed);

    for (int f : flashed)
      oct[f] = 0;

    return flashed.size();
}

void funcA() {
  std::vector<int> input;
  for (char c; std::cin >> c;)
    input.push_back(c - 48);

  int count = 0;
  for (int i = 0; i < 100; i++)
    count += ite(input);

  std::cout << count << std::endl;
}

void funcB() {
  std::vector<int> input;
  for (char c; std::cin >> c;)
    input.push_back(c - 48);

  int steps = 1;
  while (ite(input) != (int)input.size())
    steps++;

  std::cout << steps << std::endl;
}

int main() {
    // funcA();
    funcB();
}
