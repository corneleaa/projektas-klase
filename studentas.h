#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

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

void rikiuotiStudentus(vector<Studentas>& grupe, const string& pagal);
void padalintiStudentusTik(vector<Studentas>& grupe, vector<Studentas>& vargs, vector<Studentas>& kiet);
void isvestiStudentus(const vector<Studentas>& grupe, const string& failoVardas);
void processStreaming(const string& failoVardas, const string& failasVargs, const string& failasKiet); 

#endif

