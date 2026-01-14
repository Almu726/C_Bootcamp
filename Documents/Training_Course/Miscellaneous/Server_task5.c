#include <stdio.h>
#include <string.h>    
#include <unistd.h>    
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

int main(){
    int sd = socket(AF_INET, SOCK_DGRAM, 0);
    
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5000);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(sd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    printf("Server waiting for client registration...\n");

    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[1024];

    recvfrom(sd, buffer, sizeof(buffer), 0 ,(struct sockaddr*)&client_addr ,&client_len );

    printf("Client registered. Starting time updates...\n");

        

    while (1) {

        time_t now = time(NULL);          
        struct tm *t = localtime(&now);  

        char date_str[128];
        strftime(date_str, sizeof(date_str), "%Y-%m-%d %H:%M:%S", t);
        // formatted time into a string

         sendto(sd, date_str, strlen(date_str), 0, (struct sockaddr*)&client_addr, client_len);

        printf("Sent time to client: %s\n", date_str);
        sleep(5); 
    }

    close(sd);
    return 0;
}












