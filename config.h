#ifndef SHTTPD_H 
#define	SHTTPD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <getopt.h>
#include <semaphore.h>
#include <string.h>
#include <assert.h>
#include "pool.h"

/*********************************
 ****** The macro define area!****
 * *******************************/
/*debug flag*/
#define DEBUG 0

/* the sleep time for distribute and manage */
#define SLEEP_TIME 2

/*define the SUCCESS and FAILED MACRO**/
#define SUCCESS 1
#define FAILURE -1 

/*the events type*/
#define	 DATA_IN 0
#define DATA_OUT 1

/**********************************
 * The data define area*
 * *******************************/

/*Sever config struct*/ 
struct server_conf{
				char CGIRoot[128];
				char DefaultFile[128];
				char DocumentRoot[128];
				char ConfigFile[128];
				int ListenPort;
				int MaxClient;
				int TimeOut;
				int InitWorkerNum;
				int MaxWoerkerNum;
};


/**********************************
 * The global data declare area*
 * *******************************/

/*********************************
 *declare sever config structure*
 *********************************/
extern struct server_conf server_para;

/**********************************
 * the function declare area*
 * *******************************/

int DisplayConf();

int GetParaFromFile(char * file);

int GetParaFromCmd(int argc, char * argv[]);

int Gthread_pool_init(struct Gthread_pool * pool, int max_tasks, int max_workers, int min_workers);

int close_pool(struct Gthread_pool * pool);

int add_job(struct Gthread_pool * pool, void * (* job)(void * arg), void * arg);

void add_event(int epoll_fd, int fd, int event_type);

void del_event(int epoll_fd, int fd, int event_type);

#ifdef __cplusplus
}
#endif
#endif

