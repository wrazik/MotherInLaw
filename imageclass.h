#ifndef MOTHERINLAW_FILENAME_H
#define MOTHERINLAW_FILENAME_H
#include <iostream>
#include <opencv2/core.hpp>

class ImageMap{

public:
    ImageMap(const std::string& filename);
    cv::Mat pixels; //Our picture
    std::string outFileName; //Filename that we save
    void show();//showing result of file
    void drawCircle(int radius);//drawing a circles from the middle of it
    void sizeImage();//at begining without parameters after we add size of targets
    static std::string create_out_filename(const std::string& input_filename); //remember it was privat temporary
};

#endif //MOTHERINLAW_FILENAME_H
