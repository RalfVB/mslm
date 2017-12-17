#include "destfilesview.h"
/*                                                                                                 */
DestFilesView::DestFilesView(QWidget *parent):QTableView(parent)
{
    setModel(new DestFilesModel(this));
}
/*                                                                                                 */