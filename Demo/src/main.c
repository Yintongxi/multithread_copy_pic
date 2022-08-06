#include<pthread_copy.h>

	  
int main(int argc,char ** argv){
	int pronum;
	if(argv[3]==0)
		pronum = 3;
	else
		pronum = atoi(argv[3]);
	//参数校验
	pram_check(argc,argv[1],pronum);
	 //任务量计算
	int blocksize;
	blocksize = file_block(argv[1],pronum);
	//进程创建
	process_create(argv[1],argv[2],blocksize,pronum);
	return 0;
					    
}
