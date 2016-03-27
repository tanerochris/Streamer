#include<iostream>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<netdb.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#define MAXHOSTNAME 256
#define SERVERSTATUS false
//server side application
using namespace std;

class 	Server {
  private:
	int    serverHandle;
	int    clientHandle;
	int    portNumber = 8080;
	struct sockaddr_in sockAdress;
	struct sockaddr_in clientSockAdress;
	char   serHostName[MAXHOSTNAME + 1];
	socklen_t cl_size;
	struct hostent *hPtr;
	int bytesRead = 0;
	char  buffer[512];
	int  socketConnection;
    
  public:
      Server(){
	    serverIni();
  		};
		
	  void serverIni(){
		  	
             try{
                  serverHandle = createSocket();
				if(!serverHandle){
                  throw "Could not create socket";  
                }else { cout<<"socket created "<<endl;}
                bzero(&sockAdress,sizeof(sockaddr_in));
				gethostname(serHostName,MAXHOSTNAME);
				if((hPtr = gethostbyname(serHostName)) == NULL){
					   
						throw "System Hostname Misconfigured"; 
					}
				
               }catch(const char *msg){
					cerr<< msg <<endl;
                    cout<<"trying again to configure ..."<<endl;
					gethostname(serHostName,MAXHOSTNAME);
				if((hPtr = gethostbyname(serHostName)) == NULL){
					   cerr<<"Still could not configure the hostaname exiting";
						exit(EXIT_FAILURE);
					}

				}
			 sockAdress.sin_family = AF_INET;
			 sockAdress.sin_port = htons(portNumber);
			 sockAdress.sin_addr.s_addr = htonl(INADDR_ANY);
			  if(servBind()){
                
              listen(serverHandle, 1);
			cl_size = sizeof(struct sockaddr_in);
			}else{ 
                  perror("bind");
				  exit(EXIT_FAILURE);
                }
				
		}
	  bool servBind(){
      int success = bind(serverHandle,(struct sockaddr*)&sockAdress,sizeof(sockAdress));
			if(success < 0){
				return false;		
			}else return true;

			}
     void test(){
         cout<<"test passed"<<endl;

		}
     int createSocket(){
     int socket_id  =  socket(AF_INET,SOCK_STREAM,IPPROTO_IP);		
	 if(socket_id<0){
			return 0;
		} else return socket_id;

	}
	void comunication(){
	/*we read data from the clients*/
	
    for(;;){

         socketConnection = accept(serverHandle,(struct sockaddr*)&clientSockAdress,&cl_size);
				if(socketConnection < 0){
 					/*close(serverHandle);
					perror("accept");
					exit(EXIT_FAILURE);*/
                   continue;
                }
			bytesRead = recv(socketConnection,buffer,512,0);
			buffer[bytesRead] = (char)NULL;
			cout<<"Number of Bytes read"<<bytesRead<<endl;
			cout<<"Received "<<buffer<<endl;
			char buf[512];
            strcpy(buf,"Welcome to your streaming service");
			send(socketConnection,buf,strlen(buf)+1,0);
    }
    
    
	}
	friend void commandParser( const string* command);


};

int main(){
    Server server = Server();
		server.comunication();
      return 0;
}
   void commandParser(const string*){



}
