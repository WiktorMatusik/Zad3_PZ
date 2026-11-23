#include <iostream>
#include <vector>
#include "SortowaniePrzezScalanie.h"

using namespace std;

template <typename T>
void wyswietlTablice(const vector<T>& tablica) {
    for (const auto& element : tablica) {
        cout << element << " ";
    }
    cout << "\n";
}

int main() {
    vector<int> tablicaInt = { 14, 17, 33, 3, 9, 32, 7, -5, 0 };
    cout << "Tablica int przed sortowaniem:\n";
    wyswietlTablice(tablicaInt);

    SortowaniePrzezScalanie<int>::sortuj(tablicaInt);
    cout << "Tablica int po sortowaniu:\n";
    wyswietlTablice(tablicaInt);

    cout << "----------------------------------------\n";

    vector<double> tablicaDouble = { 3.14, -1.71, 0.0, 12.5, -10.12, 1.318, 6.14 };
    cout << "Tablica double przed sortowaniem:\n";
    wyswietlTablice(tablicaDouble);

    SortowaniePrzezScalanie<double>::sortuj(tablicaDouble);
    cout << "Tablica double po sortowaniu:\n";
    wyswietlTablice(tablicaDouble);

    return 0;
}