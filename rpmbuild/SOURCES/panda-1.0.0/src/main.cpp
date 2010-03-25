////////////////////////////////////////
//  File      : main.cpp              //
//  Written by: zv.zorro@gmail.com  //
//  Copyright : GPL                   //
////////////////////////////////////////

#include "defs.h"
#include "panda.h"

////////////////////////////////////////


int main(int argc, char **argv)
{
    Panda a(argc, argv);
    XSelectInput(QX11Info::display(), QX11Info::appRootWindow(QX11Info::appScreen()), KeyPressMask | KeyReleaseMask | ButtonPressMask | ButtonReleaseMask |
                 KeymapStateMask | ButtonMotionMask | PointerMotionMask | EnterWindowMask | LeaveWindowMask | FocusChangeMask | VisibilityChangeMask |
                 ExposureMask | StructureNotifyMask | SubstructureRedirectMask | SubstructureNotifyMask);

    XClearWindow(QX11Info::display(), QX11Info::appRootWindow(QX11Info::appScreen()));
    XSync(QX11Info::display(), False);
    
    QTranslator translator;
    qDebug() << "Language:" << QLocale::system().name();
    translator.load(QLocale::system().name(), QCoreApplication::applicationDirPath() + "/language/");
    a.installTranslator(&translator);
    
    qDebug() << "GUI creation...";
    a.create_gui();
    
    a.connect(&a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()));
    return a.exec();
}

