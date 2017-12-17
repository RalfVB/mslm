#include "fileview.h"
/*                                                                                                 */
FileView::FileView(QString file,QWidget *parent):QWidget(parent)
{
    m_layout=new QVBoxLayout(this);
    m_layout->setMargin(3);
    setLayout(m_layout);
    m_toolBar=new QToolBar(this);

    m_addSoftware=new QAction(QIcon::fromTheme("list-add"),"Add software",this);
    connect(m_addSoftware,SIGNAL(triggered(bool)),this,SLOT(addSoftwareTriggered(bool)));
    addAction(m_addSoftware);

    m_removeSoftware=new QAction(QIcon::fromTheme("list-remove"),"Remove software",this);
    //connect(m_removeSoftware,SIGNAL(triggered(bool)),this,SLOT(removeSoftwareTriggered(bool)));
    addAction(m_removeSoftware);

    m_fileModel=new FileModel(file,this);
    m_treeView=new QTreeView(this);
    m_treeView->setModel(m_fileModel);
    m_treeView->setItemsExpandable(false);
    m_layout->addWidget(m_toolBar);
    m_layout->addWidget(m_treeView);
    connect(m_fileModel,SIGNAL(modelReset()),this,SLOT(modelReset()));
    m_toolBar->addActions(actions());
}
/*                                                                                                 */
void FileView::modelReset()
{
    setWindowTitle(m_fileModel->name()+" ("+m_fileModel->description()+")");
}
/*                                                                                                 */
void FileView::addSoftwareTriggered(const bool &triggered)
{
    m_editorWindow=new EditorWindow(this);
    m_editorWindow->setWindowFlag(Qt::Window);
    m_editorWindow->show();
}
/*                                                                                                 */