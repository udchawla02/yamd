#include "lj_direct_summation.h"
#include <cmath>

double LennardJones::compute(Atoms &atoms) {
    double sigma6 = std::pow(sigma, 6);
    double sigma12 = std::pow(sigma, 12);

    int n = atoms.positions.cols();
    atoms.forces.setZero();
    double potential_energy = 0.0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            Eigen::Vector3d rij = atoms.positions.col(i) - atoms.positions.col(j);
            double r2 = rij.squaredNorm();
            double r6 = r2 * r2 * r2;
            double r12 = r6 * r6;

            double lj_potential = 4 * epsilon * (sigma12 / r12 - sigma6 / r6);
            potential_energy += lj_potential;

            Eigen::Vector3d force_ij = 24 * epsilon * (2 * sigma12 / r12 - sigma6 / r6) * rij / r2;
            atoms.forces.col(i) += force_ij;
            atoms.forces.col(j) -= force_ij;
        }
    }

    return potential_energy;
}
