#include "pch.h"
#include <vector>
#include <algorithm>
#include <random>
#include "../Zad3/SortowaniePrzezScalanie.h"

using namespace std;

TEST(TestySortowaniaPrzezScalanie, JuzPosortowanaRosnaco) {
    vector<int> tablica = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector<int> oczekiwana = tablica;

    SortowaniePrzezScalanie<int>::sortuj(tablica);
    EXPECT_EQ(tablica, oczekiwana);
}

TEST(TestySortowaniaPrzezScalanie, PosortowanaOdwrotnie) {
    vector<int> tablica = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    vector<int> oczekiwana = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    SortowaniePrzezScalanie<int>::sortuj(tablica);
    EXPECT_EQ(tablica, oczekiwana);
}

TEST(TestySortowaniaPrzezScalanie, LosowaTablica) {
    vector<double> tablica = { 45.2, 12.8, 89.1, 3.4, 67.0, 23.5, 99.9, 1.1 };
    vector<double> oczekiwana = tablica;
    sort(oczekiwana.begin(), oczekiwana.end());

    SortowaniePrzezScalanie<double>::sortuj(tablica);
    EXPECT_EQ(tablica, oczekiwana);
}

TEST(TestySortowaniaPrzezScalanie, TylkoLiczbyUjemne) {
    vector<int> tablica = { -5, -100, -1, -42, -15, -3 };
    vector<int> oczekiwana = { -100, -42, -15, -5, -3, -1 };

    SortowaniePrzezScalanie<int>::sortuj(tablica);
    EXPECT_EQ(tablica, oczekiwana);
}

TEST(TestySortowaniaPrzezScalanie, LiczbyUjemneIDodatnie) {
    vector<long int> tablica = { -10, 25, 0, -3, 14, -50, 8 };
    vector<long int> oczekiwana = { -50, -10, -3, 0, 8, 14, 25 };

    SortowaniePrzezScalanie<long int>::sortuj(tablica);
    EXPECT_EQ(tablica, oczekiwana);
}

TEST(TestySortowaniaPrzezScalanie, PustaTablicaBezWyjatku) {
    vector<int> tablica = {};

    EXPECT_NO_THROW(SortowaniePrzezScalanie<int>::sortuj(tablica));
    EXPECT_TRUE(tablica.empty());
}

TEST(TestySortowaniaPrzezScalanie, JedenElement) {
    vector<float> tablica = { 42.5f };
    vector<float> oczekiwana = { 42.5f };

    SortowaniePrzezScalanie<float>::sortuj(tablica);
    EXPECT_EQ(tablica, oczekiwana);
}

TEST(TestySortowaniaPrzezScalanie, TablicaZDuplikatami) {
    vector<int> tablica = { 5, 2, 8, 2, 5, 1, 8, 5 };
    vector<int> oczekiwana = { 1, 2, 2, 5, 5, 5, 8, 8 };

    SortowaniePrzezScalanie<int>::sortuj(tablica);
    EXPECT_EQ(tablica, oczekiwana);
}

TEST(TestySortowaniaPrzezScalanie, UjemnaTablicaZDuplikatami) {
    vector<int> tablica = { -3, -10, -3, -1, -10, -7, -1 };
    vector<int> oczekiwana = { -10, -10, -7, -3, -3, -1, -1 };

    SortowaniePrzezScalanie<int>::sortuj(tablica);
    EXPECT_EQ(tablica, oczekiwana);
}

TEST(TestySortowaniaPrzezScalanie, MieszanaZDuplikatami) {
    vector<double> tablica = { -4.5, 2.0, 0.0, -4.5, 7.1, 0.0, 2.0, -1.2 };
    vector<double> oczekiwana = { -4.5, -4.5, -1.2, 0.0, 0.0, 2.0, 2.0, 7.1 };

    SortowaniePrzezScalanie<double>::sortuj(tablica);
    EXPECT_EQ(tablica, oczekiwana);
}

TEST(TestySortowaniaPrzezScalanie, DwaElementyRosnaco) {
    vector<int> tablica = { 10, 20 };
    vector<int> oczekiwana = { 10, 20 };

    SortowaniePrzezScalanie<int>::sortuj(tablica);
    EXPECT_EQ(tablica, oczekiwana);
}

TEST(TestySortowaniaPrzezScalanie, DuzaTablicaPonad100Elementow) {
    vector<int> tablica(150);
    mt19937 generator(42);
    uniform_int_distribution<int> rozklad(1, 10000);

    for (auto& element : tablica) {
        element = rozklad(generator);
    }

    vector<int> oczekiwana = tablica;
    sort(oczekiwana.begin(), oczekiwana.end());

    SortowaniePrzezScalanie<int>::sortuj(tablica);
    EXPECT_EQ(tablica, oczekiwana);
}

TEST(TestySortowaniaPrzezScalanie, DuzaTablicaMieszanaZDuplikatami) {
    vector<int> tablica(200);
    mt19937 generator(123);
    uniform_int_distribution<int> rozklad(-25, 25);

    for (auto& element : tablica) {
        element = rozklad(generator);
    }

    vector<int> oczekiwana = tablica;
    sort(oczekiwana.begin(), oczekiwana.end());

    SortowaniePrzezScalanie<int>::sortuj(tablica);
    EXPECT_EQ(tablica, oczekiwana);
}