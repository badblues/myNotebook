#include "base.h"

using namespace std;

int getChoice(int l_gap, int h_gap) {
    int num;
    num = getch() - '0';
    while((num < l_gap) || (num > h_gap)) {
        num = getch() - '0';
        cout << num << "\n";
    }
    return num;
}