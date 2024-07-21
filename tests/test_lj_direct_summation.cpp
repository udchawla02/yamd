#include <gtest/gtest.h>
#include "lj_direct_summation.h"
#include "types.h"
#include <vector>

TEST(LennardJonesTest, ForceCalculation) {
    LennardJones lj(1.0, 1.0);

    Atoms atoms(2); // Initialize Atoms structure with 2 atoms

    atoms.positions(0, 0) = 0.0;
    atoms.positions(1, 0) = 0.0;
    atoms.positions(2, 0) = 0.0;

    atoms.positions(0, 1) = 1.0;
    atoms.positions(1, 1) = 0.0;
    atoms.positions(2, 1) = 0.0;

    lj.compute(atoms);

    EXPECT_NEAR(atoms.forces(0, 0), -24.0, 1e-5);
    EXPECT_NEAR(atoms.forces(0, 1), 0.0, 1e-5);
    EXPECT_NEAR(atoms.forces(0, 2), 0.0, 1e-5);
    EXPECT_NEAR(atoms.forces(1, 0), 24.0, 1e-5);
    EXPECT_NEAR(atoms.forces(1, 1), 0.0, 1e-5);
    EXPECT_NEAR(atoms.forces(1, 2), 0.0, 1e-5);
}
