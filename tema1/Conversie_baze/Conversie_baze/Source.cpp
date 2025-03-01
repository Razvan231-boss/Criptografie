#include <iostream>
#include<string>
#include<algorithm>

using namespace std;

int toDecimal(const string& num, int base) {
	int value = 0;
	int power = 1;

	for (int i = num.size() - 1; i >= 0; i--) {
		int digit;
		if (isdigit(num[i])) {
			digit = num[i] - '0';
		}
		else {
			digit = num[i] - 'A' + 10;
		}

		if (digit >= base) {
			cerr << "Cifra invalida pentru baza " << base << "!\n";
			exit(1);
		}

		value += digit * power;
		power *= base;
	}
	return value;
}

string fromDecimal(int num, int base) {
	if (num == 0) return "0";

	string result;
	while (num > 0) {
		int remainder = num % base;
		if (remainder < 10)
			result += (char)('0' + remainder);
		else
			result += (char)('A' + (remainder - 10));
		num /= base;
	}
	reverse(result.begin(), result.end());
	return result;
}

string convertBase(const string& num, int b1, int b2) {
	int decimalValue = toDecimal(num, b1);
	return fromDecimal(decimalValue, b2);
}

int main() {
	string num;
	int b1, b2;

	cout << "Introduceti numarul: ";
	cin >> num;
	cout << "Introduceti baza initiala (b1): ";
	cin >> b1;
	cout << "Introduceti baza finala (b2): ";
	cin >> b2;

	if (b1 < 2 || b1>26 || b2 < 2 || b2>26) {
		cerr << "Bazele trebuie sa fie intre 2 si 26!\n";
		return 1;
	}

	string result = convertBase(num, b1, b2);
	cout << "Numarul " << num << " in baza " << b1 << " este " << result << " in baza " << b2 << ".\n";

	return 0;
}