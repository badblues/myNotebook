#include "base.h"

using namespace std;

int getChoice(int l_gap, int h_gap) {
    int num;
    while((!(cin >> num)) || (num < l_gap) || (num > h_gap)) {}
    return num;
}