#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <sys/time.h>

int read_com(char* port)
{
	char result;
	int fd, n;
	char *device_name;
	struct termios port_settings;

	fd = open(port, O_RDWR | O_NOCTTY | O_NDELAY);
	printf("%d\n", fd);
	
	/*Error handling*/
	if (fd < 0)
	{
		printf("Open com port %s failed\n", port);
		return fd;
	}

	fcntl(fd, F_SETFL, FNDELAY);

	cfsetispeed(&port_setting, B9600);
	cfsetospeed(&port_setting, B9600);

	port_settings.c_cflag &= ~PARENB;
	port_settings.c_cflag &= ~CSTOPB;
	port_settings.c_cflag &= ~CSIZE;
	port_settings.c_cflag |= CS8;
	port_settings.c_cflag &= ~CRTSCTS;

	tcsetattr(fd, TCSANOW, &port_settungs);

	while(1)
	{
		n = read(fd, &result, sizeof(result));

		if( 0 < n)
		{
			printf("%c", result);
		}
	}

	close(fd);
	return 0;
}
