#ifndef SOURCEFILESMODEL_H
#define SOURCEFILESMODEL_H
/*                                                                                                 */
#include <QtConcurrentRun>
#include <QFileInfo>
#include <QFutureWatcher>
#include <QStandardItemModel>
#include <QCryptographicHash>
/*                                                                                                 */
class SourceFilesModel:public QStandardItemModel
{
    Q_OBJECT
public:
    explicit SourceFilesModel(QObject *parent = nullptr);
    void addFile(const QString &file);

private:
    QFutureWatcher<qint64> *m_sizeWatcher;
    QFutureWatcher<QByteArray> *m_crcWatcher;
    QFutureWatcher<QByteArray> *m_sha1Watcher;

    qint64 sizeThread(const QString &file);
    QByteArray crcThread(const QString &file);
    QByteArray sha1Thread(const QString &file);

private slots:
    void sizeReady();
    void crcReady();
    void sha1Ready();
};
/*                                                                                                 */
#endif