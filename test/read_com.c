#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <sys/time.h>

int main(int argc, char** argv)
{
	char result;
	int fd, n;
	char *device_name;
	struct termios port_settings;

	if(argc > 1)
	{
		device_name = (char*) malloc(strlen(argv[1] + 1));
		strcpy(device_name, argv[1]);
	}
	else
	{
		device_name = "/dev/ttyUSB0"; 
	}
	printf("1111\n");
	fd = open(device_name, O_RDWR | O_NOCTTY | O_NDELAY);
	printf("%d\n", fd);
	printf("2222\n");
	 /*Error handling*/
	if ( fd < 0)
	{
		printf("Open com port %s failed\n", device_name);
		return fd;
	}

	fcntl(fd, F_SETFL, FNDELAY);


	cfsetispeed(&port_settings, B9600);
	cfsetospeed(&port_settings, B9600);

	port_settings.c_cflag &= ~PARENB;		/**/
	port_settings.c_cflag &= ~CSTOPB;
	port_settings.c_cflag &= ~CSIZE;
	port_settings.c_cflag |= CS8;
	port_settings.c_cflag &= ~CRTSCTS;		/*No hardware handshaking*/

	tcsetattr(fd, TCSANOW, &port_settings);

	while(1)
	{	//printf("1111\n");
		n = read(fd, &result, sizeof(result));
		//printf("%d\n", n);
		if( 0 < n)
		{
			printf("%c", result);
		}

	}

	close(fd);
	return 0;

}
