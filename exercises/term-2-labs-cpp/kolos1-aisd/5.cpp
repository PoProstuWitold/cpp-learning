// LABORATORIUM 5. ALGORYTMY TEKSTOWE

// Pytania kontrolne:
// 1) Jakie są algorytmy wyszukiwania wzorca w tekście?
// 2) Na czym polega algorytm naiwny?
// 3) W jaki sposób należy stworzyć tablicę dopasowań dla algorytmu
// Knutha-Morrisa-Pratta?
// 4) W jaki sposób dla znaku wyświetlić jego kod z tabeli ASCII?
// 5) Na czym polega algorytm Boyer’a-Moore’a?
// 6) Do czego służy tablica przesunięć dla algorytmu Boyer’a-Moore’a?
// 7) Jaka jest wada algorytmu naiwnego?


// 1)
// Algorytmy wyszukiwania wzorca w tekście to m.in. algorytm naiwny, algorytm Knutha-Morrisa-Pratta, 
// algorytm Boyer’a-Moore’a i algorytm Rabina-Karpa.


// 2)
// Algorytm naiwny polega na porównywaniu wzorca z każdym możliwym podciągiem tekstu. Jest to najprostszy i najsłabszy algorytm wyszukiwania wzorca, gdyż jego złożoność wynosi O(n*m), gdzie n to długość tekstu, a m to długość wzorca.


// 3)
// Tablica dopasowań dla algorytmu Knutha-Morrisa-Pratta (KMP) tworzona jest w czasie O(m), gdzie m to długość wzorca. 
// Każdy element tablicy odpowiada długości najdłuższego prefiksu wzorca, który jest jednocześnie jego sufiksem.


// 4)
// Aby wyświetlić kod znaku z tabeli ASCII, należy użyć funkcji ord() w Pythonie, np. ord('a') zwraca wartość 97.


// 5)
// Algorytm Boyer’a-Moore’a polega na porównywaniu wzorca z tekstem z prawej strony. W przypadku niezgodności, 
// algorytm przesuwa wzorzec w prawo o określoną wartość zależną od wystąpienia znaku, który nie pasuje do wzorca. 
// Dzięki temu, algorytm może przeskakiwać znaczne fragmenty tekstu i ma złożoność O(n+m), gdzie n to długość tekstu, 
// a m to długość wzorca.


// 6)
// Tablica przesunięć dla algorytmu Boyer’a-Moore’a określa, o ile przesunąć wzorzec w przypadku wystąpienia niezgodnego znaku.
// Tablica ta jest tworzona w czasie O(m), gdzie m to długość wzorca. 
// Dla każdego znaku z alfabetu obliczana jest maksymalna wartość, 
// o którą można przesunąć wzorzec bez zaglądania poza jego granice.


// 7)
// Główną wadą algorytmu naiwnego (ang. naive algorithm) wyszukiwania wzorca w tekście jest to, 
// że jego czas działania zależy liniowo od długości tekstu oraz wzorca. 
// W najgorszym przypadku, gdy wzorzec występuje bardzo rzadko lub nie występuje w tekście, 
// algorytm ten musi porównać każdy znak tekstu z każdym znakiem wzorca, 
// co może skutkować dużym narzutem czasowym i prowadzić do nieakceptowalnie długiego czasu działania. 

// W praktyce, kiedy mamy do czynienia z dużymi tekstami i skomplikowanymi wzorcami, 
// algorytm naiwny jest zwykle niewystarczający i należy zastosować bardziej zaawansowane algorytmy, t
// akie jak np. algorytmy Knutha-Morrisa-Pratta, Boyer’a-Moore’a czy Rabin-Karpa, które mają znacznie lepszą złożoność czasową.