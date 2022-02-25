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

/*** 電話帳を全て出力 ***/
void list(PhoneList** p, PhoneList** start)
{
	//ポインタを初期位置にセット
	*p = *start;

	/*** 宣言 ***/
	int caunt = 0;

	/*** 動作 ***/
	printf("mode list\n");
	printf("\n");

	//構造体ポインタを最初からたどりNULLになったら終わる
	while ((*p)!=NULL)
	{
		caunt++;
		//名前　番号　出力
		printf("add | %*s |",-21, (*p)->name);
		printf("%s", (*p)->number);
		printf("\n");
		//次のデータへ
		(*p) = (*p)->next;
	}
	//出力件数　出力
	printf("%d件\n", caunt);
	printf("\n");

	*p = *start;

}