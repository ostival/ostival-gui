// =============================================================================
// Ostival - Open Silicon Technology Integration for VLSI ASIC and LOGIC
// -----------------------------------------------------------------------------
// File:        RightDockBuilder.cpp
// Description: Logic for invoking right dock.
// License:     AGPL-3.0
//
// Made with 💚 by Team Ostival <hello@ostival.org>
// =============================================================================

#include <gui/RightDockBuilder.hpp>
#include <QMainWindow>

RightDockBuilder::RightDockBuilder(QMainWindow *mainWindow, QObject *parent):QObject(parent), OstivalmainWindow(mainWindow){
    OstivalrightDock = new QDockWidget("Right Panel", OstivalmainWindow);
    OstivalmainWindow->addDockWidget(Qt::RightDockWidgetArea, OstivalrightDock);
}

QDockWidget* RightDockBuilder::getRightDockWidget() const {
    return OstivalrightDock;
}