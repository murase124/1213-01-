#include<stdio.h>
#include<string.h>

typedef struct _PhoneList
{
	char name[21];
	char number[21];
	struct _PhoneList* next;
	struct _PhoneList* Back_next;
}PhoneList;

void list(PhoneList** p, PhoneList** start);
void gomi();

/*** �d�b����S�ďo�� ***/
void list(PhoneList** p, PhoneList** start)
{
	//�|�C���^�������ʒu�ɃZ�b�g
	*p = *start;

	/*** �錾 ***/
	int caunt = 0;

	/*** ���� ***/
	printf("mode list\n");
	printf("\n");

	//�\���̃|�C���^���ŏ����炽�ǂ�NULL�ɂȂ�����I���
	while ((*p)!=NULL)
	{
		caunt++;
		//���O�@�ԍ��@�o��
		printf("add | %*s |",-21, (*p)->name);
		printf("%s", (*p)->number);
		printf("\n");
		//���̃f�[�^��
		(*p) = (*p)->next;
	}
	//�o�͌����@�o��
	printf("%d��\n", caunt);
	printf("\n");

	*p = *start;

}