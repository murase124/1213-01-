#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct _PhoneList
{
	char name[21];
	char number[21];
	struct _PhoneList* next;
	struct _PhoneList* Back_next;
}PhoneList;


void search(PhoneList** p, PhoneList** start);
void list(PhoneList** p, PhoneList** start);
char* lowerstring_ver2(char* in);
void gomi();

void search(PhoneList** p, PhoneList** start)
{
	//�|�C���^�������ʒu�ɃZ�b�g
	*p = *start;

	/*** �錾 ***/
	char search[7];
	char Name[20];
	char* PName;
	char SeName[20];
	char* PSeName;
	char SeNameMax[20];
	char* PSeNameMax;
	char SeNumber[20];
	char SeNumberMax[20];
	int caunt = 0;

	/*** ���� ***/
	//�R�}���h��end�łȂ����
	while (true)
	{
		//�R�}���h���́@����
		printf("mode search\n");
		printf("| �I�� |   �����Ώ�    | �ꗗ | ��ʃN���A |\n");
		printf("| end  | name | number | list |    clear   |\n");
		scanf_s("%s", search, 7);
		printf("\n");

		//����������name
		if (strcmp("name", search) == 0)
		{
			//����
			printf("�������閼�O�����  ");
			scanf_s("%s", SeName, 20);
			//�T��
			while (*p != NULL)
			{
				//��������������
				int len = strlen(SeName);
				//�����������R�s�[
				strcpy_s(SeNameMax, SeName);
				strcpy_s(Name,(*p)->name);

				//�Ō�̕����ɑ΂��ĕ����R�[�h�{�P
				SeNameMax[len - 1] = SeName[len - 1] + 1;	
				//�������ɂ��낦��
				PSeName = lowerstring_ver2(SeName);
				PName = lowerstring_ver2(Name);
				PSeNameMax = lowerstring_ver2(SeNameMax);

				//������@�ŏ����猟���������܂œ���
				//if (strcmp(lowerstring_ver2((*p)->name),lowerstring_ver2( SeName)) >= 0 && strcmp(lowerstring_ver2(SeNameMax),lowerstring_ver2((*p)->name)) > 0)
				if (strcmp(PName, PSeName) >= 0 && strcmp(PSeNameMax, PName) > 0)
				{
					caunt++;
					//�o��
					printf("add | %*s |",-21, (*p)->name);
					printf("%s", (*p)->number);
					printf("\n");
				}
				//�|�C���^������
				(*p) = (*p)->next;
			}
			//�o�͌����@�o��
			printf("%d��\n", caunt);
			caunt = 0;
		}
		//����������number
		else if (strcmp("number", search) == 0)
		{
			//����
			printf("��������ԍ������  ");
			scanf_s("%s", SeNumber, 20);
			//�T��
			while (*p != NULL)
			{
				//��������������
				int len = strlen(SeNumber);
				//�����������R�s�[
				strcpy_s(SeNumberMax, SeNumber);
				//�Ō�̕����ɑ΂��ĕ����R�[�h�{�P
				SeNumberMax[len - 1] = SeNumber[len - 1] + 1;

				//������@�ŏ����猟���������܂œ���
				if (strcmp(SeNumber, ((*p)->number)) <= 0 && strcmp(SeNumberMax, (*p)->number) > 0)
				{
					caunt++;
					//�o��
					printf("add | %*s |",-21, (*p)->name);
					printf("%s", (*p)->number);
					printf("\n");
				}
				//�|�C���^������
				(*p) = (*p)->next;
			}
			//�o�͌����@�o��
			printf("%d��\n", caunt);
			caunt = 0;
		}
		//�I��
		else if (strcmp(search, "end") == 0)
		{
			//�|�C���^�������ʒu�ɃZ�b�g
			*p = *start;
			return;
		}
		//�ꗗ
		else if (strcmp("list", search) == 0)
		{
			printf("\n");
			list(p, start);
		}
		//��ʂ��N���A
		else if (strcmp( "clear", search) == 0)
		{
			system("cls");
		}

		printf("\n");
		//�|�C���^�������ʒu�ɃZ�b�g
		*p = *start;
	}

	
}