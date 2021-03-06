/*
 * In The Name Of God
 * ========================================
 * [] File Name : trap.c
 *
 * [] Creation Date : 12-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/
#include <glib.h>
#include <stdlib.h>
#include <libsoup/soup.h>

#include "trap.h"
#include "rest.h"
#include "trex.h"

static void trap_callback(SoupServer *server, SoupMessage *msg,
	const char *path, GHashTable *query,
	SoupClientContext *client, gpointer user_data)
{
	g_print("%s\n", path);
	rest_parse(path, NULL);
	SoupHTTPVersion version = soup_message_get_http_version(msg);
	if (version == SOUP_HTTP_1_0)
		g_print("1\n");
	if (version == SOUP_HTTP_1_1)
		g_print("1.1\n");
	g_print("%s\n", soup_client_context_get_host(client));

	trex_callback(server, msg, path, query, "http://127.0.0.1");
}

void trap_init(void)
{
	GError *error = NULL;
	SoupServer *server;

	server = soup_server_new(SOUP_SERVER_SERVER_HEADER,
		"TRAP-1.0", NULL);
	soup_server_listen_all(server, 1373,
		SOUP_SERVER_LISTEN_IPV4_ONLY, &error);
	if (error) {
		g_critical("Unable to create soup server: %s\n", error->message);
		exit(1);
	}
	soup_server_add_handler(server, NULL, trap_callback, NULL, NULL);
}
