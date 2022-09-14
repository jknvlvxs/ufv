#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int main() {
    char linha1[1000];
    char linha2[1000];
    char linha1s[1000];
    char linha2s[1000];

    cin.getline(linha1, 1000);
    cin.getline(linha2, 1000);

    if(strcmp (linha1, linha2) == 0){
        cout << "Accepted" << endl;
    } else {
        int j = 0;
        for(int i = 0; i < strlen(linha1); i++) {
            if(linha1[i] != ' ') {
                linha1s[j] = linha1[i];
                j++;
            }
        }
        linha1s[j] = '\0';

        j = 0;
        for(int i = 0; i < strlen(linha2); i++) {
            if(linha2[i] != ' ') {
                linha2s[j] = linha2[i];
                j++;
            }
        }
        linha2s[j] = '\0';

        
        cout << (strcmp (linha1s, linha2s) == 0? "Presentation Error": "Wrong Answer") << endl;
    }

    return 0;
}