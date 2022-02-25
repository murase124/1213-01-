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
void soot(PhoneList** p, PhoneList** start, PhoneList** last);
void del(PhoneList** p, PhoneList* *start, PhoneList** last);
void list(PhoneList** p, PhoneList* *start);
void File_Set(PhoneList** p, PhoneList* *start, PhoneList** last);
bool del_process(PhoneList** p, PhoneList* *start, PhoneList** last);
void gomi();

/*** �f�[�^���� ***/
void del(PhoneList** p, PhoneList** start, PhoneList** last)
{
	//�|�C���^�������ʒu�ɃZ�b�g
	*p = *start;

	/*** �錾 ***/
	char flg_search[7];
	char SeName[20];
	char SeNumber[20];
	char NeName[20];
	char NeNumber[20];
	int caunt = 0;
	PhoneList* pbox1;

	/*** ���� ***/
	//�R�}���h��end�łȂ����
	while (true)
	{
		//�R�}���h���́@����
		printf("mode del\n");
		printf("| �I�� |   �����Ώ�    | ����(�X�V) | �ꗗ(�X�V) | ��ʃN���A |\n");
		printf("| end  | name | number |   search   |    list    |   clear   |\n");
		scanf_s("%s", flg_search, 7);
		printf("\n");

		//�����̌�����name�ł���
		if (strcmp("name", flg_search) == 0)
		{
			//����
			printf("�������閼�O�����  ");
			scanf_s("%s", SeName, 20);

			//�T��
			while (*p != NULL)
			{
				//������
				if (strcmp(SeName, (*p)->name) == 0)//���O�Ō���
				{
					//�\���@���O�@�ԍ�
					printf("add | %*s |", -21, (*p)->name);
					printf("%s", (*p)->number);
					printf("\n");

					//�����@�I��
					do
					{
						printf("���� del,�@�ύX�Ȃ� -1  ");
						scanf_s("%s", NeName, 20);
					} while (strcmp(NeName, "del") != 0 && strcmp(NeName, "-1") != 0);
					//��������
					if (strcmp(NeName, "del") == 0)
					{
						caunt++;
						if (del_process(p, start, last))
						{
							*start = *p;
							return;
						}
					}
				}
				//�|�C���^������
				(*p) = (*p)->next;
			}
			//�o�͌����@�o��
			printf("%d��\n", caunt);
			printf("\n");
			caunt = 0;
		}
		//�����̌�����ԍ��ł���
		else if (strcmp("number", flg_search) == 0)//�ԍ��Ō���
		{
			//����
			printf("��������ԍ������  ");
			scanf_s("%s", SeNumber, 20);

			//�T��
			while (*p != NULL)
			{
				//������
				if (strcmp((*p)->number, SeNumber) == 0)
				{
					//�\���@���O�@�ԍ�
					printf("add | %*s |", -21, (*p)->name);
					printf("%s", (*p)->number);
					printf("\n");

					//�����I��
					do
					{
						printf("���� del,�@�ύX�Ȃ� -1  ");
						scanf_s("%s", NeName, 20);
					} while (strcmp(NeName, "del") != 0 && strcmp(NeName, "-1") != 0);
					//��������
					if (strcmp(NeName, "del") == 0)
					{
						caunt++;
						if (del_process(p, start, last))
						{
							*start = *p;
							return;
						}
					}
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
		else if (strcmp("end" , flg_search) == 0)
		{
			//�|�C���^�������ʒu�ɃZ�b�g
			*p = *start;
			return;
		}
		//����
		else if (strcmp("search", flg_search) == 0)
		{
			printf("\n");
			search(p, start);
		}
		//�ꗗ
		else if (strcmp("list", flg_search) == 0)
		{
			printf("\n");
			list(p, start);
		}
		//��ʂ��N���A
		else if (strcmp("clear", flg_search) == 0)
		{
			system("cls");
		}
		

		printf("\n");
		//�|�C���^�������ʒu�ɃZ�b�g
		*p = *start;
	}
	
}

bool del_process(PhoneList** p, PhoneList* *start, PhoneList** last)
{
	PhoneList* pbox1;
	char NeName[21];

	//�|�C���^���ŏ��̎�
	if ((*p)->Back_next == NULL)
	{
		//�|�C���^����̎��@false
		if ((*p)->next != NULL)
		{
			(*p)->next->Back_next = NULL;
			*start = (*p)->next;
			pbox1 = *start;
		}
		else
		{
			//�f�[�^����̎�
			*start = (*p);
			(*p)->name[0] = NULL;
			(*p)->next = NULL;
			(*p)->Back_next = NULL;
			printf("�f�[�^����ɂȂ�܂���");

			//�t�@�C���ɃZ�b�g
			File_Set(p, start, last);
			//�|�C���^�������ʒu�ɃZ�b�g
			*p = *start;
			return true;
		}
	}
	//�|�C���^���Ō�̎�
	else if ((*p)->next == NULL)
	{
		pbox1 = (*p)->Back_next;
		(*p)->Back_next->next = NULL;
	}
	//����ȊO
	else
	{
		(*p)->Back_next->next = (*p)->next;
		(*p)->next->Back_next = (*p)->Back_next;
		pbox1 = (*p)->Back_next;
	}

	//���������
	free(*p);

	//���[�v�΍�
	//�\�[�g����
	soot(p, start, last);
	*p = *start;

	//�t�@�C���ɃZ�b�g
	File_Set(p, start, last);
	//�|�C���^�������ʒu�ɃZ�b�g
	*p = *start;

	//���[�v�΍�
	*p = pbox1;
	return false;
}