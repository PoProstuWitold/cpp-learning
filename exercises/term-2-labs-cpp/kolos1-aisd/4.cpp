// LABORATORIUM 4. ALGORYTMY PODZIAŁU ZBIORU NA DWIE ALBO TRZY CZĘŚCI

// Pytania kontrolne:
// 1) W jaki sposób działa algorytm podziału zbioru na dwie części?
// 2) Jaka jest złożoność czasowa algorytmu podziału zbioru na dwie części?
// 3) W jaki sposób działa algorytm podziału zbioru na trzy części?
// 4) Jaka jest złożoność czasowa algorytmu podziału zbioru na trzy części?


// 1)
// Algorytm podziału zbioru na dwie części (ang. partitioning) polega na wyborze elementu zwanego pivotem, 
// a następnie podziale zbioru na dwie części: jedną zawierającą elementy mniejsze lub równe pivotowi, 
// a drugą zawierającą elementy większe od niego. Elementy te nie muszą być posortowane między sobą. 
// Proces podziału jest powtarzany rekurencyjnie na każdej z dwóch części, 
// aż do momentu, gdy pozostanie tylko jeden element.


// 2)
// Złożoność czasowa algorytmu podziału zbioru na dwie części zależy od wyboru pivota i może być różna. 
// W najgorszym przypadku (gdy pivot jest zawsze wybierany jako skrajny element i podział powoduje, 
// że jedna z części jest pusta) złożoność wynosi O(n^2), 
// jednak w przypadku optymalnym złożoność wynosi O(n*log n).


// 3)
// Algorytm podziału zbioru na trzy części (ang. tri-partitioning) działa podobnie jak podział na dwie części, 
// ale tworzy trzy części: jedną zawierającą elementy mniejsze od pivota, 
// drugą zawierającą elementy równe pivotowi i trzecią zawierającą elementy większe od pivota. 
// Elementy w każdej z tych trzech części nie muszą być posortowane między sobą. 
// Proces podziału jest powtarzany rekurencyjnie na części zawierających elementy mniejsze i większe od pivota.


// 4)
// Złożoność czasowa algorytmu podziału zbioru na trzy części zależy również od wyboru pivota i może być różna. 
// W przypadku optymalnym złożoność wynosi O(n), ponieważ w każdym rekurencyjnym wywołaniu przetwarzane 
// są tylko elementy, które nie są równe pivotowi. 
// Jednak w najgorszym przypadku (gdy wszystkie elementy w zbiorze są równe) złożoność wynosi O(n^2).