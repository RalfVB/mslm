#include "filemodel.h"
/*                                                                                                 */
FileModel::FileModel(QString file,QObject *parent):QAbstractItemModel(parent)
{
    m_file=file;
    readFile();
}
/*                                                                                                 */
QHash<int, QByteArray> FileModel::roleNames() const
{
    QHash<int,QByteArray> hash;
    hash[0]="Name";
    hash[1]="Description";
    return hash;
}
/*                                                                                                 */
QVariant FileModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid()){
        if(role==Qt::DisplayRole)
        return m_vector.at(index.row())->name();;
    }
    //return m_results.at(index.row()).at(role);
    return QVariant();
}
/*                                                                                                 */
void FileModel::readFile()
{
    m_futureWatcher=new QFutureWatcher<QVector<Software*> >(this);
    connect(m_futureWatcher,SIGNAL(finished()),this,SLOT(threadFinished()));

    m_futureWatcher->setFuture(QtConcurrent::run(this,&FileModel::thread));
}
/*                                                                                                 */
extern QVector<Software*> FileModel::thread()
{
    QVector<Software*> v;
    QFile f("/mame/hash/"+m_file);
    if(f.exists()){
        if(f.open(QFile::ReadOnly)){
            QXmlStreamReader reader;
            reader.setDevice(&f);
            if(reader.readNextStartElement() && reader.name()=="softwarelist"){
                QXmlStreamAttributes a=reader.attributes();
                m_name=a.value("name").toString();
                m_description=a.value("description").toString();

                while(!reader.atEnd()){
                    reader.readNext();
                    if(reader.isStartElement()){
                        if(reader.name()=="software"){
                            QXmlStreamAttributes attr=reader.attributes();
                            v.append(new Software(attr.value("name").toString()));
                        }
                    }
                    else if(reader.isEndElement()){
                        if(reader.name()=="software"){
                        }
                    }
                }
            }
            else
                qDebug() << m_file << " is not a software list?";
            f.close();
        }
    }
    else
        qDebug() << m_file << "does not exist";

    return v;
}
/*                                                                                                 */
void FileModel::threadFinished()
{
    beginResetModel();
    m_vector=m_futureWatcher->result();
    endResetModel();
    m_futureWatcher->deleteLater();
    //emit name(m_name);
    //emit description(m_description);
}
/*                                                                                                 */
FileModel::~FileModel()
{
}
/*                                                                                                 */