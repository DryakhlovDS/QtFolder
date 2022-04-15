#include "folder.h"
#include <QDebug>

Folder::Folder(QObject *parent): QObject(parent)
{

}

void Folder::read(QString path)
{
QDir dir(path);
_files = dir.entryInfoList(QDir::Files);

emit filesChanged();
}

QList<QFileInfo> Folder::files()
{
 qInfo() << _files.at(0).fileName() << _files.at(0).filePath();
    return _files;  //QQmlListProperty<QFileInfo>(this, 0, &Folder::append_file, nullptr, nullptr, nullptr) ;
}

int Folder::files_count()
{
    return _files.count();  //QQmlListProperty<QFileInfo>(this, 0, &Folder::append_file, nullptr, nullptr, nullptr) ;
}

QVariant Folder::getFileInfo(int i)
{
//   a.fromValue<FF>({_files.at(i)->fileName(), _files.at(i)->filePath()});
   qInfo() << _files.at(i).fileName();

    return QVariant::fromValue(_files.at(i));
}

void Folder::append_file(QQmlListProperty<QFileInfo> *list, QFileInfo *file)
{
    Folder *folder = qobject_cast<Folder *>(list->object);
    if (file)
        folder->m_files.append(file);
}
