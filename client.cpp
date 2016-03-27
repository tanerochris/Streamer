#include<iostream>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<netdb.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include "include/commands.h"
#define MAXHOSTNAME 256

using namespace std;

class Client{
	private :
	int    clientHandle;
	int    portNumber = 8080;
	struct sockaddr_in remoteSockAdress;
	struct hostent *hPtr;
	char   remoteHostName[MAXHOSTNAME + 1];
	int    connection;
 	public:
	Client(){
       
		clientSetup();		
	}
	void clientSetup(){
		
    	try{  char array[] = {'l','o','c','a','l','h','o','s','t','\0'};
               strcpy(remoteHostName,array);
			 clientHandle = createSocket();
				if(!clientHandle){
                  throw "Could not create socket";  
                }else { cout<<"socket created "<<endl;}
                
				bzero(&remoteSockAdress,sizeof(sockaddr_in));
				
				if((hPtr = gethostbyname(remoteHostName)) == NULL){
					   throw "System DNS resolution not configured properly."; 
					}
				//loading system information for socket server into data structures
				memcpy((char *)&remoteSockAdress.sin_addr,hPtr->h_addr,hPtr->h_length);
				remoteSockAdress.sin_family = AF_INET;
				remoteSockAdress.sin_port = htons((u_short)portNumber);
				  connection = connectToServer();
				if(connection < 0 ){
					perror("connect");	   
					throw "could not connect to server";
				}
						
		}catch(const char* msg){
			cerr<<msg<<endl;
			exit(EXIT_FAILURE);
		}

	}
 	 int connectToServer(){
		 int conn = connect(clientHandle,(struct sockaddr*)&remoteSockAdress ,sizeof(struct sockaddr));
		
			return conn;		
		} 
	 int createSocket(){
		 int socket_id  =  socket(AF_INET,SOCK_STREAM,IPPROTO_IP);		
		 if(socket_id<0){
				return 0;
			} else return socket_id;

	}
friend command(string  commandLine);
	 void communicate(){
			//we connect to the server
            string command;			
			int bytesRead;	
			char buffer[512];
            strcpy(buffer,"CONNECT me please");
			send(clientHandle,buffer,strlen(buffer)+1,0);
			char buf[512];
			bytesRead = recv(clientHandle,buf,512,0);
			buf[bytesRead] = (char)NULL;
			cout<<buf<<endl;
			while(1){
				string commandLine;
                getline(cin,commandLine);
			    command(commandLine);
			}
		}
};
int main(){
Client client = Client();
    client.communicate();
	
return 0;

}
void command(string  commandLine){
   //we get the first word
  


}
