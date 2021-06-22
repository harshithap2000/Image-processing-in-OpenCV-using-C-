#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<iostream>
#include<math.h>

using namespace cv;
using namespace std;

Mat zooming(Mat& imgIn) {
    Mat imgOut(imgIn.rows * 2, imgIn.cols * 2, CV_8UC1);
    for (int i = 0, x = 0; i < imgIn.rows; i++, x += 2) {
        for (int j = 0, y = 0; j < imgIn.cols; j++, y += 2) {
            imgOut.at<uchar>(x, y) = imgIn.at<uchar>(i, j);
            imgOut.at<uchar>(x + 1, y) = imgIn.at<uchar>(i, j);
            imgOut.at<uchar>(x, y + 1) = imgIn.at<uchar>(i, j);
            imgOut.at<uchar>(x + 1, y + 1) = imgIn.at<uchar>(i, j);
        }
    }
    return imgOut;
}

Mat shrink(Mat& imgIn) {
    Mat imgOut((int)imgIn.rows / 2, (int)imgIn.cols / 2, CV_8UC1);
    for (int i = 0, x = 0; i < imgIn.rows; i += 2, x++) {
        for (int j = 0, y = 0; j < imgIn.cols; j += 2, y++) {
            imgOut.at<uchar>(x, y) = imgIn.at<uchar>(i, j);
        }
    }
    return imgOut;
}

void main() {
    string path = "Resources/img.jpeg";
    Mat img = imread(path, IMREAD_GRAYSCALE);
    Mat imgZoom(img.rows * 2, img.cols * 2, CV_8UC1);
    Mat imgShrink((int)img.rows * 0.5, (int)img.cols * 0.5, CV_8UC1);
    imgZoom = zooming(img);
    imgShrink = shrink(img);
    imshow("Original Image", img);
    imshow("Zoomed image", imgZoom);
    imshow("Shrunk image", imgShrink);
    waitKey(0);
}
