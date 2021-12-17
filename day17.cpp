#include <iostream>

int lx = 282, hx = 314, ly = -80, hy = -45;

int simulate(int dx, int dy) {
  int x = 0, y = 0, sol = 0;
  while(x <= hx && y >= ly) {
    x += dx; if(dx) dx--;
    y += dy--;
    if(sol < y) sol = y;
    if(lx <= x && x <= hx && ly <= y && y <= hy) return sol;
  }
  return -1;
}

int main() {
  int p1 = 0, p2 = 0;
  for(int y = ly; y <= -ly; y++) {
    for(int x = 0; x <= hx; x++) {
      int res = simulate(x, y);
      if(res != -1) {
        if(res > p1) p1 = res;
        p2++;
      }
    }
  }
  std::cout << p1 << " " << p2;
}
