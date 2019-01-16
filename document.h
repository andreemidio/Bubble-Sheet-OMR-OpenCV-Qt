#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <pdf.h>
#include <sheet.h>

#include <QString>
#include <QObject>

class document : public QObject
{
    Q_OBJECT
public:
    document();
    document(QString);

    pdf _PDF;
    QVector<sheet> _sheets;

    bool hasConvertedImgs();
    int nSheets();
signals:
    void sheetsReady();

public slots:
    void convertPDF2Img();

};

#endif // DOCUMENT_H