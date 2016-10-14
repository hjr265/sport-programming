// In the name of Allah, Most Gracious, Most Merciful

// Live Archive/2754
// Delta Encoding and Decoding
// implementation
// 
// 
// AC (2012-07-16 05:00:34)

#include <cstring>
#include <iostream>
#include <map>
#include <string>

#define SET(c, v) memset(c, v, sizeof(c))

using namespace std;

string L, Co, C, Io, I, P;
map<char, int> Pi;

string lower(const string &s) {
    string r = "";
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] >= 'A' && s[i] <= 'Z')
            r += s[i]-'A'+'a';
        else
            r += s[i];
    }
    return r;
}

void cipher(const string &s, bool p = true) {
    bool O[30];
    SET(O, 0);
    string R = "";
    int N = 0;
    for(int i = 0; i < s.size(); ++i) if(s[i] >= 'a' && s[i] <= 'z') {
        if(O[s[i]-'a'])
            goto LCERR;
        O[s[i]-'a'] = true;
        ++N;
        R += s[i];
    }
    if(N != 26)
        goto LCERR;
    P = R;
    Pi.clear();
    for(int i = 0; i < R.size(); ++i)
        Pi[R[i]] = i;
    for(int i = 0; i < R.size(); ++i)
        R[i] += -'a'+'A';
    if(p)
        cout << "Good cipher.  Using " << R << "." << endl;
    return;
LCERR:
    if(p)
        cout << "Bad cipher.  Using default." << endl;
    cipher("abcdefghijklmnopqrstuvwxyz", false);
    return;
}

void encrypt(const string &s, const string &So) {
    char L = 'a';
    string r = "";
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            r += P[(Pi[s[i]]-Pi[L]+26*2)%26];
            L = s[i];
        } else {
            r += s[i];
            L = 'a';
        }
        if(So[i] >= 'A' && So[i] <= 'Z')
            r[i] += -'a'+'A';
    }
    cout << "RESULT:  " << r << endl;
}

void decrypt(const string &s, const string &So) {
    char L = 'a';
    string r = "";
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            for(char c = 'a'; c <= 'z'; ++c) if(P[(Pi[c]-Pi[L]+26*2)%26] == s[i]) {
                r += c;
                L = c;
                break;
            }
        } else {
            r += s[i];
            L = 'a';
        }
        if(So[i] >= 'A' && So[i] <= 'Z')
            r[i] += -'a'+'A';
    }
    cout << "RESULT:  " << r << endl;
}

int main() {
    cipher("", false);
    while(getline(cin, L)) {
        for(int i = 0; i < L.size()+1; ++i) if(L[i] == ' ' || i == L.size()) {
            Co = L.substr(0, i);
            if(i != L.size())
                ++i;
            Io = L.substr(i);
            C = lower(Co);
            I = lower(Io);
            break;
        }
        if(C == "encrypt") {
            encrypt(I, Io);
        } else if(C == "decrypt") {
            decrypt(I, Io);
        } else if(C == "cipher") {
            cipher(I);
        } else {
            cout << "Command not understood." << endl;
        }
    }
    return 0;
}
