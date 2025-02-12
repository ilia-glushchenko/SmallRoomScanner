#ifndef ARUCOKEYPOINTDETECTOR_H
#define ARUCOKEYPOINTDETECTOR_H

#include <QDebug>
#include <QFileInfo>
#include <QObject>
#include <QSettings>

#include <stdio.h>

#include <aruco.h>
#include <cvdrawingutils.h>
#include <highlyreliablemarkers.h>

#include "core/base/scannertypes.h"

class ArUcoKeypointDetector : public ScannerBase {
    Q_OBJECT

public:
    ArUcoKeypointDetector(
        QObject* parent, QSettings* parent_settings);
    ArUcoKeypointDetector(
        QObject* parent,
        QSettings* parent_settings,
        PcdPtr cloud_ptr1,
        PcdPtr cloud_ptr2,
        cv::Mat img1,
        cv::Mat img2,
        PcdPtr keypoint_cloud_ptr1,
        PcdPtr keypoint_cloud_ptr2);

    void detect();
    void getMarkersVector(
        cv::Mat InImage,
        std::vector<aruco::Marker>* Markers);

private:
    PcdPtr point_cloud_ptr1;
    PcdPtr point_cloud_ptr2;
    cv::Mat image1;
    cv::Mat image2;
    PcdPtr keypoint_point_cloud_ptr1;
    PcdPtr keypoint_point_cloud_ptr2;

    aruco::CameraParameters CamParam;
    aruco::Dictionary D;

    void recognize_markers(
        cv::Mat InImage,
        std::vector<aruco::Marker>* Markers);

    void find_keypoints();
};

#endif // ARUCOKEYPOINTDETECTOR_H
