/**
 * @file main.cpp
 * @brief Plik główny programu demonstrujący działanie szablonowej klasy SortowaniePrzezScalanie.
 * @author Wiktor Matusik
 * @date 2026
 */

#include <iostream>
#include <vector>
#include "SortowaniePrzezScalanie.h"

using namespace std;

/**
 * @brief Funkcja szablonowa wypisująca wszystkie elementy wektora na standardowe wyjście.
 *
 * @tparam T Typ danych przechowywanych w wektorze.
 * @param[in] tablica Stała referencja do wektora, którego zawartość ma zostać wyświetlona
 */
template <typename T>
void wyswietlTablice(const vector<T>& tablica) {
    for (const auto& element : tablica) {
        cout << element << " ";
    }
    cout << "\n";
}

/**
 * @brief Punkt wejścia aplikacji konsolowej.
 *
 * Tworzy dwie przykładowe instancje wektorów (dla typu int oraz typu double),
 * prezentuje ich stan początkowy, sortuje je przy użyciu klasy SortowaniePrzezScalanie
 * i wyświetla wynik końcowy w konsoli.
 *
 * @return Kod zakończenia programu (0 oznacza poprawne wykonanie).
 */
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