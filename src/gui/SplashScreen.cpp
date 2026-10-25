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
#include <QFileDialog>
#include <QDir>
#include <QString>
#include <QRegularExpression>
#include <QMessageBox>
#include <cli/ProjectFileHandler.hpp>
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
    openProjectButton = new QPushButton("Open Existing Project", this);
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
    buttonLayout->addWidget(openProjectButton);
    buttonLayout->addWidget(cancelButton);

    // Assemble all
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(logoLabel, 0, Qt::AlignCenter);
    mainLayout->addSpacing(12);
    mainLayout->addWidget(createModeContainer);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);

    connect(browseButton, &QPushButton::clicked, this, &SplashScreen::browseForPath);
    connect(openProjectButton, &QPushButton::clicked, this, &SplashScreen::openExistingProject);
    connect(okButton, &QPushButton::clicked, this, &SplashScreen::validateAndAccept);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
}

void SplashScreen::browseForPath() {
    QString directory = QFileDialog::getExistingDirectory(this, tr("Select Project Path"), QDir::homePath());
    if (!directory.isEmpty()) {
        pathLineEdit->setText(directory);
    }
}

void SplashScreen::openExistingProject() {
    qDebug() << "[Splash] opening existing project";
    
    QString filePath = QFileDialog::getOpenFileName(this, "Select a file");

    if (filePath.isEmpty()) {
        QMessageBox::warning(this, "No File Selected", "Please select a project file.");
        return;
    }

    qDebug() << "[Splash] Selected file:" << filePath;

    QFileInfo fileInfo(filePath);

    if (fileInfo.suffix().compare("ostival", Qt::CaseInsensitive) == 0) {
        projectFile = filePath;
        QDir parentDir = fileInfo.dir();
        projectName = parentDir.dirName();

        if (parentDir.cdUp()) {
            projectPath = parentDir.absolutePath();
            QMessageBox::information(this, "Opening Project", QString("Ostival Project: %1 is opening.").arg(projectName));        
            accept();
        } else {
            qDebug() << "[Splash] Cannot go up from path:" << fileInfo.dir().absolutePath();
            QMessageBox::critical(this, "Error", "Failed to resolve parent directory.");
            return;
        }
    } else {
        QMessageBox::warning(this, "File Error", "Selected file is not a valid .ostival file.");
        return;
    }
}

void SplashScreen::validateAndAccept() {

    projectName = getProjectName();
    projectPath = getProjectPath();
    QString project = projectPath + "/" + projectName;
    QString project_design = projectPath + "/" + projectName + "/design";
    QString project_log = projectPath + "/" + projectName + "/logs";
    QString project_tb = projectPath + "/" + projectName + "/verify"; 
    QString project_py = projectPath + "/" + projectName + "/scripts";
    QRegularExpression re("^[A-Za-z0-9_]+$");

    if (projectName.isEmpty() || projectPath.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Project name and path cannot be empty.");
        return;
    }

    QDir dir(projectPath);

    if(dir.mkdir(project)){
        dir.mkdir(project_design);
        dir.mkdir(project_log);
        dir.mkdir(project_tb);
        dir.mkdir(project_py);
        QMessageBox::warning(this, "Folder created", "Project folder created\n");
    } else {
        QMessageBox::warning(this, "Something wrong", "Something wrong!!! Path Invalid\n");
        qDebug() << "[Splash] " + project;
        return;
    }

    ProjectFileHandler file_check;
    if(file_check.createInitialfile() == 0) {
        qDebug() << "[Splash] Unable to create initial file";
    }

    accept();
}

QString SplashScreen::getProjectName() const { return nameLineEdit->text().trimmed(); }
QString SplashScreen::getProjectPath() const { return pathLineEdit->text(); }