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

void search(PhoneList** p, PhoneList* *start);
void soot(PhoneList** p, PhoneList** start, PhoneList** last);
void del(PhoneList** p, PhoneList* *start, PhoneList** last);
void list(PhoneList** p, PhoneList* *start);
void File_Set(PhoneList** p, PhoneList* *start, PhoneList** last);
bool del_process(PhoneList** p, PhoneList* *start, PhoneList** last);
void gomi();

/*** データ消去 ***/
void del(PhoneList** p, PhoneList** start, PhoneList** last)
{
	//ポインタを初期位置にセット
	*p = *start;

	/*** 宣言 ***/
	char flg_search[7];
	char SeName[20];
	char SeNumber[20];
	char NeName[20];
	char NeNumber[20];
	int caunt = 0;
	PhoneList* pbox1;

	/*** 動作 ***/
	//コマンドがendでなければ
	while (true)
	{
		//コマンド入力　説明
		printf("mode del\n");
		printf("| 終了 |   検索対象    | 検索(更新) | 一覧(更新) | 画面クリア |\n");
		printf("| end  | name | number |   search   |    list    |   clear   |\n");
		scanf_s("%s", flg_search, 7);
		printf("\n");

		//消去の検索をnameでする
		if (strcmp("name", flg_search) == 0)
		{
			//検索
			printf("検索する名前を入力  ");
			scanf_s("%s", SeName, 20);

			//探す
			while (*p != NULL)
			{
				//見つかる
				if (strcmp(SeName, (*p)->name) == 0)//名前で検索
				{
					//表示　名前　番号
					printf("add | %*s |", -21, (*p)->name);
					printf("%s", (*p)->number);
					printf("\n");

					//消去　選択
					do
					{
						printf("消去 del,　変更なし -1  ");
						scanf_s("%s", NeName, 20);
					} while (strcmp(NeName, "del") != 0 && strcmp(NeName, "-1") != 0);
					//消去処理
					if (strcmp(NeName, "del") == 0)
					{
						caunt++;
						if (del_process(p, start, last))
						{
							*start = *p;
							return;
						}
					}
				}
				//ポインタを次へ
				(*p) = (*p)->next;
			}
			//出力件数　出力
			printf("%d件\n", caunt);
			printf("\n");
			caunt = 0;
		}
		//消去の検索を番号でする
		else if (strcmp("number", flg_search) == 0)//番号で検索
		{
			//検索
			printf("検索する番号を入力  ");
			scanf_s("%s", SeNumber, 20);

			//探す
			while (*p != NULL)
			{
				//見つかる
				if (strcmp((*p)->number, SeNumber) == 0)
				{
					//表示　名前　番号
					printf("add | %*s |", -21, (*p)->name);
					printf("%s", (*p)->number);
					printf("\n");

					//消去選択
					do
					{
						printf("消去 del,　変更なし -1  ");
						scanf_s("%s", NeName, 20);
					} while (strcmp(NeName, "del") != 0 && strcmp(NeName, "-1") != 0);
					//消去処理
					if (strcmp(NeName, "del") == 0)
					{
						caunt++;
						if (del_process(p, start, last))
						{
							*start = *p;
							return;
						}
					}
				}
				//ポインタを次へ
				(*p) = (*p)->next;
			}
			//出力件数　出力
			printf("%d件\n", caunt);
			printf("\n");
			caunt = 0;
		}
		//終了
		else if (strcmp("end" , flg_search) == 0)
		{
			//ポインタを初期位置にセット
			*p = *start;
			return;
		}
		//検索
		else if (strcmp("search", flg_search) == 0)
		{
			printf("\n");
			search(p, start);
		}
		//一覧
		else if (strcmp("list", flg_search) == 0)
		{
			printf("\n");
			list(p, start);
		}
		//画面をクリア
		else if (strcmp("clear", flg_search) == 0)
		{
			system("cls");
		}
		

		printf("\n");
		//ポインタを初期位置にセット
		*p = *start;
	}
	
}

bool del_process(PhoneList** p, PhoneList* *start, PhoneList** last)
{
	PhoneList* pbox1;
	char NeName[21];

	//ポインタが最初の時
	if ((*p)->Back_next == NULL)
	{
		//ポインタが一個の時　false
		if ((*p)->next != NULL)
		{
			(*p)->next->Back_next = NULL;
			*start = (*p)->next;
			pbox1 = *start;
		}
		else
		{
			//データが空の時
			*start = (*p);
			(*p)->name[0] = NULL;
			(*p)->next = NULL;
			(*p)->Back_next = NULL;
			printf("データが空になりました");

			//ファイルにセット
			File_Set(p, start, last);
			//ポインタを初期位置にセット
			*p = *start;
			return true;
		}
	}
	//ポインタが最後の時
	else if ((*p)->next == NULL)
	{
		pbox1 = (*p)->Back_next;
		(*p)->Back_next->next = NULL;
	}
	//それ以外
	else
	{
		(*p)->Back_next->next = (*p)->next;
		(*p)->next->Back_next = (*p)->Back_next;
		pbox1 = (*p)->Back_next;
	}

	//メモリ解放
	free(*p);

	//ループ対策
	//ソート昇順
	soot(p, start, last);
	*p = *start;

	//ファイルにセット
	File_Set(p, start, last);
	//ポインタを初期位置にセット
	*p = *start;

	//ループ対策
	*p = pbox1;
	return false;
}