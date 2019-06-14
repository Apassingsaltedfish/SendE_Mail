#include "Smtp.h"
#include <iostream>
using namespace std;
#define SMTP_PORT               25                          /*smtp_port*/
#define SMTP_SERVER_ADDR       "smtp.163.com"				/*smtp_addr*/
#define MAIL_SERVER_ADDR       "£¿£¿£¿@163.com"				/*server_E-mail*/		
#define MAIL_SERVER_PASSWORD   "***********"			    /*smtp authorization code*/    /*Set your authorization code*/

int main()
{		/*CSmtp(port,smtp_addr£¬server_E-mail£¬authorization code £¬Send to target addr£¬title£¬content);*/															
	CSmtp smtp(SMTP_PORT,SMTP_SERVER_ADDR,MAIL_SERVER_ADDR,MAIL_SERVER_PASSWORD,"???@163.com","title","content");
	if (smtp.SendEmail_Ex())
	{
		if (smtp.SendEmail_Ex() == 1)cout << "error1: Because the network is not smooth, send failed!" << endl;
		if (smtp.SendEmail_Ex() == 2)cout << "error2: user name, please check!" << endl;
		if (smtp.SendEmail_Ex() == 3)cout << "error3: User password error, please check!" << endl;
	  //if (smtp.SendEmail_Ex() == 4)cout << "error4: Please check whether the attached directory is correct and whether the file exists!" << endl;
	}
	return 0;
}
