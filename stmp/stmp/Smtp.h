
#ifndef __SMTP_H__
#define __SMTP_H__

#ifdef _MSC_VER
#	include <winsock2.h>
#	pragma comment(lib, "Ws2_32.lib")
#else
#	include <unistd.h>
#	include <sys/errno.h>
#	include <sys/fcntl.h>
#	include <sys/types.h>
#	include <sys/socket.h>
#	include <netinet/in.h>
#	include <netinet/tcp.h>
#	include <arpa/inet.h>
#	include <netdb.h>
#	include <net/if.h>
#	include <sys/ioctl.h>
#endif
#include <iostream>
#include <list>
using namespace std;
const int MAX_EMAIL_MESSAGE_LEN = 1024;//Set Message the Max Length
static const char base64Char[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

class CSmtp
{
public:
	CSmtp(void);
	/*CSmtp(port,smtp_addr£¬server_E-mail£¬authorization code £¬Send to target addr£¬title£¬content);*/
	CSmtp(int port,string srvDomain,string userName,string password,string targetEmail,string emailTitle,string content);
public:
	~CSmtp(void);
public:
	int port;
public:
	string domain;
	string user;
	string pass;
	string targetAddr;
	string title;
	string content;
public:
	char buff[MAX_EMAIL_MESSAGE_LEN + 1];
	int buffLen;
	int sockClient;
public:
	bool CreateConn();
	bool Send(string& strMessage);
	bool Recv();
	void FormatEmailHead(string& strEmail);
	int Login();
	bool SendEmailHead();
	bool SendTextBody();
	bool SendEnd();
public:
	void SetSrvDomain(string& strDomain) { this->domain = strDomain; }
	void SetUserName(string& strUser) { this->user = strUser; }
	void SetPass(string& strPass) { this->pass = strPass; }
	void SetTargetEmail(string& strTargetAddr) { this->targetAddr = strTargetAddr; }
	void SetEmailTitle(string& strTitle) { this->title = strTitle; }
	void SetContent(string& strContent) { this->content = strContent; }
	void SetPort(int nPort) { this->port = nPort; }
	int SendEmail_Ex();
	char* base64Encode(char const* pOrigSigned, unsigned origLength);
};
#endif // !__SMTP_H__
