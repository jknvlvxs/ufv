#include <iostream>
#include <iomanip>

using namespace std;

void convhoras(int seg, int &h, int &m, int &s){
    while (seg > 0){
        if(seg / 3600 >= 1){
            h++;
            seg -= 3600;
        } else if (seg / 60 >= 1){
            m++;
            seg -= 60;
        } else {
            s = seg;
            seg = 0;
        }
    }
}

int main() {
    int seg, h=0, m=0, s=0;
    cin >> seg;
    convhoras(seg, h, m, s);
    cout << setfill('0') << setw(2) << h << ":" << setfill('0') << setw(2) << m << ":" << setfill('0') << setw(2) << s << endl;

    return 0;
}