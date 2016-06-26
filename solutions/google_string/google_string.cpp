#include <iostream>
#include <string>

using namespace std;

int kth_char(unsigned long long k) {
    if ((k&(k-1)) == 0)
        return 0;
    unsigned long long b = k;
    while (k&(k-1)) {
        k &= k-1;
    }
    return 1 - kth_char((k<<1) - b);
}

int main(void)
{
    int count;
    cin >> count;
    for (int i = 1; i <= count; ++i) {
        unsigned long long k;
        cin >> k;
        cout << "Case #" << i << ": " << kth_char(k) << endl;
    }
    return 0;
}
