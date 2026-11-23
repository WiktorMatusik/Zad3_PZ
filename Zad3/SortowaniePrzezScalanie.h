/**
 * @file SortowaniePrzezScalanie.h
 * @brief Definicja oraz implementacja szablonowej klasy realizującej algorytm sortowania przez scalanie (MergeSort).
 * @author Wiktor Matusik
 * @date 2026
 */

#pragma once
#include <vector>
#include <cstddef>

using namespace std;

/**
 * @class SortowaniePrzezScalanie
 * @brief Szablonowa klasa udostępniająca statyczne metody do sortowania wektorów algorytmem MergeSort.
 *
 * Klasa implementuje stabilny algorytm sortowania przez scalanie w oparciu o strategię
 * „dziel i zwyciężaj” (ang. Divide and Conquer) o złożoności obliczeniowej $O(n \log n)$.
 * Dzięki wykorzystaniu szablonów obsługuje dowolne typy danych posiadające zdefiniowany operator porównania (<=).
 *
 * @tparam T Typ elementów przechowywanych w sortowanym wektorze (np. int, long int, float, double)
 */
template <typename T>
class SortowaniePrzezScalanie {
public:
    /**
     * @brief Główna metoda publiczna uruchamiająca proces sortowania rosnącego przekazanego wektora.
     *
     * W przypadku tablic pustych lub jednoelementowych metoda kończy działanie natychmiast,
     * nie wykonując zbędnych alokacji pamięci.
     *
     * @param[in,out] tablica Referencja do wektora typu std::vector<T>, który ma zostać posortowany w miejscu.
     */
    static void sortuj(vector<T>& tablica) {
        if (tablica.size() <= 1) {
            return;
        }
        sortujRekurencyjnie(tablica, 0, tablica.size() - 1);
    }

private:
    /**
     * @brief Rekurencyjna metoda dzieląca zadany przedział tablicy na dwie mniejsze podtablice.
     *
     * Wyznacza indeks środkowy przedziału, wywołuje siebie rekurencyjnie dla lewej oraz prawej
     * połowy, a następnie scala oba uporządkowane fragmenty metodą scal().
     *
     * @param[in,out] tablica Referencja do sortowanego wektora.
     * @param[in] lewy Indeks początkowy aktualnie rozpatrywanego przedziału.
     * @param[in] prawy Indeks końcowy aktualnie rozpatrywanego przedziału.
     */
    static void sortujRekurencyjnie(vector<T>& tablica, size_t lewy, size_t prawy) {
        if (lewy >= prawy) {
            return;
        }

        size_t srodek = lewy + (prawy - lewy) / 2;

        sortujRekurencyjnie(tablica, lewy, srodek);
        sortujRekurencyjnie(tablica, srodek + 1, prawy);
        scal(tablica, lewy, srodek, prawy);
    }

    /**
     * @brief Scala dwie sąsiednie, posortowane podtablice w jeden uporządkowany ciąg.
     *
     * Tworzy tymczasowe kopie lewego [lewy..srodek] oraz prawego [srodek+1..prawy] podprzedziału,
     * a następnie przepisuje elementy w porządku niemalejącym z powrotem do wektora głównego.
     *
     * @param[in,out] tablica Referencja do głównego wektora, w którym zapisywany jest wynik scalania.
     * @param[in] lewy Indeks początku lewej podtablicy.
     * @param[in] srodek Indeks końca lewej podtablicy (punkt podziału).
     * @param[in] prawy Indeks końca prawej podtablicy.
     */
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

        size_t i = 0;       ///< Indeks bieżącego elementu w lewej podtablicy pomocniczej
        size_t j = 0;       ///< Indeks bieżącego elementu w prawej podtablicy pomocniczej
        size_t k = lewy;    ///< Indeks docelowy w tablicy wynikowej

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