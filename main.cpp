#include <iostream>
#include <chrono>
#include "studentas.h"

using cout;
using endl;
using vector;

int main() {
    srand(time(nullptr));

    vector<int> kiekiai = {1000, 10000, 100000, 1000000, 10000000};

    for (int kiek : kiekiai) {
        cout << "\n=== TESTAS: " << kiek << " studentu ===\n";

