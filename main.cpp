extern "C" {
	#include <curl/curl.h>
	#include <stdlib.h>
	#include <string.h>
}
#include "nhen_parser.hpp"

#define NHEN "https://nhentai.net"

static size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp)
{
  size_t realsize = size * nmemb;
  struct memory *mem = (struct memory *)userp;
 
  char *ptr = (char*)realloc(mem->response, mem->size + realsize + 1);
  if(!ptr) {
    /* out of memory! */
    printf("not enough memory (realloc returned NULL)\n");
    return 0;
  }
 
  mem->response = ptr;
  memcpy(&(mem->response[mem->size]), contents, realsize);
  mem->size += realsize;
  mem->response[mem->size] = 0;
 
  return realsize;
}

int main()
{
	struct memory mem = {0};

	CURL* curl;
	CURLcode res;

	curl = curl_easy_init();

	curl_easy_setopt(curl, CURLOPT_URL, NHEN);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&mem);

	res = curl_easy_perform(curl);

	if(res != CURLE_OK) {
		printf("Failed to execute curle\n");
		return EXIT_FAILURE;
	}
	else printf("CURLE_OK!\n");

	return nhen_core(mem.response, mem.size);
}

