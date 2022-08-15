#include <stdio.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <string.h>
#include <microhttpd.h>
#include <stdlib.h>
#include <time.h>

#define PORT 8888

char* get_time() {
	time_t rawtime;
	struct tm *timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	return asctime(timeinfo);
}

char* substr(char* string) {
	char* newString = (char *) malloc(strlen(string) * sizeof(char));
	size_t len = strlen(string) - 3;
	strncpy(newString, string, len);
	return newString; 
}

int answer_to_connection(void *cls, struct MHD_Connection *connection, 
											const char *url, const char *method, 
											const char *version, const char *upload_data, 
											size_t *upload_data_size, void **con_cls) { // callback to store the data
																						// of connection 

	printf("Received request\n" );

	char* (*func)();
	func = cls;
	char *s = substr(func());
	printf("Time: %s\n", s);
	char *page = "{\"data\": \"%s\"}";
	// char *page2 = (char *) malloc((strlen(page) + strlen(s)) * sizeof(char));
	char *response_string = (char *) malloc((strlen(page) + strlen(s)) * sizeof(char));
	sprintf(response_string, page, s);
	printf("Time: %s\n", response_string);
	// char *response_string = "{\"data\":\"HELLO\"}";
	struct MHD_Response *response;
	int ret;
	(void) cls;
	(void) url;
	(void) method;
	(void) version;
	(void) upload_data;
	(void) upload_data_size;
	(void) con_cls;

	response = MHD_create_response_from_buffer(strlen (response_string), (void *) (response_string), MHD_RESPMEM_PERSISTENT);
	MHD_add_response_header(response, "Access-Control-Allow-Origin", "http://localhost:4200");
	MHD_add_response_header(response, "Content-Type", "application/json");
	ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
	MHD_destroy_response(response);
	// free(response_string);
	return ret;
}

int main(int argc, char const *argv[]) {
	
	struct MHD_Daemon *daemon;
	daemon = MHD_start_daemon(MHD_USE_PEDANTIC_CHECKS | MHD_USE_INTERNAL_POLLING_THREAD, PORT, NULL, NULL, 
										&answer_to_connection, &get_time, MHD_OPTION_END);
	if(NULL == daemon) {
		return 1;
	}
	
	(void) getchar();

	MHD_stop_daemon(daemon);
	return 0;
}