#include "sourcefilesview.h"
/*                                                                                                 */
SourceFilesView::SourceFilesView(QWidget *parent):QTableView(parent)
{
    setModel(new SourceFilesModel(this));
}
/*                                                                                                 */