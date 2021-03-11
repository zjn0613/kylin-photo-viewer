#ifndef KYVIEW_H
#define KYVIEW_H

//#include <QKyView>
#include <QWidget>
#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include <QScreen>
#include <QGuiApplication>
#include <QPushButton>
#include <QLabel>
#include <QMouseEvent>
#include <QTimer>

#include "toolbar.h"
#include "titlebar.h"
#include "openimage.h"
#include "showimagewidget.h"
#include "navigator.h"
#include "information.h"

#include "src/global/variable.h"
#include "src/controller/interaction.h"
#include "src/global/variable.h"

class KyView : public QWidget
{
    Q_OBJECT
public:
    explicit KyView(QWidget *parent = nullptr);
    ~KyView();
    static KyView *mutual;//指针类型静态成员变量
    void menuopen(QString path);
    ToolBar *toolbar = nullptr;//工具栏

private:
    Interaction *interaction = nullptr;
    TitleBar *titlebar = nullptr;//顶栏
    Navigator *navigator = nullptr;//导航器
    OpenImage *openImage = nullptr;//打开图片
    ShowImageWidget *showImageWidget = nullptr;//展示图片
    Information *information = nullptr;//信息窗口

    QSize widgetSize;
    QSize widgetPosition;
    QPoint p;

    QTimer *timer;

    bool inforState = true;

    void _setstyle();//设置QSS
    void _initconnect();//初始化连接
    void _openState();//  判断打开应用应该是什么状态

    void _titlebarChange();//改变顶栏位置和大小
    void _openImageChange();//改变中间打开图片位置和大小
    void _showImageChange();//改变图片展示的位置和大小
    void _toolbarChange();//改变工具栏位置和大小
    void _naviChange();//改变导航栏位置
    void _inforChange();//改变信息栏位置
    void _delayHide();//顶栏工具栏的延时隐藏
    void _showInforWid();//展示或隐藏图片信息窗口

    void _clearImage();//无图片，需要返回默认界面
    void _hoverChange(int y);//hover态，顶栏和工具栏的状态

    void mouseMoveEvent(QMouseEvent *event);
    void resizeEvent(QResizeEvent *event);
    void leaveEvent(QEvent *event);


private slots:

    void changFullScreen();
    void changOrigSize();
    void _Toshowimage();


signals:
    void openSignal(QString path);


};

#endif // KYVIEW_H
