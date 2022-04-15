#include <sailfishapp.h>
#include <QtQuick>
#include "folder.h"

int main(int argc, char *argv[])
{
    // SailfishApp::main() will display "qml/FolderRead.qml", if you need more
    // control over initialization, you can use:
    //
    //   - SailfishApp::application(int, char *[]) to get the QGuiApplication *
    //   - SailfishApp::createView() to get a new QQuickView * instance
    //   - SailfishApp::pathTo(QString) to get a QUrl to a resource file
    //   - SailfishApp::pathToMainQml() to get a QUrl to the main QML file
    //
    // To display the view, call "show()" (will show fullscreen on device).

    QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
    app->setApplicationName("FolderRead");
    app->setOrganizationName("ru.test");

    qmlRegisterType<Folder, 1>("my.qml", 1, 0, "Folder");

    Folder folder;

    QScopedPointer<QQuickView> view(SailfishApp::createView());
    view->engine()->rootContext()->setContextProperty("folder", &folder);
    view->setSource(SailfishApp::pathToMainQml());
    view->showFullScreen();

    return app->exec();
}
