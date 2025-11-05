
#ifndef MEDIANA_H
#define MEDIANA_H

#include <vector>
#include <algorithm>

inline double mediana(std::vector<int> v) {
    if (v.empty()) return 0.0;
    std::sort(v.begin(), v.end());
    const size_t n = v.size();
    if (n % 2 == 0) return (v[n/2 - 1] + v[n/2]) / 2.0;
    return v[n/2];
}
inline double vidurkis(const std::vector<int>& v) {
    if (v.empty()) return 0.0;
    long long s = 0;
    for (int x : v) s += x;
    return static_cast<double>(s) / v.size();
}

#endif
