// =============================================================================
// Ostival - Open Silicon Technology Integration for VLSI ASIC and LOGIC
// -----------------------------------------------------------------------------
// File:        ToolBarBuilder.cpp
// Description: Header file for for toolbar.
// License:     AGPL-3.0
//
// Made with 💚 by Team Ostival <hello@ostival.org>
// =============================================================================

#ifndef TOOLBARBUILDER_H
#define TOOLBARBUILDER_H

#include <QObject>
#include <QToolBar>

#include <gui/MainGUIWindow.hpp>

class ToolBarBuilder : public QObject {
    Q_OBJECT

    public:
        ToolBarBuilder(QMainWindow *mainWindow, QObject *parent = nullptr);

    private:
        QMainWindow *OstivalmainWindow;
        MainGUIWindow *OstivalguiWindow;

};

#endif