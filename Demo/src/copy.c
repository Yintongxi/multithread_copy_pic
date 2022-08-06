#include<pthread_copy.h>
   
     
	   
void copy(const char * sfile,const char * dfile,int block_size,int copy_pos)
{
	
	
	char buffer[block_size];
	bzero(buffer,sizeof(buffer));
	ssize_t readlen;
					   
	int sfd=open(sfile,O_RDONLY);
	int dfd=open(dfile,O_RDWR|O_CREAT,0664);
						 
	//修改偏移量
	lseek(sfd,copy_pos,SEEK_SET);
	lseek(dfd,copy_pos,SEEK_SET);
						   
	//拷贝读写
	readlen = read(sfd,buffer,sizeof(buffer));
	write(dfd,buffer,readlen);
	close(sfd);
	close(dfd);
							   
	
							     
									 
	 }

