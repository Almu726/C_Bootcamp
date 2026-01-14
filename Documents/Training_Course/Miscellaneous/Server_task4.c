#include <stdio.h>
#include <string.h>    
#include <unistd.h>    
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

int main(){
    int sd = socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5000);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(sd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    listen(sd,1);

    int client_sd = accept(sd, NULL, NULL);


    while (1) {

        time_t now = time(NULL);          
        struct tm *t = localtime(&now);  

        char date_str[128];
        strftime(date_str, sizeof(date_str), "%Y-%m-%d %H:%M:%S", t);
        // format time into a readable string

        if (send(client_sd, date_str, strlen(date_str), 0) < 0) {
            perror("send");
            break;
        }

        printf("Sent time to client: %s\n", date_str);

        sleep(5); 
    }

    close(client_sd);
    close(sd);
    return 0;
}












