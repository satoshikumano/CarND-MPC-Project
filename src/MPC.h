#ifndef MPC_H
#define MPC_H

#include <vector>
#include "Eigen-3.3/Eigen/Core"

using namespace std;

// TODO: Set the timestep length and duration
const size_t N = 5;
const double dt = 0.5;
const double mile_in_meter = 1609.344;
const double Lf = 2.67;
// Convert unit. (mile/h -> meter/s)
const double ref_v = 40 * mile_in_meter / 3600.;

class MPCResult {
  public:
    MPCResult();
    virtual ~MPCResult();
    vector<double> x;
    vector<double> y;
    double delta;
    double a;
};

class MPC {
  public:
    MPC();

    virtual ~MPC();

    // Solve the model given an initial state and polynomial coefficients.
    // Return the first actuatotions.
    void Solve(Eigen::VectorXd state, Eigen::VectorXd coeffs, MPCResult *result);

  private:
    long long duration_total = 0;
    size_t count = 0;
};


#endif /* MPC_H */
