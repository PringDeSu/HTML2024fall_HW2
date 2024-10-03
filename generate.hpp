#include <random>
#include <ctime>
#include "struct.hpp"
using namespace std;

namespace GENERATE {
    mt19937 rnd(time(NULL));
    const long double RND_X_MIN = -1.0, RND_X_MAX = 1.0;
    const long double FLIPPING_Y_CHANCE = 0.15;

    uniform_real_distribution<long double> rnd_x(RND_X_MIN, RND_X_MAX);
    uniform_real_distribution<long double> rnd_y(0.0, 1.0);

    bool noise(const long double flip_chance) {
        long double val = rnd_y(rnd);
        return (val <= flip_chance);
    }

    DATA generate_data() {
        long double x = rnd_x(rnd);
        int y = (x > 0 ? 1 : -1);
        if (noise(FLIPPING_Y_CHANCE)) y *= -1;
        return DATA(x, y);
    }
}