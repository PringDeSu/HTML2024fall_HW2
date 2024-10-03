#include <random>
#include <ctime>
#include "struct.hpp"
using namespace std;

namespace DECISION_STUMP {
    mt19937 rnd(time(NULL));
    HYPOTHESIS apply(vector<DATA> &data) {
        HYPOTHESIS h = HYPOTHESIS();
        h.s = (uniform_int_distribution(0, 1)(rnd) ? 1 : -1);
        h.theta = uniform_real_distribution<long double>(-1.0, 1.0)(rnd);
        // count mistake made by this hypothesis
        int mistake_count = 0;
        for (auto d : data) {
            int prediction = (((h.s == -1) ^ (h.theta < d.x)) ? 1 : -1);
            mistake_count += (prediction != d.y);
        }
        h.E_in = (long double) mistake_count / data.size();
        return h;
    }
}
