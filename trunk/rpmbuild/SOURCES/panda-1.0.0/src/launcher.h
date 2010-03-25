////////////////////////////////////////
//  File      : launcher.h            //
//  Written by: zv.zorro@gmail.com  //
//  Copyright : GPL                   //
////////////////////////////////////////

// the "Start" menu in the bottom-left of the dockbar
// manage the menu entry

////////////////////////////////////////

#ifndef LAUNCHER_H
#define LAUNCHER_H

#include "defs.h"
#include "panda.h"
#include "manager.h"
#include "settings.h"
#include "runner.h"
#include "utils.h"

class Panda;

////////////////////////////////////////

class Launcher : public QLabel
{
    Q_OBJECT

public:
    Launcher(Panda *, QWidget *parent=0);
    ~Launcher();
    void read_settings();
    void init();
    void update_style();

public slots:
    void run_command(QAction *);
    
signals:
 
protected:
    void mousePressEvent(QMouseEvent *);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);

private:
    QString launcher_pix;
    QString quit_pix;
    QString shutdown_pix;
    QString restart_pix;
    QString show_pix;
    QString settings_pix;
    QString refresh_pix;
    QString run_pix;
    QString manager_pix;
    int dock_position;
    int dock_height;
    Panda *app;
    QAction *quit;
    QAction *shutdown;
    QAction *restart;
    QAction *refresh;
    QAction *run;
    QAction *show_desk;
    QAction *settings;
    QAction *manager;
    QSettings *appsettings;
    QMenu *main_menu;
};

#endif
