#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <syslog.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	const char *filename = argv[1];
	const char *buf = argv[2];
	int fd;
	ssize_t nr;

	openlog(NULL,0,LOG_USER);

	if (argc != 3){
		syslog(LOG_ERR, "Invalid Number of arguments: %d", argc);
		return 1;
	}

	//Linux system programming page 31 
    fd = open (filename, O_WRONLY | O_TRUNC | O_CREAT, 0664);
	
    if (fd == -1) {
		syslog(LOG_ERR, "Could not open file");
		return -1; 
	} else {
        //Linux system programming page 37
		nr = write(fd, buf, strlen(buf));
		if (nr == -1) {
			syslog(LOG_ERR, "Total failure to write");
			return -1;
		}
	}
	
    syslog(LOG_DEBUG, "Successfully wrote %s to %s", filename, buf);
	close(fd);
	closelog();
    return 0;
}