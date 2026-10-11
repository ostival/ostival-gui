// =============================================================================
// Ostival - Open Silicon Technology Integration for VLSI ASIC and LOGIC
// -----------------------------------------------------------------------------
// File:        MenuBarBuilder.cpp
// Description: Logic for menubar building.
// License:     AGPL-3.0
//
// Made with 💚 by Team Ostival <hello@ostival.org>
// =============================================================================

#ifndef MENUBARBUILDER_H
#define MENUBARBUILDER_H

#include <QObject>
#include <QMenuBar>
#include <gui/LeftDockBuilder.hpp>
#include <gui/RightDockBuilder.hpp>

class MenuBarBuilder : public QObject {
    Q_OBJECT

    public:
        MenuBarBuilder(QMenuBar *menuBar, QWidget *parentWindow, LeftDockBuilder *leftDock, RightDockBuilder *rightDock, QObject *parent = nullptr);

    private:
        QMenuBar *OstivalmenuBar;
        QWidget *OstivalparentWindow;
        LeftDockBuilder *OstivalleftDockBuilder;
        RightDockBuilder *OstivalrightDockBuilder;
};

#endif