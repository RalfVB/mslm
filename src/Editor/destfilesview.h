#ifndef DESTFILESVIEW_H
#define DESTFILESVIEW_H
/*                                                                                                 */
#include "destfilesmodel.h"
#include <QTableView>
/*                                                                                                 */
class DestFilesView : public QTableView
{
    Q_OBJECT
public:
    explicit DestFilesView(QWidget *parent = nullptr);
};
/*                                                                                                 */
#endif