#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(){

     char *hello="hello";
     int network_socket;
     network_socket=socket(AF_INET, SOCK_STREAM, 0);
     
     struct sockaddr_in server_address;
     server_address.sin_family=AF_INET;
     server_address.sin_port=htons(9002);
     server_address.sin_addr.s_addr=inet_addr("10.0.2.15");
     
     int stat=connect(network_socket,(struct sockaddr*) &server_address,sizeof(server_address));
     
     if(stat== -1){
        printf("error");
     } 
       
     char server_response[256];
     
     send(network_socket, hello, strlen(hello), 0 );
     
     recv(network_socket, &server_response, sizeof(server_response),0);
     
     printf("yeay,%s", server_response);
     
     close(network_socket);
     
     return 0;
     
     }
