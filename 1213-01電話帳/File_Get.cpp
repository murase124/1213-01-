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

void input(PhoneList** p, PhoneList* *start, PhoneList** last);
void File_Get(PhoneList** p, PhoneList* *start, PhoneList** last);
void value(PhoneList** p, char* reading);
//void gomi();

/*** �t�@�C���̓d�b�����\���̂ɑS�ē���� ***/
void File_Get(PhoneList** p, PhoneList* *start, PhoneList** last)
{
	//�|�C���^�������ʒu�ɃZ�b�g
	*last = *p;

	/*** �錾 ***/
	int i;
	char reading[60];
	FILE* fp;

	/*** ���� ***/
	//�t�@�C�����J��
	if(fopen_s(&fp,"add.txt", "r"))
	{
		printf("�t�@�C���G���[");
		return ;
	}

	//�t�@�C���̓d�b�����\���̂ɓ���
	for (i = 1;; i++)
	{
		//�t�@�C�������s�ǂݍ��݁@�@�Ō�܂œ��ꂽ��I��
		if (fgets(reading, 60, fp) == NULL)
			break;

		//�ǂݍ��񂾈�s���@�\���̂֓���
		value(p, reading);
	}

	//�t�@�C�������
	fclose(fp);

	//�|�C���^�������ʒu�ɃZ�b�g
	*last = *p;
}


//���O�@�ԍ��@�ǉ�
void value(PhoneList** p, char* reading)
{
	/*** �錾 ***/
	int i = 0;
	int j;


	//�\���̒ǉ�
	if ((*p)->name[0] != NULL)
	{
		(*p)->next = (PhoneList*)malloc(sizeof(PhoneList));
		(*p)->next->Back_next = (*p);
		(*p) = (*p)->next;
		(*p)->next = NULL;
	}

	/*** ���� ***/

	/*** ���O�@�d�b�@�ǉ� ***/
	//add������
	for (j = 0; reading[j] != ' '; j++);
	//name�����
	for (j = j + 1; reading[j] != ' '; j++)
	{
		(*p)->name[i] = reading[j];
		i++;
	}
	//�Ō�Ƀk����
	(*p)->name[i] = '\0';

	//������
	i = 0;
	//�ԍ������
	for (j = j + 1; reading[j] != '\n'; j++)
	{
		(*p)->number[i] = reading[j];
		i++;
	}
	//�Ō�Ƀk����
	(*p)->number[i] = '\0';


}
