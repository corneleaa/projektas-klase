#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <chrono>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>

inline double mediana_ref(const std::vector<int>& v) {
    std::vector<int> tmp = v;
    return mediana(tmp);
}

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
double skaiciuotiGalutiniPagalTipa(const vector<int>& paz, int egz, int tipas);

Studentas generuotiStudenta(int id);
void generuotiFaila(const string& failoVardas, int kiek);

vector<Studentas> nuskaitytiIsFailo(const string& failoVardas);
void rikiuotiStudentus(vector<Studentas>& grupe, const string& pagal);
void padalintiStudentusTik(vector<Studentas>& grupe, vector<Studentas>& vargs, vector<Studentas>& kiet);
void isvestiStudentus(const vector<Studentas>& grupe, const string& failoVardas);

void split_strat1_vector(const std::vector<Studentas>& src,
                         std::vector<Studentas>& vargs,
                         std::vector<Studentas>& kiet);

void split_strat2_vector(std::vector<Studentas>& all,
                         std::vector<Studentas>& vargs);

void split_strat3_vector(std::vector<Studentas>& all,
                         std::vector<Studentas>& vargs);

void split_strat1_list(const std::list<Studentas>& src,
                       std::list<Studentas>& vargs,
                       std::list<Studentas>& kiet);

void split_strat2_list(std::list<Studentas>& all,
                       std::list<Studentas>& vargs);

void split_strat3_list(std::list<Studentas>& all,
                       std::list<Studentas>& vargs);

template <typename Container>
Container nuskaitytiIsFailoT(const string& failoVardas);

template <typename Container>
void padalintiStudentusTikT(const Container& grupe, Container& vargs, Container& kiet);

template <typename Container>
void isvestiStudentusT(const Container& grupe, const string& failoVardas);

#endif

