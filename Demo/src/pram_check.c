#include<pthread_copy.h>

// ./PROCESS_COPY xxx.jpg xxx.jpg 20
int pram_check(int argc,const char* sfile,int pronum)
{
	if(argc<3){
				printf("error:缺少必要参数\n");
				exit(0);
	 }
	if((access(sfile,F_OK))!=0)
	{
		printf("error:源文件不正确或不存在\n");
		exit(0);
		
	}
	if(pronum <= 0|| pronum>100)
	{
		printf("error:进程数量不允许小于0并大于100\n");
		exit(0);
	}
	return 0;
}
