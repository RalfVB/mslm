#include "infoboxpanel.h"
/*                                                                                                 */
InfoBoxPanel::InfoBoxPanel(QWidget *parent):QWidget(parent)
{
    m_layout=new QVBoxLayout(this);
    this->setLayout(m_layout);

    m_nameBox=new InfoBox("Name",this);
    m_descriptionBox=new InfoBox("Description",this);
    m_yearBox=new InfoBox("Year",this);
    m_publisherBox=new InfoBox("Publisher",this);

    m_layout->addWidget(m_nameBox);
    m_layout->addWidget(m_descriptionBox);
    m_layout->addWidget(m_yearBox);
    m_layout->addWidget(m_publisherBox);
}
/*                                                                                                 */