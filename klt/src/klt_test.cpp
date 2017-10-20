#include <opencv2/opencv.hpp>
#include <Eigen/Dense>

const std::string FOLDER("/home/stan/projects/robotics-playground/klt/test_imgs/");
const std::string TEST_IMG_1 = FOLDER + std::string("sea_floor_1.jpg");
const std::string TEST_IMG_2 = FOLDER + std::string("elephant.jpg");
const std::string TEST_IMG_3 = FOLDER + std::string("piggy.png");

int main () {

  cv::Mat img = cv::imread(TEST_IMG_1, 0);
  cv::Mat filtered;
  cv::Mat kernel;

  cv::Point anchor;
  double delta;
  int ddepth;
  int kernel_size;
  std::string window_name = "filter2d demo";

  int c;

  if (!img.data) {
    return -1;
  }

  cv::namedWindow(window_name, CV_WINDOW_AUTOSIZE);

  // set up filter
  anchor = cv::Point(-1, -1);
  delta = 0;
  ddepth = -1;

  double kernel_vals[2] = {0.0f, 1.0f};
  kernel = cv::Mat(1, 2 , CV_32F, &kernel_vals);
  kernel = cv::Mat(3, 1 , CV_32F, &kernel_vals);
  cv::filter2D(img, filtered, ddepth, kernel); // , anchor, delta, cv::BORDER_DEFAULT);
  // cv::Sobel(img, filtered, -1, 1, 0, 3, 1, 100);
  cv::imshow(window_name, filtered);
  cv::waitKey(0);

  return 0;
}




