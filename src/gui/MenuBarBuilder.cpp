// =============================================================================
// Ostival - Open Silicon Technology Integration for VLSI ASIC and LOGIC
// -----------------------------------------------------------------------------
// File:        MenuBarBuilder.cpp
// Description: Header file for menubar.
// License:     AGPL-3.0
//
// Made with 💚 by Team Ostival <hello@ostival.org>
// =============================================================================

#include <QMenu>
#include <QAction>
#include <gui/MenuBarBuilder.hpp>

MenuBarBuilder::MenuBarBuilder(QMenuBar *menuBar, QWidget *parentWindow, LeftDockBuilder *leftDock, RightDockBuilder *rightDock, QObject *parent) : QObject(parent), OstivalmenuBar(menuBar), OstivalparentWindow(parentWindow),OstivalleftDockBuilder(leftDock),OstivalrightDockBuilder(rightDock) {
    
    // --- File Menu ---
    QMenu *fileMenu = OstivalmenuBar->addMenu("File");
    QAction *openFolderAction = fileMenu->addAction("Create Or Open Project");
    fileMenu->addSeparator();
    QAction *createVfile = fileMenu->addAction("Create Design file");
    QAction *createtbfile = fileMenu->addAction("Create Testbench file");
    QAction *createpyfile = fileMenu->addAction("Create Python file");
    fileMenu->addSeparator();
    QAction *clearAction = fileMenu->addAction("Clear");
    fileMenu->addSeparator();
    QAction *exitAction = fileMenu->addAction("Exit");

    // --- Edit Menu ---
    QMenu *editMenu = OstivalmenuBar->addMenu("Edit");
    QAction *cutAction = editMenu->addAction("Cut");
    fileMenu->addSeparator();
    QAction * copyAction = editMenu->addAction("Copy");

    // --- Run Flow Menu ---
    QMenu *flowMenu = OstivalmenuBar->addMenu("Run");
    QAction *compileAction = flowMenu->addAction("Compile");

    // --- Tools Menu ---
    QMenu *toolsMenu = OstivalmenuBar->addMenu("Tools");
    QAction *settingTool = toolsMenu->addAction("Ostival Settings");

    // --- Reports Menu ---
    QMenu *reportsMenu = OstivalmenuBar->addMenu("Reports");
    QAction *synthesisReportAction = reportsMenu->addAction("Get Synthesis Report");

    // --- View Menu ---
    QMenu *viewMenu = OstivalmenuBar->addMenu("View");
    QAction *toggleLeftPanel = new QAction("Left Panel", this);
    toggleLeftPanel->setCheckable(true);
    toggleLeftPanel->setChecked(true);
    viewMenu->addAction(toggleLeftPanel);
    QAction *toggleRightPanel = new QAction("Right Panel", this);
    toggleRightPanel->setCheckable(true);
    toggleRightPanel->setChecked(true);
    viewMenu->addAction(toggleRightPanel);

    // --- Help Menu ---
    QMenu *helpMenu = OstivalmenuBar->addMenu("Help");
    QAction *aboutAction = helpMenu->addAction("About");
}