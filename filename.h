#ifndef MOTHERINLAW_FILENAME_H
#define MOTHERINLAW_FILENAME_H
#include <iostream>
#include <opencv2/core.hpp>

class ImageMap{

public:

    ImageMap(const std::string& filename);
    cv::Mat pixels;
    std::string outFileName;
    void show();
    void drawCircle(int radius);
    static std::string create_out_filename(const std::string& input_filename); //remember it was privat temporary
};

#endif //MOTHERINLAW_FILENAME_H
