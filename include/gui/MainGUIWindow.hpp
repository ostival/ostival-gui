// =============================================================================
// Ostival - Open Silicon Technology Integration for VLSI ASIC and LOGIC
// -----------------------------------------------------------------------------
// File:        MainGUIWindow.hpp
// Description: Header file for core window setup and layout logic.
// License:     AGPL-3.0
//
// Made with 💚 by Team Ostival <hello@ostival.org>
// =============================================================================

#ifndef MAIN_GUI_WINDOW_H
#define MAIN_GUI_WINDOW_H

#include <QMainWindow>
#include <gui/StatusBarBuilder.hpp>
#include <gui/LeftDockBuilder.hpp>
#include <gui/RightDockBuilder.hpp>

class MainGUIWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit MainGUIWindow(QWidget *parent = nullptr);
        ~MainGUIWindow() override = default; 
    private:
        StatusBarBuilder *OstivalstatusBarBuilder = nullptr;
        LeftDockBuilder *OstivalleftDockBuilder = nullptr;
        RightDockBuilder *OstivalrightDockBuilder = nullptr;
};

#endif