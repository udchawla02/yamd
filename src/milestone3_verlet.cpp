#include "verlet.h"

// Step 1: Update positions and half-step velocities for multiple atoms
void verlet_step1(Eigen::Array3Xd &positions, Eigen::Array3Xd &velocities,
                  const Eigen::Array3Xd &forces, double timestep) {
    // Number of atoms
    int nb_atoms = positions.cols();

    // Loop over atoms
    for (int i = 0; i < nb_atoms; ++i) {
        // Update positions
        positions(0, i) += velocities(0, i) * timestep + 0.5 * forces(0, i) * timestep * timestep;
        positions(1, i) += velocities(1, i) * timestep + 0.5 * forces(1, i) * timestep * timestep;
        positions(2, i) += velocities(2, i) * timestep + 0.5 * forces(2, i) * timestep * timestep;

        // Update velocities to half-step
        velocities(0, i) += 0.5 * forces(0, i) * timestep;
        velocities(1, i) += 0.5 * forces(1, i) * timestep;
        velocities(2, i) += 0.5 * forces(2, i) * timestep;
    }
}

// Step 2: Update velocities to full-step for multiple atoms
void verlet_step2(Eigen::Array3Xd &velocities, const Eigen::Array3Xd &forces, double timestep) {
    // Number of atoms
    int nb_atoms = velocities.cols();

    // Loop over atoms
    for (int i = 0; i < nb_atoms; ++i) {
        // Update velocities to full-step
        velocities(0, i) += 0.5 * forces(0, i) * timestep;
        velocities(1, i) += 0.5 * forces(1, i) * timestep;
        velocities(2, i) += 0.5 * forces(2, i) * timestep;
    }
}

