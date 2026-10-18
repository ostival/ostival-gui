// =============================================================================
// Ostival - Open Silicon Technology Integration for VLSI ASIC and LOGIC
// -----------------------------------------------------------------------------
// File:        SplashScreen.hpp
// Description: Logic for splash screen.
// License:     AGPL-3.0
//
// Made with 💚 by Team Ostival <hello@ostival.org>
// =============================================================================

#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QFormLayout>
#include <gui/SplashScreen.hpp>
#include <gui/config.hpp>

SplashScreen::SplashScreen(QWidget *parent) : QDialog(parent) {
    setWindowTitle("Ostival - Open/Create a Project");
    this->setStyleSheet(SPLASH_SCREEN_STYLE);

    // Ostival Logo
    QLabel *logoLabel = new QLabel(this);
    const QString LOGO_RESOURCE_PATH = ":/resources/ostival-logo.png";
    const int LOGO_SIZE = 130;
    QPixmap logoPixmap(LOGO_RESOURCE_PATH);
    if (logoPixmap.isNull()) {
        logoLabel->setText("Ostival");
        logoLabel->setAlignment(Qt::AlignCenter);
    } else {
        QPixmap scaledPixmap = logoPixmap.scaled(LOGO_SIZE, LOGO_SIZE, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        logoLabel->setPixmap(scaledPixmap);
        logoLabel->setAlignment(Qt::AlignCenter);
    }

    // Buttons
    okButton = new QPushButton("Create", this);
    cancelButton = new QPushButton("Cancel", this);

    // Create project container 
    createModeContainer = new QWidget(this);
    QFormLayout *createFormLayout = new QFormLayout(createModeContainer);
    createFormLayout->setContentsMargins(0, 0, 0, 0);

    // Container form
    nameLineEdit = new QLineEdit(this);
    nameLineEdit->setPlaceholderText("Enter project name");
    pathLineEdit = new QLineEdit(this);
    pathLineEdit->setPlaceholderText("Select project location");
    pathLineEdit->setReadOnly(true);

    browseButton = new QPushButton("Browse", this);
    QHBoxLayout *pathLayout = new QHBoxLayout();
    pathLayout->setContentsMargins(0, 0, 0, 0);
    pathLayout->addWidget(pathLineEdit);
    pathLayout->addWidget(browseButton);
    pathLayout->addWidget(okButton);

    createFormLayout->addRow("Name This Project:", nameLineEdit);
    createFormLayout->addRow("Choose Location:", pathLayout);

    // Button layout
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(cancelButton);

    // Assemble all
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(logoLabel, 0, Qt::AlignCenter);
    mainLayout->addSpacing(12);
    mainLayout->addWidget(createModeContainer);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);
}