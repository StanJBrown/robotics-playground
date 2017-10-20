#include <ceres/ceres.h>
#include <glog/logging.h>


struct CostFunctor {
  template <typename T>
  bool operator() (const T* const x, T* residual) const {
    residual[0] = T(10.0) - pow(x[0], 5);
    return true;
  }
};



int main(int argc, char** argv) {

  // google::initGoogleLogging(argv[0]);

  double init_x = 10;
  double x = init_x;

  // Set up the ceres problem
  ceres::Problem problem;

  // Set up only the cost function (or residual) using auto-differentiation to find J
  ceres::CostFunction* cost_function =
    new ceres::AutoDiffCostFunction<CostFunctor, 1, 1>(new CostFunctor);

  problem.AddResidualBlock(cost_function, NULL, &x);

  // start solving
  ceres::Solver::Options options;
  options.linear_solver_type = ceres::DENSE_QR;
  options.minimizer_progress_to_stdout = true;
  ceres::Solver::Summary summary;
  ceres::Solve(options, &problem, &summary);

  std::cout << summary.BriefReport() << "\n";
  std::cout << "x: " << init_x
    << " -> " << x << "\n";
  return 0;
}
