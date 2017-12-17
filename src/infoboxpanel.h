#ifndef INFOBOXPANEL_H
#define INFOBOXPANEL_H
/*                                                                                                 */
#include "infobox.h"
#include <QWidget>
#include <QVBoxLayout>
/*                                                                                                 */
class InfoBoxPanel : public QWidget
{
    Q_OBJECT
public:
    explicit InfoBoxPanel(QWidget *parent = nullptr);

private:
    QVBoxLayout *m_layout;
    InfoBox *m_nameBox;
    InfoBox *m_descriptionBox;
    InfoBox *m_yearBox;
    InfoBox *m_publisherBox;
};
/*                                                                                                 */
#endif