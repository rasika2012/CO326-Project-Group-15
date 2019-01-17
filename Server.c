#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

char state[] = "1100";
int int_state =0;

void set_port(){
   //int state eka d out register ekata denna one;
   printf("Get State\n");
}

void set_state(char* command){
   int i;
   int_state=0;
   int k=1;
   for(i=0;i<strlen(command);i++){
      if(command[i]=='1')
         int_state+=k;
      k=k*2; 
   }
   strcpy(state,command);
   
   printf("Set State:%s  register:%d\n",command,int_state);
   //create function to turn on and off pararl port output acourding to command
   //State eka pararal port ekata setwenna
   set_port();


}



int main( int argc, char *argv[] ) {
   int sockfd, newsockfd, portno, clilen;
   char buffer[5];
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
   int pass=1;
   portno = 5002;
   printf("port_no: 5002\n");
   while(pass){
      pass=0;
      
      
      serv_addr.sin_family = AF_INET;
      serv_addr.sin_addr.s_addr = INADDR_ANY;
      serv_addr.sin_port = htons(portno);
      
      /* Bind the scket*/
      if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
         perror("ERROR on binding try with 5001");
         pass=1;
         portno=5001;
         //exit(1);
      }
   }
         listen(sockfd,10);
         clilen = sizeof(cli_addr);
      
        
         newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
         
         if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
         }
         
         
         bzero(buffer,4);
         while(1){
            n = read( newsockfd,buffer,4);
         
            if (n < 0) {
               perror("ERROR reading from socket");
               exit(1);
            }
            
            printf("%s\n",buffer);
            set_state(buffer);
            //get_state();
            n = write(newsockfd,state,4);
            
            if (n < 0) {
               perror("ERROR writing to socket");
               exit(1);
            }
         }
   return 0;
}
