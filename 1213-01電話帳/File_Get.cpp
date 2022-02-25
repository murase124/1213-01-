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

/*** ファイルの電話帳を構造体に全て入れる ***/
void File_Get(PhoneList** p, PhoneList* *start, PhoneList** last)
{
	//ポインタを初期位置にセット
	*last = *p;

	/*** 宣言 ***/
	int i;
	char reading[60];
	FILE* fp;

	/*** 動作 ***/
	//ファイルを開く
	if(fopen_s(&fp,"add.txt", "r"))
	{
		printf("ファイルエラー");
		return ;
	}

	//ファイルの電話帳を構造体に入力
	for (i = 1;; i++)
	{
		//ファイルから一行読み込み　　最後まで入れたら終了
		if (fgets(reading, 60, fp) == NULL)
			break;

		//読み込んだ一行を　構造体へ入力
		value(p, reading);
	}

	//ファイルを閉じる
	fclose(fp);

	//ポインタを初期位置にセット
	*last = *p;
}


//名前　番号　追加
void value(PhoneList** p, char* reading)
{
	/*** 宣言 ***/
	int i = 0;
	int j;


	//構造体追加
	if ((*p)->name[0] != NULL)
	{
		(*p)->next = (PhoneList*)malloc(sizeof(PhoneList));
		(*p)->next->Back_next = (*p);
		(*p) = (*p)->next;
		(*p)->next = NULL;
	}

	/*** 動作 ***/

	/*** 名前　電話　追加 ***/
	//addを消す
	for (j = 0; reading[j] != ' '; j++);
	//nameを入力
	for (j = j + 1; reading[j] != ' '; j++)
	{
		(*p)->name[i] = reading[j];
		i++;
	}
	//最後にヌルを
	(*p)->name[i] = '\0';

	//初期化
	i = 0;
	//番号を入力
	for (j = j + 1; reading[j] != '\n'; j++)
	{
		(*p)->number[i] = reading[j];
		i++;
	}
	//最後にヌルを
	(*p)->number[i] = '\0';


}
