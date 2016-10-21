// Copyright JETSCAPE Collaboration @ 2016
// This is a general basic class for hydrodynamics
// This is written by Longgang Pang and Chun Shen

#include <iostream>
#include "./fluid_dynamics.h"

using namespace std;

real FluidDynamics::get_energy_density(real time, real x, real y, real z) {
    // this function returns the energy density [GeV] at a space time point
    // (time, x, y, z)
    FluidCellInfo *fluid_cell_ptr = new FluidCellInfo;
    get_hydro_info(time, x, y, z, fluid_cell_ptr);
    real energy_density = fluid_cell_ptr->energy_density;
    delete fluid_cell_ptr;
    return(energy_density);
}

real FluidDynamics::get_entropy_density(real time, real x, real y, real z) {
    // this function returns the entropy density [GeV] at a space time point
    // (time, x, y, z)
    FluidCellInfo *fluid_cell_ptr = new FluidCellInfo;
    get_hydro_info(time, x, y, z, fluid_cell_ptr);
    real entropy_density = fluid_cell_ptr->entropy_density;
    delete fluid_cell_ptr;
    return(entropy_density);
}

real FluidDynamics::get_temperature(real time, real x, real y, real z) {
    // this function returns the temperature [GeV] at a space time point
    // (time, x, y, z)
    FluidCellInfo *fluid_cell_ptr = new FluidCellInfo;
    get_hydro_info(time, x, y, z, fluid_cell_ptr);
    real temperature = fluid_cell_ptr->temperature;
    delete fluid_cell_ptr;
    return(temperature);
}

real FluidDynamics::get_qgp_fraction(real time, real x, real y, real z) {
    // this function returns the QGP fraction at a space time point
    // (time, x, y, z)
    FluidCellInfo *fluid_cell_ptr = new FluidCellInfo;
    get_hydro_info(time, x, y, z, fluid_cell_ptr);
    real qgp_fraction = fluid_cell_ptr->qgp_fraction;
    delete fluid_cell_ptr;
    return(qgp_fraction);
}

void FluidDynamics::print_fluid_cell_information(
                                        FluidCellInfo* fluid_cell_info_ptr) {
    // this function print out the information of the fluid cell to the screen
    cout << "=======================================================" << endl;
    cout << "print out cell information:" << endl;
    cout << "=======================================================" << endl;
    cout << "energy density = " << fluid_cell_info_ptr->energy_density
         << " GeV/fm^3." << endl;
    cout << "entropy density = " << fluid_cell_info_ptr->entropy_density
         << " 1/fm^3." << endl;
    cout << "temperature = " << fluid_cell_info_ptr->temperature
         << " GeV." << endl;
    cout << "pressure = " << fluid_cell_info_ptr->pressure
         << " GeV/fm^3." << endl;
    cout << "QGP_fraction = " << fluid_cell_info_ptr->qgp_fraction
         << endl;
    cout << "mu_B = " << fluid_cell_info_ptr->mu_B << " GeV." << endl;
    cout << "mu_S = " << fluid_cell_info_ptr->mu_S << " GeV." << endl;
    cout << "mu_C = " << fluid_cell_info_ptr->mu_C << " GeV." << endl;
    cout << "vx = " << fluid_cell_info_ptr->vx << endl;
    cout << "vy = " << fluid_cell_info_ptr->vy << endl;
    cout << "vz = " << fluid_cell_info_ptr->vz << endl;
    cout << "shear viscous pi^{munu} (GeV/fm^3): " << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << fluid_cell_info_ptr->pi[i][j] << "   ";
        }
        cout << endl;
    }
    cout << "bulk_Pi = " << fluid_cell_info_ptr->bulk_Pi << " GeV/fm^3"
         << endl;
    cout << "=======================================================" << endl;
}
