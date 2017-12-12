#include <iostream>
#include <fstream>
using namespace std;

// using KMP algorithm
class countPattern {
    int *next, lenP, count, lpos;
    string s, p, s_l;
public:
    countPattern(ifstream &in, string pat) {
        p = pat;
        count = 0;
        getline(in, s, '#');
        lenP = (int)p.length();
    }
    int fastfind(int k);
    void getnext();
    int countpattern(int k);
    int getCount() {return count;}
};

int countPattern::fastfind(int k) {
    int posP = 0, posT = k;
    int lenT = (int)s.length();
    while (posP < lenP && posT < lenT)
        if (posP == -1 || p[posP] == s[posT]) {
            posT++; posP++;
        }
        else {
            posP = next[posP];
        }
    if (posP < lenP) return -1;
    else             return (posT - lenP);
}

void countPattern::getnext() {
    int j = 0, k = -1;
    next = new int[lenP];
    next[0] = -1;
    while (j < lenP - 1) {
        if (k == -1 || p[j] == p[k]) {
            j++; k++;
            next[j] = k;
        }
        else k = next[k];
    }
}

int countPattern::countpattern(int k) {
    lpos = k;
    int pos = fastfind(k);
    if (pos == -1) {
        s_l += s.substr(lpos, 10000);
        //cout << s_l;
        return -1;
    }
    else {
        count++;
        return (pos + lenP);
    }
}

int main(int argc, char **argv) {
    if(argc < 3) {
        cout << "No enough arguments.\n";
        return 0;
    }
    ifstream input(argv[1], ios::in);
    if (!input) exit(1);
    countPattern A(input, argv[2]);
    A.getnext();
    int k = 0;
    while (k != -1) {
        k = A.countpattern(k);
    }
    cout << "Total：" << A.getCount() << endl;
    return 0;
}