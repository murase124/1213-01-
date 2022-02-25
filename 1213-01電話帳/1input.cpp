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

void input(PhoneList** p, PhoneList** start, PhoneList** last);
void File_input_Set(PhoneList** p, PhoneList** start, PhoneList** last);
void search(PhoneList** p, PhoneList** start);
void list(PhoneList** p, PhoneList** start);
void newregister(PhoneList** p,char* name,char* number);
void gomi();

void input(PhoneList** p, PhoneList** start, PhoneList** last)
{
	//�|�C���^�������ʒu�ɃZ�b�g
	*p = *last;

	/*** �錾 ***/
	char add[10];
	/*** �錾 ***/
	char name[20];
	char number[20];

	/*** ���� ***/

	//�R�}���h���́@����
	printf("mode input |    �o�^���� ");
	printf("\033[34m");   /* �����F��F�� */
	printf("����");
	printf("\033[39m");   /*�@�����F��W���F�� */
	printf(" |    �o�^���s ");
	printf("\033[31m");   /* �����F��ԐF�� */
	printf("�ԕ���\n");
	printf("\033[39m");   /*�@�����F��W���F�� */
	printf("| �I�� | ����(�X�V) | �ꗗ(�X�V) | ��ʃN���A |\n");
	printf("| end  |   search   |    list    |    clear   |\n\n");
	printf("�o�^���� | add ���O �ԍ�\n");

	//�R�}���h��end�łȂ����
	while (true)
	{
		add[0] = 0;
		//�R�}���h���́@add OR end
		scanf_s("%s", add, 10);

		//add�̎�
		if (strcmp("add", add) == 0)
		{
			//���́@���O�@�ԍ�
			scanf_s("%s", name, 20);
			scanf_s("%s", number, 20);

			if (name[0] != 0 && number[0] != 0)
			{
				//�\���̂ɓ���
				newregister(p, name, number);
				//�|�C���^�̍Ō��ݒ�
				*last = *p;

				//�����@�����ɂ���
				printf("\033[1A"); /* �J�[�\�����ړ� */
				printf("\033[34m");   /* �����F��F�� */
				printf("%s %s %s\n", add, name, number);  /* �o�� */
				printf("\033[39m");   /* �����F��W���F�� */

				//���͎̂Ă�
				gomi();

				//�t�@�C���ɃZ�b�g
				File_input_Set(p, start, last);
			}
			else
			{
				//���͎̂Ă�
				printf("\033[1A"); /* �J�[�\�����ړ� */
				printf("\033[31m");   /* �����F��ԐF�� */
				gomi();		/* �̂Ă� */
				printf("\033[K");   /*�@��s���� */
				printf("�������I�o�[\n");
				printf("\033[39m");   /*�@�����F��W���F�� */
			}
		}
		//end�̎�
		else if (strcmp("end", add) == 0)
		{
			//���͎̂Ă�
			gomi();
			//�|�C���^�������ʒu�ɃZ�b�g
			*p = *start;
			return;
		}
		//����
		else if (strcmp("search", add) == 0)
		{
			printf("\n");
			search(p, start);

			//�R�}���h���́@����
			printf("mode input\n");
			printf("�I���R�}���h end �ꗗ(�X�V)�@search\n");
			printf("�o�^�����@add ���O �ԍ�\n");
		}//�ꗗ
		else if (strcmp("list", add) == 0)
		{
			printf("\n");
			list(p, start);

			//�R�}���h���́@����
			printf("mode input\n");
			printf("�I���R�}���h end �ꗗ(�X�V)�@search\n");
			printf("�o�^�����@add ���O �ԍ�\n");
		}
		//��ʂ��N���A
		else if (strcmp("clear", add) == 0)
		{
			system("cls");
			printf("�I���R�}���h end �ꗗ(�X�V)�@search\n");
			printf("�o�^�����@add ���O �ԍ�\n");
		}
		//����ȊO
		else if (add[0] != 0)
		{
			//���͎̂Ă�
			printf("\033[1A"); /* �J�[�\�����ړ� */
			printf("\033[31m");   /* �����F��ԐF�� */
			printf("%s", add);
			while (true)
			{
				char gomi;
				//����
				scanf_s("%c", &gomi, 1);
				//�o��
				printf("%c", gomi);
				//�̂ďI����Ă�
				if (gomi == '\n')
					break;
			}
			printf("\033[39m");   /*�@�����F��W���F�� */
		}
		else
		{
			//add �������I�[�o�[
			//���͎̂Ă�
			printf("\033[1A");        /* �J�[�\�����ړ� */
			printf("\033[31m");		  /* �����F��ԐF�� */
			gomi();					  /* �̂Ă� */
			printf("\033[K");		  /*�@��s���� */
			printf("�������I�o�[\n");
			printf("\033[39m");		  /*�@�����F��W���F�� */
		}
	}
} 

//���O�@�ԍ��@�ǉ�
void newregister(PhoneList** p,char* name,char* number)
{
	//�\���̒ǉ�
	if ((*p)->name[0] != NULL) 
	{
		(*p)->next = (PhoneList*)malloc(sizeof(PhoneList));
		(*p)->next->Back_next = (*p);
		(*p) = (*p)->next;
		(*p)->next = NULL;
	}

	//���O�@�d�b�@�ǉ��@
	strcpy_s((*p)->name, 20,name);
	strcpy_s((*p)->number,20, number);
}

