#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void main() {

    string path = "Resources/lambo.png";
    Mat img = imread(path, IMREAD_GRAYSCALE);
    Mat imgOut(img.rows, img.cols, CV_8UC1, Scalar(0));
    int n;
    cout << "Enter the n-bit of code to generate : ";
    cin >> n;
    int divideFactor = pow(2, (8 - n));
    cout << n << " bit version of the image";
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            img.at<uchar>(i, j) /= divideFactor;
        }
    }
    imshow("Grayscale image", img);
    waitKey(0);
}
