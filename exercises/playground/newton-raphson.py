import math

# funkcja, dla której szukamy pierwiastka
def f(x):
    return x ** 3 - math.e

# pochodna funkcji f
def df(x):
    return 3 * x ** 2

# metoda Newtona-Raphsona
def newton_raphson(x0, f, df, epsilon):
    x1 = x0 - f(x0) / df(x0)
    while abs(x1 - x0) > epsilon:
        x0 = x1
        x1 = x0 - f(x0) / df(x0)
    return x1

# obliczenie pierwiastka
e = math.e
x0 = e**(1/3)  # przybliżone początkowe przybliżenie
epsilon = 1e-6  # dokładność obliczeń
x = newton_raphson(x0, f, df, epsilon)

print(x)  # wyświetlenie wyniku