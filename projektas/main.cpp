#include "studentas.h"

int main() {
    srand(time(nullptr));
    std::cout << "Ar norite (1) generuoti nauja faila ar (2) naudoti esama? Įveskite 1 arba 2: ";
    int pasirinkimas;
    std::cin >> pasirinkimas;

    std::string failas;
    int kiek = 0;

    if (pasirinkimas == 1) {
        cout << "Įveskite failo pavadinimą (pvz. studentai1000.txt): ";
        std::cin >> failas;
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
    auto start = std::chrono::high_resolution_clock::now();
    vector<Studentas> grupe = nuskaitytiIsFailo(failas);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo nuskaitymas: " << diff.count() << " s\n";

    string rikiuotiPagal;
    cout << "Pagal ka norite surikiuoti studentus? (vardas/pavarde/galutinis/vidurkis/mediana): ";
    std::cin >> rikiuotiPagal;

    start = std::chrono::high_resolution_clock::now();
    rikiuotiStudentus(grupe, rikiuotiPagal);
    end = std::chrono::high_resolution_clock::now();
    cout << "Studentai surikiuoti pagal: " << rikiuotiPagal
         << " (" << std::chrono::duration<double>(end - start).count() << " s)\n";

    start = std::chrono::high_resolution_clock::now();
    vector<Studentas> vargsiukai;
    vector<Studentas> kietiakiai;
    padalintiStudentusTik(grupe, vargsiukai, kietiakiai);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    cout << "Padalinimas i 2 grupes: " << diff.count() << " s\n";

    string isvedimoFailas;
    cout << "Pagal ka norite isvesti? (vargsiukai/kietiakiai/visi): ";
    std::cin >> isvedimoFailas;

    start = std::chrono::high_resolution_clock::now();
    if (isvedimoFailas == "vargsiukai") {
        isvestiStudentus(vargsiukai, "vargsiukai.txt");
        cout << "Isvesta i faila vargsiukai.txt\n";
    } else if (isvedimoFailas == "kietiakiai") {
        isvestiStudentus(kietiakiai, "kietiakiai.txt");
        cout << "Isvesta i faila kietiakiai.txt\n";
    } else if (isvedimoFailas == "visi") {
        isvestiStudentus(grupe, "visi.txt");
        cout << "Isvesta i faila visi.txt\n";
    } else {
        cout << "Neteisingas pasirinkimas!\n";
    }
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    cout << "Isvedimas i faila: " << diff.count() << " s\n";

    cout << "\nPrograma baigta sekmingai.\n";
    return 0;
}

