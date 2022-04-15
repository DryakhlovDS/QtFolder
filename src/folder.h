#ifndef FOLDER_H
#define FOLDER_H

#include <QObject>
#include <QDir>
#include <QQmlListProperty>

struct FF {
    QString fileName;
    QString filePath;
};

class Folder: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QFileInfo> files READ files NOTIFY filesChanged)

public:
    explicit Folder(QObject *parent=nullptr);

   Q_INVOKABLE void read(QString path);
   Q_INVOKABLE int files_count();
    Q_INVOKABLE QVariant getFileInfo(int i);
   QList<QFileInfo> files();

//public slots:
//     void setFiles(QFileInfoList);
signals:
     void filesChanged();
private:
   QList<QFileInfo> _files;
   QList<QFileInfo *> m_files;
    static void append_file(QQmlListProperty<QFileInfo> *list, QFileInfo *file);
};

//Q_DECLARE_METATYPE(QQmlListProperty<QFileInfo>);
Q_DECLARE_METATYPE(FF);
Q_DECLARE_METATYPE(QList<QFileInfo>);
#endif // FOLDER_H
