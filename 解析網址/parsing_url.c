#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
int get_num_url(char *total_url);
	/*�γ~:�p��w�ѪR�X�Ӻ��}���ƶq
	*total_url:�w�ѪR�X�Ӫ��}�C */

void parsing_request_all_URL(char *server_respone,char **result_parsing_url);
	/* �γ~�G �ѪR�������Y�Ҧ��۹���|�ɮ׺��} 
		server_respone	: �n�Q�ѪR�X���}���}�C ,��ƫ��A:�@���}�C 
		result_parsing_url:   ��ѪR�X�Ӫ����}�s��b�Ӧ�} ,��ƫ��A:�G���}�C  �B�ŧi�榡: char �}�C�W��[i][200]; i�����N��ơA���ѪR�X�Ӫ����}�j���ƶq���M�w 
	*/
void parsing_request_one_URL(char *k,char **one_url);
	/*�γ~: �� parsing_request_all_URL(char *server_respone,char *total_url)�ΡA�u�ѪR1�պ��}
		 char *k  :�n�Q�ѪR�X���}���}�C ,��ƫ��A:�@���}�C
		 one_url  :�ѪR�X�Ӫ����}�s��b�Ӧ�} ,��ƫ��A:�@���}�C 
	 */


int main()
{
    char hello[] = "src=\"/V7/js/jquery-ui-1.8.20.custom.min.js\"></script><script type=\"text/javascript\" src=\"/V7/js/funcTable.js\"></script><script type=\"text/javascript\" src=\"/V7/js/stone.js\"></script><script type=\"text/javascript\" src=\"/V7/js/cwb.js\"></script><script type=\"text/javascript\" src=\"/V7/js/warning_info.js\"></script><script type=\"text/javascript\" src=\"/V7/js/warning.js\"></script><script type=\"text/javascript\" src=\"/V7/js/scrolltopcontrol.js\"></script><script language=\"JavaScript\" src=\"/V7/js/HotSearch.js\"></script><script language=\"JavaScript\" src=\"/V7/js/jquery.jsonSuggest.js\"></script>";
 	char k[100][200];
 	int i,url_num;
	char *hello_test="HTTP/1.1\r\nHost:";
	char *request = (char *)malloc(sizeof(char) * (11));
	parsing_request_all_URL(hello,k); //��hello���e�ѪR�X���}��k 

	url_num=get_num_url(k);    //���o�Q�ѪR�X�Ӫ�url�ƶq 
	
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
		count+=200;                    //�G���}�C,�e���U�@�ӤG�L�}�C 
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
