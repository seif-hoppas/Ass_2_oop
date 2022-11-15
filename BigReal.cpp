#include <iostream>
#include <deque>
#include <regex>
#include "BigReal.h"
#include <math.h>

using namespace std;
void makeEqualAtFront(string& A,string & B)
{
    int n = A.size();
    int m = B.size();
    int diff = abs(n - m);

    if (n < m) {
        for (int i = 0; i < diff; i++) {
            A.insert(A.begin(), '0');
        }
    }
    else {
        for (int i = 0; i < diff; i++) {
            B.insert(B.begin(), '0');
        }
    }
}

// Function to make Integral part
// with equal digits
void makeEqualAtback(string& A,string& B)
{
    int n = A.size();
    int m = B.size();
    int diff = abs(n - m);

    if (n < m) {
        for (int i = 0; i < diff; i++) {
            A.push_back('0');
        }
    }
    else {
        for (int i = 0; i < diff; i++) {
            B.push_back('0');
        }
    }

}

void BigReal :: set_number(string f_number)
{
    for(int i = 0 ; i < f_number.size() ; i++)
    {
        if(f_number[i] == '.' && i==f_number.size()-1)
        {
           f_number+='0';
        }else if(f_number[i] == '.' && i==0)
        {
            f_number+='0';
        }
    }
    bool validNumber = is_valid(f_number);
    if(validNumber)
    {
        number = f_number;
        if(number[0] == '+')
        {
            number.erase(0,1);
            sign = '+';
        }
        else if (number[0] == '-')
        {
            number.erase(0,1);
            sign = '-';
        }
    }
    else
    {
        cout << "Invalid" << "\n";
        exit(1);
    }
}

bool BigReal :: is_valid(string number)
{
    regex is_valid("[-+]?[0-9]+[.][0-9]+");
    return regex_match(number, is_valid);
}

BigReal& BigReal::operator= (BigReal& other)
{
    sign = other.sign;
    number = other.number;
    return *this;
}

bool BigReal::operator==(BigReal anotherReal){
    return (number == anotherReal.number);
}

bool BigReal:: operator< ( BigReal &anotherReal){//lesa na2s el size w frac w el int
    return !(*this > anotherReal);
}

bool BigReal:: operator> ( BigReal &anotherReal){
    if (sign == '-' && anotherReal.sign == '+')
        return false;
    else if (sign == '+' && anotherReal.sign == '-')
        return true;
    else if (sign == '-' && anotherReal.sign == '-'){
        if (Int < anotherReal.Int)
            return true;
        else if (Int > anotherReal.Int)
            return false;
        else if (Int == anotherReal.Int){
            if (Int < anotherReal.Int)
                return false;
            else if (Int > anotherReal.Int)
                return true;
            else if (Int == anotherReal.Int) {//here append "0" to smaller Frac to make them equal
                if (Frac.size() < anotherReal.Frac.size()) {
                    string temp = Frac.getNumber();
                    for (int i = 0; i < anotherReal.Frac.size() - Frac.size(); i++) {
                        temp += "0";
                    }
                    Frac.setNumber(temp);
                    if (Frac < anotherReal.Frac)
                        return true;
                    else if (Frac > anotherReal.Frac)
                        return false;
                    else
                        return true;
                }
                else if (Frac.size() > anotherReal.Frac.size()) {
                    string temp = anotherReal.Frac.getNumber();
                    for (int i = 0; i < Frac.size() - anotherReal.Frac.size(); i++) {
                        temp += "0";
                    }
                    anotherReal.Frac.setNumber(temp);
                    if (Frac < anotherReal.Frac)
                        return true;
                    else if (Frac > anotherReal.Frac)
                        return false;
                    else
                        return true;
                }
                else if (Frac.size() == anotherReal.Frac.size()) {
                    if (Frac < anotherReal.Frac)
                        return true;
                    else if (Frac > anotherReal.Frac)
                        return false;
                    else
                        return true;
                }
            }
        }
    }
    else if (sign == '+' && anotherReal.sign == '+'){
        if (Int < anotherReal.Int)
            return false;
        else if (Int > anotherReal.Int)
            return true;
        else if (Int == anotherReal.Int) {//here append "0" to smaller Frac to make them equal
            if (Frac.size() < anotherReal.Frac.size()) {
                string temp = Frac.getNumber();
                for (int i = 0; i < anotherReal.Frac.size() - Frac.size(); i++) {
                    temp += "0";
                }
                Frac.setNumber(temp);
                if (Frac < anotherReal.Frac)
                    return false;
                else if (Frac > anotherReal.Frac)
                    return true;
                else
                    return false;
            }
            else if (Frac.size() > anotherReal.Frac.size()) {
                string temp = anotherReal.Frac.getNumber();
                for (int i = 0; i < Frac.size() - anotherReal.Frac.size(); i++) {
                    temp += "0";
                }
                anotherReal.Frac.setNumber(temp);
                if (Frac < anotherReal.Frac)
                    return false;
                else if (Frac > anotherReal.Frac)
                    return true;
                else
                    return false;
            }
            else if (Frac.size() == anotherReal.Frac.size()) {
                if (Frac < anotherReal.Frac)
                    return false;
                else if (Frac > anotherReal.Frac)
                    return true;
                else
                    return false;
            }
        }

    }

}

int BigReal :: Size(){//not count the point
    return Frac.size()+Int.size();
}

int BigReal ::Sign(){
    if (sign == '+')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

ostream& operator << (ostream& out, BigReal num){
    if(num.sign == '+')
    {
        out << num.number ;
    }
    else
    {
        if(num.number == "0")
        {
            out << num.number ;
        }
        else
        {
            out << num.sign << num.number ;
        }
    }
    return out;
}

istream& operator >> (istream& in, BigReal num){
    in >> num.number;
    num.set_number(num.number);
    return in;
}

void BigReal :: phrase()
{

    string Int1,Frac1;
    int i =0;
    for (i = number.length() - 1; i > -1; i--) {

        // If decimal occurs break
        if (number[i] == '.') {
            break;
        }
        Frac1.push_back(number[i]);
    }

    i--;
    for (; i > -1; i--) {
        Int1.push_back(number[i]);
    }
    if (Frac1.empty())
        Frac1 = "0";
    if (Int1.empty())
        Int1 = "0";
    reverse(Frac1.begin(), Frac1.end()), reverse(Int1.begin(), Int1.end());

    Int = Int1;
    Frac = Frac1;

}
BigReal BigReal :: operator+ (BigReal& other){
    if(sign == other.sign){
        int i=0;
        string Int1=Int.getNumber(), Int2=other.Int.getNumber(), Frac1=Frac.getNumber(), Frac2=other.Frac.getNumber();
        makeEqualAtFront(Int1, Int2);
        makeEqualAtback(Frac1, Frac2);
        int n = Frac1.size();
        int m = Frac2.size();
        i = 0;
        int carry = 0;

        reverse(Frac1.begin(), Frac1.end()), reverse(Frac2.begin(), Frac2.end());
        while (i < n && i < m) {
            int sum = (Frac1[i]-'0')
                      + (Frac2[i]-'0')
                      + carry;

            Frac1[i] = to_string(sum % 10)[0];
            carry = sum / 10;
            i++;
        }
        reverse(Frac1.begin(), Frac1.end()), reverse(Frac2.begin(), Frac2.end());
        BigDecimalInt first_int(Int1),second_int(Int2),first_frac(Frac1),second_frac(Frac2);

        if (carry != 0){
            first_int = first_int + BigDecimalInt(to_string(carry));
        }

        first_int = first_int + second_int;

        string result = first_int.getNumber()+ "." + Frac1;
        BigReal result1(result);
        if(sign=='+' && other.sign=='+')
        {
            result1.sign='+';
        }
        else result1.sign='-';
        return result1;
    }else{
        BigReal result(*this);
        if(sign=='-')
        {
            sign = '+';
            if(*this > other)
            {
                result = *this - other;
                result.sign = '-';
            }
            else
            {
                result = other - *this;
                result.sign = '+';
            }
            sign = '-';
        }
        else{
            other.sign = '+';
            if(*this > other)
            {
                result = *this - other;
                result.sign = '+';
            }
            else
            {
                result = other - *this;
                result.sign = '-';
            }
            other.sign = '-';
        }
        return result;

    }
}
BigReal BigReal:: operator- (BigReal& other){
    if(sign ==other.sign){
        string Frac1=Frac.getNumber(),Frac2=other.Frac.getNumber();
        makeEqualAtback(Frac1,Frac2);
        BigDecimalInt first_int(Int),second_int(other.Int),first_frac(Frac1),second_frac(Frac2);
        char sgn='+';
        if(first_int>second_int && first_frac > second_frac){
            first_int = first_int - second_int;
            first_frac = first_frac - second_frac;

        }else if(first_int > second_int && second_frac > first_frac){
            first_int = first_int - second_int;
            first_int=first_int - BigDecimalInt("1");
            first_frac = second_frac - first_frac;
            int size=first_frac.getNumber().size();
            first_frac = first_frac - BigDecimalInt(to_string(int(pow(10,size))));
            

        }else if( second_int > first_int && second_frac < first_frac){
            sgn='-';
            first_int = second_int - first_int;
            first_int=first_int - BigDecimalInt("1");
            first_frac = first_frac - second_frac;
            int size=first_frac.getNumber().size();
            first_frac = first_frac - BigDecimalInt(to_string(int(pow(10,size))));
        }else{
            sgn='-';
            first_int = second_int - first_int;
            first_frac = second_frac - first_frac;

        }
        string result = first_int.getNumber()+ "." + first_frac.getNumber();
        BigReal sub(result);
        sub.sign=sgn;
        return sub;
    }else{
        BigReal result(*this);
        if(sign=='-')
        {
            sign = '+';
            result = *this + other;
            sign = '-';
            result.sign = '-';
        }
        else{
            other.sign = '+';
            result = *this + other;
            other.sign = '-';
            result.sign = '+';
        }
        return result;
    }

}