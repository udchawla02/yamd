#include <gtest/gtest.h>
#include "../src/verlet.h"  // Adjust the include path if necessary

// Test case for the Velocity-Verlet integration
TEST(VerletTest, ConstantForce) {
    double x = 0.0, y = 0.0, z = 0.0;
    double vx = 0.0, vy = 0.0, vz = 0.0;
    double fx = 1.0, fy = 0.0, fz = 0.0;  // Constant force in the x direction
    double timestep = 0.01;
    int nb_steps = 1000;

    for (int i = 0; i < nb_steps; ++i) {
        verlet_step1(x, y, z, vx, vy, vz, fx, fy, fz, timestep);
        // In a real simulation, you would compute new forces here
        verlet_step2(vx, vy, vz, fx, fy, fz, timestep);
    }

    // Analytical solution for constant acceleration
    double expected_x = 0.5 * fx * timestep * timestep * nb_steps * nb_steps;
    double expected_vx = fx * timestep * nb_steps;

    EXPECT_NEAR(x, expected_x, 1e-6);
    EXPECT_NEAR(vx, expected_vx, 1e-6);
}