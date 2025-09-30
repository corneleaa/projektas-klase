#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <chrono>

using cout;
using cin;
using endl;
using string;
using vector;
using setw;
using left;
using right;
using fixed;
using setprecision;
using getline;
using numeric_limits;
using streamsize;
using ifstream;
using ofstream;
using istringstream;

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

