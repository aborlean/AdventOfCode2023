#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("data1.in");
char s[1000];

bool check() {
    int i = 0, n = strlen(s), num;

    while(s[i] != ':')
        i++;
    i += 2;

    int red = 0, green = 0, blue = 0;
    while(i < n) {
        if(isnumber(s[i])) {
            num = 0;
            while(isnumber(s[i])) {
                num *= 10;
                num += s[i] - '0';
                i++;
            }
            i++;
            if(s[i] == 'r')
                red += num;
            else if(s[i] == 'g')
                green += num;
            else
                blue += num;
        }
        if(isalpha(s[i]))
            while(i < n && isalpha(s[i]))
                i++;
        if(s[i] == ',')
            i += 2;
        if(s[i] == ';') {
            if(red > 12 || green > 13 || blue > 14)
                return false;
            red = 0, green = 0, blue = 0;
            i += 2;
        }
    }
    if(red > 12 || green > 13 || blue > 14)
        return false;

    return true;
}

int main(void)
{
    int id = 0, sum = 0;

    while(!fin.eof()) {
        id++;

        fin.getline(s, 1000);

        if(check())
            sum += id;

    }

    cout << sum;
    
    return 0;
}