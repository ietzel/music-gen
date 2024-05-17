#include <cmath>
#include <iostream>
#include <random>
#include <string>

using namespace std;

int[10] mtlc_ratios;

int[32] int_nums = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,20,21,23,24,25,26,28,29,30,32,34,37,39,41,42,45,48,49,52,56,60,64,66,69,74,77,79,84,91,97,104,106,111,119,125,128,137,147,58,169,172,181,194,203,208,223,238,239,256,274,280,294,315,28,338,362,386,388,416,446,453,478,512,532,549,588,625,630,676,724,734,776,832,862,891,955,1013,1024,1097,1176,1190,1261,1351,1398,1448,1552,1642,1663,1783,1911,1928,2048,2195,2265,2353,2521,2660,2702,2896,3104,3125};

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
    [1, 23, 25, 27, 28, 32, 35, 37, 39, 40, 42, 46, 48, 49, 51], // (funk for children)
    [1, 8, 11, 12, 13, 28, 30, 35], //madd#6Maj7sus11add#13 (idol)
    [1, 4, 9, 11, 16, 20, 21, 28], //m13 omit 9th omit 11th (intermezzio in a major)
    [1, 5, 6, 8, 13, 17, 20, 22], //Msus4sus13 (love of my life)
    [1, 13, 15, 17, 20, 25], //Madd9 (overjoyed)
    [1, 15, 16, 23], //m9 omit 5th (road taken)
    [], // ()
    [], // ()
    [], // ()
    [], // ()
    [], // ()
    [] // ()
  ],
  [ 
    [5, 18, 22, 25], //Mb13b9 omit 3rd, omit 5th, omit 7th (a wind bell)
    [1, 8, 15, 20, 22, 24, 25], //M13 omit 3rd (black hole sun)
    [1, 10, 15, 19, 20, 22], //M13#11 omit 3rd omit 7th (christian women)
    [1, 13, 29, 40, 41, 43, 49, 53, 54], //Madd11 (crazy hot)
    [1, 4, 5, 25, 27, 29, 30, 32, 36, 39, 41, 44, 46, 48, 49, 51], // (funk for children)
    [1, 4, 8, 13, 15, 22], //madd9addM13 (idol)
    [1, 4, 7, 10, 15, 16, 19, 22, 27], //dim9 (intermezzio in a major)
    [1, 11, 13, 15, 17, 23], //9 omit 5th (love of my life)
    [1, 17, 20, 25, 29, 30], //Msus11 (overjoyed)
    [1, 17, 23, 27], //#9 omit 5th (road taken)
    [], // ()
    [], // ()
    [], // ()
    [], // ()
    [], // ()
    [] // ()
  ],
  [  
    [11, 25, 28, 33], //11 omit 3rd, omit 5th (a wind bell)
    [1, 8, 15, 20, 22, 24, 25], //M13 omit 3rd (black hole sun)
    [1, 15, 20, 24, 25, 27], //M9 omit 3rd (christian women)
    [1, 13, 32, 43, 44, 46, 49, 51, 53, 55, 56], //M13#11 omit 7th (crazy hot)
    [1, 15, 18, 22, 23, 25, 29, 30, 32, 34, 35, 37, 39, 42, 45, 47], // (funk for children)
    [1, 8, 13, 20, 25, 27], //Madd9 (idol)
    [1, 13, 29, 33, 34, 44], //maddM13 (intermezzio in a major)
    [1, 8, 11, 13, 15, 16], //m9 (love of my life)
    [1, 13, 17, 24], //M7 omit 5th (overjoyed)
    [1, 8, 11, 17], //m7 (road taken)
    [], // ()
    [], // ()
    [], // ()
    [], // ()
    [], // ()
    [] // ()
  ]
];

string chords(ratio) {
  string[8][] chord_progression = new string[8][];
  for(int i = 0; i < chord_progression.length; i++) {
    if(rand() > ratio) {
      chord_progression[i] = chords[0][floor(rand()*chords.length)];
    } else if(rand() > ratio/2) {
      chord_progression[i] = chords[1][floor(rand()*chords.length)];
    } else {
      chord_progression[i] = chords[2][floor(rand()*chords.length)];
    }
  }
  return ;
}

int main() {
  
  return 0;
}
