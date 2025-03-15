#include <iostream>
using namespace std;

// Funcția care calculează simbolul lui Jacobi (a / n)
int jacobi(int a, int n) {
    // Cazul de bază: a = 0
    if (a == 0)
        return 0;

    // Reducerea a modulo n
    a = a % n;

    // Dacă a este negativ, facem ajustare
    if (a < 0)
        a = a + n;

    // Algoritmul lui Jacobi
    int result = 1;
    while (a != 0) {
        // Dacă a este par
        while (a % 2 == 0) {
            a = a / 2;
            // Legea de semn: (2 / n) = (-1)^((n^2 - 1) / 8)
            if (n % 8 == 3 || n % 8 == 5)
                result = -result;
        }

        // Dacă a este impar, aplicăm reciproca pătratică
        swap(a, n);

        if (a % 4 == 3 && n % 4 == 3)
            result = -result;

        a = a % n;
    }

    // Dacă a ajunge la 1, înseamnă că simbolul lui Jacobi este 1
    return (n == 1) ? result : 0;
}

int main() {
    int a, n;

    // Citirea valorilor
    cout << "Introduceti a si n: ";
    cin >> a >> n;

    // Calculul simbolului lui Jacobi
    int result = jacobi(a, n);

    // Afișarea rezultatului
    if (result == 1)
        cout << "( " << a << " / " << n << " ) = 1 (este un patrat quadratic mod " << n << ")" << endl;
    else if (result == -1)
        cout << "( " << a << " / " << n << " ) = -1 (nu este un patrat quadratic mod " << n << ")" << endl;
    else
        cout << "( " << a << " / " << n << " ) = 0 (n este divizibil cu " << a << ")" << endl;

    return 0;
}
