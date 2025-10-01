#include "studentas.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using ofstream;
using ifstream;
using istringstream;
using cerr;
using endl;
using setw;
using left;
using right;
using fixed;
using setprecision;

double skaiciuotiVidurki(const vector<int>& v) {
    if (v.empty()) return 0.0;
    double suma = 0;
    for (int x : v) suma += x;
    return suma / v.size();
}

double skaiciuotiMediana(vector<int> v) {
    if (v.empty()) return 0.0;
    std::sort(v.begin(), v.end());
    size_t n = v.size();
    if (n % 2 == 0)
        return (v[n/2 - 1] + v[n/2]) / 2.0;
    else
        return v[n/2];
}

double skaiciuotiGalutini(const vector<int>& paz, int egz) {
    return skaiciuotiVidurki(paz) * 0.4 + egz * 0.6;
}

