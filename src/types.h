#ifndef TYPES_H
#define TYPES_H

#include <Eigen/Dense>

struct Atoms {
  Eigen::MatrixXd positions;
  Eigen::MatrixXd velocities;
  Eigen::MatrixXd forces;

  Atoms(int n) {
    positions.resize(3, n);
    velocities.resize(3, n);
    forces.resize(3, n);
  }
};

#endif // TYPES_H
