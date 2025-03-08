#include <iostream>
using namespace std;

long long phi(long long n) {
    long long result = n;

    // Verificăm divizibilitatea cu 2
    if (n % 2 == 0) {
        while (n % 2 == 0)
            n /= 2;
        result -= result / 2;
    }

    // Verificăm divizorii primi impari de la 3 la sqrt(n)
    for (long long p = 3; p * p <= n; p += 2) {
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }

    // Dacă rămâne un factor prim mai mare decât sqrt(n)
    if (n > 1)
        result -= result / n;

    return result;
}

int main() {
	long long n;
	cout << "Introduceti nu numar: ";
	cin >> n;
	cout << "phi(" << n << ")=" << phi(n) << endl;
	return 0;
}