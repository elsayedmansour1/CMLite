#include "../../source/wrapperLibInterface/QDBusInterfaceWrapperInterface.hpp"

#include<gmock/gmock.h>

class MockQDBusInterfaceWrapperInterface : public QDBusInterfaceWrapperInterface
{
private:
    /* data */
public:
    MockQDBusInterfaceWrapperInterface(){};
    virtual ~MockQDBusInterfaceWrapperInterface()= default;

    MOCK_METHOD(bool , isValid , (), (override));
    MOCK_METHOD(QDBusReply<QString> , call , (const QString& method), (override));

    // Helper method to create valid responses  
    static QDBusMessage createMockResponse(const QVariant& data) {
        QDBusMessage msg;
        msg << data;
        return msg;
    }
};

