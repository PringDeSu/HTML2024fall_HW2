#include <vector>
#include <algorithm>
#include "struct.hpp"
using namespace std;

namespace DECISION_STUMP {
    HYPOTHESIS apply(vector<DATA> &data) {
        int n = data.size();
        sort(data.begin(), data.end(), [](DATA a, DATA b) -> bool {
            return a.x < b.x;
        });

        // using prefix/suffix sum to calculate mistakes made by each hypothesis
        vector<int> prefix_positive_count(n, 0), suffix_positive_count(n, 0);
        for (int i = 1; i < n; i++) {
            prefix_positive_count[i] = prefix_positive_count[i - 1] + (data[i].y == 1);
        }
        suffix_positive_count[n - 1] = (data[n - 1].y == 1);
        for (int i = n - 2; i >= 0; i--) {
            suffix_positive_count[i] = suffix_positive_count[i + 1] + (data[i].y == 1);
        }

        // get all hypothesis with E_in, put them into H
        vector<HYPOTHESIS> H;
        H.push_back(HYPOTHESIS(1, -1.0, (long double) (n - suffix_positive_count[0]) / n));
        for (int i = 1; i < n; i++) {
            H.push_back(HYPOTHESIS(1, (data[i - 1].x + data[i].x) / 2, 
                                (long double) (prefix_positive_count[i] + (n - i) - suffix_positive_count[i]) / n
                                ));
        }
        H.push_back(HYPOTHESIS(-1, -1.0, (long double) (suffix_positive_count[0]) / n));
        for (int i = 1; i < n; i++) {
            H.push_back(HYPOTHESIS(-1, (data[i - 1].x + data[i].x) / 2,
                                (long double) (i - prefix_positive_count[i] + suffix_positive_count[i]) / n
                                ));
        }

        // remove duplicate in H
        sort(H.begin(), H.end(), [](HYPOTHESIS a, HYPOTHESIS b) -> bool {
            return (a.s == b.s ? a.theta < b.theta : a.s < b.s);
        });
        H.erase(unique(H.begin(), H.end(), [](HYPOTHESIS a, HYPOTHESIS b) -> bool {
            return (a.s == b.s && a.theta == b.theta);
        }), H.end());

        // get the hypothesis with the smallest E_in
        return *min_element(H.begin(), H.end(), [](HYPOTHESIS a, HYPOTHESIS b) -> bool {
            return (a.E_in == b.E_in ? a.s * a.theta < b.s * b.theta : a.E_in < b.E_in);
        });
    }
}