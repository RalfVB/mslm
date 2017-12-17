#ifndef INFOBOX_H
#define INFOBOX_H
/*                                                                                                 */
#include <QWidget>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QLabel>
/*                                                                                                 */
class InfoBox : public QWidget
{
    Q_OBJECT
public:
    explicit InfoBox(const QString &label,QWidget *parent = nullptr);

private:
    QLineEdit *m_lineEdit;
    QHBoxLayout *m_layout;
    QLabel *m_label;
};
/*                                                                                                 */
#endif