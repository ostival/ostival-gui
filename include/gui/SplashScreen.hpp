// =============================================================================
// Ostival - Open Silicon Technology Integration for VLSI ASIC and LOGIC
// -----------------------------------------------------------------------------
// File:        SplashScreen.hpp
// Description: Header file for splash screen.
// License:     AGPL-3.0
//
// Made with 💚 by Team Ostival <hello@ostival.org>
// =============================================================================

#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QString>


class SplashScreen : public QDialog {
    Q_OBJECT

    private slots:
        void browseForPath();
        void validateAndAccept();
        void openExistingProject();

    public:
        explicit SplashScreen(QWidget *parent = nullptr);
        QString getProjectName() const;
        QString getProjectPath() const;

    private:
        QWidget *createModeContainer;
        
        QLineEdit *nameLineEdit;
        QLineEdit *pathLineEdit;

        QPushButton *browseButton;
        QPushButton *okButton;
        QPushButton *openProjectButton;
        QPushButton *cancelButton;

};



#endif