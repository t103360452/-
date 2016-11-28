#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
int get_num_url(char *total_url)
	{
		int num=0, sum=0;
		while(*(total_url+sum)=='/')
		{
			sum+=200;
			num++;
		}
	return num;
	}
	
void parsing_request_one_URL(char *k,char *one_url)
{
	char *front_url,*end_url;
	char *a="href=\"/";
	char *b="href='/";
	char *c="src=\"/";
	char *d="src='/";
		
	if((strncmp(k,a,7)==0)||(strncmp(k,c,6)==0))
		{
			front_url=strstr(k,"=\"");
			front_url+=2;
			end_url=strchr(front_url,'\"');
			memcpy(one_url,front_url,end_url-front_url);
		}
		
	else if((strncmp(k,b,7)==0)||(strncmp(k,d,6)==0))
		{
			front_url=strstr(k,"='");
			front_url+=2;
			end_url=strchr(front_url,'\'');
			memcpy(one_url,front_url,end_url-front_url);
		}	
}
void parsing_request_all_URL(char *server_respone,char *total_url)
{
	int count=0;
	char *front_url;
	   
	char *a="href=\"/";
	char *b="href='/";
	char *c="src=\"/";
	char *d="src='/";
	
	front_url=strstr(server_respone,b);			
	while(front_url!=NULL){
		parsing_request_one_URL(front_url,&total_url[count]);
		count+=200; 
		front_url+=1;
		front_url=strstr(front_url,b);
	}
	
	front_url=strstr(server_respone,c);			
	while(front_url!=NULL){  //main
	
		parsing_request_one_URL(front_url,&total_url[count]);
		count+=200;                    //二維陣列,前往下一個二微陣列 
		front_url+=1;
		front_url=strstr(front_url,c);
	}
	
	front_url=strstr(server_respone,d);			
	while(front_url!=NULL){
		parsing_request_one_URL(front_url,&total_url[count]);
		count+=200; 
		front_url+=1;
		front_url=strstr(front_url,d);
	}
	
	front_url=strstr(server_respone,a);			
	while(front_url!=NULL){
		parsing_request_one_URL(front_url,&total_url[count]);
		count+=200; 
		front_url+=1;
		front_url=strstr(front_url,a);
	}
}

int main(int argc, char **argv)
{
     char hello[] = "src=\"/V7/js/jquery-ui-1.8.20.custom.min.js\"></script><script type=\"text/javascript\" src=\"/V7/js/funcTable.js\"></script><script type=\"text/javascript\" src=\"/V7/js/stone.js\"></script><script type=\"text/javascript\" src=\"/V7/js/cwb.js\"></script><script type=\"text/javascript\" src=\"/V7/js/warning_info.js\"></script><script type=\"text/javascript\" src=\"/V7/js/warning.js\"></script><script type=\"text/javascript\" src=\"/V7/js/scrolltopcontrol.js\"></script><script language=\"JavaScript\" src=\"/V7/js/HotSearch.js\"></script><script language=\"JavaScript\" src=\"/V7/js/jquery.jsonSuggest.js\"></script>";
     char *ptr,*eptr; 
     int i=0,y;
	 
    char k[500][200];
    

	parsing_request_all_URL(hello,&k);	
	y=get_num_url(k);
	printf("%d\n",y);
	for(i=0;i<y;i++)
	{
			
			if(k[i]== '\0')
			 printf("%d is empty \n",i);
			else
			 printf("i=%d %s\n",i,k[i]);
	}	
    return 0;
}
