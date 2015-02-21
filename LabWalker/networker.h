#ifndef NETWORKER_H
#define NETWORKER_H

#include <string>
#include <boost/asio.hpp>


boost::asio::io_service io_service;
using boost::asio::ip::tcp;

class NetWorker
{
public:
	NetWorker();
	void SetHostWithPort(const std::string &iHost, const std::string &iPort);
	bool Connect();
	void Disconnect();
	int SendAndReceive(std::string, std::string *);

private:
	tcp::socket *mSock;
	tcp::resolver *mResolver;
	std::string mHostAddress;
	std::string mHostPort;

};


#endif
