// =============================================================================
// Ostival - Open Silicon Technology Integration for VLSI ASIC and LOGIC
// -----------------------------------------------------------------------------
// File:        ProjectFileHandler.hpp
// Description: Header file for file handler.
// License:     AGPL-3.0
//
// Made with 💚 by Team Ostival <hello@ostival.org>
// =============================================================================


#ifndef PROJECTFILEHANDLER_H
#define PROJECTFILEHANDLER_H

#include <QFile>


class ProjectFileHandler {

    public:
        int checkFile();
        int createInitialfile();
};


#endif