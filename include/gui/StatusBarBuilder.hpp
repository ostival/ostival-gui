// =============================================================================
// Ostival - Open Silicon Technology Integration for VLSI ASIC and LOGIC
// -----------------------------------------------------------------------------
// File:        StatusBarBuilder.cpp
// Description: Header file for for status bar.
// License:     AGPL-3.0

// Made with 💚 by Team Ostival <hello@ostival.org>
// =============================================================================

#ifndef STATUSBARBUILDER_H
#define STATUSBARBUILDER_H

#include <QObject>
#include <QStatusBar>
#include <QMainWindow>

class StatusBarBuilder : public QObject {
    Q_OBJECT

    public:
        explicit StatusBarBuilder(QMainWindow *mainWindow);
        QStatusBar *getStatusBar() const;

    private:
        QStatusBar *OstivalStatusBar;
};

#endif