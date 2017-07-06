#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
int main() {
  const double pi = 3.1415926535;
  const int n = 18; // # of division
  const string fn = "sin.txt";
  {
    ofstream ofs(fn.c_str());
    ofs << "# sine curve\n";
    for(int i=0; i<n; ++i) {
      const double a = i*(360.0/n);
      ofs << a << " "
        << sin(a*(pi/180.0)) << "\n";
    }
  }
  cout << "Output " << fn << "\n";
}

