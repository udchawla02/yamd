#include "types.h"
#include "lj_direct_summation.h"
#include "xyz.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    // Construct the path to the lj54.xyz file
    fs::path current_path = fs::current_path();
    fs::path file_path = current_path / "milestones" / "04" / "lj54.xyz";

    std::string filename = file_path.string();

    std::cout << "Attempting to open file: " << filename << std::endl;

    // Check if the file exists
    if (!fs::exists(file_path)) {
        std::cerr << "Error: File does not exist: " << filename << std::endl;
        return 1;
    }

    std::ifstream file_check(filename);
    if (!file_check.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }
    file_check.close();

    try {
        auto [names, positions] = read_xyz(filename);

        Atoms atoms(positions.cols());
        atoms.positions = positions;
        atoms.velocities.setZero(); // Initialize velocities to zero

        double time_step = 0.001;
        double total_time = 1.0;
        size_t num_steps = static_cast<size_t>(total_time / time_step);

        LennardJones lj;

        for (size_t step = 0; step < num_steps; ++step) {
            double potential_energy = lj.compute(atoms);
            double kinetic_energy = 0.5 * atoms.velocities.squaredNorm();
            double total_energy = potential_energy + kinetic_energy;

            std::cout << "Step: " << step << ", Total Energy: " << total_energy << std::endl;

            // Verlet integration
            atoms.positions += atoms.velocities * time_step + 0.5 * atoms.forces * time_step * time_step;

            lj.compute(atoms);

            atoms.velocities += 0.5 * atoms.forces * time_step;

            // Output XYZ file every 100 steps
            if (step % 100 == 0) {
                std::string output_filename = "output_" + std::to_string(step) + ".xyz";
                write_xyz(output_filename, atoms);
            }
        }

        // Write final configuration
        write_xyz("final_output.xyz", atoms);

    } catch (const std::runtime_error& e) {
        std::cerr << "Runtime error: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
        return 1;
    }

    return 0;
}
