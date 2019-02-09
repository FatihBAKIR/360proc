#include <opencv2/opencv.hpp>

#include <iostream>

std::pair<cv::Rect, cv::Rect> get_rects(const cv::Size& imsz)
{
    cv::Rect left{};
    left.width = imsz.width / 2;
    left.height = imsz.height;
    cv::Rect right = left;
    right.x = left.width;
    return { left, right };
}

std::pair<cv::Mat, cv::Mat> split(cv::Mat im)
{
    auto [lrec, rrec] = get_rects(im.size());
    auto l_im = im(lrec);
    auto r_im = im(rrec);
    return { l_im, r_im };
}

void proc_frame(const cv::Mat& im)
{
    auto [l_im, r_im] = split(im);
    imwrite("left.png", l_im);
    imwrite("right.png", r_im);
}

int main(int argc, char** argv)
{
    auto fr = cv::imread(argv[1]);
    proc_frame(fr);
}
