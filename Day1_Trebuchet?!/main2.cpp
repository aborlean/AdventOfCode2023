#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("data2.in");
string s;

void check(int i, bool &found, int &val) {
    int diff = s.length() - i;
    if(diff >= 5) {
        if(s.substr(i, 5) == "seven") {
            found = true;
            val = 7;
            return;
        }
        if(s.substr(i, 5) == "eight") {
            found = true;
            val = 8;
            return;
        }
        if(s.substr(i, 5) == "three") {
            found = true;
            val = 3;
            return;
        }
    }
    if(diff >= 4) {
        if(s.substr(i, 4) == "four") {
            found = true;
            val = 4;
            return;
        }
        if(s.substr(i, 4) == "five") {
            found = true;
            val = 5;
            return;
        }
        if(s.substr(i, 4) == "nine") {
            found = true;
            val = 9;
            return;
        }
    }
    if(diff >= 3) {
        if(s.substr(i, 3) == "one") {
            found = true;
            val = 1;
            return;
        }
        if(s.substr(i, 3) == "two") {
            found = true;
            val = 2;
            return;
        }
        if(s.substr(i, 3) == "six") {
            found = true;
            val = 6;
            return;
        }
    }
}

int main(void)
{
    int sum = 0;

    while(fin >> s) {
        int digit1, digit2;
        for(int i = 0; i < s.length(); i++) {
            if(isdigit(s[i])) {
                digit1 = s[i] - '0';
                break;
            }

            int val;
            bool found = false;
            check(i, found, val);

            if(found) {
                digit1 = val;
                break;
            }
        }

        for(int i = 0; i < s.length(); i++) {
            if(isdigit(s[i]))
                digit2 = s[i] - '0';

            int val;
            bool found = false;
            check(i, found, val);

            if(found)
                digit2 = val;
        }
        sum += digit1 * 10 + digit2;
    }

    cout << sum;

    return 0;
}