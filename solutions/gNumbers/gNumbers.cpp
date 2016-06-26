#include <iostream>
#include <map>
#include <vector>

using namespace std;

int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149};
map<uint64_t, char> dict;

bool isprime(uint64_t n) {
    if (n == 1)
        return true;
    int len = sizeof(prime)/sizeof(prime[0]);
    for (int i = 0; i < len; ++i) {
        if (n == prime[i])
            return true;
    }
    return false;
}

uint64_t sum(uint64_t n) {
    uint64_t ret = 0;
    while (n) {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

vector<uint64_t> primes(uint64_t b) {
    vector<uint64_t> ret;
    for (uint64_t i = 2; i*i <= b; ++i) {
        uint64_t count = 0;
        while (b % i == 0) {
            b /= i;
            ++count;
        }
        if (count)
            ret.push_back(i);
    }
    if (b > 2)
        ret.push_back(b);
    return ret;
}

int solve(uint64_t n) {
    if (dict[n])
        return dict[n];
    uint64_t x = sum(n);
    if (isprime(x)) {
        return dict[n] = -1;
    }
    vector<uint64_t> ps = primes(n);
    for (auto p : ps) {
        uint64_t b = n;
        while (b % p == 0)
            b /= p;
        if (solve(b) == -1)
            return dict[n] = 1;
    }
    return dict[n] = -1;
}

int main(void)
{
    int count;
    cin >> count;
    for (int i = 1; i <= count; ++i) {
        uint64_t n;
        cin >> n;
        cout << "Case #" << i << ": " << (solve(n)==1 ? "Laurence" : "Seymour") << endl;
    }
    return 0;
}
