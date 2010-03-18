////////////////////////////////////////
//  File      : trash.h               //
//  Written by: g_cigala@virgilio.it  //
//  Copyright : GPL                   //
////////////////////////////////////////

// Trash pixmap (freedesktop.org implementation)

////////////////////////////////////////

#ifndef STARTER_H
#define STARTER_H

#include "defs.h"
#include "utils.h"
#include "msgbox.h"
#include "starterdialog.h"

////////////////////////////////////////

class Starter : public QWidget
{
    Q_OBJECT

public:
    Starter(QWidget *parent=0);
    ~Starter();
    void read_settings();
    void update_style();
    void init();

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseDoubleClickEvent(QMouseEvent *);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void paintEvent(QPaintEvent *);

signals:

public slots:

private:
    QString starter_pix;
    QColor starter_col;
    QPixmap pix;
    bool zoom;
    QPoint mousepos;
    QString stl_path;
    QString stl_name;
    QSettings *antico;
    StarterDialog *starter_dlg;
};

#endif
