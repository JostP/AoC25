#include "functions.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

long long resiPart1(istream& file){
    string vrstica1;
    string vrstica2;
    string vrstica3;
    string vrstica4;
    string operacije;

    getline(file, vrstica1);
    stringstream s1(vrstica1);
    getline(file, vrstica2);
    stringstream s2(vrstica2);
    getline(file, vrstica3);
    stringstream s3(vrstica3);
    getline(file, vrstica4);
    stringstream s4(vrstica4);
    getline(file, operacije);
    stringstream ops(operacije);

    int a, b, c, d;
    char op;
    long long skupaj = 0;

    while(s1 >> a && s2 >> b && s3 >> c && s4 >> d && ops >> op){
        long long rezultat = 0;

        if(op == '+'){
            rezultat = a + b + c + d;
        }
        else if(op == '*'){
            rezultat = a;
            rezultat *= b;
            rezultat *= c;
            rezultat *= d;
        }

        skupaj += rezultat;
    }

    return skupaj;
}

long long resiPart2(istream& file){
    string l1, l2, l3, l4, ops;

    getline(file, l1);
    stringstream s1(l1);
    getline(file, l2);
    stringstream s2(l2);
    getline(file, l3);
    stringstream s3(l3);
    getline(file, l4);
    stringstream s4(l4);
    getline(file, ops);
    stringstream os(ops);

    char o;
    char c1, c2, c3, c4;
    char trenutniOp{};
    long long trenutniRezultat = 0;
    long long skupaj = 0;

    while(os >> noskipws >> o &&
          s1 >> noskipws >> c1 &&
          s2 >> noskipws >> c2 &&
          s3 >> noskipws >> c3 &&
          s4 >> noskipws >> c4){

        int stevilo = 0;
        bool imaStevilo = false;

        if(o != ' '){
            skupaj += trenutniRezultat;
            trenutniRezultat = 0;
            trenutniOp = o;
        }

        if(c1 != ' '){
            stevilo = c1 - '0';
            imaStevilo = true;
        }
        if(c2 != ' '){
            stevilo *= 10;
            stevilo += c2 - '0';
            imaStevilo = true;
        }
        if(c3 != ' '){
            stevilo *= 10;
            stevilo += c3 - '0';
            imaStevilo = true;
        }
        if(c4 != ' '){
            stevilo *= 10;
            stevilo += c4 - '0';
            imaStevilo = true;
        }

        if(imaStevilo){
            if(trenutniOp == '+'){
                trenutniRezultat += stevilo;
            }
            else if(trenutniOp == '*'){
                if(o == '*') trenutniRezultat = stevilo;
                else trenutniRezultat *= stevilo;
            }
        }
    }

    skupaj += trenutniRezultat;
    return skupaj;
}
