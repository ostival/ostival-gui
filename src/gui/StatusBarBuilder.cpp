// =============================================================================
// Ostival - Open Silicon Technology Integration for VLSI ASIC and LOGIC
// -----------------------------------------------------------------------------
// File:        StatusBarBuilder.cpp
// Description: The logic for status bar.
// License:     AGPL-3.0

// Made with 💚 by Team Ostival <hello@ostival.org>
// =============================================================================


#include <gui/StatusBarBuilder.hpp>

StatusBarBuilder::StatusBarBuilder(QMainWindow *mainWindow) {
    OstivalStatusBar = new QStatusBar(mainWindow);
    mainWindow->setStatusBar(OstivalStatusBar);
}

QStatusBar *StatusBarBuilder::getStatusBar() const {
    return OstivalStatusBar;
}