#include <iostream>
#include <cmath>

using namespace std;
int main() {
  int[10] ratios;
  for(int i = 0; i < 10; i++) {
    ratios[i] = (ceil((2/(1+(sqrt(i+4))))*100)/100);
    cout << ratios[i];
  }
  return 0;
}
