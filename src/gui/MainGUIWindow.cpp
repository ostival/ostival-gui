// =============================================================================
// Ostival - Open Silicon Technology Integration for VLSI ASIC and LOGIC
// -----------------------------------------------------------------------------
// File:        MainGUIWindow.cpp
// Description: Core window setup and layout logic.
// License:     AGPL-3.0
//
// Made with 💚 by Team Ostival <hello@ostival.org>
// =============================================================================

#include <gui/MainGUIWindow.hpp>
#include <gui/CentralDockBuilder.hpp>

MainGUIWindow::MainGUIWindow(QWidget *parent) : QMainWindow(parent) {
    // Status Bar
    OstivalstatusBarBuilder = new StatusBarBuilder(this);
    QStatusBar *bbar = OstivalstatusBarBuilder->getStatusBar();
    bbar->showMessage("Ostival is Ready!", 1200);

    // Central Widget
    CentralDockBuilder *central = new CentralDockBuilder(this);
    setCentralWidget(central);

    // Left Dock Panel
    OstivalleftDockBuilder = new LeftDockBuilder(this, this);

    // Right Dock Panel
    OstivalrightDockBuilder = new RightDockBuilder(this, this);

}