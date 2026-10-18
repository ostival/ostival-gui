// =============================================================================
// Ostival - Open Silicon Technology Integration for VLSI ASIC and LOGIC
// -----------------------------------------------------------------------------
// File:        OstivalMain.cpp
// Description: The main cpp file. The application starts here.
// License:     AGPL-3.0

// Made with 💚 by Team Ostival <hello@ostival.org>
// =============================================================================

#include <QApplication>
#include <QDebug>
#include <gui/config.hpp>
#include <gui/MainGUIWindow.hpp>
#include <gui/SplashScreen.hpp>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Application metadata
    app.setApplicationName(APP_NAME);
    app.setApplicationDisplayName(APP_NAME);
    app.setApplicationVersion(APP_VERSION);
    app.setOrganizationName(DEV_TEAM);
    app.setOrganizationDomain(DOMAIN_NAME);


    SplashScreen init_dialog;

    if(init_dialog.exec() == QDialog::Accepted){
        qDebug() << "[Main] splash screen accepted";
    } else {
        return 0;
    }

    // Main window invoke
    MainGUIWindow window;
    window.setWindowTitle("Ostival Desktop");
    window.showMaximized();

    return app.exec();
}