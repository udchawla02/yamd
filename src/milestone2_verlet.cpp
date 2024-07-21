#include "verlet.h"

    // Step 1: Update positions and half-step velocities
    void verlet_step1(double &x, double &y, double &z, double &vx, double &vy, double &vz,
                      double fx, double fy, double fz, double timestep) {
    // Update positions
    x += vx * timestep + 0.5 * fx * timestep * timestep;
    y += vy * timestep + 0.5 * fy * timestep * timestep;
    z += vz * timestep + 0.5 * fz * timestep * timestep;

    // Update velocities to half-step
    vx += 0.5 * fx * timestep;
    vy += 0.5 * fy * timestep;
    vz += 0.5 * fz * timestep;
}

// Step 2: Update velocities to full-step
void verlet_step2(double &vx, double &vy, double &vz, double fx, double fy, double fz,
                  double timestep) {
    // Update velocities to full-step
    vx += 0.5 * fx * timestep;
    vy += 0.5 * fy * timestep;
    vz += 0.5 * fz * timestep;
}