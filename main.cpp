#include <iostream>
#include <fstream>
#include <iomanip>
#include "generate.hpp"

#ifdef DECISION_STUMP_MODIFIED
#include "decision_stump_modified.hpp"
#else
#include "decision_stump.hpp"
#endif

using namespace std;

long double calc_E_out(const HYPOTHESIS h) {
    long double v = h.s * ((long double) 1.0 / 2 - GENERATE::FLIPPING_Y_CHANCE);
    long double u = (long double) 1.0 / 2 - v;
    return u + v * abs(h.theta);
}

const int INPUT_SIZE = 12, ITERATION_COUNT = 2000;

int main(int argc, char **argv) {
    ofstream output(argv[1]);
    for (int iteration = 1; iteration <= ITERATION_COUNT; iteration++) {
        vector<DATA> input(INPUT_SIZE);
        for (int i = 0; i < INPUT_SIZE; i++) input[i] = GENERATE::generate_data();
        HYPOTHESIS h = DECISION_STUMP::apply(input);
        long double E_out = calc_E_out(h);
        output << setprecision(10) << h.E_in << ' ' << E_out << '\n';
        #ifdef PRINT
        cout << "iteration #" << iteration << ':' << '\n';
        cout << "(E_in, E_out) = (" << h.E_in << ", " << E_out << ')' << '\n';
        #endif
    }
    return 0;
}