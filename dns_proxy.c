#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DOMAIN_LENGTH 256

typedef struct {
    char upstream_dns_ip[16];
    char blacklist_domains[MAX_DOMAIN_LENGTH];
    char response_for_blacklisted[20];
} DNSProxyConfig;

void process_dns_request(const char* client_request, const DNSProxyConfig* config) {
    printf("Received DNS request: %s\n", client_request);

    // Check if the domain is in the blacklist
    if (strstr(config->blacklist_domains, client_request) != NULL) {
        printf("Blacklisted domain found: %s\n", client_request);

        // Respond according to the configuration
        if (strcmp(config->response_for_blacklisted, "refused") == 0) {
            printf("Refused response sent\n");
            // Logic for refused response
        } else {
            printf("Custom IP response sent\n");
            // Logic for response with a predefined IP
        }
    } else {
        printf("Forwarding request to upstream DNS: %s\n", client_request);
        // Logic for forwarding the request to upstream DNS
    }
}

DNSProxyConfig load_config(const char* filename) {
    DNSProxyConfig config;

    // Open the configuration file for reading
    FILE* file = fopen(filename, "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read parameters from the file
    fscanf(file, "upstream_dns_ip = %s\n", config.upstream_dns_ip);
    fscanf(file, "blacklist_domains = %[^\n]\n", config.blacklist_domains);
    fscanf(file, "response_for_blacklisted = %s\n", config.response_for_blacklisted);

    // Close the file
    fclose(file);

    return config;
}

int main() {
    // Load configuration from the file with .conf extension
    DNSProxyConfig config = load_config("dns_proxy_config.conf");

    // Infinite loop to continuously accept DNS requests
    while (1) {
        char client_request[MAX_DOMAIN_LENGTH];

        // Prompt the user for a DNS request
        printf("Enter a domain name (or 'exit' to quit): ");
        scanf("%s", client_request);

        // Check if the user wants to exit
        if (strcmp(client_request, "exit") == 0) {
            printf("Exiting DNS proxy.\n");
            break;
        }

        // Process the DNS request
        process_dns_request(client_request, &config);
    }

    return 0;
}
