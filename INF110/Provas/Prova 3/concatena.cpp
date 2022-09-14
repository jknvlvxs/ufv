#include <iostream>
#include <stdio.h>
#include <stdlib.h>   

using namespace std;

char * concatena(char c1[],char c2[]){
    int i;

    for (i = 0; c1[i] != '\0'; i++);

    for (int j = 0; c2[j] != '\0'; j++) {
        c1[i] = c2[j];
        i++;
    }

    c1[i] = '\0';

    return c1;
}

int main() {
    int x = 20;
    char *a;
    char *b;
    a = (char*) malloc (x+1);

    b = (char*) malloc (x+1);
        
    cin >> a >> b;
    cout << concatena(a, b) << endl;

    free (a);
    free (b);

    return 0;
}