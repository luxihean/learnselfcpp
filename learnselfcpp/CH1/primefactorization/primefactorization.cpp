#include <iostream>
#include <vector>
using namespace std;

void primeFactorization(int n, vector<int>& factors) {
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    if (n > 2) {
        factors.push_back(n);
    }
}

int main() {
        int n;
        while(true){
        cout << "input your number: ";
        cin >> n;

        if (n <= 1) {
            cout << "input must be larger than 1。" << endl;
        } else {
            vector<int> factors;
            primeFactorization(n, factors);

            cout << "number " << n << " divide into: ";
            for (size_t i = 0; i < factors.size(); i++) {
                cout << factors[i];
                if (i != factors.size() - 1) {
                    cout << " x ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}
