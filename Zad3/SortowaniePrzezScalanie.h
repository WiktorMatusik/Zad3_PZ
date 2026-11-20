#pragma once
#include <vector>
#include <cstddef>

using namespace std;

template <typename T>
class SortowaniePrzezScalanie {
public:
    static void sortuj(vector<T>& tablica) {
        if (tablica.size() <= 1) {
            return;
        }
        sortujRekurencyjnie(tablica, 0, tablica.size() - 1);
    }

private:
    static void sortujRekurencyjnie(vector<T>& tablica, size_t lewy, size_t prawy) {
        if (lewy >= prawy) {
            return;
        }

        size_t srodek = lewy + (prawy - lewy) / 2;

        sortujRekurencyjnie(tablica, lewy, srodek);
        sortujRekurencyjnie(tablica, srodek + 1, prawy);
        scal(tablica, lewy, srodek, prawy);
    }

    static void scal(vector<T>& tablica, size_t lewy, size_t srodek, size_t prawy) {
        size_t rozmiarLewej = srodek - lewy + 1;
        size_t rozmiarPrawej = prawy - srodek;

        vector<T> lewaTablica(rozmiarLewej);
        vector<T> prawaTablica(rozmiarPrawej);

        for (size_t i = 0; i < rozmiarLewej; ++i) {
            lewaTablica[i] = tablica[lewy + i];
        }
        for (size_t j = 0; j < rozmiarPrawej; ++j) {
            prawaTablica[j] = tablica[srodek + 1 + j];
        }

        size_t i = 0;       
        size_t j = 0;       
        size_t k = lewy;    

        while (i < rozmiarLewej && j < rozmiarPrawej) {
            if (lewaTablica[i] <= prawaTablica[j]) {
                tablica[k] = lewaTablica[i];
                ++i;
            }
            else {
                tablica[k] = prawaTablica[j];
                ++j;
            }
            ++k;
        }

        while (i < rozmiarLewej) {
            tablica[k] = lewaTablica[i];
            ++i;
            ++k;
        }

        while (j < rozmiarPrawej) {
            tablica[k] = prawaTablica[j];
            ++j;
            ++k;
        }
    }
};