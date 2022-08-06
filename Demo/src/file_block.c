#include<pthread_copy.h>
   
     
int file_block(const char* sfile,int pronum)
{
 /*打开文件，获取文件大小*/
	int fd=open(sfile,0,O_RDONLY);
	int fsize = lseek(fd,0,SEEK_END);
	
/*计算任务量*/

	if(fsize % pronum == 0)
		return fsize/pronum;
	else
		return fsize/pronum + 1;
					  
}
