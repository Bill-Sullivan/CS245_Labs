#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <errno.h>
#include <time.h>

#include <unistd.h> 

void printHelp() {
	printf("Call program with the fallowing arguments to get the fallowing results\n");
	printf("-s: OS system name and release\n");
	printf("-t: Time of day\n");
	printf("-p: Process ID and parent process ID\n");
	printf("-u: Username\n");
	printf("-h: This message\n");
}


int main(int argc, char * argv[]) {
	if (argc > 1) {
		printf("%s\n\n\n", argv[1]);		
		for (int i = 1; i<argc; i++) {
			if (strcmp(argv[i], "-t")==0) {				
				time_t tnow;  /* time now */
   				char *tp;  /* printable time pointer */
   				time(&tnow);
   				//printf("tnow=%08x\n", &tnow);
   				tp = ctime(&tnow);

				printf("time is =%s\n",tp);
			} else if (strcmp(argv[i], "-s")==0) {
				int err;
				struct utsname u;	
				err = uname(&u);
				if (err != 0) {
					perror(NULL);
					exit(0);
				}
				printf("sysname %s\n", u.sysname);
				printf("nodename %s\n", u.nodename);
				printf("release %s\n", u.release);
				printf("version %s\n", u.version);
				printf("machine %s\n", u.machine);
			} else if (strcmp(argv[i], "-p")==0) {

				printf("Parent Process id of current process : %d\n", getppid());
				printf("Process id : %d\n", getpid());
			} else if (strcmp(argv[i], "-u")==0) {
				printf("username: %s\n", getenv("USER"));
				printf("user id:%d\n", getuid());
			} else if (strcmp(argv[i], "-h")==0) {
				printHelp();
			}

		}
		
	} else {
		printHelp();
	}
}