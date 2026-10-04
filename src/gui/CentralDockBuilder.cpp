// =============================================================================
// Ostival - Open Silicon Technology Integration for VLSI ASIC and LOGIC
// -----------------------------------------------------------------------------
// File:        CentralDockBuilder.cpp
// Description: Logic for invoking central widget.
// License:     AGPL-3.0
//
// Made with 💚 by Team Ostival <hello@ostival.org>
// =============================================================================

#include <QVBoxLayout>
#include <gui/CentralDockBuilder.hpp>


CentralDockBuilder::CentralDockBuilder(QWidget *parent):QWidget(parent) {

    OstivalTextEdit = new QTextEdit(this);
    OstivalTextEdit->setPlaceholderText("Ostival text editor...");
    OstivalTextEdit->setFont(QFont("Courier", 16));
    OstivalTextEdit->setStyleSheet("background-color: #282A36; color: #F8F8F2;");
    OstivalTextEdit->setTabStopDistance(4 * QFontMetricsF(OstivalTextEdit->font()).horizontalAdvance(' '));

    auto *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(OstivalTextEdit);
    setLayout(mainLayout);
}