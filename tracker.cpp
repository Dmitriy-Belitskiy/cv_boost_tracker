#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>
//#include <boost/lexical_cast.hpp>
#include <chrono>

int main() {
    cv::VideoCapture video(0);
    if (!video.isOpened()) {
        return -1;
    }

    cv::Rect roi;
    cv::Mat frame;
    video.read(frame);

    roi = cv::selectROI("Select Object", frame);
    cv::destroyWindow("Select Object");

    cv::Ptr<cv::Tracker> tracker = cv::TrackerKCF::create();
    tracker->init(frame, roi);

    auto start = std::chrono::steady_clock::now();
    int frameCounter = 0;

    while (video.read(frame)) {
        if (tracker->update(frame, roi)) {
            cv::rectangle(frame, roi, cv::Scalar(255, 0, 0), 2, 1);
        }

        // Calculate FPS
        frameCounter++;
        auto end = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        double fps = 1000.0 * frameCounter / duration;

        // Draw FPS on the frame
        std::string fpsString = "FPS: " + std::to_string(fps);
        cv::putText(frame, fpsString, cv::Point(10, 30), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 0), 2);

        cv::imshow("Tracking", frame);

        if (cv::waitKey(1) == 27) {
            break;
        }
    }

    return 0;
}
