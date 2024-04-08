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

string[] tonics = [1, 4, 5];
string[] dominants = [2, 8, 11, 12];
string[] predominants = [3, 6, 7, 9, 10];

string chords(ratio) {
  string chord = 
  return ;
}

int main() {
  
  return 0;
}
