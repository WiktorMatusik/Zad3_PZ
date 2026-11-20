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
    vector<int> tablicaInt = { 38, 27, 43, 3, 9, 82, 10, -5, 0 };
    cout << "Tablica int przed sortowaniem:\n";
    wyswietlTablice(tablicaInt);

    SortowaniePrzezScalanie<int>::sortuj(tablicaInt);
    cout << "Tablica int po sortowaniu:\n";
    wyswietlTablice(tablicaInt);

    cout << "----------------------------------------\n";

    vector<double> tablicaDouble = { 3.14, -2.71, 0.0, 42.5, -10.12, 1.618, 3.14 };
    cout << "Tablica double przed sortowaniem:\n";
    wyswietlTablice(tablicaDouble);

    SortowaniePrzezScalanie<double>::sortuj(tablicaDouble);
    cout << "Tablica double po sortowaniu:\n";
    wyswietlTablice(tablicaDouble);

    return 0;
}