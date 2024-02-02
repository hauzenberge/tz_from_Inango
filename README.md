# DNS Proxy Server

This project is a simple DNS proxy server written in C that allows filtering unwanted host names resolving based on a provided blacklist. The server reads its configuration from a .conf file, and the user can interactively input domain names to simulate DNS requests.

## Features

- **Configuration**: The proxy server reads its parameters during startup from a configuration file (dns_proxy_config.conf).
- **Blacklist**: The configuration file contains parameters such as the IP address of the upstream DNS server, a list of domain names to filter resolving (blacklist), and the type of DNS proxy server's response for blacklisted domains.
- **DNS Request Processing**: The server processes DNS requests in an infinite loop, accepting user input for domain names. It checks if the domain is in the blacklist and responds accordingly.
- **Exit Command**: The user can exit the program by typing 'exit' when prompted for a domain name.

## Getting Started

1. **Compile the Code**: Use the provided Makefile to compile the code. Run `make` in the terminal.
2. **Run the Proxy Server**: Execute the compiled binary. Run `./dns_proxy` in the terminal.
3. **Interact with the Server**: Enter domain names when prompted. Type 'exit' to quit the program.

## Configuration File Example (dns_proxy_config.conf)

```plaintext
upstream_dns_ip = 8.8.8.8
blacklist_domains = example.com, unwanteddomain.net, blocked.org
response_for_blacklisted = refused


## Additional Logic

If you have additional features or modifications you'd like to implement, feel free to discuss them, and I'm ready to incorporate the changes into the code.