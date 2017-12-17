#ifndef SOURCEFILESVIEW_H
#define SOURCEFILESVIEW_H
/*                                                                                                 */
#include "sourcefilesmodel.h"
#include <QTableView>
/*                                                                                                 */
class SourceFilesView : public QTableView
{
    Q_OBJECT
public:
    explicit SourceFilesView(QWidget *parent = nullptr);


};
/*                                                                                                 */
#endif