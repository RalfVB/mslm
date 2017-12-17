#include "editorwindow.h"
/*                                                                                                 */
EditorWindow::EditorWindow(QWidget *parent):QWidget(parent)
{
    setWindowFlag(Qt::Dialog);
    setWindowModality(Qt::WindowModal);
    setWindowTitle("Add software");
    m_layout=new QVBoxLayout(this);
    setLayout(m_layout);

    m_toolBar=new QToolBar(this);

    m_addFile=new QAction(QIcon::fromTheme("list-add"),"Add file",this);
    //m_addFile->setIcon(QIcon::fromTheme("list-add"));

    addAction(m_addFile);
    connect(m_addFile,SIGNAL(triggered(bool)),this,SLOT(addFile(bool)));

    m_removeFile=new QAction(QIcon::fromTheme("list-remove"),"Remove file",this);
    addAction(m_removeFile);

    m_convertToChd=new QAction(QIcon::fromTheme("view-refresh"),"Convert",this);
    connect(m_convertToChd,SIGNAL(triggered(bool)),this,SLOT(convert(bool)));
    //m_convertToChd->setCheckable(false);
    addAction(m_convertToChd);


    //m_toolBar->addAction(m_addFile);
    //m_toolBar->addAction(m_removeFile);



    m_sourceFilesTableView=new SourceFilesView(this);
    //m_sourceFilesModel=new SourceFilesModel(this);
    //m_sourceFilesTableView->setModel(m_sourceFilesModel);

    //m_sourceFilesTableView->horizontalHeader()->setSectionResizeMode(4,QHeaderView::Fixed);

    m_destFilesTableView=new DestFilesView(this);
    //m_destFilesModel=new DestFilesModel(this);
    //m_destFilesTableView->setModel(m_destFilesModel);


    m_infoBoxPanel=new InfoBoxPanel(this);
    m_layout->addWidget(m_toolBar);
    m_layout->addWidget(m_sourceFilesTableView);
    m_layout->addWidget(m_destFilesTableView);
    m_layout->addWidget(m_infoBoxPanel);

    m_toolBar->addActions(actions());
}
/*                                                                                                 */
void EditorWindow::chdProcessFinished(const int &exitCode,QProcess::ExitStatus status)
{
    switch(status){
    case QProcess::NormalExit:{
        m_infoProcess=new QProcess(this);
        m_infoProcess->setProgram("chdman");
        QStringList args;
        args << "info" << "-i" << m_chdFile;
        m_infoProcess->setArguments(args);
        if(m_infoProcess->open(QProcess::ReadOnly)){
            while(!m_infoProcess->waitForFinished());
            QByteArray s=m_infoProcess->readAllStandardOutput();
            s = s.mid(s.indexOf("SHA1")+5);
            s.truncate(s.indexOf("\n"));
            //qDebug() << "CHD SHA1:" << s.trimmed();



            //int idx=s.indexOf("SHA1")+5;
            //int idx2=s.indexOf("\n",idx);

            //qDebug() << "Index:" << s.mid(idx,s.indexOf("\n",idx2-idx));

            //            foreach(QString line,s.split("\n")){
            //                qDebug() << "Out:" << line;
            //            }

        }


        break;}
    case QProcess::CrashExit:break;

    }


    //m_chdProcess->cl
    if(m_chdProcess->isOpen()){
        //qDebug() << m_chdProcess->program() << "is open";
        m_chdProcess->close();
        //qDebug() << m_chdProcess->isOpen();
    }
}
/*                                                                                                 */
//void EditorWindow::readStandardOutput()
//{
//    qDebug() << "C:" << m_chdProcess->readAllStandardOutput();

//}
/*                                                                                                 */
QByteArray EditorWindow::fileChecksum(const QString &fileName, QCryptographicHash::Algorithm hashAlgorithm)
{
    QFile f(fileName);
    if (f.open(QFile::ReadOnly)) {
        QCryptographicHash hash(hashAlgorithm);
        if (hash.addData(&f)) {
            return hash.result();
        }
    }
    return QByteArray();
}
/*                                                                                                 */
void EditorWindow::addFile(bool trig)
{
    m_fileName=QFileDialog::getOpenFileName(this,"Add file","/emu/!REDUMP","Disc images (*.cue *.iso)");
    if(!m_fileName.isEmpty()){
        qobject_cast<SourceFilesModel*>(m_sourceFilesTableView->model())->addFile(m_fileName);

        //m_sourceFilesTableView->model()->addFile(m_fileName);
    }
}
/*                                                                                                 */
void EditorWindow::removeFile()
{
    qDebug() << "Removing file!";
}
/*                                                                                                 */
void EditorWindow::convert(const bool &triggered)
{
    m_chdProcess=new QProcess(this);


    //    for(int i=0;i<m_sourceFilesModel->rowCount();i++){

    //        qDebug() << "Checking row " << i;

    //        qDebug() << m_sourceFilesModel->data(m_sourceFilesModel->index(0,0)).toString();

    //    }



    //    qDebug() << "SOURCE FILES:" << m_sourceFilesModel->rowCount();

    //    m_chdProcess->setProgram("chdman");
    //    QStringList args;

    //args << "createcd" << "-i" << info.absoluteFilePath() << "-o" << m_chdFile;
    //m_chdProcess->setArguments(args);

    //    if(m_chdProcess->open(QProcess::ReadOnly)){
    //        connect(m_chdProcess,SIGNAL(started()),this,SLOT(chdmanStarted()));
    //        connect(m_chdProcess,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(chdProcessFinished(int,QProcess::ExitStatus)));
    //    }
}
/*                                                                                                 */
void EditorWindow::chdmanStarted()
{
    //qDebug() << "Converting to CHD...";
}


//        //        m_chdFile="/download/"+info.baseName().toLower()+".chd";

//}