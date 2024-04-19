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
    [1, 5, 6, 8, 13, 17, 20, 22], //Msus4sus13 (love of my life)
    [1, 15, 16, 23], // m9 omit 5th (road taken)
    [],
    [],
    []
  ],
  [ 
    [5, 18, 22, 25], //Mb13b9 omit 3rd, omit 5th, omit 7th (a wind bell)
    [1, 8, 15, 20, 22, 24, 25], //M13 omit 3rd (black hole sun)
    [1, 10, 15, 19, 20, 22], //M13#11 omit 3rd, omit 7th (christian women)
    [1, 11, 13, 15, 17, 23], //9 omit 5th (love of my life)
    [1, 17, 23, 27], //#9 omit 5th (road taken)
    [],
    [],
    []
  ],
  [  
    [11, 25, 28, 33], //11 omit 3rd, omit 5th (a wind bell)
    [1, 8, 15, 20, 22, 24, 25], //M13 omit 3rd (black hole sun)
    [1, 15, 20, 24, 25, 27], //M9 omit 3rd (christian women)
    [1, 8, 11, 13, 15, 16], //m9 (love of my life)
    [1, 8, 11, 17], //m7 (road taken)
    [],
    [],
    []
  ]
];

string chords(ratio) {
  string chord = 
  return ;
}

int main() {
  
  return 0;
}
