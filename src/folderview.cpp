#include "folderview.h"
/*                                                                                                 */
FolderView::FolderView(QWidget *parent):QWidget(parent)
{
    m_layout=new QVBoxLayout(this);
    m_layout->setMargin(3);
    setLayout(m_layout);

    m_listView=new QListView(this);

    m_listModel=new QFileSystemModel(this);
    m_listModel->setRootPath("/");
    m_listModel->setNameFilters(QStringList("*.xml"));
    m_listView->setModel(m_listModel);
    m_listView->setRootIndex(m_listModel->index("/mame/hash"));
    connect(m_listView,SIGNAL(activated(QModelIndex)),this,SLOT(activated(QModelIndex)));
    //connect(m_listView,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(menu(QPoint)));
    m_layout->addWidget(m_listView);
}
/*                                                                                                 */
void FolderView::activated(QModelIndex index)
{
    emit openFile(m_listModel->data(index).toString());
}
/*                                                                                                 */
void FolderView::menu(QPoint loc)
{
    //qDebug() << "Open menu on " << loc.x() << "/" << loc.y();
}
/*                                                                                                 */