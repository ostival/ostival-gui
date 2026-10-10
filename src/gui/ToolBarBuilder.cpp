// =============================================================================
// Ostival - Open Silicon Technology Integration for VLSI ASIC and LOGIC
// -----------------------------------------------------------------------------
// File:        ToolBarBuilder.cpp
// Description: Logic for invoking the toolbar.
// License:     AGPL-3.0
//
// Made with 💚 by Team Ostival <hello@ostival.org>
// =============================================================================

#include <QAction>
#include <QIcon>
#include <QToolButton>
#include <QDebug>
#include <gui/ToolBarBuilder.hpp>
#include <gui/MainGUIWindow.hpp>

ToolBarBuilder::ToolBarBuilder(QMainWindow *mainWindow, QObject *parent) : QObject(parent), OstivalmainWindow(mainWindow) {
    OstivalguiWindow = qobject_cast<MainGUIWindow *>(mainWindow);

    if (!OstivalguiWindow)
        return;

    // 1. Create Toolbar and attach it to MainGUIWindow
    QToolBar *toolBar = new QToolBar("Main Toolbar", OstivalmainWindow);
    toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    OstivalmainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

    // Common built-in icons in Qt 6:
    QAction *newAction   = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::DocumentNew), "New", OstivalmainWindow);
    QAction *openAction  = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen), "Open", OstivalmainWindow);
    QAction *saveAction  = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave), "Save", OstivalmainWindow);
    QAction *addAction   = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::ListAdd), "Add", OstivalmainWindow);
    QAction *removeAction= new QAction(QIcon::fromTheme(QIcon::ThemeIcon::ListRemove), "Remove", OstivalmainWindow);
    QAction *schematicAction = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::AddressBookNew), "Schematic", OstivalmainWindow);
    QAction *timingAction = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::NetworkOffline), "Timing", OstivalmainWindow);
    QAction *lintingAction = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::VideoDisplay), "Linting", OstivalmainWindow);
    QAction *simulateAction = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::NetworkWireless), "Simulate", OstivalmainWindow);
    QAction *scriptAction = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::Computer), "Run Script", OstivalmainWindow);

    // Add them to your toolbar
    toolBar->addAction(newAction);
    toolBar->addAction(openAction);
    toolBar->addAction(saveAction);
    toolBar->addSeparator();
    toolBar->addAction(addAction);
    toolBar->addAction(removeAction);
    toolBar->addSeparator();
    toolBar->addAction(lintingAction);
    toolBar->addAction(simulateAction);
    toolBar->addAction(scriptAction);
    toolBar->addSeparator();
    toolBar->addAction(schematicAction);
    toolBar->addAction(timingAction);
}
