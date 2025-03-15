#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Exponentiere modulară rapida: calculeaza (base^exp) % mod
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)  // Daca exponentul este impar
            result = (result * base) % mod;
        exp = exp >> 1;  // Impărtim la 2 (shift bit)
        base = (base * base) % mod;
    }
    return result;
}

// Functia care calculeaza simbolul lui Jacobi (a / n)
int jacobi(long long a, long long n) {
    if (n <= 0 || n % 2 == 0) return 0; // n trebuie sa fie impar si pozitiv

    int result = 1;
    a = a % n;
    while (a != 0) {
        while (a % 2 == 0) { // Daca a este par, folosim regula (2 / n)
            a /= 2;
            if (n % 8 == 3 || n % 8 == 5) result = -result;
        }

        // Aplicam reciprocitatea patratica
        swap(a, n);
        if (a % 4 == 3 && n % 4 == 3) result = -result;
        a = a % n;
    }

    return (n == 1) ? result : 0;
}

// Testul Solovay-Strassen pentru primalitate
bool solovay_strassen(long long n, int k) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false; // Numerele pare (în afară de 2) sunt compuse

    srand(time(0)); // Initializare pentru numere random

    for (int i = 0; i < k; i++) {
        long long a = 2 + rand() % (n - 2); // Alegem a între 2 si n-2
        int jacobi_symbol = jacobi(a, n) % n;
        if (jacobi_symbol < 0) jacobi_symbol += n; // Ajustam negativitatea

        long long mod_exp_result = mod_exp(a, (n - 1) / 2, n);

        // Verificam conditia Euler-Jacobi
        if (jacobi_symbol == 0 || mod_exp_result != jacobi_symbol)
            return false; // Daca conditia nu e indeplinita, n e compus
    }
    return true; // Daca trece toate testele, e probabil prim
}

// Functia principala
int main() {
    long long n;
    int k;

    cout << "Introduceti numarul n pentru testul de primalitate: ";
    cin >> n;
    cout << "Introduceti numarul de iteratii k: ";
    cin >> k;

    if (solovay_strassen(n, k))
        cout << n << " este probabil prim." << endl;
    else
        cout << n << " este compus." << endl;

    return 0;
}
