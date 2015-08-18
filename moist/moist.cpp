#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int moist(vector<string> &cards) {
    int ret = 0;
    if (cards.size() < 2)
        return ret;
    for (vector<string>::size_type start = 0, i = 1, iend = cards.size(); i < iend; ++i) {
        if (lexicographical_compare(cards[i].begin(), cards[i].end(), cards[start].begin(), cards[start].end()))
            ++ret;
        else
            start = i;
    }
    return ret;
}

int main(void)
{
    int count;
    cin >> count;
    for (int i = 1; i <= count; ++i) {
        int card_num;
        cin >> card_num;
        cin.get();
        vector<string> cards;
        while (card_num) {
            string tmp;
            getline(cin, tmp);
            cards.push_back(tmp);
            --card_num;
        }
        cout << "Case #" << i << ": " << moist(cards) << endl;
    }
}
