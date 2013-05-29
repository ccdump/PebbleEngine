// ****************************************************************************************
//
// Pebble Scene Editor 
// --------------------------------------
// Copyright (C) 2011 Antmanler
// 
// This file is part of the Pebble Scene Editor.
//
// The Pebble Scene Editor is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation version 3 of the License 
//
// The Pebble Scene Editor is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
// Credits : Volker Wiendl who created the major work of the original editor and Horde3D
// is a flexible graphics engine. see <http://www.horde3d.org> and <http://http://goo.gl/Me2HT>
//
// ****************************************************************************************

#ifndef COLLADAIMPORTER_H_
#define COLLADAIMPORTER_H_

#include "ui_ColladaImporter.h"

#include <QtCore/QDir>

class QFileSystemWatcher;
class QProcess;
class ColladaImporter : public QDialog, protected Ui_ColladaImporter
{
    Q_OBJECT
public:
    ColladaImporter(QWidget* parent = 0, Qt::WFlags flags = 0);
    virtual ~ColladaImporter();

    void initImportPath(const QString& resourcePath);

public slots:
    bool setColladaFiles();

private slots:
    void importFiles();
    void lodLevelChanged(int index);
//    void typeChanged(int index);
    void lodChanged(int value);

private:
    void cleanUp();

    QDir m_resourceDir;
    // Temp dir for conversion
    QDir m_outputDir;

    QProcess*	m_convertProcess;

    QStringList	 m_colladaFiles;
};
#endif

