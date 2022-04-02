#include <stdio.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <string.h>
#include <microhttpd.h>

#define PORT 8888

int answer_to_connection(void *cls, struct MHD_Connection *connection, 
											const char *url, const char *method, 
											const char *version, const char *upload_data, 
											size_t *upload_data_size, void **con_cls) { // callback to store the data
																						// of connection 

	printf("Received request\n" );

	const char *page = "{\"data\": \"Hello, browser\"}";
	struct MHD_Response *response;
	int ret;
	(void) cls;
	(void) url;
	(void) method;
	(void) version;
	(void) upload_data;
	(void) upload_data_size;
	(void) con_cls;

	response = MHD_create_response_from_buffer(strlen (page), (void *) page, MHD_RESPMEM_PERSISTENT);
	MHD_add_response_header(response, "Access-Control-Allow-Origin", "http://localhost:4200");
	ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
	MHD_destroy_response(response);

	return ret;
}

int main(int argc, char const *argv[]) {
	
	struct MHD_Daemon *daemon;
	daemon = MHD_start_daemon(MHD_USE_AUTO | MHD_USE_INTERNAL_POLLING_THREAD, PORT, NULL, NULL, &answer_to_connection, NULL, MHD_OPTION_END);
	if(NULL == daemon) {
		return 1;
	}
	
	(void) getchar();

	MHD_stop_daemon(daemon);
	return 0;
}