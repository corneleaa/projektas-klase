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
        
        auto start = std::chrono::high_resolution_clock::now();
                string failas = "studentai" + std::to_string(kiek) + ".txt";
                generuotiFaila(failas, kiek);
                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> diff = end - start;
                cout << "Failo generavimas: " << diff.count() << " s\n";
        
        start = std::chrono::high_resolution_clock::now();
                vector<Studentas> grupe = nuskaitytiIsFailo(failas);
                end = std::chrono::high_resolution_clock::now();
                diff = end - start;
                cout << "Failo nuskaitymas: " << diff.count() << " s\n";

        
