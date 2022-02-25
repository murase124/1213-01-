#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct _PhoneList
{
	char name[21];
	char number[20];
	struct _PhoneList* next;
	struct _PhoneList* Back_next;
}PhoneList;

void soot(PhoneList** p, PhoneList** start, PhoneList** last);
void lowerstring(char* out, const char* in);
char* lowerstring_ver2(char* in);
char lower(char c);
void upperstring(char* out, const char* in);
char upper(char c);
void gomi();

//���͗]�����
void gomi()
{
	//�錾
	char gomi;

	while (true)
	{
		//����
		scanf_s("%c", &gomi, 1);
		//�̂ďI����Ă�
		if (gomi == '\n')
			break;
	}
}

//�\�[�g����
void soot(PhoneList** p, PhoneList* *start, PhoneList** last)
{
	//�|�C���^�������ʒu�ɃZ�b�g
	*p = *start;
	/*** �錾 ***/
	bool flg = true;

	//�����ɂȂ�����I��
	while (true)
	{
		//�ŏ�����Ō�܂�
		for (int j = 0; (*p)->next != NULL; j++)
		{
			
			//name���nexr->name�����������
			if (strcmp((*p)->name, (*p)->next->name) > 0)
			{
				//�ŏ��̃|�C���^�Ȃ�
				if ((*p)->Back_next == NULL)
				{
					*start = (*p)->next;
				}
				else
				{
					//�ŏ��̃|�C���^�ȊO
					(*p)->Back_next->next = (*p)->next;
				}
				//�S�Ẵ|�C���^
				(*p)->next->Back_next = (*p)->Back_next;
				(*p)->Back_next = (*p)->next;
				(*p)->next = (*p)->next->next;
				(*p)->Back_next->next = (*p);
				//next���Ō�̃|�C���^�ȊO
				if ((*p)->next != NULL) (*p)->next->Back_next = (*p);
				flg = false;
				break;
			}

			//�|�C���^��NULL�łȂ���΁@�@�|�C���^������
			if ((*p)->next != NULL) * p = (*p)->next;
		}
		if (flg)
		{
			//�|�C���^�������ʒu�ɃZ�b�g
			*last = *p;
			*p = *start;
			return ;
		}
		//flg��������
		flg = true;

		//�|�C���^�������ʒu�ɃZ�b�g
		*p = *start;
	}
}

//�������啶���ɂ���
void upperstring(char* out, const char* in) 
{
	int i;

	i = 0;
	while (in[i] != '\0') 
	{
		out[i] = upper(in[i]);
		i++;
	}
}



//�������������ɂ���
char lower(char c) 
{
	if ('A' <= c && c <= 'Z')
	{
		c = c + ('a' - 'A');
	}
	return c;
}



//��������������ɂ���
void lowerstring(char* out, const char* in) 
{
	int i;

	i = 0;
	while (in[i] != '\0') 
	{
		out[i] = lower(in[i]);
		i++;
	}
}
//ver2
char* lowerstring_ver2(char* in)
{
	int i;
	char* out = (char*)malloc(sizeof(char) * 20);

	i = 0;
	while (in[i] != '\0')
	{
		out[i] = lower(in[i]);
		i++;
	}
	out[i] = lower(in[i]);
	return out;
}

//������啶���ɂ���
char upper(char c) 
{
	if ('a' <= c && c <= 'z') 
	{
		c = c - ('a' - 'A');
	}
	return c;
}

