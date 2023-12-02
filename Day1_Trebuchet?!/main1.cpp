#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("data1.in");

int main(void)
{
    int sum = 0;
    string s;

    while(fin >> s) {
        int digit1, digit2;

        for(int i = 0; i < s.length(); i++)
            if(isdigit(s[i])) {
                digit1 = s[i] - '0';
                break;
            }

        for(int i = s.length() - 1; i >= 0; i--)
            if(isdigit(s[i])) {
                digit2 = s[i] - '0';
                break;
            }

        sum += digit1 * 10 + digit2;
    }

    cout << sum;

    return 0;
}