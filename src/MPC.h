#ifndef MPC_H
#define MPC_H

#include <vector>
#include "Eigen-3.3/Eigen/Core"

using namespace std;

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
  void Solve(Eigen::VectorXd state, Eigen::VectorXd coeffs, MPCResult* result);
};


#endif /* MPC_H */
