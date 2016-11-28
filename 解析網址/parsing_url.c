#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

void parsing_request_one_URL(char *k,char *one_url);
	/*用途: 給 parsing_request_all_URL用的，只解析1組網址
		 char *k  :要被解析出網址的陣列 ,資料型態:一維陣列
		 one_url  :解析出來的網址存放在該位址 ,資料型態:一維陣列 
	 */
void parsing_request_all_URL(char *server_respone,char *result_parsing_url , int size, int *num);
	/* 用途： 解析網頁裡頭所有相對路徑檔案網址,並計算有幾個 
		server_respone	: 要被解析出網址的陣列 ,資料型態:一維陣列 
		result_parsing_url:   把解析出來的網址存放在該位址 ,資料型態:傳入二維陣列的第一個地址 
		size: 二維陣列中array[i][k]的k的size值
		num : 把解析出來的網址的數量存放在該位址
	*/

int main()
{
    char hello[] = "src=\"/V7/js/jquery-ui-1.8.20.custom.min.js\"></script><script type=\"text/javascript\" src=\"/V7/js/funcTable.js\"></script><script type=\"text/javascript\" src=\"/V7/js/stone.js\"></script><script type=\"text/javascript\" src=\"/V7/js/cwb.js\"></script><script type=\"text/javascript\" src=\"/V7/js/warning_info.js\"></script><script type=\"text/javascript\" src=\"/V7/js/warning.js\"></script><script type=\"text/javascript\" src=\"/V7/js/scrolltopcontrol.js\"></script><script language=\"JavaScript\" src=\"/V7/js/HotSearch.js\"></script><script language=\"JavaScript\" src=\"/V7/js/jquery.jsonSuggest.js\"></script>";
 	char url_parsed[100][200];
 	int i,num;
	parsing_request_all_URL(hello,&url_parsed[0][0],200,&num);
	
	printf("-----------------------\n");
	printf("num=%d\n",num);
//	printf("sizeof(url_parsed)=%d  \n",sizeof(url_parsed));
for(i=0;i<9;i++)
	printf("%s\n",url_parsed[i]);
	return 0;
}


void parsing_request_one_URL(char *k,char *one_url)
{
	char *front_ptr_url,*end_ptr_url;
	char src_double_quotes[]="src=\"/";
	char src_apostrophe[]="src='/";
		
	if(strncmp(k,src_double_quotes,6)==0)
		{
			front_ptr_url=strstr(k,"=\"");
			front_ptr_url+=2;
			end_ptr_url=strchr(front_ptr_url,'\"');
			memcpy(one_url,front_ptr_url,end_ptr_url-front_ptr_url);
		}
		
	else if(strncmp(k,src_apostrophe,6)==0)
		{
			front_ptr_url=strstr(k,"='");
			front_ptr_url+=2;
			end_ptr_url=strchr(front_ptr_url,'\'');
			memcpy(one_url,front_ptr_url,end_ptr_url-front_ptr_url);
		}	
}
void parsing_request_all_URL(char *server_respone,char *result_parsing_url , int size, int *num)
{		
	int count=0,i;
	char *front_ptr_url;
	char src_double_quotes[]="src=\"/";
	char src_apostrophe[]="src='/";
	char temp[100][200];

	//解析出  
	front_ptr_url=strstr(server_respone,src_double_quotes);			
	while(front_ptr_url!=NULL){  
	
		parsing_request_one_URL(front_ptr_url,temp[count++]);
		front_ptr_url+=1;
		front_ptr_url=strstr(front_ptr_url,src_double_quotes);
	}
	
	front_ptr_url=strstr(server_respone,src_apostrophe);				
	while(front_ptr_url!=NULL){
		parsing_request_one_URL(front_ptr_url,temp[count++]); 
		front_ptr_url+=1;
		front_ptr_url=strstr(front_ptr_url,src_apostrophe);
	}	
	//把解析出的網址數量存到num 
	*num=count;	
	
	//把解析出來的每個網址存到二維陣列中 
	for(i=0;i<count;i++)
	{	
		memcpy(result_parsing_url,temp[i],200);	
		result_parsing_url+=size;
		
	}
}
