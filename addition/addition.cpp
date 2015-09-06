#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
#include <sstream>

using namespace std;
struct Equation {
    explicit Equation(string s) {
        string::size_type add = s.find('+');
        string::size_type eq = s.find('=');
        if (eq == string::npos)
            make_equation(s.substr(0, add), s.substr(add+1), "0");
        else
            make_equation(s.substr(0, add), s.substr(add+1, eq-add-1), s.substr(eq+1));
    }
    void make_equation(string a, string b, string c) {
        v1 = a;
        v2 = b;
        istringstream is(c);
        is >> val;
    }
    string v1, v2;
    int val;
};

ostream & operator<< (ostream &os, const Equation &eq) {
    os << eq.v1 << "+" << eq.v2 << "=" << eq.val;
    return os;
}

typedef vector<vector<float> > Matrix;

void print(Matrix matrix) {
    for (Matrix::size_type i = 0, iend = matrix.size(); i < iend; ++i) {
        for (Matrix::size_type j = 0, jend = matrix[i].size(); j < jend; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

vector<Equation> solve(vector<Equation> &bases, map<string, int> &vars, vector<Equation> &equations) {
    Matrix matrix;
    for (vector<Equation>::iterator i = bases.begin(), iend = bases.end(); i != iend; ++i) {
        vector<float> vec(vars.size()+1, 0);
        vec[vars[i->v1]] += 1;
        vec[vars[i->v2]] += 1;
        vec[vars.size()] = i->val;
        matrix.push_back(vec);
    }
    //print(matrix);
    Matrix::size_type last = matrix.size()-1;
    for (Matrix::size_type i = 0, iend = min(matrix.size(), vars.size()); i < iend; ++i) {
        if (matrix[i][i] == 0) {
            if (last > i)
                matrix[i--].swap(matrix[last--]);
            else
                last = matrix.size()-1;
            continue;
        }
        last = matrix.size()-1;
        if (matrix[i][i] != 1) {
            float divide = matrix[i][i];
            for (Matrix::size_type j = 0, jend = vars.size()+1; j < jend; ++j) {
                matrix[i][j] /= divide;
            }
        }
        for (Matrix::size_type j = 0, jend = matrix.size(); j < jend; ++j) {
            if (i == j || matrix[j][i] == 0)
                continue;
            float factor = matrix[j][i];
            for (Matrix::size_type k = 0, kend = vars.size()+1; k < kend; ++k) {
                matrix[j][k] -= matrix[i][k] * factor;
            }
        }
    }
    //print(matrix);
#if 1
    vector<Equation> ret;
    for (vector<Equation>::iterator i = equations.begin(), iend = equations.end(); i != iend; ++i) {
        vector<float> vec(vars.size()+1, 0);
        vec[vars[i->v1]] += 1;
        vec[vars[i->v2]] += 1;
        vector<float>::size_type j = 0, jend = vec.size();
        for (; j < jend-1; ++j) {
            if (vec[j]) {
                if (j < matrix.size() && matrix[j][j]) {
                    float factor = vec[j];
                    for (vector<float>::size_type k = j, kend = jend; k < kend; ++k) {
                        vec[k] -= matrix[j][k] * factor;
                    }
                } else
                    break;
            }
        }
        if (j == jend-1) {
            Equation eq(*i);
            eq.val = -vec.back();
            ret.push_back(eq);
        }
    }
#endif 
    return ret;
}

int main(void)
{
    int count;
    cin >> count;
    for (int i = 1; i <= count; ++i) {
        vector<Equation> bases, equations;
        map<string, int> vars;
        int n, q;
        cin >> n;
        for (int j = 0; j < n; ++j) {
            string s;
            cin >> s;
            Equation eq(s);
            bases.push_back(eq);
            vars.insert(make_pair(eq.v1, vars.size()));
            vars.insert(make_pair(eq.v2, vars.size()));
        }
        cin >> q;
        for (int j = 0; j < q; ++j) {
            string s;
            cin >> s;
            Equation eq(s);
            equations.push_back(eq);
            vars.insert(make_pair(eq.v1, vars.size()));
            vars.insert(make_pair(eq.v2, vars.size()));
        }
        cout << "Case #" << i << ":" << endl;
        vector<Equation> ret = solve(bases, vars, equations);
        for (vector<Equation>::iterator i = ret.begin(), iend = ret.end(); i != iend; ++i) {
            cout << *i << endl;
        }
    }
    return 0;
}
