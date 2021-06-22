#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<iostream>
#include<math.h>

using namespace cv;
using namespace std;

Mat bitplane(Mat& imgIn, int n) {
    int cols, rows, x, y;
    cols = imgIn.cols;
    rows = imgIn.rows;
    printf("%d %d \n", imgIn.rows, imgIn.cols);
    Mat out1(rows, cols, CV_8UC1);


    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {

            out1.at<uchar>(y, x) = (imgIn.at<uchar>(y, x) & uchar(pow(2, n))) ? uchar(255) : uchar(0);
        }
    }
    return out1;
}


int main() {
    int m, n, p;
    string path = "Resources/coin1.png";
    Mat img = imread(path, IMREAD_GRAYSCALE);
    Mat imgBit(img.rows, img.cols, CV_8UC1);
    Mat imgReconstruct(img.rows, img.cols, CV_8UC1);
    cout << "Enter the bit plane number : " << endl;
    cin >> p;
    imgBit = bitplane(img, p);
    cout << "Enter the bits for reconstruction" << endl;
    cin >> m >> n;
    imgReconstruct = bitplane(img, m) + bitplane(img, n);
    imshow("Original Image", img);
    imshow("Bitplane image", imgBit);
    imshow("Reconstructed image", imgReconstruct);
    waitKey(0);
    return 0;
}
