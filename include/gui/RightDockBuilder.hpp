// =============================================================================
// Ostival - Open Silicon Technology Integration for VLSI ASIC and LOGIC
// -----------------------------------------------------------------------------
// File:        RightDockBuilder.hpp
// Description: Header file for right dock builder.
// License:     AGPL-3.0
//
// Made with 💚 by Team Ostival <hello@ostival.org>
// =============================================================================

#ifndef RIGHTDOCKBUILDER_H
#define RIGHTDOCKBUILDER_H

#include <QObject>
#include <QDockWidget>


class RightDockBuilder : public QObject {
    Q_OBJECT

    public:
        explicit RightDockBuilder(QMainWindow *mainWindow, QObject *parent = nullptr);
        QDockWidget* getRightDockWidget() const;

    private:
        QMainWindow *OstivalmainWindow;
        QDockWidget *OstivalrightDock;
};


#endif