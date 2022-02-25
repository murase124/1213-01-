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
	printf("\033[39m");   /*　文字色を標準色に */

	/*** 宣言 ***/
	//コマンド読み取り
	char command[10];
	//スイッチ文　判定フラグ
	int flg = -1;

	/*** 構造体宣言 ***/
	//構造体のポインタのポインタ
	PhoneList** p;
	//構造体のポインタ
	PhoneList* p1;
	//構造体のポインタの最初
	PhoneList* start;
	//構造体のポインタの最後
	PhoneList* last;
	
	//構造体作成
	p1 = (PhoneList*)malloc(sizeof(PhoneList));
	//構造体のポインタをポインタに入れる
	p = &p1;
	//構造体のポインタの最初をセット
	start = p1;
	//構造体のポインタの最後をセット
	last = p1;
	
	//構造体の中身を設定
	(*p)->name[0] = NULL;
	(*p)->next = NULL;
	(*p)->Back_next = NULL;

	/*** 起動時の設定 ***/
	//ファイル読み込み
	File_Get(p, &start, &last);
	*p = start;
	//ソート昇順
	soot(p, &start, &last);
	*p = start;
	printf("電話帳\n");
	//終了コマンド時に抜ける
	while (true)
	{
		/*** 入力 ***/
		//コマンド　入力
		printf("mode Function_selection\n");
		printf("| 終了 | 追加  | 一覧 |  検索  | 編集 | 削除 | クリア |\n");
		printf("| exit | input | list | search | mod  | del  | clear  |\n");
		scanf_s("%s[^\0]", command, 10);
		//入力余り消去
		gomi();

		/*** コマンドをフラグに変換　スイッチ文用 ***/
		//変換　switchで使用のため
		if (strcmp(command, "exit") == 0)	flg = 0;
		if (strcmp(command, "input") == 0)	flg = 1;
		if (strcmp(command, "list") == 0)	flg = 2;
		if (strcmp(command, "search") == 0)	flg = 3;
		if (strcmp(command, "mod") == 0)	flg = 4;
		if (strcmp(command, "del") == 0)	flg = 5;

		if ((*p)->name[0] == NULL && (flg != 0 && flg != 1) && flg == -1)	flg = -2;
		if (strcmp(command, "clear") == 0)	flg = -3;

		/*** 画面クリア ***/
		system("cls");

		/*** 動作選択 ***/

		switch (flg)
		{
		case(-3)://画面クリア
			break;

		case(-2)://データが空
			printf("電話帳は空です");
			break;
		case(0)://終了
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

		case(1)://電話帳に登録
			input(p, &start, &last);
			soot(p, &start, &last);
			File_Set(p, &start, &last);
			break;

		case(2)://電話帳を全て出力
			list(p, &start);
			break;

		case(3)://電話帳を検索して出力
			search(p, &start);
			break;

		case(4)://電話帳のデータを編集（１件）
			mod(p, &start,&last);
			soot(p, &start,&last);
			last = *p;
			break;

		case(5)://電話帳のデータを削除（１件）
			del(p, &start,&last);
			break;

		default://コマンド以外の入力
			printf("文字エラー");
			break;
		}
		//間を開ける
		printf("\n");

		/*** 初期化 ***/
		//フラグを初期化
		flg = -1;
		//ポインタを初期位置にセット
		*p = start;
	}	
}


