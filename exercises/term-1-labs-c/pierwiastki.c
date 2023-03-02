#include <math.h>
#include <stdio.h>

struct pierwiastki_kw
{
    int ilosc;
    float rozw1;
    float rozw2;
};

void pokaz_rozwiazania(const struct pierwiastki_kw* s);
struct pierwiastki_kw rozwiazanie_rownania_kw(float a, float b, float c);

int main(void)
{
    float a, b, c;
    printf("Podaj a: ");
    scanf("%f", &a);
    printf("Podaj b: ");
    scanf("%f", &b);
    printf("Podaj c: ");
    scanf("%f", &c);

    struct pierwiastki_kw rozwiazanie = rozwiazanie_rownania_kw(a, b, c);
    pokaz_rozwiazania(&rozwiazanie);

    return 0;
}

void pokaz_rozwiazania(const struct pierwiastki_kw* s)
{
    if (s->ilosc == 0)
        printf("Brak rozwiazan.\n");
    else if (s->ilosc == 1)
        printf("Jedno rozwiazanie rowne: %f.\n", s->rozw1);
    else
        printf("Dwa rozwiazania rowne: %f, %f.\n", s->rozw1, s->rozw2);
}

struct pierwiastki_kw rozwiazanie_rownania_kw(float a, float b, float c)
{
    struct pierwiastki_kw o = {0, 0.0, 0.0};
    float delta = b*b - 4*a*c;

    if (delta == 0)
    {
        o.ilosc = 1;
        o.rozw1 = -b/(2*a);
    }
    else if (delta > 0)
    {
        o.ilosc = 2;
        o.rozw1 = (-b-sqrt(delta))/(2*a);
        o.rozw2 = (-b+sqrt(delta))/(2*a);
    }

    return o;
}
