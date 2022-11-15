#include <iostream>
#include <deque>
#include <regex>
#include "BigDecimalIntClass.h"

using namespace std;

class BigReal {
private :
    string number;
    char sign = '+';
    bool is_valid(string number);
    BigDecimalInt Int;
    BigDecimalInt Frac;
public :
    void phrase();

    BigReal(double realNumber = 0.0);
    BigReal(string realNumber) {
        number = realNumber;
        set_number(number);
        phrase();
    }

    BigReal (BigDecimalInt bigInteger) {
        BigDecimalInt temp;
        temp = bigInteger;
    }

    BigReal(const BigReal &other) {
        number = other.number;
        sign = other.sign;
    }

    BigReal(BigReal &&other) = default; // Move constructor

    BigReal &operator=(BigReal &other); // Assignment operator

    BigReal &operator=(BigReal &&other) = default; // Move assignment

    BigReal operator+(BigReal &other);
    BigReal operator+(BigReal &&other);


    BigReal operator-(BigReal &other);
    BigReal operator-(BigReal &&other);


    bool operator<( BigReal &anotherReal);

    bool operator>( BigReal &anotherReal);

    bool operator==(BigReal anotherReal);

    int Size();

    int Sign();

    void set_number(string f_number);

    friend ostream &operator<<(ostream &out, BigReal num);

    friend istream &operator>>(istream &in, BigReal num);
};