#ifndef TEXTVIEWERAREA_H
#define TEXTVIEWERAREA_H

#include <QObject>
#include <simplegreparea.h>
#include <QTextEdit>
#include <QDebug>
#include <QVBoxLayout>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QElapsedTimer>
#include <sys/time.h>
#include <sys/resource.h>

class TextViewerArea : public SimpleGrepArea
{
public:
    TextViewerArea(QWidget *parent = nullptr);
    QAbstractScrollArea* get_main_view_() override{return text_viewer_;}
public slots:
    void next();
    void previous();
private:
    QTextEdit* text_viewer_;
    QAction* next_;
    QAction* previous_;

    void initialization_components() override;
    void desing_area() override;
    void desing_main_view() override;
    void desing_status_bar() override;
    void desing_toolbar() override;
    void make_connections() override;


};

#endif // TEXTVIEWERAREA_H
