// =============================================================================
// Ostival - Open Silicon Technology Integration for VLSI ASIC and LOGIC
// -----------------------------------------------------------------------------
// File:        LeftDockBuilder.cpp
// Description: Logic for invoking left dock.
// License:     AGPL-3.0
//
// Made with 💚 by Team Ostival <hello@ostival.org>
// =============================================================================

#include <QMainWindow>
#include <gui/LeftDockBuilder.hpp>

LeftDockBuilder::LeftDockBuilder(QMainWindow *mainWindow, QObject *parent):QObject(parent), OstivalmainWindow(mainWindow){
    OstivalleftDock = new QDockWidget("Left Panel", OstivalmainWindow);
    OstivalmainWindow->addDockWidget(Qt::LeftDockWidgetArea, OstivalleftDock);
}

QDockWidget* LeftDockBuilder::getLeftDockWidget() const {
    return OstivalleftDock;
}
