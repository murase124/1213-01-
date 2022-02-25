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
	//ポインタを初期位置にセット
	*p = *last;

	/*** 宣言 ***/
	char add[10];
	/*** 宣言 ***/
	char name[20];
	char number[20];

	/*** 動作 ***/

	//コマンド入力　説明
	printf("mode input |    登録完了 ");
	printf("\033[34m");   /* 文字色を青色に */
	printf("青文字");
	printf("\033[39m");   /*　文字色を標準色に */
	printf(" |    登録失敗 ");
	printf("\033[31m");   /* 文字色を赤色に */
	printf("赤文字\n");
	printf("\033[39m");   /*　文字色を標準色に */
	printf("| 終了 | 検索(更新) | 一覧(更新) | 画面クリア |\n");
	printf("| end  |   search   |    list    |    clear   |\n\n");
	printf("登録書式 | add 名前 番号\n");

	//コマンドがendでなければ
	while (true)
	{
		add[0] = 0;
		//コマンド入力　add OR end
		scanf_s("%s", add, 10);

		//addの時
		if (strcmp("add", add) == 0)
		{
			//入力　名前　番号
			scanf_s("%s", name, 20);
			scanf_s("%s", number, 20);

			if (name[0] != 0 && number[0] != 0)
			{
				//構造体に入力
				newregister(p, name, number);
				//ポインタの最後を設定
				*last = *p;

				//成功　青文字にする
				printf("\033[1A"); /* カーソルを移動 */
				printf("\033[34m");   /* 文字色を青色に */
				printf("%s %s %s\n", add, name, number);  /* 出力 */
				printf("\033[39m");   /* 文字色を標準色に */

				//入力捨てる
				gomi();

				//ファイルにセット
				File_input_Set(p, start, last);
			}
			else
			{
				//入力捨てる
				printf("\033[1A"); /* カーソルを移動 */
				printf("\033[31m");   /* 文字色を赤色に */
				gomi();		/* 捨てる */
				printf("\033[K");   /*　一行消去 */
				printf("文字数オバー\n");
				printf("\033[39m");   /*　文字色を標準色に */
			}
		}
		//endの時
		else if (strcmp("end", add) == 0)
		{
			//入力捨てる
			gomi();
			//ポインタを初期位置にセット
			*p = *start;
			return;
		}
		//検索
		else if (strcmp("search", add) == 0)
		{
			printf("\n");
			search(p, start);

			//コマンド入力　説明
			printf("mode input\n");
			printf("終了コマンド end 一覧(更新)　search\n");
			printf("登録書式　add 名前 番号\n");
		}//一覧
		else if (strcmp("list", add) == 0)
		{
			printf("\n");
			list(p, start);

			//コマンド入力　説明
			printf("mode input\n");
			printf("終了コマンド end 一覧(更新)　search\n");
			printf("登録書式　add 名前 番号\n");
		}
		//画面をクリア
		else if (strcmp("clear", add) == 0)
		{
			system("cls");
			printf("終了コマンド end 一覧(更新)　search\n");
			printf("登録書式　add 名前 番号\n");
		}
		//それ以外
		else if (add[0] != 0)
		{
			//入力捨てる
			printf("\033[1A"); /* カーソルを移動 */
			printf("\033[31m");   /* 文字色を赤色に */
			printf("%s", add);
			while (true)
			{
				char gomi;
				//入力
				scanf_s("%c", &gomi, 1);
				//出力
				printf("%c", gomi);
				//捨て終わってら
				if (gomi == '\n')
					break;
			}
			printf("\033[39m");   /*　文字色を標準色に */
		}
		else
		{
			//add が文字オーバー
			//入力捨てる
			printf("\033[1A");        /* カーソルを移動 */
			printf("\033[31m");		  /* 文字色を赤色に */
			gomi();					  /* 捨てる */
			printf("\033[K");		  /*　一行消去 */
			printf("文字数オバー\n");
			printf("\033[39m");		  /*　文字色を標準色に */
		}
	}
} 

//名前　番号　追加
void newregister(PhoneList** p,char* name,char* number)
{
	//構造体追加
	if ((*p)->name[0] != NULL) 
	{
		(*p)->next = (PhoneList*)malloc(sizeof(PhoneList));
		(*p)->next->Back_next = (*p);
		(*p) = (*p)->next;
		(*p)->next = NULL;
	}

	//名前　電話　追加　
	strcpy_s((*p)->name, 20,name);
	strcpy_s((*p)->number,20, number);
}

