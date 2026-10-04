// =============================================================================
// Ostival - Open Silicon Technology Integration for VLSI ASIC and LOGIC
// -----------------------------------------------------------------------------
// File:        LeftDockBuilder.hpp
// Description: Header file for left dock builder.
// License:     AGPL-3.0
//
// Made with 💚 by Team Ostival <hello@ostival.org>
// =============================================================================

#ifndef LEFTDOCKBUILDER_H
#define LEFTDOCKBUILDER_H

#include <QWidget>
#include <QObject>
#include <QDockWidget>
#include <QMainWindow>


class LeftDockBuilder : public QObject{
    Q_OBJECT

    public:
    explicit LeftDockBuilder(QMainWindow *mainWindow, QObject *parent = nullptr);
    QDockWidget* getLeftDockWidget() const;

    private:
        QMainWindow *OstivalmainWindow;
        QDockWidget *OstivalleftDock;
};


#endif