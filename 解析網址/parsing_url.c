#include <stdio.h>
#include <string.h>
#include <stdlib.h> 


void parsing_request_all_URL(char *server_respone,char *result_parsing_url ,int response_size,int array_size, int *num);
	/* �γ~�G �ѪR�������Y�Ҧ��۹���|�ɮ׺��},�íp�⦳�X�� 
		server_respone	: �n�Q�ѪR�X���}���}�C ,��ƫ��A:�@���}�C 
		result_parsing_url:   ��ѪR�X�Ӫ����}�s��b�Ӧ�} ,��ƫ��A:�ǤJ�G���}�C���Ĥ@�Ӧa�} 
		size: �G���}�C��array[i][k]��k��size��
		num : ��ѪR�X�Ӫ����}���ƶq�s��b�Ӧ�}
	*/

int main()
{
    char hello[] = "src=\"/V7/js/jquery-ui-1.8.20.custom.min.js\"></script><script type=\"text/javascript\" src=\"/V7/js/funcTable.js\"></script><script type=\"text/javascript\" src=\"/V7/js/stone.js\"></script><script type=\"text/javascript\" src=\"/V7/js/cwb.js\"></script><script type=\"text/javascript\" src=\"/V7/js/warning_info.js\"></script><script type=\"text/javascript\" src=\"/V7/js/warning.js\"></script><script type=\"text/javascript\" src=\"/V7/js/scrolltopcontrol.js\"></script><script language=\"JavaScript\" src=\"/V7/js/HotSearch.js\"></script><script language=\"JavaScript\" src=\"/V7/js/jquery.jsonSuggest.js\"></script>src=\"/V7/js/jquery-ui-1.8.20.custom.min.js\"></script><script type=\"text/javascript\" src=\"/V7/js/funcTable.js\"></script><script type=\"text/javascript\" src=\"/V7/js/stone.js\"></script><script type=\"text/javascript\" src=\"/V7/js/cwb.js\"></script><script type=\"text/javascript\" src=\"/V7/js/warning_info.js\"></script><script type=\"text/javascript\" src=\"/V7/js/warning.js\"></script><script type=\"text/javascript\" src=\"/V7/js/scrolltopcontrol.js\"></script><script language=\"JavaScript\" src=\"/V7/js/HotSearch.js\"></script><script language=\"JavaScript\" src=\"/V7/js/jquery.jsonSuggest.js\"></script>src=\"/V7/js/jquery-ui-1.8.20.custom.min.js\"></script><script type=\"text/javascript\" src=\"/V7/js/funcTable.js\"></script><script type=\"text/javascript\" src=\"/V7/js/stone.js\"></script><script type=\"text/javascript\" src=\"/V7/js/cwb.js\"></script><script type=\"text/javascript\" src=\"/V7/js/warning_info.js\"></script><script type=\"text/javascript\" src=\"/V7/js/warning.js\"></script><script type=\"text/javascript\" src=\"/V7/js/scrolltopcontrol.js\"></script><script language=\"JavaScript\" src=\"/V7/js/HotSearch.js\"></script><script language=\"JavaScript\" src=\"/V7/js/jquery.jsonSuggest.js\"></script>src=\"/V7/js/jquery-ui-1.8.20.custom.min.js\"></script><script type=\"text/javascript\" src=\"/V7/js/funcTable.js\"></script><script type=\"text/javascript\" src=\"/V7/js/stone.js\"></script><script type=\"text/javascript\" src=\"/V7/js/cwb.js\"></script><script type=\"text/javascript\" src=\"/V7/js/warning_info.js\"></script><script type=\"text/javascript\" src=\"/V7/js/warning.js\"></script><script type=\"text/javascript\" src=\"/V7/js/scrolltopcontrol.js\"></script><script language=\"JavaScript\" src=\"/V7/js/HotSearch.js\"></script><script language=\"JavaScript\" src=\"/V7/js/jquery.jsonSuggest.js\"></script>src=\"/V7/js/jquery-ui-1.8.20.custom.min.js\"></script><script type=\"text/javascript\" src=\"/V7/js/funcTable.js\"></script><script type=\"text/javascript\" src=\"/V7/js/stone.js\"></script><script type=\"text/javascript\" src=\"/V7/js/cwb.js\"></script><script type=\"text/javascript\" src=\"/V7/js/warning_info.js\"></script><script type=\"text/javascript\" src=\"/V7/js/warning.js\"></script><script type=\"text/javascript\" src=\"/V7/js/scrolltopcontrol.js\"></script><script language=\"JavaScript\" src=\"/V7/js/HotSearch.js\"></script><script language=\"JavaScript\" src=\"/V7/js/jquery.jsonSuggest.js\"></script>src=\"/V7/js/jquery-ui-1.8.20.custom.min.js\"></script><script type=\"text/javascript\" src=\"/V7/js/funcTable.js\"></script><script type=\"text/javascript\" src=\"/V7/js/stone.js\"></script><script type=\"text/javascript\" src=\"/V7/js/cwb.js\"></script><script type=\"text/javascript\" src=\"/V7/js/warning_info.js\"></script><script type=\"text/javascript\" src=\"/V7/js/warning.js\"></script><script type=\"text/javascript\" src=\"/V7/js/scrolltopcontrol.js\"></script><script language=\"JavaScript\" src=\"/V7/js/HotSearch.js\"></script><script language=\"JavaScript\" src=\"/V7/js/jquery.jsonSuggest.js\"></script>src=\"/V7/js/jquery-ui-1.8.20.custom.min.js\"></script><script type=\"text/javascript\" src=\"/V7/js/funcTable.js\"></script><script type=\"text/javascript\" src=\"/V7/js/stone.js\"></script><script type=\"text/javascript\" src=\"/V7/js/cwb.js\"></script><script type=\"text/javascript\" src=\"/V7/js/warning_info.js\"></script><script type=\"text/javascript\" src=\"/V7/js/warning.js\"></script><script type=\"text/javascript\" src=\"/V7/js/scrolltopcontrol.js\"></script><script language=\"JavaScript\" src=\"/V7/js/HotSearch.js\"></script><script language=\"JavaScript\" src=\"/V7/js/jquery.jsonSuggest.js\"></script>src=\"/V7/js/jquery-ui-1.8.20.custom.min.js\"></script><script type=\"text/javascript\" src=\"/V7/js/funcTable.js\"></script><script type=\"text/javascript\" src=\"/V7/js/stone.js\"></script><script type=\"text/javascript\" src=\"/V7/js/cwb.js\"></script><script type=\"text/javascript\" src=\"/V7/js/warning_info.js\"></script><script type=\"text/javascript\" src=\"/V7/js/warning.js\"></script><script type=\"text/javascript\" src=\"/V7/js/scrolltopcontrol.js\"></script><script language=\"JavaScript\" src=\"/V7/js/HotSearch.js\"></script><script language=\"JavaScript\" src=\"/V7/js/jquery.jsonSuggest.js\"></script>src=\"/V7/js/jquery-ui-1.8.20.custom.min.js\"></script><script type=\"text/javascript\" src=\"/V7/js/funcTable.js\"></script><script type=\"text/javascript\" src=\"/V7/js/stone.js\"></script><script type=\"text/javascript\" src=\"/V7/js/cwb.js\"></script><script type=\"text/javascript\" src=\"/V7/js/warning_info.js\"></script><script type=\"text/javascript\" src=\"/V7/js/warning.js\"></script><script type=\"text/javascript\" src=\"/V7/js/scrolltopcontrol.js\"></script><script language=\"JavaScript\" src=\"/V7/js/HotSearch.js\"></script><script language=\"JavaScript\" src=\"/V7/js/jquery.jsonSuggest.js\"></script>src=\"/V7/js/jquery-ui-1.8.20.custom.min.js\"></script><script type=\"text/javascript\" src=\"/V7/js/funcTable.js\"></script><script type=\"text/javascript\" src=\"/V7/js/stone.js\"></script><script type=\"text/javascript\" src=\"/V7/js/cwb.js\"></script><script type=\"text/javascript\" src=\"/V7/js/warning_info.js\"></script><script type=\"text/javascript\" src=\"/V7/js/warning.js\"></script><script type=\"text/javascript\" src=\"/V7/js/scrolltopcontrol.js\"></script><script language=\"JavaScript\" src=\"/V7/js/HotSearch.js\"></script><script language=\"JavaScript\" src=\"/V7/js/jquery.jsonSuggest.js\"></script>";
 	char url_parsed[100][200];
	int size=sizeof(hello);
 	int i,num;
 	
	parsing_request_all_URL(hello,&url_parsed[0][0],size,200,&num);
 	
	
	for(i=0;i<num;i++)
		printf("%s\n",url_parsed[i]);
	
	return 0;
}



void parsing_request_all_URL(char *server_respone,char *result_parsing_url , int response_size,int array_size, int *num)
{		
	int count=0,url_num=0;
	char *front_ptr_url,*end_ptr_url;
	char temp[100][200];
	

	while( count < response_size  )
	{
		if( strncmp(server_respone,"src=\"/",6) == 0)
		{
			front_ptr_url=strstr(server_respone,"=\"");
			front_ptr_url+=2;
			end_ptr_url=strchr(front_ptr_url,'\"');
			memcpy( temp[url_num++],front_ptr_url,end_ptr_url-front_ptr_url);	
		}
		else if(strncmp(server_respone,"src='/",6) == 0)
		{
			front_ptr_url=strstr(server_respone,"='");
			front_ptr_url+=2;
			end_ptr_url=strchr(front_ptr_url,'\'');
			memcpy( temp[url_num++],front_ptr_url,end_ptr_url-front_ptr_url);
			
		}
		
		server_respone++;
		count++;
	}


	//��ѪR�X�����}�ƶq�s��num 
	*num=url_num;	
	
	//��ѪR�X�Ӫ��C�Ӻ��}�s��G���}�C�� 
	for(count=0;count<url_num;count++)
	{	
		memcpy(result_parsing_url,temp[count],200);	
		result_parsing_url+=array_size;
		
	}
}
