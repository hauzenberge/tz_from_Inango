# Makefile

CC = gcc
CFLAGS = -Wall

all: dns_proxy

dns_proxy: dns_proxy.c
	$(CC) $(CFLAGS) dns_proxy.c -o dns_proxy

clean:
	rm -f dns_proxy
