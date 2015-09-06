#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <bitset>
#include <vector>
#include <set>

using namespace std;

string next(vector<bitset<7> > nums, vector<bitset<7> > &states) {
    bitset<7> mask;
    for (vector<bitset<7> >::iterator i = states.begin(), iend = states.end(); i != iend; ++i) {
        mask |= *i;
    }
    set<string> ret;
    for (ulong m = 0; m < 128; ++m) {
        bitset<7> cm = mask;
        cm |= m;
        //cout << "-->" << cm << endl;
        vector<bitset<7> > s(nums);
        for (vector<bitset<7> >::iterator i = s.begin(), iend = s.end(); i != iend; ++i) {
            *i &= cm;
        }
        for (vector<bitset<7> >::iterator i = s.begin(), iend = s.end(); i != iend; ++i) {
            vector<bitset<7> >::iterator k = i;
            if (*k == states.front()) {
                vector<bitset<7> >::iterator j = states.begin(), jend = states.end();
                for ( ; j != jend; ++j) {
                    if (*k != *j)
                        break;
                    ++k;
                    if (k == s.end())
                        k = s.begin();
                }
                if (j == jend) {
                    ret.insert(k->to_string());
                    //cout << k->to_string() << " ";
                }
            }
        }
    }
    //cout << endl;
    if (ret.size() != 1)
        return "ERROR!";
    else
        return *(ret.begin());
}

int main(void)
{
    
    vector<bitset<7> > nums;
    nums.push_back(bitset<7>(string("1111011")));
    nums.push_back(bitset<7>(string("1111111")));
    nums.push_back(bitset<7>(string("1110000")));
    nums.push_back(bitset<7>(string("1011111")));
    nums.push_back(bitset<7>(string("1011011")));
    nums.push_back(bitset<7>(string("0110011")));
    nums.push_back(bitset<7>(string("1111001")));
    nums.push_back(bitset<7>(string("1101101")));
    nums.push_back(bitset<7>(string("0110000")));
    nums.push_back(bitset<7>(string("1111110")));
    int count;
    cin >> count;
    for (int i = 1; i <= count; ++i) {
        int n;
        cin >> n;
        vector<bitset<7> > states;
        for (int j = 0; j < n; ++j) {
            string state;
            cin >> state;
            states.push_back(bitset<7>(state));
        }
        cout << "Case #" << i << ": " << next(nums, states) << endl;
    }
    return 0;
}
