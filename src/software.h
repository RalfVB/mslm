#ifndef SOFTWARE_H
#define SOFTWARE_H
/*                                                                                                 */
#include <QString>
/*                                                                                                 */
class Software
{
public:
    Software(QString name);
    QString name()const{return m_name;}

private:
    QString m_name;
};
/*                                                                                                 */
#endif