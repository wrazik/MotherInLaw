#include "imageclass.h"
#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

ImageMap::ImageMap(const std::string& filename) {//init.
    pixels = imread(filename, cv::IMREAD_COLOR);
    outFileName = create_out_filename(filename);
}
    std::string ImageMap::create_out_filename(const std::string& input_filename) {
        auto foo = input_filename.find_last_of('.');

        std::string output_filename = "";
        if(foo != std::string::npos) { //for safety when there is no dot
                    output_filename = input_filename.substr(0, foo) +
                            "_new" + input_filename.substr(foo, input_filename.length());//Adding new before dot
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
        cv::imshow("Your's target", pixels);
        int k = cv::waitKey(0); // Wait for a keystroke in the window

    }
}

void ImageMap::drawCircle(int radius, int sizeLine) {
    int centerX = pixels.rows/2;
    int centerY = pixels.cols/2;

    cv::circle(pixels,cv::Point (centerX,centerY),radius,cv::Scalar (0, 255, 0), sizeLine);
}

void ImageMap::sizeImage(){
    int up_width = 1965; //520 mm from px.
    int up_height = 1965;
    cv::Mat resized_up;
    //resize up
    cv::resize(pixels, pixels, cv::Size(up_width, up_height), cv::INTER_LINEAR);
}