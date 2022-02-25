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

void soot(PhoneList** p, PhoneList** start, PhoneList** last);
void del(PhoneList** p, PhoneList** start, PhoneList** last);
void mod(PhoneList** p, PhoneList** start, PhoneList** last);
void input(PhoneList** p, PhoneList** start, PhoneList** last);
void File_Get(PhoneList** p, PhoneList** start, PhoneList** last);
void File_Set(PhoneList** p, PhoneList** start, PhoneList** last);
void list(PhoneList** p, PhoneList** start);
void search(PhoneList** p, PhoneList** start);
void gomi();

int main()
{
	printf("\033[39m");   /*�@�����F��W���F�� */

	/*** �錾 ***/
	//�R�}���h�ǂݎ��
	char command[10];
	//�X�C�b�`���@����t���O
	int flg = -1;

	/*** �\���̐錾 ***/
	//�\���̂̃|�C���^�̃|�C���^
	PhoneList** p;
	//�\���̂̃|�C���^
	PhoneList* p1;
	//�\���̂̃|�C���^�̍ŏ�
	PhoneList* start;
	//�\���̂̃|�C���^�̍Ō�
	PhoneList* last;
	
	//�\���̍쐬
	p1 = (PhoneList*)malloc(sizeof(PhoneList));
	//�\���̂̃|�C���^���|�C���^�ɓ����
	p = &p1;
	//�\���̂̃|�C���^�̍ŏ����Z�b�g
	start = p1;
	//�\���̂̃|�C���^�̍Ō���Z�b�g
	last = p1;
	
	//�\���̂̒��g��ݒ�
	(*p)->name[0] = NULL;
	(*p)->next = NULL;
	(*p)->Back_next = NULL;

	/*** �N�����̐ݒ� ***/
	//�t�@�C���ǂݍ���
	File_Get(p, &start, &last);
	*p = start;
	//�\�[�g����
	soot(p, &start, &last);
	*p = start;
	printf("�d�b��\n");
	//�I���R�}���h���ɔ�����
	while (true)
	{
		/*** ���� ***/
		//�R�}���h�@����
		printf("mode Function_selection\n");
		printf("| �I�� | �ǉ�  | �ꗗ |  ����  | �ҏW | �폜 | �N���A |\n");
		printf("| exit | input | list | search | mod  | del  | clear  |\n");
		scanf_s("%s[^\0]", command, 10);
		//���͗]�����
		gomi();

		/*** �R�}���h���t���O�ɕϊ��@�X�C�b�`���p ***/
		//�ϊ��@switch�Ŏg�p�̂���
		if (strcmp(command, "exit") == 0)	flg = 0;
		if (strcmp(command, "input") == 0)	flg = 1;
		if (strcmp(command, "list") == 0)	flg = 2;
		if (strcmp(command, "search") == 0)	flg = 3;
		if (strcmp(command, "mod") == 0)	flg = 4;
		if (strcmp(command, "del") == 0)	flg = 5;

		if ((*p)->name[0] == NULL && (flg != 0 && flg != 1) && flg == -1)	flg = -2;
		if (strcmp(command, "clear") == 0)	flg = -3;

		/*** ��ʃN���A ***/
		system("cls");

		/*** ����I�� ***/

		switch (flg)
		{
		case(-3)://��ʃN���A
			break;

		case(-2)://�f�[�^����
			printf("�d�b���͋�ł�");
			break;
		case(0)://�I��
			if ((*p)->next != NULL)
			{
				*p = start->next;
				while (true)
				{
					free((*p)->Back_next);
					if ((*p)->next == NULL)
					{
						break;
					}
					*p = (*p)->next;
				}
			}
			free(*p);
			return 0;
			break;

		case(1)://�d�b���ɓo�^
			input(p, &start, &last);
			soot(p, &start, &last);
			File_Set(p, &start, &last);
			break;

		case(2)://�d�b����S�ďo��
			list(p, &start);
			break;

		case(3)://�d�b�����������ďo��
			search(p, &start);
			break;

		case(4)://�d�b���̃f�[�^��ҏW�i�P���j
			mod(p, &start,&last);
			soot(p, &start,&last);
			last = *p;
			break;

		case(5)://�d�b���̃f�[�^���폜�i�P���j
			del(p, &start,&last);
			break;

		default://�R�}���h�ȊO�̓���
			printf("�����G���[");
			break;
		}
		//�Ԃ��J����
		printf("\n");

		/*** ������ ***/
		//�t���O��������
		flg = -1;
		//�|�C���^�������ʒu�ɃZ�b�g
		*p = start;
	}	
}


