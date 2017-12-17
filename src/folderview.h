#ifndef FOLDERVIEW_H
#define FOLDERVIEW_H
/*                                                                                                 */
#include <QListView>
#include <QFileSystemModel>
#include <QVBoxLayout>
/*                                                                                                 */
class FolderView : public QWidget
{
    Q_OBJECT
public:
    explicit FolderView(QWidget *parent = nullptr);

private:
    QFileSystemModel *m_listModel;
    QListView *m_listView;
    QVBoxLayout *m_layout;

private slots:
    void activated(QModelIndex index);
    void menu(QPoint loc);

signals:
    void openFile(QString file);
};
/*                                                                                                 */
#endif