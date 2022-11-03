#include <math.h>
#include <stdio.h>

struct rownanie
{
    float a1;
    float a2;
    float b1;
    float b2;
    float c1;
    float c2;
};

struct para_liczbowa
{
    float x;
    float y;
};

struct rownanie uzupelnij_rownanie(void);
struct para_liczbowa podaj_niewiadome(void);
struct para_liczbowa rozwiaz_rownanie(const struct rownanie* r);

int main(void)
{
    struct rownanie r = uzupelnij_rownanie();
    struct para_liczbowa odp = rozwiaz_rownanie(&r);

    printf("\nx = %f, y = %f\n", odp.x, odp.y);

    return 0;
}

struct rownanie uzupelnij_rownanie(void)
{
    struct rownanie r;

    printf("a1*x + b1*y = c1\n");
    printf("a2*x + b2*y = c2\n");
    printf("\nPodaj a1: ");
    scanf("%f", &r.a1);
    printf("Podaj b1: ");
    scanf("%f", &r.b1);
    printf("Podaj c1: ");
    scanf("%f", &r.c1);
    printf("Podaj a2: ");
    scanf("%f", &r.a2);
    printf("Podaj b2: ");
    scanf("%f", &r.b2);
    printf("Podaj c2: ");
    scanf("%f", &r.c2);

    return r;
}

struct para_liczbowa podaj_niewiadome(void)
{
    struct para_liczbowa p;

    printf("\nPodaj x: ");
    scanf("%f", &p.x);
    printf("Podaj y: ");
    scanf("%f", &p.y);

    return p;
}

struct para_liczbowa rozwiaz_rownanie(const struct rownanie* r)
{
    struct para_liczbowa p = {0.0, 0.0};
    float w = r->a1*r->b2 - r->a2*r->b1;

    if (w != 0)
    {
        p.x = (r->c1*r->b2 - r->c2*r->b1)/w;
        p.y = (r->a1*r->c2 - r->a2*r->c1)/w;
    }

    return p;
}
