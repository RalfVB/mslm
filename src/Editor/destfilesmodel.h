#ifndef DESTFILESMODEL_H
#define DESTFILESMODEL_H
/*                                                                                                 */
#include <QStandardItemModel>
/*                                                                                                 */
class DestFilesModel : public QStandardItemModel
{
    Q_OBJECT
public:
    explicit DestFilesModel(QObject *parent = nullptr);
};
/*                                                                                                 */
#endif