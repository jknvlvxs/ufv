#include <iostream>

using namespace std;

int main() {
    bool a = false;
    bool b = true;
    bool c = true;
    bool f = (a&b&c) | (a&b&!c) | (a&!b&c)| (!a&b&c);
    cout << f << endl;
    return 0;
}