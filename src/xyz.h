#ifndef XYZ_H
#define XYZ_H

#include "types.h"
#include <string>
#include <utility>

std::pair<std::vector<std::string>, Eigen::MatrixXd> read_xyz(const std::string &filename);
void write_xyz(const std::string &filename, const Atoms &atoms);

#endif // XYZ_H
