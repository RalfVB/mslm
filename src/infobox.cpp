#include "infobox.h"
/*                                                                                                 */
InfoBox::InfoBox(const QString &label,QWidget *parent) : QWidget(parent)
{
    m_layout=new QHBoxLayout(this);
    setLayout(m_layout);


    m_label=new QLabel(this);
    m_label->setText(label);
    m_label->setFrameStyle(QFrame::Panel|QFrame::Raised);

    m_lineEdit=new QLineEdit(this);

    m_layout->addWidget(m_label);
    m_layout->addWidget(m_lineEdit);

}
/*                                                                                                 */