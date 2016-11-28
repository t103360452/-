#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

void parsing_request_one_URL(char *k,char *one_url);
	/*�γ~: �� parsing_request_all_URL�Ϊ��A�u�ѪR1�պ��}
		 char *k  :�n�Q�ѪR�X���}���}�C ,��ƫ��A:�@���}�C
		 one_url  :�ѪR�X�Ӫ����}�s��b�Ӧ�} ,��ƫ��A:�@���}�C 
	 */
void parsing_request_all_URL(char *server_respone,char *result_parsing_url , int size, int *num);
	/* �γ~�G �ѪR�������Y�Ҧ��۹���|�ɮ׺��},�íp�⦳�X�� 
		server_respone	: �n�Q�ѪR�X���}���}�C ,��ƫ��A:�@���}�C 
		result_parsing_url:   ��ѪR�X�Ӫ����}�s��b�Ӧ�} ,��ƫ��A:�ǤJ�G���}�C���Ĥ@�Ӧa�} 
		size: �G���}�C��array[i][k]��k��size��
		num : ��ѪR�X�Ӫ����}���ƶq�s��b�Ӧ�}
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

	//�ѪR�X  
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
	//��ѪR�X�����}�ƶq�s��num 
	*num=count;	
	
	//��ѪR�X�Ӫ��C�Ӻ��}�s��G���}�C�� 
	for(i=0;i<count;i++)
	{	
		memcpy(result_parsing_url,temp[i],200);	
		result_parsing_url+=size;
		
	}
}
