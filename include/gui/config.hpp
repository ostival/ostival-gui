// =============================================================================
// Ostival - Open Silicon Technology Integration for VLSI ASIC and LOGIC
// -----------------------------------------------------------------------------
// File:        config.hpp
// Description: Global variables and app configurations.
// License:     AGPL-3.0
//
// Made with 💚 by Team Ostival <hello@ostival.org>
// =============================================================================

#ifndef CONFIG_H
#define CONFIG_H

#include <QString>

#define APP_VERSION "1.0.0"
#define APP_NAME "Ostival GUI"
#define ABOUT_MESSAGE "Ostival GUI is a cross-platform desktop application \n for Front-End VLSI Design Flow \n Version 1.0.0 \n Developed by Team Ostival"
#define DEV_TEAM "Team Ostival"
#define DOMAIN_NAME "ostival.org"


const QString SPLASH_SCREEN_STYLE = "QDialog {"
            "background-color: #2b2b2b;"
            "color: #f0f0f0;"
            "border: 1px solid #555555;"
        "}"
        "QLineEdit {"
            "background-color: #3c3c3c;"
            "border: 1px solid #555555;"
            "color: #f0f0f0;"
        "}"
        "QPushButton {"
            "background-color: #00A9A5;"
            "color: #ffffff;"
            "border: 1px solid #00A9A5;"
            "border-radius: 8px;"
            "padding: 6px 8px;"
        "}"

        "QPushButton:hover {"
            "background-color: #008785;"
            "border: 1px solid #008785;"
        "}"

        "QPushButton:pressed {"
            "background-color: #01d0cd;"
        "}"
        "QLabel {"
            "color: #f0f0f0;"
        "}"
        "QLineEdit {"
            "border-radius: 5px;"
            "border: 1px solid gray;"
        "}";

#endif