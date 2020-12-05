
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <termios.h>
#include <time.h>

int main()
{
	char result[99];
	int n;
	
	 /*struct to store the port settings in*/
	struct termios port_settings; 

	 /*Open*/
	int fd = open("/dev/ttyUSB0", O_RDWR);   

	 /*Error handling*/
	if ( fd < 0)
	{
		        printf("Error %d opening dev/ttyUSB0 \n", errno);
	}
	
	fcntl(fd, F_SETFL, FNDELAY);
	printf("\nfd = %d", fd);

	/*Setup configuration*/
	cfsetispeed(&port_settings, B9600);
	cfsetospeed(&port_settings, B9600);
	
	port_settings.c_cflag &= ~PARENB;			/*set no parity, stop bít, data bits*/
	port_settings.c_cflag &= ~CSTOPB;
	port_settings.c_cflag &= ~CSIZE;
	port_settings.c_cflag |= CS8;
	port_settings.c_cflag &= ~CRTSCTS;			/*Set no hardware handshaking*/
	tcsetattr(fd, TCSANOW, &port_settings);		/*apply the setting to the port */
	while(1)
	{
		char key = getchar();
		result[0] = key;
		write(fd, result, 1);
	}

	close (fd);

	return 0;
}

