/******************************************************************************
    Simple Player:  this file is part of QtAV examples
    Copyright (C) 2012-2015 Wang Bin <wbsecg1@gmail.com>

*   This file is part of QtAV

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/
#include <QApplication>
#include "playerwindow.h"
#include <QtAVWidgets>

int main(int argc, char *argv[])
{    // 设置GL参数
    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);
    format.setVersion(4, 5);
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setSwapBehavior(QSurfaceFormat::DoubleBuffer);
    // 开启垂直同步，如果不开启，则GPU占用率可能直接飙升到100%
    // 设置前后缓冲区交换时间至少为1帧, 限制了最大帧率为屏幕刷新率, 减少了GPU占用
    format.setSwapInterval(1);
    QSurfaceFormat::setDefaultFormat(format);
    QtAV::Widgets::registerRenderers();
    QApplication a(argc, argv);
    PlayerWindow player;
    player.show();
    player.resize(800, 600);
    return a.exec();
}
