#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void main() {

    string path = "Resources/image.png";
    Mat img = imread(path, IMREAD_GRAYSCALE);
    // Declare the variables we are going to use
    Mat src, src_gray, dst;
    int kernel_size = 3;
    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;
    const char* window_name = "Laplace Demo";
  
    GaussianBlur(img,img, Size(3, 3), 0, 0, BORDER_DEFAULT);
    Mat abs_dst;
    Laplacian(img, dst, ddepth, kernel_size, scale, delta, BORDER_DEFAULT);
    convertScaleAbs(dst, abs_dst);
    imshow("Original Image", img);
    imshow(window_name, abs_dst);
    waitKey(0);

}
