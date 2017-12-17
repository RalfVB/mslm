#ifndef CHDMAN_H
#define CHDMAN_H
/*                                                                                                 */
#include <QProcess>
/*                                                                                                 */
class CHDMan : public QProcess
{
    Q_OBJECT
public:
    explicit CHDMan(QObject *parent = nullptr);
};
/*                                                                                                 */
#endif