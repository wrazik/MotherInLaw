#include "filename.h"
#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

ImageMap::ImageMap(const std::string& filename) {
    pixels = imread(filename, cv::IMREAD_COLOR);
    outFileName = create_out_filename(filename);
}
    std::string ImageMap::create_out_filename(const std::string& input_filename) {
        auto foo = input_filename.find_last_of('.');

        std::string output_filename = "";
        if(foo != std::string::npos) {
                    output_filename = input_filename.substr(0, foo) + "_new" + input_filename.substr(foo, input_filename.length());
            }
        else {
            output_filename = input_filename+"_new";
        }
        return output_filename;
}
void ImageMap::show() {
    if(pixels.empty()){
        std::cout<<"File not exist\n";
    }
    else{
        cv::imshow("Display window", pixels);
        int k = cv::waitKey(0); // Wait for a keystroke in the window

    }
}
void ImageMap::drawCircle(int radius) {
    int centerX = pixels.rows/2;
    int centerY = pixels.cols/2;

    cv::circle(pixels,cv::Point (centerX,centerY),radius,cv::Scalar (0, 255,0));
}