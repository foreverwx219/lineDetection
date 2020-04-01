#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <ctime>

using namespace std;

void loadImage(string img_path, cv::Mat *src);
vector<cv::Vec4f> lineDetection(cv::Mat *src);
cv::Mat drawLines(vector<cv::Vec4f> lines, cv::Mat *src);

void loadImage(string img_path, cv::Mat *src)
{
    *src = cv::imread(img_path);
    if(!(src->data)){
        cout << "could not read image..." << endl;
        exit(100);
    }

    //cv::namedWindow("src_img");
    //cv::imshow("src_img", *src);
    //cv::waitKey(0);
}

vector<cv::Vec4f> lineDetection(cv::Mat *src)
{
    cv::Mat dst = *src;
    cv::cvtColor(*src, dst, CV_BGR2GRAY);
    cv::GaussianBlur(dst, dst, cv::Size(5, 5), 0.5, 0.5);
    vector<cv::Vec4f> lines;
    cv::Canny(dst, dst, 100, 200);
    cv::HoughLinesP(dst, lines, 1, CV_PI/180.0, 50, 10, 20);
    return lines;
}

cv::Mat drawLines(vector<cv::Vec4f> lines, cv::Mat *src)
{
    cv::Mat result = cv::Mat::zeros(cv::Size(src->cols, src->rows), CV_8UC3);
    cv::Scalar color = cv::Scalar(255, 255, 255);
    for(size_t i = 0; i < lines.size(); i++){
        cv::line(result, cv::Point(lines[i][0], lines[i][1]), cv::Point(lines[i][2], lines[i][3]), color, 2);
    }
    return result;
}

int main(int argc, char *argv[]){
    clock_t startTime, endTime;
    startTime = clock();
    cv::Mat src;
    if(argc < 2){
        cout << "Please input the image path." << endl;
        cout << "like './Project ../imgData/src.JPG' " << endl;
        return 0;
    }else{
        loadImage(argv[1], &src);
    }
    
    vector<cv::Vec4f> lines = lineDetection(&src);

    cv::Mat result = drawLines(lines, &src);

    //cv::namedWindow("result_img");
    //cv::imshow("result_img", result);
    //cv::waitKey(0);
    cv::imwrite("result.jpg", result);
    endTime = clock();
    cout << (double)(endTime - startTime)/CLOCKS_PER_SEC << endl;

    return 0;
}
