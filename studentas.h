#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <iostream>
#include <string>
#include <vector>

using string;
using vector;

struct Studentas {
    string vardas;
    string pavarde;
    vector<int> pazymiai;
    int egzaminas{};
    double galutinis{};
};

double skaiciuotiVidurki(const vector<int>& v);
double skaiciuotiMediana(vector<int> v);
double skaiciuotiGalutini(const vector<int>& paz, int egz);
Studentas generuotiStudenta(int id);
void generuotiFaila(const string& failoVardas, int kiek);
vector<Studentas> nuskaitytiIsFailo(const string& failoVardas);
void padalintiStudentus(const vector<Studentas>& grupe,
                        const string& failasVargsiukai,
                        const string& failasKietiakiai);
#endif

