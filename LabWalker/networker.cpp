#include "networker.h"

NetWorker::NetWorker()
{
	mSock = new tcp::socket(io_service);
	mResolver = new tcp::resolver(io_service);
}

void NetWorker::SetHostWithPort(const std::string &iHost, const std::string &iPort)
{
	mHostAddress = iHost;
	mHostPort = iPort;
}

bool NetWorker::Connect()
{
	boost::asio::connect(*mSock, mResolver->resolve({ mHostAddress.c_str(), mHostPort.c_str() }));
}

void NetWorker::Disconnect()
{

}

int NetWorker::SendAndReceive(std::string, std::string *)
{

}
