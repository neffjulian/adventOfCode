#include <iostream>
#include <vector>

int dice = 0;
int roll1() {
  dice++ < 100 ? dice : dice = 1;
  return dice;
}

int func1(int p1, int p2) {
  int turn = 0, dice = 1, winner = 0;
  int pos1 = p1, pos2 = p2;
  int poi1 = 0, poi2 = 0;
  bool turnP1 = true;
  
  while(poi1 < 1000 && poi2 < 1000) {
    int sum = roll1() + roll1() + roll1();
    if(turn++ % 2 == 0) {
      pos1 += sum;
      while(pos1 > 10) pos1 -= 10;
      poi1 += pos1;
    } else {
      pos2 += sum;
      while(pos2 > 10) pos2 -= 10;
      poi2 += pos2;
    }
    turnP1 = !turnP1;
  }
  
  int scoreL; turnP1 ? scoreL = poi1 : scoreL = poi2;
  return scoreL * 3*turn;
}


// int DP[2][32][32][10][10]; // DP[P][poi1][poi2][pos1][pos2]

typedef std::vector<int> VI;
typedef std::vector<VI> VII;
typedef std::vector<VII> VIII;
typedef std::vector<VIII> VIIII;
typedef std::vector<VIIII> VIIIII;


void func2(int p1, int p2) {
  long DP[2][32][32][10][10];
  DP[0][0][0][p1-1][p2-1] = 1;
  int newPoi1, newPoi2, newPos1, newPos2;
  
  for(int poi1 = 0; poi1 < 21; poi1++) {
    for(int poi2 = 0; poi2 < 21; poi2++) {
      for(int pos1 = 0; pos1 < 10; pos1++) {
        for(int pos2 = 0; pos2 < 10; pos2++) {
          
          for(int a = 1; a < 4; a++) {
            for(int b = 1; b < 4; b++) {
              for(int c = 1; c < 4; c++) {
                int curr = a + b + c;
                newPos1 = (pos1 + curr) % 10;
                newPos2 = (pos2 + curr) % 10;
                
                newPoi1 = poi1 + newPos1 + 1;
                newPoi2 = poi2 + newPos2 + 1;
                
                DP[1][newPoi1][poi2][newPos1][pos2] += DP[0][poi1][poi2][pos1][pos2];
                DP[0][poi1][newPoi2][pos1][newPos2] += DP[1][poi1][poi2][pos1][pos2];
              }
            }
          }
          
        }
      }
    }
  }
  
  long w1 = 0, w2 = 0;
  for(int poi1 = 21; poi1 < 32; poi1++) {
    for(int poi2 = 0; poi2 < 21; poi2++) {
      for(int pos1 = 0; pos1 < 10; pos1++) {
        for(int pos2 = 0; pos2 < 10; pos2++) {
          w1 += DP[1][poi1][poi2][pos1][pos2];
        }
      }
    }
  }
  
  for(int poi1 = 0; poi1 < 21; poi1++) {
    for(int poi2 = 21; poi2 < 32; poi2++) {
      for(int pos1 = 0; pos1 < 10; pos1++) {
        for(int pos2 = 0; pos2 < 10; pos2++) {
          w2 += DP[0][poi1][poi2][pos1][pos2];
        }
      }
    }
  }
  w1 > w2 ? std::cout << w1 : std::cout << w2;
}

int main() {
  int p1 = 2;
  int p2 = 7;
  
  func2(p1, p2);
}
