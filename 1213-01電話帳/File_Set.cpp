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

//void input(PhoneList** p, PhoneList* *start, PhoneList** last);
void File_input_Set(PhoneList** p, PhoneList* *start, PhoneList** last);
void File_Set(PhoneList** p, PhoneList* *start, PhoneList** last);
//void newregister(PhoneList** p, char* reading);
//void gomi();

/*** �t�@�C���ɓd�b����S�ĕۑ� ***/
void File_Set(PhoneList** p, PhoneList* *start, PhoneList** last)
{
	//�|�C���^�������ʒu�ɃZ�b�g
	*p = *start;

	/*** �錾 ***/
	int i;
	char reading[60];
	FILE* fp;

	/*** ���� ***/

	//�t�@�C�����J��
	if (fopen_s(&fp, "add.txt", "w"))
	{
		printf("�t�@�C���G���[");
		return;
	}

	//�ŏ�����Ō�܂őS�ď�������
	while ((*p) != NULL)
	{
		//��������
		fprintf(fp, "add %s %s\n", (*p)->name, (*p)->number);
		//�|�C���^������
		(*p) = (*p)->next;
	}

	//�t�@�C�������
	fclose(fp);
}

/*** input���̓r���I���΍� ***/
void File_input_Set(PhoneList** p, PhoneList* *start, PhoneList** last)
{
	/*** �錾 ***/
	int i;
	char reading[60];
	FILE* fp;

	/*** ���� ***/
	//�t�@�C���J��
	if (fopen_s(&fp, "add.txt", "a"))
	{
		printf("�t�@�C���G���[");
		return;
	}
	//�t�@�C���̍Ō�ɏ�������
	if ((*p)->name[0] == NULL)
	{
		//�f�[�^����̎�
		fprintf(fp, "\n");
	}
	else
	{
		fprintf(fp, "add %s %s\n", (*p)->name, (*p)->number);
	}

	//�t�@�C�������
	fclose(fp);

}