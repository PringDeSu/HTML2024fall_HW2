#pragma once

struct DATA {
    long double x;
    int y;
    DATA() : x(0), y(0) {}
    DATA(long double _x, int _y) : x(_x), y(_y) {}
};

struct HYPOTHESIS {
    int s;
    long double theta;
    long double E_in;
    HYPOTHESIS() : s(0), theta(0), E_in(0) {}
    HYPOTHESIS(int _s, long double _theta, long double _E_in) : s(_s), theta(_theta), E_in(_E_in) {}
};
