#ifndef EDITORWINDOW_H
#define EDITORWINDOW_H
/*                                                                                                 */
#include "infoboxpanel.h"
#include "sourcefilesview.h"
#include "destfilesview.h"


//#include "sourcefilesmodel.h"
//#include "destfilesmodel.h"

#include <QAction>
#include <QFileDialog>
#include <QFileInfo>
#include <QProcess>
#include <QTableView>
#include <QHeaderView>
#include <QToolBar>
/*                                                                                                 */
class EditorWindow : public QWidget
{
    Q_OBJECT
public:
    explicit EditorWindow(QWidget *parent = nullptr);

private:
    QProcess *m_chdProcess;
    QProcess *m_infoProcess;
    QByteArray fileChecksum(const QString &fileName, QCryptographicHash::Algorithm hashAlgorithm);
    QString m_fileName;
    QString m_chdFile;
    InfoBoxPanel *m_infoBoxPanel;
    QVBoxLayout *m_layout;




    SourceFilesView *m_sourceFilesTableView;
    //SourceFilesModel *m_sourceFilesModel;

    DestFilesView *m_destFilesTableView;
    //DestFilesModel *m_destFilesModel;

    //QTableView *m_sourceFilesTableView;
    //QTableView *m_destFilesTableView;


    QAction *m_addFile;
    QAction *m_removeFile;
    QToolBar *m_toolBar;
    QAction *m_convertToChd;

private slots:
    void convert(const bool &triggered);


    void chdmanStarted();
    void chdProcessFinished(const int &exitCode,QProcess::ExitStatus status);
    void addFile(bool trig);
    void removeFile();
};
/*                                                                                                 */
#endif