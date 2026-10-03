// =============================================================================
// Ostival - Open Silicon Technology Integration for VLSI ASIC and LOGIC
// -----------------------------------------------------------------------------
// File:        CentralDockBuilder.hpp
// Description: Header file for central dock.
// License:     AGPL-3.0
//
// Made with 💚 by Team Ostival <hello@ostival.org>
// =============================================================================

#ifndef CENTRALDOCKBUILDER_H
#define CENTRALDOCKBUILDER_H

#include <QWidget>
#include <QTextEdit>

class CentralDockBuilder : public QWidget {
    Q_OBJECT

    public:
        explicit CentralDockBuilder(QWidget *parent = nullptr);

    private:
        QTextEdit *OstivalTextEdit = nullptr;

};

#endif