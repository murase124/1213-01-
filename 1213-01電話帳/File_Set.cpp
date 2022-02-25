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

/*** ファイルに電話帳を全て保存 ***/
void File_Set(PhoneList** p, PhoneList* *start, PhoneList** last)
{
	//ポインタを初期位置にセット
	*p = *start;

	/*** 宣言 ***/
	int i;
	char reading[60];
	FILE* fp;

	/*** 動作 ***/

	//ファイルを開く
	if (fopen_s(&fp, "add.txt", "w"))
	{
		printf("ファイルエラー");
		return;
	}

	//最初から最後まで全て書き込む
	while ((*p) != NULL)
	{
		//書き込む
		fprintf(fp, "add %s %s\n", (*p)->name, (*p)->number);
		//ポインタを次へ
		(*p) = (*p)->next;
	}

	//ファイルを閉じる
	fclose(fp);
}

/*** input時の途中終了対策 ***/
void File_input_Set(PhoneList** p, PhoneList* *start, PhoneList** last)
{
	/*** 宣言 ***/
	int i;
	char reading[60];
	FILE* fp;

	/*** 動作 ***/
	//ファイル開く
	if (fopen_s(&fp, "add.txt", "a"))
	{
		printf("ファイルエラー");
		return;
	}
	//ファイルの最後に書き込み
	if ((*p)->name[0] == NULL)
	{
		//データが空の時
		fprintf(fp, "\n");
	}
	else
	{
		fprintf(fp, "add %s %s\n", (*p)->name, (*p)->number);
	}

	//ファイルを閉じる
	fclose(fp);

}