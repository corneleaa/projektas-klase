#include "studentas.h"
int main() {
    srand(time(nullptr));
    cout << "Ar norite (1) generuoti nauja faila ar (2) naudoti esama? Įveskite 1 arba 2: ";
        int pasirinkimas;
        std::cin >> pasirinkimas;

        std::string failas;
        int kiek = 0;
    if (pasirinkimas == 1) {
            cout << "Įveskite failo pavadinimą (pvz. studentai1000.txt): ";
            cin >> failas;
            cout << "Kiek studentų generuoti? ";
            std::cin >> kiek;

            auto start = std::chrono::high_resolution_clock::now(); 
            generuotiFaila(failas, kiek);
            auto end = std::chrono::high_resolution_clock::now();

            std::cout << "Failas sugeneruotas per "
                      << std::chrono::duration<double>(end - start).count()
                      << " s.\n";
        }
        else if (pasirinkimas == 2) {
            std::cout << "Įveskite egzistuojančio failo pavadinimą: ";
            std::cin >> failas;
        }
        else {
            cout << "Neteisingas pasirinkimas!\n";
            return 0;
        }


    vector<int> kiekiai = {1000, 10000, 100000, 1000000, 10000000};

    for (int kiek : kiekiai) {
        cout << "\n TESTAS: " << kiek << " studentu \n";
        
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

        start = std::chrono::high_resolution_clock::now();
        vector<Studentas> vargsiukai;
        vector<Studentas> kietiakiai;
        padalintiStudentusTik(grupe, vargsiukai, kietiakiai);
        isvestiStudentus(vargsiukai, "vargsiukai.txt");
        isvestiStudentus(kietiakiai, "kietiakiai.txt");
        end = std::chrono::high_resolution_clock::now();
        diff = end - start;
        cout << "Padalinimas i 2 grupes ir isvedimas: " << diff.count() << " s\n";
    }

    return 0;
}

