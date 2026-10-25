// =============================================================================
// Ostival - Open Silicon Technology Integration for VLSI ASIC and LOGIC
// -----------------------------------------------------------------------------
// File:        ProjectFileHandler.cpp
// Description: File handler logic.
// License:     AGPL-3.0
//
// Made with 💚 by Team Ostival <hello@ostival.org>
// =============================================================================


#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QString>
#include <cli/ProjectFileHandler.hpp>
#include <gui/config.hpp>

int ProjectFileHandler::checkFile(){
    QString path = ::projectPath + "/" + ::projectName + "/" + ::projectName + ".ostival";
    qDebug() << "[P-File]" +  path;
    return QFile::exists(path);
}

int ProjectFileHandler::createInitialfile(){
    qDebug() << "[P-File] Creating Ostival project file" << ::projectPath << ::projectName;
    ::projectFile = ::projectPath + "/" + ::projectName + "/" + ::projectName + ".ostival";

    QJsonObject projectJson;

    // global settings
    projectJson["CustomStructure"] = "0";
    projectJson["ProjectPath"] = ::projectPath;
    projectJson["ProjectName"] = ::projectName;
    // folder structure
    projectJson["design"] = "";
    projectJson["verify"] = "";
    projectJson["scripts"] = "";
    projectJson["logs"] = "";
    // files structure
    projectJson["design_files"] = "";
    projectJson["test_files"] = "";
    projectJson["script_files"] = "";

    QJsonDocument doc(projectJson);

    QFile file(::projectFile);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        qWarning() << "[P-File] Can't open the file for writing. The issue is" << file.errorString();
        return 0;
    } else {
        file.write(doc.toJson(QJsonDocument::Indented));
        file.close();
        qDebug() << "[P-File] File created successfully" << ::projectFile;
    }

    return 1;
}