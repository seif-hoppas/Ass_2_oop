
#include <bits/stdc++.h>
#include "BigReal.h"
#define el endl

using namespace std;
void test1()
{
    BigReal num1("-1134.654");
    BigReal num2("6561.12");
    BigReal num100 = num1 + num2;


    BigReal num3("56465464.146");
    BigReal num4("-6546546.4");
    BigReal num101 = num3 + num4;

    BigReal num5("321321.15");
    BigReal num6("987645.56");
    BigReal num102 = num5 + num6;

    BigReal num7("-2163321.1546");
    BigReal num8("-5454541.345");
    BigReal num103 = num7 + num8;

    BigReal num9("11.9000000000000000000000000000000001");
    BigReal num10("2333333333339.1134322222222292");
    BigReal num104 = num9 + num10;





    cout << num100 << endl; // 5426.466
    cout << num101 << endl; //49918917.746
    cout << num102 << endl; //1308966.71
    cout << num103 << endl; // -7617862.4996
    cout << num104 << endl; //2,333,333,333,351.0134322222222292000000000000000001
    cout << endl;
}
void test2()
{
    cout << "----------------------------------------------------" << endl;
    BigReal num1("-1941.654");
    BigReal num2("-9431.15");
    BigReal num100 = num1 - num2;


    BigReal num3("2171.46");
    BigReal num4("3691.15461");
    BigReal num101 = num3 - num4;

    BigReal num5("-4.62");
    BigReal num6("3.885");
    BigReal num102 = num5 - num6;

    BigReal num7("1664546.624");
    BigReal num8("-3213212.354");
    BigReal num103 = num7 - num8;

    cout << num100 << endl; // 7489.496
    cout << num101 << endl; // -1519,69461
    cout << num102 << endl; // -8.505
    cout << num103 << endl; // 4877758.978
    cout << endl;
}
void test3()
{
    cout << "---------------------------------------------------------" << endl;
    BigReal n1("321321.163");
    BigReal n2("321.640");
    cout << (n1 > n2) << endl; // 1

    BigReal n3("123456.571");
    BigReal n4("923456.10");
    cout << (n3 > n4) << endl; // 0

    BigReal n5("-10000.2");
    BigReal n6("-1.835");
    cout << (n5 > n6) << endl; // 0
}


int main(){
    string s1,s2;
    cin>>s1>>s2;
    BigReal a(s1),b(s2);
    BigReal c=a+b;
    BigReal d=a-b;
    BigReal n1 ("11.9000000000000000000000000000000001");
    BigReal n2 ("2333333333339.1134322222222292");
    BigReal n3 = n1 + n2;
    cout << n3;
//    n3 = n3 + BigReal ("0,9");
    cout << c << endl;
    cout << d << endl;
    test1();
    test2();
    test3();
}



