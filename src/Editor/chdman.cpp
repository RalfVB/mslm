#include "chdman.h"
/*                                                                                                 */
CHDMan::CHDMan(QObject *parent):QProcess(parent)
{
    setProgram("chdman");
}
/*                                                                                                 */