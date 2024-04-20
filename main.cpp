#include <cmath>
#include <iostream>
#include <random>
#include <string>

using namespace std;

int[10] mtlc_ratios;
for(int i = 0; i < 10; i++) {
  mtlc_ratios[i] = (ceil((2/(1+(sqrt(i+4))))*100)/100);
  cout << mtlc_ratios[i];
}

random_device rd;
mt19937 gen(rd());
uniform_real_distribution<> dis(0.0, 1.0);

int[] tonics = [1, 4, 5];
int[] dominants = [2, 8, 11, 12];
int[] predominants = [3, 6, 7, 9, 10];

int[3][][] chords = [
  [
    [1, 15, 17, 20], //Madd9 (a wind bell)
    [1, 8, 15, 20, 22, 24, 25], //M13 omit 3rd (black hole sun)
    [1, 8, 13, 17, 18, 20], //Madd11 (christian women)
    [1, 13, 25, 27, 28, 32, 37, 39, 40, 44, 49, 51, 52, 56], //madd9 (crazy hot)
    [1, 4, 9, 11, 16, 20, 21, 28], //m13 omit 9th omit 11th (intermezzio in a major)
    [1, 5, 6, 8, 13, 17, 20, 22], //Msus4sus13 (love of my life)
    [], // (overjoyed)
    [1, 15, 16, 23], //m9 omit 5th (road taken)
  ],
  [ 
    [5, 18, 22, 25], //Mb13b9 omit 3rd, omit 5th, omit 7th (a wind bell)
    [1, 8, 15, 20, 22, 24, 25], //M13 omit 3rd (black hole sun)
    [1, 10, 15, 19, 20, 22], //M13#11 omit 3rd omit 7th (christian women)
    [1, 13, 29, 40, 41, 43, 49, 53, 54], //Madd11 (crazy hot)
    [1, 4, 7, 10, 15, 16, 19, 22, 27], //dim9 (intermezzio in a major)
    [1, 11, 13, 15, 17, 23], //9 omit 5th (love of my life)
    [], // (overjoyed)
    [1, 17, 23, 27], //#9 omit 5th (road taken)
  ],
  [  
    [11, 25, 28, 33], //11 omit 3rd, omit 5th (a wind bell)
    [1, 8, 15, 20, 22, 24, 25], //M13 omit 3rd (black hole sun)
    [1, 15, 20, 24, 25, 27], //M9 omit 3rd (christian women)
    [1, 13, 32, 43, 44, 46, 49, 51, 53, 55, 56], //M13#11 omit 7th (crazy hot)
    [1, 13, 29, 33, 34, 44], //maddM13 (intermezzio in a major)
    [1, 8, 11, 13, 15, 16], //m9 (love of my life)
    [], // (overjoyed)
    [1, 8, 11, 17], //m7 (road taken)
  ]
];

string chords(ratio) {
  string chord = 
  return ;
}

int main() {
  
  return 0;
}
