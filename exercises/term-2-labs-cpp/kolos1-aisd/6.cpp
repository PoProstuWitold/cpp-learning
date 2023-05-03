// LABORATORIUM 6. ALGORYTMY TEKSTOWE Z UŻYCIEM FUNKCJI HASZUJĄCYCH

// Pytania kontrolne:
// 1) Co to jest funkcja haszująca i do czego służy?
// 2) Na czym polega algorytm Karpa-Rabina?
// 3) W jaki sposób wyliczyć hasz na podstawie poprzednio wyliczonego haszu?
// 4) Jakie zastosowanie ma użycie arytmetyki modulo przy implementacji algorytmu 
// Karpa-Rabina?


// 1)
// Funkcja haszująca to funkcja, która mapuje dowolnie długi ciąg danych na skróconą reprezentację, zwykle o stałej długości.
// Służy ona do przyspieszenia przetwarzania danych poprzez umożliwienie szybkiego porównywania i wyszukiwania danych. 
// Funkcje haszujące są stosowane w wielu dziedzinach informatyki, w tym w algorytmach wyszukiwania wzorców 
// w tekście, kryptografii, systemach baz danych, a także w inżynierii oprogramowania do sprawdzania integralności danych.


// 2)
// Algorytm Karpa-Rabina to algorytm wyszukiwania wzorca w tekście, który opiera się na użyciu funkcji haszującej. 
// Algorytm ten działa w czasie liniowym O(n+m) dla tekstu o długości n i wzorca o długości m. 
// Polega na wygenerowaniu funkcji haszującej dla wzorca oraz tekstu, a następnie porównaniu wyników, 
// w przypadku gdy hasze są zgodne, zostają wykonane dodatkowe sprawdzenia.


// 3)
// W przypadku algorytmu Karpa-Rabina, hasz wyliczany jest na podstawie poprzednio 
// wyliczonego haszu poprzez wykorzystanie tzw. szacunkowego haszowania, czyli obliczenie 
// nowego hasza na podstawie poprzedniego hasza i zmian w tekście (np. przesunięcie o jeden znak).


// 4)
// Użycie arytmetyki modulo przy implementacji algorytmu Karpa-Rabina umożliwia zachowanie stałego rozmiaru hasza, 
// niezależnie od długości tekstu czy wzorca. Ponadto, użycie modulo zwykle skraca czas wykonywania funkcji haszującej, 
// co wpływa korzystnie na czas działania algorytmu.