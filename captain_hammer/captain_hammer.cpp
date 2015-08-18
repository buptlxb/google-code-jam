#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(void)
{
    int count;
    cin >> count;
    double a = 9.8;
    cout << showpoint << fixed << setprecision(7);
    for (int i = 1; i <= count; ++i) {
        int v, d;
        cin >> v >> d;
        double res = (a*d) / (v*v);
        if (fabs(res-1.000000) < 1.0e-6)
            res = 1.0;
        cout << "Case #" << i << ": " << asin(res) * 90.0 / M_PI << endl;
    }
    return 0;
}
