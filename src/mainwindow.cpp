#include "mainwindow.h"
/*                                                                                                 */
MainWindow::MainWindow(QWidget *parent):QMainWindow(parent)
{
    QIcon::setThemeName("oxygen");
    //QSettings settings;

    setMenuBar(new QMenuBar(this));
    setStatusBar(new QStatusBar(this));
    m_mdiArea=new QMdiArea(this);
    m_mdiArea->setViewMode(QMdiArea::TabbedView);

    setCentralWidget(m_mdiArea);
    m_folderView=new FolderView(this);
    m_leftDock=new QDockWidget("Hash",this);
    m_leftDock->setAllowedAreas(Qt::LeftDockWidgetArea);
    m_leftDock->setWidget(m_folderView);
    m_leftDock->setFloating(false);
    m_leftDock->setFeatures(QDockWidget::NoDockWidgetFeatures);
    addDockWidget(Qt::LeftDockWidgetArea,m_leftDock,Qt::Vertical);
    connect(m_folderView,SIGNAL(openFile(QString)),this,SLOT(openFile(QString)));

    //    m_toggleTabView=new QAction(QIcon(),"Tabbed",this);
    //    m_toggleTabView->setCheckable(true);
    //    connect(m_toggleTabView,SIGNAL(toggled(bool)),this,SLOT(tabViewToggled(bool)));


    m_fileMenu=new QMenu("File",this);
    //m_fileMenu->addAction(m_addSoftware);

    m_viewMenu=new QMenu("View",this);
    //m_viewMenu->addAction(m_toggleTabView);

    menuBar()->addMenu(m_fileMenu);
    menuBar()->addMenu(m_viewMenu);
    //menuBar()->setVisible(true);
    //statusBar()->setVisible(true);
}
/*                                                                                                 */
void MainWindow::openFile(const QString &file)
{
    QMdiSubWindow *subWindow1 = new QMdiSubWindow;
    subWindow1->setWidget(new FileView(file));
    subWindow1->setAttribute(Qt::WA_DeleteOnClose);
    m_mdiArea->addSubWindow(subWindow1);
    subWindow1->showMaximized();
}
/*                                                                                                 */
void MainWindow::tabViewToggled(const bool &toggled)
{
    if(toggled)
        m_mdiArea->setViewMode(QMdiArea::TabbedView);
    else
        m_mdiArea->setViewMode(QMdiArea::SubWindowView);
}
/*                                                                                                 */
MainWindow::~MainWindow()
{
    //QSettings settings;
    //settings.setValue("TabbedView",m_mdiArea->viewMode());
}
/*                                                                                                 */