#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

char* state = "Accepted";


void set_state(char command){
      //create function to turn on and off pararl port output acourding to command
      printf("Set State\n");
}

char get_state(){
      char * command = "<command>"
      //create function to turn on and off pararl port output acourding to command
      printf("Get State\n");
      return command
}


int main( int argc, char *argv[] ) {
   int sockfd, newsockfd, portno, clilen;
   char buffer[8];
   struct sockaddr_in serv_addr, cli_addr;
   int  n;
   
   /* Declear a socket */
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   
   if (sockfd < 0) {
      perror("ERROR opening socket");
      exit(1);
   }
   
   /* Init Socket*/
   bzero((char *) &serv_addr, sizeof(serv_addr));
   portno = 5002;
   
   serv_addr.sin_family = AF_INET;
   serv_addr.sin_addr.s_addr = INADDR_ANY;
   serv_addr.sin_port = htons(portno);
   
   /* Bind the scket*/
   if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
      perror("ERROR on binding");
      exit(1);
   }
           listen(sockfd,5);
         clilen = sizeof(cli_addr);
      
        
         newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
         
         if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
         }
         
         
         bzero(buffer,10);
         while(1){
            n = read( newsockfd,buffer,10);
         
            if (n < 0) {
               perror("ERROR reading from socket");
               exit(1);
            }
            
            printf("%s\n",buffer);
            n = write(newsockfd,state,8);
            
            if (n < 0) {
               perror("ERROR writing to socket");
               exit(1);
            }
         }
   return 0;
}