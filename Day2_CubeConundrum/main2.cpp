#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("data2.in");
char s[1000];

long long power() {
    int i = 0, n = strlen(s), num;

    while(s[i] != ':')
        i++;
    i += 2;

    long long red = 0, green = 0, blue = 0, min_red = 0, min_green = 0, min_blue = 0;
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
            min_red = max(min_red, red);
            min_green = max(min_green, green);
            min_blue = max(min_blue, blue);

            red = 0, green = 0, blue = 0;
            i += 2;
        }
    }
    min_red = max(min_red, red);
    min_green = max(min_green, green);
    min_blue = max(min_blue, blue);

    long long power = 1LL * min_red * min_green * min_blue;

    return power;
}

int main(void)
{
    long long p = 0, sum = 0;

    while(!fin.eof()) {
        fin.getline(s, 1000);

        long long p = power();
        sum += p;
    }

    cout << sum;

    return 0;
}