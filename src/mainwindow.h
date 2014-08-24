#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    bool openMatFile(const QString& fname);

public slots:
    void preOpenMatFile(void);
    void postOpenMatFile(void);

protected:
    void dragEnterEvent(QDragEnterEvent* event);
    void dragMoveEvent(QDragMoveEvent* event);
    void dragLeaveEvent(QDragLeaveEvent* event);
    void dropEvent(QDropEvent* event);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
