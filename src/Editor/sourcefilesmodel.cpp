#include "sourcefilesmodel.h"
/*                                                                                                 */
SourceFilesModel::SourceFilesModel(QObject *parent):QStandardItemModel(parent)
{
    setColumnCount(4);
    setHorizontalHeaderLabels(QStringList() << "File" << "Size" << "CRC" << "SHA1");
}
/*                                                                                                 */
void SourceFilesModel::addFile(const QString &file)
{
    m_sizeWatcher=new QFutureWatcher<qint64>(this);
    connect(m_sizeWatcher,SIGNAL(finished()),this,SLOT(sizeReady()));
    m_sizeWatcher->setFuture(QtConcurrent::run(this,&SourceFilesModel::sizeThread,file));

    m_crcWatcher=new QFutureWatcher<QByteArray>(this);
    connect(m_crcWatcher,SIGNAL(finished()),this,SLOT(crcReady()));
    m_crcWatcher->setFuture(QtConcurrent::run(this,&SourceFilesModel::crcThread,file));

    m_sha1Watcher=new QFutureWatcher<QByteArray>(this);
    connect(m_sha1Watcher,SIGNAL(finished()),this,SLOT(sha1Ready()));
    m_sha1Watcher->setFuture(QtConcurrent::run(this,&SourceFilesModel::sha1Thread,file));

    QStandardItem *item=new QStandardItem(file.mid(file.lastIndexOf("/")+1));
    appendRow(item);
}
/*                                                                                                 */
extern qint64 SourceFilesModel::sizeThread(const QString &file)
{
    QFileInfo info(file);
    return info.size();
}
/*                                                                                                 */
void SourceFilesModel::sizeReady()
{
    QStandardItem *item=new QStandardItem(QString::number(m_sizeWatcher->result()));
    this->setItem(0,1,item);
    m_sizeWatcher->deleteLater();
}
/*                                                                                                 */
extern QByteArray SourceFilesModel::crcThread(const QString &file)
{
    return "crc";
}
/*                                                                                                 */
void SourceFilesModel::crcReady()
{
    QStandardItem *item=new QStandardItem(QString(m_crcWatcher->result()));
    this->setItem(0,2,item);
    m_crcWatcher->deleteLater();
}
/*                                                                                                 */
extern QByteArray SourceFilesModel::sha1Thread(const QString &file)
{
    QFile f(file);
    if(f.open(QFile::ReadOnly)){
        QCryptographicHash hash(QCryptographicHash::Sha1);
        if(hash.addData(&f)){
            return hash.result().toHex();
        }
        f.close();
    }
    return QByteArray();
}
/*                                                                                                 */
void SourceFilesModel::sha1Ready()
{
    QStandardItem *item=new QStandardItem(QString(m_sha1Watcher->result()));
    this->setItem(0,3,item);
    m_sha1Watcher->deleteLater();
}
/*                                                                                                 */