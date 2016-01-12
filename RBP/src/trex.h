/*
 * In The Name Of God
 * ========================================
 * [] File Name : trex.h
 *
 * [] Creation Date : 12-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/
#ifndef TREX_H
#define TREX_H

void trex_callback(SoupServer *server, SoupMessage *msg,
	const char *path, GHashTable *query, const char *dest);

#endif
