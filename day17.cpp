#include <iostream>

int lx = 282, hx = 314, ly = -80, hy = -45;

int checkIfHit(int dx, int dy) {
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
  int f1 = 0, f2 = 0;
  for(int y = ly; y <= -ly; y++) {
    for(int x = 0; x <= hx; x++) {
      int res = checkIfHit(x, y);
      if(res != -1) {
        if(res > f1) f1 = res;
        f2++;
      }
    }
  }
  std::cout << f1 << " " << f2;
}
