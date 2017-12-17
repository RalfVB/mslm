#ifndef FILEVIEW_H
#define FILEVIEW_H
/*                                                                                                 */
#include "Editor/editorwindow.h"
#include "filemodel.h"
#include <QAction>
#include <QTreeView>
#include <QToolBar>
#include <QVBoxLayout>
#include <QIcon>
/*                                                                                                 */
class FileView : public QWidget
{
    Q_OBJECT
public:
    explicit FileView(QString file,QWidget *parent = nullptr);

private:
    QVBoxLayout *m_layout;
    QToolBar *m_toolBar;
    QAction *m_addSoftware;
    QAction *m_removeSoftware;
    QTreeView *m_treeView;
    FileModel *m_fileModel;
    EditorWindow *m_editorWindow;

private slots:
    void modelReset();
    void addSoftwareTriggered(const bool &triggered);
};
/*                                                                                                 */
#endif