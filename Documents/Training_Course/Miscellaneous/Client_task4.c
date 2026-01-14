#include <stdio.h>
#include <string.h>     // for strlen()
#include <unistd.h>     // for close()
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {

    int sd = socket(AF_INET, SOCK_STREAM, 0);
}