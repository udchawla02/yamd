#include <gtest/gtest.h>
#include <Eigen/Dense> // Include Eigen headers
#include "../src/verlet.h"  // Adjust the include path if necessary

using namespace Eigen; // Using Eigen namespace for convenience

// Test case for the Velocity-Verlet integration
TEST(VerletTest, ConstantForce) {
    // Initialize Eigen arrays for positions, velocities, and forces
    Array3Xd positions(3, 1);
    Array3Xd velocities(3, 1);
    Array3Xd forces(3, 1);

    // Set initial position, velocity, and constant force in the x-direction
    positions.col(0) << 0.0, 0.0, 0.0;
    velocities.col(0) << 0.0, 0.0, 0.0;
    forces.col(0) << 1.0, 0.0, 0.0;

    double timestep = 0.01;
    int nb_steps = 1000;

    for (int i = 0; i < nb_steps; ++i) {
        verlet_step1(positions, velocities, forces, timestep);
        // In a real simulation, you would compute new forces here
        verlet_step2(velocities, forces, timestep);
    }

    // Analytical solution for constant acceleration
    double expected_x = 0.5 * forces(0, 0) * timestep * timestep * nb_steps * nb_steps;
    double expected_vx = forces(0, 0) * timestep * nb_steps;

    // Check if the final positions and velocities match the expected values
    EXPECT_NEAR(positions(0, 0), expected_x, 1e-6);
    EXPECT_NEAR(velocities(0, 0), expected_vx, 1e-6);
}

