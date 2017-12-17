#ifndef FILEMODEL_H
#define FILEMODEL_H
/*                                                                                                 */
#include "software.h"
#include <QtConcurrentRun>
#include <QAbstractItemModel>
#include <QFile>
#include <QFutureWatcher>
#include <QXmlStreamReader>
#include <QVector>
#include <QXmlStreamAttributes>
/*                                                                                                 */
class FileModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit FileModel(QString file,QObject *parent = nullptr);
    QString name(){return m_name;}
    QString description(){return m_description;}
    ~FileModel();

private:
    int columnCount(const QModelIndex &parent)const{Q_UNUSED(parent);return 1;}
    QModelIndex index(int row, int column, const QModelIndex &parent)const{Q_UNUSED(parent);return createIndex(row,column);}
    QModelIndex parent(const QModelIndex &child)const{Q_UNUSED(child);return QModelIndex();}
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent)const{Q_UNUSED(parent);return m_vector.size();}
    QHash<int, QByteArray> roleNames() const;
    QVector<Software*> m_vector;
    QFutureWatcher<QVector<Software*> > *m_futureWatcher;
    QString m_file;
    void readFile();
    QVector<Software*> thread();

    QString m_name;
    QString m_description;

private slots:
    void threadFinished();
};
/*                                                                                                 */
#endif