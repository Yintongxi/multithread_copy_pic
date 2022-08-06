#include <pthread_copy.h>

struct Info
{
	char * arg_sfile;
	char * arg_dfile;
	int  arg_blocksize;
	int  arg_pos;
};
     
void * jobs(void * arg){

	pthread_detach(pthread_self());
	
	struct Info* info = (struct Info *)arg;
///home/pinkk/0913/Demo/moudle
//	execl("/home/pinkk/0913/Demo/moudle/COPY","COPY",info->arg_sfile,info->arg_dfile,info->arg_blocksize,info->arg_pos,NULL);
	copy(info->arg_sfile,info->arg_dfile,info->arg_blocksize,info->arg_pos);
	return NULL;

}
int process_create(const char*sfile,const char* dfile,int blocksize,int pronum)
{
	pthread_t tid;
	int flag;
	struct Info info;
	int err;	
	for(flag=0;flag<pronum;flag++){

		int pos;
		pos=flag * blocksize;
		info.arg_sfile=sfile;
		info.arg_dfile=dfile;
		info.arg_blocksize=blocksize;
		info.arg_pos=pos;
		//char str_blocksize[50];
		//char str_pos[50];
		//bzero(str_blocksize,sizeof(str_blocksize));
		//bzero(str_pos,sizeof(str_pos));
		//sprintf(str_blocksize,"%d",blocksize);
		//sprintf(str_pos,"%d",pos);
		

		//info.arg_sfile = sfile;
		//strcpy(info.arg_sfile,sfile);
		//info.arg_dfile = dfile;
		//strcpy(info.arg_dfile,dfile);
		//info.arg_blocksize = str_blocksize;
		//strcpy(info.arg_blocksize,str_blocksize);
		//info.arg_pos = str_pos;
		//strcpy(info.arg_pos,str_pos);
		if((err = pthread_create(&tid,NULL,jobs,(void *)&info))>0){
		
			printf("pthread create failed:%s\n",strerror(err));

		}
		//else if(err == 0){
			
			//printf("Copy pthread tid %d Copy_pos %d Copy_size %d\n",pthread_self(),pos,blocksize);
			//通过重载方式使用COPY功能
		
		//execl("/home/pinkk/0913/Process/process_copy/moudle/COPY","COPY",sfile,dfile,str_blocksize,str_pos,NULL);
		//子进程重载后被覆盖，在execl后做的事没作用
		//}
	sleep(1);		
	}
		return 0;
}

