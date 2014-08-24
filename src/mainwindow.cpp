#include <QtGui/QDragEnterEvent>
#include <QtGui/QDragLeaveEvent>
#include <QtGui/QDragMoveEvent>
#include <QtGui/QDropEvent>
#include <QtCore/QMimeData>
#include <QtCore/QUrl>
#include <QtCore/QList>
#include <QFileInfo>
#include <QFuture>
#include <QFutureWatcher>
#include <QtCore>
#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matcontentsmodel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowFlags(Qt::WindowStaysOnTopHint);
    setAcceptDrops(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::openMatFile(const QString &fname)
{
    statusBar()->showMessage("Parsing MAT file...");

    MATContentsModel* model = new MATContentsModel(this);
    QFutureWatcher<void> *watcher = new QFutureWatcher<void>(this);
    connect(watcher, SIGNAL(finished()), this, SLOT(postOpenMatFile()));

    QFuture<void> future = QtConcurrent::run(model, &MATContentsModel::parseMAT, fname);
    watcher->setFuture(future);
}

void MainWindow::preOpenMatFile()
{

}

void MainWindow::postOpenMatFile()
{
    statusBar()->showMessage("MAT parsed...", 2000);
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();
}

void MainWindow::dragMoveEvent(QDragMoveEvent *event)
{
    event->acceptProposedAction();
}

void MainWindow::dragLeaveEvent(QDragLeaveEvent *event)
{
    event->accept();
}

void MainWindow::dropEvent(QDropEvent *event)
{
    const QMimeData* mimeData = event->mimeData();

    if (mimeData->hasUrls())
    {
        QStringList pathList;
        QList<QUrl> urlList = mimeData->urls();

        if (urlList.size() == 1) {
            QString fname = urlList.at(0).toLocalFile();

            if (fname.isEmpty() == false){
                if (QFileInfo(fname).suffix() == "mat") {
                    openMatFile(fname);

                    event->acceptProposedAction();
                }
            }
        }
    }
}
