#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<iostream>
#include<math.h>

using namespace cv;
using namespace std;


using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    
    Mat image = imread("Resources/test.png");

    cvtColor(image, image, COLOR_BGR2GRAY);

    Mat hist_equalized_image;
    equalizeHist(image, hist_equalized_image);
    String windowNameOfOriginalImage = "Original Image";
    String windowNameOfHistogramEqualized = "Histogram Equalized Image";
    namedWindow(windowNameOfOriginalImage, WINDOW_NORMAL);
    namedWindow(windowNameOfHistogramEqualized, WINDOW_NORMAL);
    imshow(windowNameOfOriginalImage, image);
    imshow(windowNameOfHistogramEqualized, hist_equalized_image);

    waitKey(0); 


    return 0;
}
