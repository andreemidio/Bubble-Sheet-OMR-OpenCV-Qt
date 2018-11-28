#include "cv_worker.h"

#include <QDebug>
#include <QThread>

// --- CONSTRUCTOR ---
cv_worker::cv_worker(QStringList paths) {
    // you could copy data from constructor arguments to internal variables here.
    mImgPaths = paths;
    mNPages = mImgPaths.size();
}

// --- DECONSTRUCTOR ---
cv_worker::~cv_worker() {
    // free resources
}

// --- PROCESS ---
// Start processing data.
void cv_worker::process() {
    // allocate resources using new here
    qDebug("CV WORKER STARTED");
    qDebug()<<QThread::currentThread();

    std::vector<QImage> productImgs;

    int i;
    for (i=0;i<mNPages;i++)
    {
        mDoc.push_back(cv::imread(mImgPaths[i].toStdString(), -1));
    }

    for(cv::Mat& rawImg : mDoc)
    {
        cv::Mat grayImg;
        cv::cvtColor(rawImg, grayImg, cv::COLOR_BGR2GRAY);
        cv::Mat blurry;
        cv::GaussianBlur(grayImg, blurry, cv::Size(3, 3), 1);
        cv::Mat adapt_thresh;
        cv::adaptiveThreshold(blurry, adapt_thresh, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY_INV, 11, 2);

        cv::Mat img;
        img = adapt_thresh;

        std::vector<std::vector<cv::Point> > circleContours;
        circleContours = findCircleContours(img);
        cv::drawContours(rawImg, circleContours, -1, cv::Scalar(0,0,255), 2);
        QImage finishedImg = MatToQImage(rawImg);
        //emit sendImg(finishedImg);
        productImgs.push_back(finishedImg);
    }
    emit transportImgs(productImgs);
    emit finished();
}

QImage cv_worker::MatToQImage(const cv::Mat& mat)
{
    // 8-bits unsigned, NO. OF CHANNELS=1
    if(mat.type()==CV_8UC1)
    {
        // Set the color table (used to translate colour indexes to qRgb values)
        QVector<QRgb> colorTable;
        for (int i=0; i<256; i++)
            colorTable.push_back(qRgb(i,i,i));
        // Copy input Mat
        const uchar *qImageBuffer = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage img(qImageBuffer, mat.cols, mat.rows, int(mat.step), QImage::Format_Indexed8);
        img.setColorTable(colorTable);
        return img;
    }
    // 8-bits unsigned, NO. OF CHANNELS=3
    if(mat.type()==CV_8UC3)
    {
        // Copy input Mat
        const uchar *qImageBuffer = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage img(qImageBuffer, mat.cols, mat.rows, int(mat.step), QImage::Format_RGB888);
        return img.rgbSwapped();
    }
    else
    {
        qDebug() << "ERROR: Mat could not be converted to QImage.";
        return QImage();
    }
}

std::vector<std::vector<cv::Point> > cv_worker::findCircleContours(cv::Mat img)
{
    int maxCircleR = 100;
    int minCircleW = 35;
    int minCircleH = 35;
    double minCircleArea = ((minCircleW+minCircleH)/4)*((minCircleW+minCircleH)/4)*3;

    std::vector<std::vector<cv::Point> > contours;
    std::vector<std::vector<cv::Point> >poly(contours.size());
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(img.clone(), contours, hierarchy, cv::RETR_CCOMP, cv::CHAIN_APPROX_NONE);

    std::vector<std::vector<cv::Point> > circleContours;
    std::vector<cv::Rect> rects;
    unsigned int i;
    for (i=0;i<contours.size();i++)
    {
        std::vector<cv::Point> contour = contours[i];
        cv::Rect rect = cv::boundingRect(contour);
        float ar = float(rect.width) / float(rect.height);
        if (hierarchy[i][3] == -1 && rect.width >= minCircleW && rect.height >= minCircleH && 0.9f <= ar && ar <=1.1f)
        {
            double ctnArea = cv::contourArea(contour, false);
            if (minCircleArea <= ctnArea)
            {
                double epsilon = 0.01*cv::arcLength(contour, true);
                std::vector<cv::Point> approx;
                approxPolyDP(contour, approx, epsilon, true);
                if (approx.size()>5)
                {
                    circleContours.push_back(contour);
                    rects.push_back(rect);
                }
            }
        }
    }
    //
    std::vector<int> radii(maxCircleR+1, 0);
    for (i=0;i<rects.size();i++)
    {
        if (rects.at(i).width<=maxCircleR)
        {
            radii.at(rects.at(i).width) += 1;
        }
    }
    unsigned int modeRadius = 0;
    for (i=1;i<radii.size();i++)
    {
        if (radii.at(i)>radii.at(modeRadius))
        {
            modeRadius = i;
        }
    }
    qDebug()<<rects.size()-circleContours.size();
    std::vector<std::vector<cv::Point> > retCircleContours;
    for (i=0;i<rects.size();i++)
    {
        if (std::abs(int(rects.at(i).width)-int(modeRadius))<2)
        {
            retCircleContours.push_back(circleContours.at(i));
        }
    }
    qDebug()<<retCircleContours.size();
    return retCircleContours;
}