////////////////////////////////////////
//  File      : starter.cpp             //
//  Written by: g_cigala@virgilio.it  //
//  Copyright : GPL                   //
////////////////////////////////////////

#include "starter.h"

////////////////////////////////////////

Starter::Starter(QWidget *parent) : QWidget(parent)
{
    read_settings();
    init();
    show();
}

Starter::~Starter()
{
    delete antico;
}

void Starter::init()
{
    setFixedSize(100, 50);
    pix = QPixmap(starter_pix); // set default pixmap
    zoom = false;
    starter_dlg = new StarterDialog(this); // create the Trashdialog
}

void Starter::read_settings()
{
    // get style path
    antico = new QSettings(QCoreApplication::applicationDirPath() + "/antico.cfg", QSettings::IniFormat, this);
    antico->beginGroup("Style");
    stl_name = antico->value("name").toString();
    stl_path = antico->value("path").toString();
    antico->endGroup(); //Style
    // get style values
    QSettings *style = new QSettings(stl_path + stl_name, QSettings::IniFormat, this);
    style->beginGroup("Starter");
    starter_pix = stl_path + style->value("starter_pix").toString();
    starter_col = style->value("name_color").value<QColor>();
    style->endGroup(); //Trash
}

void Starter::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setWindow(-50, -50, 100, 50);
    painter.setOpacity(0.5);
    painter.setPen(Qt::black);
    painter.drawText(-49, -14, 100, 20, Qt::AlignHCenter, tr("Starter")); // shadow Starter name
    painter.setOpacity(1);
    painter.setPen(starter_col);
    painter.drawText(-50, -15, 100, 20, Qt::AlignHCenter, tr("Starter")); // Starter name
    
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    
    if (zoom)
    {
        painter.drawPixmap(QRect(-18, -50, 36, 36), pix, QRect(0, 0, pix.width(), pix.height()));// Starter pix
    }
    else
    {
        painter.drawPixmap(QRect(-16, -50, 32, 32), pix, QRect(0, 0, pix.width(), pix.height()));// Starter pix
    }
}

void Starter::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        mousepos = event->pos();
        grabMouse(QCursor(Qt::SizeAllCursor));
    }
}

void Starter::mouseMoveEvent(QMouseEvent *event)
{
    QPoint p = event->globalPos()-mousepos;
    move(p.x(), p.y());
}

void Starter::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    releaseMouse();
    // save new Trash position on desk writing on antico.cfg
    antico->beginGroup("Starter");
    antico->setValue("pos", pos());
    antico->endGroup(); // Starter
}

void Starter::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        starter_dlg->update();
        starter_dlg->exec();
    }
}

void Starter::enterEvent(QEvent *event)
{
    Q_UNUSED(event);
    zoom = true;
    update();
    
    setToolTip(tr("Start a new session"));
}

void Starter::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    zoom = false;
    update();
}

void Starter::update_style()
{
    read_settings();
    init();
    update();
}
