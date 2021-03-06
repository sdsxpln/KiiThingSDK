SOURCES = $(wildcard *.c)
HEADERS = $(wildcard *.h)
LDFLAGS =
CC = gcc
CFLAGS = -shared -fPIC
INCLUDE = -I jansson
LIBS = -L jansson -l jansson
ifdef USE_CURL
	HTTPCLIENT_SOURCE = httpclient/kii_prv_http_execute_curl.c
	INCLUDE += -I curl
	LIBS += -l curl
else
	HTTPCLIENT_SOURCE = httpclient/kii_prv_http_execute_ssl.c
	LIBS += -l ssl -l crypto
endif

all: build doc

doc:
	doxygen doxyfile

build_jansson:
	$(MAKE) -C jansson

build: build_jansson
	$(CC) $(CFLAGS) $(SOURCES) $(HTTPCLIENT_SOURCE) $(INCLUDE) $(LIBS) -o libkii.so

archive: clean
	mkdir -p kii_sources/httpclient
	cp $(SOURCES) $(HEADERS) kii_sources
	cp $(HTTPCLIENT_SOURCE) kii_sources/httpclient
	tar -czf libkii.tar.gz kii_sources
	rm -rf kii_sources

clean_jansson:
	$(MAKE) -C jansson clean

clean: clean_jansson
	rm -rf libkii.so
	rm -rf kii_sources

phony: doc build build_jansson clean clean_jansson
