#include <string>
#include <iostream>
#include <math.h>
#include <thread>
#include <chrono>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

static void primeFactorization(int k, vector<int>& factors) {
    if (k == 1) {
        return;
    }

    if (k%2 == 0) {
        factors.push_back(2);
        primeFactorization(k/2, factors);
        return;
    }

    for (int i=3; i<=k; i+=2) {
        if (k%i == 0) {
            factors.push_back(i);
            primeFactorization(k/i, factors);
            break;
        }
    }
}

string commaSeperate(vector<int> v) {
 std::stringstream ss;
 for(size_t i = 0; i < v.size(); ++i)
 {
   if(i != 0)
     ss << ",";
   ss << v[i];
 }
 std::string s = ss.str();
 return s;
}


extern "C" char* factor(int k) {
    vector<int> factors;
    primeFactorization(k, factors);
    sort(factors.begin(), factors.end());
    const char* c = commaSeperate(factors).c_str();
    char* dest = (char*)malloc(strlen(c));
    strcpy(dest, c);
    return dest;
    //return (char*)commaSeperate(factors).c_str();
}


void printVector(vector<int> v) {
    for (std::vector<int>::iterator it = v.begin() ; it != v.end(); ++it) {
        std::cout << ' ' << *it;
    }
}

/*extern "C" int main(int    argc, char** argv) {
    vector<int> factors;
    for (int i=0; i<50; i++) {
        int num = pow(2,29) + i;
        cout << "Factoring " << floor(num) << endl;
        primeFactorization(num, factors);
        sort(factors.begin(), factors.end());
        printVector(factors);
        factors.clear();
        cout<<endl;

    }
}*/