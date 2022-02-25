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

void search(PhoneList** p, PhoneList* *start);
void mod(PhoneList** p, PhoneList* *start, PhoneList** last);
void soot(PhoneList** p, PhoneList* *start, PhoneList** last);
void list(PhoneList** p, PhoneList* *start);
void File_Set(PhoneList** p, PhoneList* *start, PhoneList** last);
void gomi();

void mod(PhoneList** p, PhoneList* *start, PhoneList** last)
{
	//�|�C���^�������ʒu�ɃZ�b�g
	*p = *start;

	/*** �錾 ***/
	char IfSearch[7];
	char SeName[20];
	char SeNumber[20]; 
	char NeName[20];
	char NeNumber[20];
	int caunt = 0;
	PhoneList* pbox1;

	/*** ���� ***/
	//�R�}���h��end�łȂ����
	while (strcmp(IfSearch, "end") != 0)
	{
		//�R�}���h���́@����		
		printf("mode mod\n");
		printf("| �I�� | mod �����Ώ�  | ����(�X�V) | �ꗗ(�X�V) | ��ʃN���A |\n");
		printf("| end  | name | number |   search   |    list    |   clear   |\n");
		scanf_s("%s", IfSearch, 7);

		//����������name
		if (strcmp("name", IfSearch) == 0)
		{
			//����
			printf("�������閼�O�����  ");
			scanf_s("%s", SeName, 20);
			printf("\n");

			//�T��
			while (*p != NULL)
			{
				//������
				if ( strcmp(SeName, (*p)->name) == 0)//���O�Ō���
				{
					//�\��
					printf("add | %*s |", -21, (*p)->name);
					printf("%s", (*p)->number);
					printf("\n");

					//�ҏW
					printf("���O����́@�ύX�Ȃ� -1  ");
					scanf_s("%s", NeName, 20);
					if (strcmp(NeName, "-1") != 0)
					{
						strcpy_s((*p)->name, 20, NeName);
						//���[�v�΍�
						pbox1 = *start;
					}
					else
					{
						//���[�v�΍�
						pbox1 = *p;
					}
					printf("�ԍ�����́@�ύX�Ȃ� -1  ");
					scanf_s("%s", NeNumber, 20);
					if (strcmp(NeNumber, "-1") != 0) strcpy_s((*p)->number,20, NeNumber);

					if (strcmp(NeName, "-1") != 0 || strcmp(NeNumber, "-1") != 0)
						caunt++;

					//�\�[�g����
					soot(p, start, last);
					*p = *start;

					//�t�@�C���ɃZ�b�g
					File_Set(p, start, last);
					*p = *start;

					//���[�v�΍�
					*p = pbox1;
				}
				//�|�C���^������
				(*p) = (*p)->next;
			}
			//�o�͌����@�o��
			printf("%d��\n", caunt);
			printf("\n");
			caunt = 0;
		}
		//����������number
		else if (strcmp("number", IfSearch) == 0)//�ԍ��Ō���
		{
			//����
			printf("��������ԍ������  ");
			scanf_s("%s", SeNumber, 20);

			//�T��
			while (*p != NULL)
			{
				//������
				if (strcmp(SeNumber, (*p)->number) == 0)
				{
					//�\���@���O�@�ԍ�
					printf("add | %*s |", -21, (*p)->name);
					printf("%s", (*p)->number);
					printf("\n");

					//�ҏW
					//���O
					printf("���O����́@�ύX�Ȃ� -1  ");
					scanf_s("%s", NeName, 20);
					if (strcmp(NeName, "-1") != 0)	strcpy_s((*p)->name, 20, NeName);
					

					//�ԍ�
					printf("�ԍ�����́@�ύX�Ȃ� -1  ");
					scanf_s("%s", NeNumber, 20);
					if (strcmp(NeNumber, "-1") != 0)
					{
						strcpy_s((*p)->number, 20, NeNumber);
						pbox1 = *start;
					}
					else
					{
						//���[�v�΍�
						pbox1 = *p;
					}
					if (strcmp(NeName, "-1") != 0 || strcmp(NeNumber, "-1") != 0)
						caunt++;

					

					//�\�[�g����
					soot(p, start, last);
					*p = *start;

					//�t�@�C���ɃZ�b�g
					File_Set(p, start, last);
					*p = *start;

					//���[�v�΍�
					*p = pbox1;
				}
				//�|�C���^������
				(*p) = (*p)->next;
			}
			//�o�͌����@�o��
			printf("%d��\n", caunt);
			printf("\n");
			caunt = 0;
		}
		//�I��
		else if (strcmp("end", IfSearch) == 0)
		{
		//�|�C���^�������ʒu�ɃZ�b�g
		*p = *start;
		return;
		}
		//����
		else if (strcmp("search", IfSearch) == 0)
		{
			printf("\n");
			search(p, start);
		}
		//�ꗗ
		else if (strcmp("list", IfSearch) == 0)
		{
			printf("\n");
			list(p, start);
		}
		//��ʂ��N���A
		else if (strcmp("clear", IfSearch) == 0)
		{
			system("cls");
		}
		

		printf("\n");
		//�|�C���^�������ʒu�ɃZ�b�g
		*p = *start;
	}

	//�ԋp�l
	return ;
}

