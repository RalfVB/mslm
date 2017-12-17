#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/*                                                                                                 */
#include "folderview.h"
#include "fileview.h"
#include <QAction>
#include <QMainWindow>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QDockWidget>
#include <QMenu>
#include <QMenuBar>
#include <QSettings>
#include <QStatusBar>
#include <QIcon>
/*                                                                                                 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    FolderView *m_folderView;

    QMenu *m_fileMenu;
    QMenu *m_viewMenu;
    QAction *m_addSoftware;
    QAction *m_toggleTabView;
    QMdiArea *m_mdiArea;
    QLayout *m_layout;
    QDockWidget *m_leftDock;

private slots:
    void openFile(const QString &file);
    void tabViewToggled(const bool &toggled);
};
/*                                                                                                 */
#endif