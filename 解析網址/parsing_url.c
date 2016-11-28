#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
int get_num_url(char *total_url);
	/*用途:計算已解析出來網址的數量
	*total_url:已解析出來的陣列 */

void parsing_request_all_URL(char *server_respone,char **result_parsing_url);
	/* 用途： 解析網頁裡頭所有相對路徑檔案網址 
		server_respone	: 要被解析出網址的陣列 ,資料型態:一維陣列 
		result_parsing_url:   把解析出來的網址存放在該位址 ,資料型態:二維陣列  且宣告格式: char 陣列名稱[i][200]; i為任意整數，視解析出來的網址大概數量做決定 
	*/
void parsing_request_one_URL(char *k,char **one_url);
	/*用途: 給 parsing_request_all_URL(char *server_respone,char *total_url)用，只解析1組網址
		 char *k  :要被解析出網址的陣列 ,資料型態:一維陣列
		 one_url  :解析出來的網址存放在該位址 ,資料型態:一維陣列 
	 */


int main()
{
    char hello[] = "src=\"/V7/js/jquery-ui-1.8.20.custom.min.js\"></script><script type=\"text/javascript\" src=\"/V7/js/funcTable.js\"></script><script type=\"text/javascript\" src=\"/V7/js/stone.js\"></script><script type=\"text/javascript\" src=\"/V7/js/cwb.js\"></script><script type=\"text/javascript\" src=\"/V7/js/warning_info.js\"></script><script type=\"text/javascript\" src=\"/V7/js/warning.js\"></script><script type=\"text/javascript\" src=\"/V7/js/scrolltopcontrol.js\"></script><script language=\"JavaScript\" src=\"/V7/js/HotSearch.js\"></script><script language=\"JavaScript\" src=\"/V7/js/jquery.jsonSuggest.js\"></script>";
 	char k[100][200];
 	int i,url_num;
	char *hello_test="HTTP/1.1\r\nHost:";
	char *request = (char *)malloc(sizeof(char) * (11));
	parsing_request_all_URL(hello,k); //把hello內容解析出網址給k 

	url_num=get_num_url(k);    //取得被解析出來的url數量 
	
	printf("sum=%d\n",url_num);
	
	for(i=0;i<url_num;i++)
		printf("%s\n",k[i]);
	printf("\n\n\n%s",hello_test);
    return 0;
}








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
	
void parsing_request_one_URL(char *k,char **one_url)
{
	char *front_ptr_url,*end_ptr_url;
	char *src_double_quotes="src=\"/";
	char *src_apostrophe="src='/";
		
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
void parsing_request_all_URL(char *server_respone,char **result_parsing_url)
{
	int count=0;
	char *front_ptr_url;
	   
	char *src_double_quotes="src=\"/";
	char *src_apostrophe="src='/";
	
	
	front_ptr_url=strstr(server_respone,src_double_quotes);			
	while(front_ptr_url!=NULL){  
	
		parsing_request_one_URL(front_ptr_url,&result_parsing_url[count]);
		count+=200;                    //二維陣列,前往下一個二微陣列 
		front_ptr_url+=1;
		front_ptr_url=strstr(front_ptr_url,src_double_quotes);
	}
	
	front_ptr_url=strstr(server_respone,src_apostrophe);			
	while(front_ptr_url!=NULL){
		parsing_request_one_URL(front_ptr_url,&result_parsing_url[count]);
		count+=200; 
		front_ptr_url+=1;
		front_ptr_url=strstr(front_ptr_url,src_apostrophe);
	}
	

}
