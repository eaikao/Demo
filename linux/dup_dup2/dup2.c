/*************************************************************************
    > File Name: dup2.c
    > Author: eaikao
    > Mail: 279712302@qq.com 
    > Created Time: 2017年12月03日 星期日 22时02分36秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
	int i_fd = open("hello_dup2.txt", O_CREAT|O_APPEND|O_RDWR, 0666);
	

	if(i_fd < 0)
	{
		printf("open error!\n");
		return 0;
	}
	
	if(write(i_fd, "hello i_fd\n", 11) != 11)
	{
		printf("write dup2 error\n");
	}


	int i_dup2_fd = dup2(i_fd, STDOUT_FILENO);

	if(i_dup2_fd != STDOUT_FILENO)
	{
		printf("error dup2!\n");
		return 0;
	}
	close(i_fd);

	char c_buf[1024];
	int i_read_n = 0;
	while((i_read_n = read(STDIN_FILENO, c_buf, 1024)) != 0)
	{
		i_read_n = read(STDIN_FILENO, c_buf + i_read_n, sizeof(c_buf) - 1 - i_read_n);

		if(i_read_n < 0)
		{
			printf("read error!\n");
			return 0;
		}
		
		printf("%s", c_buf);
		fflush(stdout);
		sleep(1);
	}
	close(i_dup2_fd);

	return 0;

}
