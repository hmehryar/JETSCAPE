/*******************************************************************************
 * Copyright (c) The JETSCAPE Collaboration, 2018
 *
 * Modular, task-based framework for simulating all aspects of heavy-ion collisions
 * 
 * For the list of contributors see AUTHORS.
 *
 * Report issues at https://github.com/JETSCAPE/JETSCAPE/issues
 *
 * or via email to bugs.jetscape@gmail.com
 *
 * Distributed under the GNU General Public License 3.0 (GPLv3 or later).
 * See COPYING for details.
 ******************************************************************************/
// This is a general basic class for a hyper-surface finder

#ifndef SURFACEFINDER_H_
#define SURFACEFINDER_H_

#include <vector>

#include "RealType.h"
#include "SurfaceCellInfo.h"
#include "FluidEvolutionHistory.h"

namespace Jetscape {

class SurfaceFinder {
private:
  Jetscape::real T_cut;
  const EvolutionHistory &bulk_info;
  bool boost_invariant;

  std::vector<SurfaceCellInfo> surface_cell_list;

public:
  SurfaceFinder(const Jetscape::real T_in, const EvolutionHistory &bulk_data);
  ~SurfaceFinder();

  void Find_full_hypersurface();

  int get_number_of_surface_cells() const { return (surface_cell_list.size()); }
  SurfaceCellInfo get_surface_cell_with_idx(int idx) const {
    return (surface_cell_list[idx]);
  }
  std::vector<SurfaceCellInfo> get_surface_cells_vector() const {
    return (surface_cell_list);
  }

  bool check_intersect_3D(Jetscape::real tau, Jetscape::real x,
                          Jetscape::real y, Jetscape::real dt,
                          Jetscape::real dx, Jetscape::real dy, double ***cube);
  void Find_full_hypersurface_3D();

  bool check_intersect_4D(Jetscape::real tau, Jetscape::real x,
                          Jetscape::real y, Jetscape::real eta,
                          Jetscape::real dt, Jetscape::real dx,
                          Jetscape::real dy, Jetscape::real deta,
                          double ****cube);
  void Find_full_hypersurface_4D();

/**
 * @brief Prepares a surface cell from given parameters and fluid cell information.
 *
 * This function initializes a `SurfaceCellInfo` structure using the provided
 * parameters and fluid cell data. It computes the four-velocity components 
 * and copies the stress-energy tensor components.
 *
 * @param tau The proper time.
 * @param x The x-coordinate.
 * @param y The y-coordinate.
 * @param eta The space-time rapidity.
 * @param da0 The 0th component of the surface normal vector.
 * @param da1 The 1st component of the surface normal vector.
 * @param da2 The 2nd component of the surface normal vector.
 * @param da3 The 3rd component of the surface normal vector.
 * @param fluid_cell The fluid cell information.
 * @return A populated `SurfaceCellInfo` structure.
 */
  SurfaceCellInfo PrepareASurfaceCell(Jetscape::real tau, Jetscape::real x,
                                      Jetscape::real y, Jetscape::real eta,
                                      Jetscape::real da0, Jetscape::real da1,
                                      Jetscape::real da2, Jetscape::real da3,
                                      const FluidCellInfo fluid_cell);
};

} // namespace Jetscape

#endif // SURFACEFINDER_H_
