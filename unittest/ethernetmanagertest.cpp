#include "gtest/gtest.h"
#include "../source/ethernetmanager/ethernetmanager.hpp"
#include "mocking/MockQDBusInterfaceWrapperInterface.hpp"
#include "QDebug"
#include <QtTest/QTest> 
#include <QSignalSpy>
#include <QCoreApplication>



class ethernetHelper : public ethernetmanager{
public:
    ethernetHelper(MockQDBusInterfaceWrapperInterface* mockDbusInterface)
    :ethernetmanager(mockDbusInterface)
    {

    }
};

class ethernetmanagertest : public ::testing::Test
{
private:

public:
    ethernetmanagertest(/* args */);
    ~ethernetmanagertest();
    MockQDBusInterfaceWrapperInterface* m_pMockdbusInterface;
    ethernetHelper* m_ethManager;
    
    virtual void SetUp() {
        qInfo() << "### welcome i'm in setup ####";
        m_pMockdbusInterface = new MockQDBusInterfaceWrapperInterface();
        m_ethManager = new ethernetHelper(m_pMockdbusInterface);
    }

    virtual void TearDown() {
        qInfo() << "### welcome i'm in TearDown ####";
        delete m_pMockdbusInterface;
        delete m_ethManager;
    }
};

ethernetmanagertest::ethernetmanagertest(/* args */)
{
    qInfo() << "############################";
}

ethernetmanagertest::~ethernetmanagertest()
{
}

TEST_F(ethernetmanagertest , test_fetchingEthernetInfo){
    /* data */
    QVariantList args;
    QString result(
        "{"
        "\"DNS\": ["
        "    {"
        "        \"Family\":2,"
        "        \"Address\":[192,168,1,1],"
        "        \"ConfigSource\":\"DHCPv4\","
        "        \"ConfigProvider\":[192,168,1,1]"
        "    },"
        "    {"
        "        \"Family\":10,"
        "        \"Address\":[254,128,0,0,0,0,0,0,44,25,37,195,110,67,242,78],"
        "        \"ConfigSource\":\"NDisc\","
        "        \"ConfigProvider\":[254,128,0,0,0,0,0,0,44,25,37,195,110,67,242,78]"
        "    }"
        "],"
        "\"Addresses\": [{"
        "    \"Family\":2,"
        "    \"Address\":[192,168,1,222],"
        "    \"Broadcast\":[192,168,1,255],"
        "    \"PrefixLength\":24,"
        "    \"Scope\":0,"
        "    \"ScopeString\":\"global\","
        "    \"Flags\":0,"
        "    \"FlagsString\":null,"  // null without quotes
        "    \"PreferredLifetimeUsec\":86428183769,"
        "    \"ValidLifetimeUsec\":86428183769,"
        "    \"ConfigSource\":\"DHCPv4\","
        "    \"ConfigState\":\"configured\","
        "    \"ConfigProvider\":[192,168,1,1]"
        "}"  
        "],"// Close array
        "\"Routes\": [{"
        "    \"Family\": 2,"
        "    \"Destination\": [0,0,0,0],"
        "    \"DestinationPrefixLength\": 0,"
        "    \"Gateway\": [192,168,1,1],"
        "    \"Scope\": 0,"
        "    \"ScopeString\": \"global\","
        "    \"Protocol\": 3,"
        "    \"ProtocolString\": \"boot\","
        "    \"Type\": 1,"
        "    \"TypeString\": \"unicast\","
        "    \"Priority\": 0,"
        "    \"Table\": 254,"
        "    \"TableString\": \"main(254)\","
        "    \"Preference\": 0,"
        "    \"Flags\": 0,"
        "    \"FlagsString\": \"\","
        "    \"ConfigSource\": \"DHCPv4\","
        "    \"ConfigState\": \"configured\""
        "}]"
        "}"
        );
    args << QVariant::fromValue(result);  
    QDBusMessage reply;
    reply.setArguments(args);
    
    EXPECT_CALL(*m_pMockdbusInterface, call(QString("Describe")))
        .Times(1)
        .WillOnce(testing::Return(QDBusReply<QString>(reply)));
    QCoreApplication::processEvents();
    // QTest::qWait(10000); // Milliseconds
    ASSERT_EQ(m_ethManager->getIPv4forEthernet(), "192.168.1.222");
    ASSERT_EQ(m_ethManager->getIPv4GatewayforEthernet(), "192.168.1.1");
    ASSERT_EQ(m_ethManager->getIPv4DNSforEthernet(), "192.168.1.1");
}
