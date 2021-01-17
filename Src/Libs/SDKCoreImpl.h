#ifndef SDKCOREIMPL_H
#define SDKCOREIMPL_H

#include <QObject>
#include "SDKStruct.h"

namespace Internal{
class SDKCoreImpl : public QObject
{
    Q_OBJECT
public:
    SDKCoreImpl();

public Q_SLOTS:
    int addNum( const DS_Request &request, DS_Request& response);
};

} // namespace Internal

#endif // SDKCOREIMPL_H
