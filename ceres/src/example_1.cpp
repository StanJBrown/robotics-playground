#include <ceres/ceres.h>
#include <glog/logging.h>


struct CostFunctor {
  template <typename T>
  bool operator() (const T* const x, T* residual) const {
    residual[0] = T(10.0) - x[0];
    return true;
  }
};



int main(int argc, char** argv) {

  google::initGoogleLogging(argv[0]);

  double init_x = -2;
  double x = init_x;

  // Set up the ceres problem
  Problem problem;

  // Set up only the cost function (or residual) using auto-differentiation to find J

  CostFunction* cost_function =
    new AutoDiffCostFunction<CostFunctor, 1, 1>(new CostFunctor);

  problem.AddResidualBlock(cost_function, NULL &x);

  // start solving
  Solver::Options options;
  options.linear_solver_type = ceres::DENSE_QR;
  options.minimizer_progress_to_stdout = true;
  Solver::Summary summary;
  Solve(options, &problem, &summary);

  std::cout << summary.BriefReport() << "\n";
  std::cout << "x: " << init_x
    << " -> " << x << "\n";
  return 0;

}



