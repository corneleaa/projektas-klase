#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::istringstream;
using std::cerr;
using std::setw;
using std::left;
using std::right;
using std::fixed;
using std::setprecision;

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
void rikiuotiStudentus(vector<Studentas>& grupe, const string& pagal);
void padalintiStudentusTik(vector<Studentas>& grupe, vector<Studentas>& vargs, vector<Studentas>& kiet);
void isvestiStudentus(const vector<Studentas>& grupe, const string& failoVardas);
template <typename Container>
Container nuskaitytiIsFailoT(const string& failoVardas);

template <typename Container>
void padalintiStudentusTikT(const Container& grupe, Container& vargs, Container& kiet);

template <typename Container>
void isvestiStudentusT(const Container& grupe, const string& failoVardas);

#endif

