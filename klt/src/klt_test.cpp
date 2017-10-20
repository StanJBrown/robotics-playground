#include <opencv2/opencv.hpp>
#include <Eigen/Dense>

class Kernel {
public:
  Kernel(
      Eigen::MatrixXd k) :
      _k(k) {}

  const Eigen::MatrixXd& operator * (Eigen::MatrixXd &mtx);
  const Eigen::MatrixXd& constructKmtx();
private:
    Eigen::MatrixXd _k;
};

const Eigen::MatrixXd& Kernel::constructKmtx(int rows, int cols) {


}

const Eigen::MatrixXd& Kernel::operator * (Eigen::MatrixXd &mtx) {
  int mtx_rows = mtx.rows();
  int mtx_cols = mtx.cols();

  int k_rows = _k.rows();
  int k_cols = _k.cols();

  // unroll the input matrix;

  Eigen::MatrixXd temp(mtx_rows + 2 * k_rows, mtx_cols + 2 * k_cols);
  temp.block(k_rows, k_cols, mtx_rows, mtx_cols) = mtx;

  Eigen::Map<Eigen::MatrixXd> unrolled(
      temp.data(),
      (mtx_rows + 2*k_rows) * (mtx_cols + 2*k_cols),
      1
  );

  Eigen::MatrixXd k_mtx =
    constructKmtx(mtx_rows, mtx_cols);

  // assume edges are zero
}


int main () {

  Eigen::MatrixXd kern(3, 3);
  kern << 1, 1, 1,
          1, 1, 1,
          1, 1, 1;

  Kernel test_kern(kern);

  Eigen::MatrixXd test_mtx;
  test_mtx = Eigen::MatrixXd::Identity(10, 10);

  test_kern * test_mtx;
  return 0;
}




