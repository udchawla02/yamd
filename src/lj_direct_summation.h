#ifndef LJ_H
#define LJ_H

#include "types.h"

class LennardJones {
public:
    LennardJones(double epsilon = 1.0, double sigma = 1.0)
        : epsilon(epsilon), sigma(sigma) {}

    double compute(Atoms &atoms);

private:
    double epsilon;
    double sigma;
};

#endif // LJ_H
