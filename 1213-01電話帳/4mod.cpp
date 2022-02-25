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
void mod(PhoneList** p, PhoneList* *start, PhoneList** last);
void soot(PhoneList** p, PhoneList* *start, PhoneList** last);
void list(PhoneList** p, PhoneList* *start);
void File_Set(PhoneList** p, PhoneList* *start, PhoneList** last);
void gomi();

void mod(PhoneList** p, PhoneList* *start, PhoneList** last)
{
	//ポインタを初期位置にセット
	*p = *start;

	/*** 宣言 ***/
	char IfSearch[7];
	char SeName[20];
	char SeNumber[20]; 
	char NeName[20];
	char NeNumber[20];
	int caunt = 0;
	PhoneList* pbox1;

	/*** 動作 ***/
	//コマンドがendでなければ
	while (strcmp(IfSearch, "end") != 0)
	{
		//コマンド入力　説明		
		printf("mode mod\n");
		printf("| 終了 | mod 検索対象  | 検索(更新) | 一覧(更新) | 画面クリア |\n");
		printf("| end  | name | number |   search   |    list    |   clear   |\n");
		scanf_s("%s", IfSearch, 7);

		//検索条件がname
		if (strcmp("name", IfSearch) == 0)
		{
			//検索
			printf("検索する名前を入力  ");
			scanf_s("%s", SeName, 20);
			printf("\n");

			//探す
			while (*p != NULL)
			{
				//見つかる
				if ( strcmp(SeName, (*p)->name) == 0)//名前で検索
				{
					//表示
					printf("add | %*s |", -21, (*p)->name);
					printf("%s", (*p)->number);
					printf("\n");

					//編集
					printf("名前を入力　変更なし -1  ");
					scanf_s("%s", NeName, 20);
					if (strcmp(NeName, "-1") != 0)
					{
						strcpy_s((*p)->name, 20, NeName);
						//ループ対策
						pbox1 = *start;
					}
					else
					{
						//ループ対策
						pbox1 = *p;
					}
					printf("番号を入力　変更なし -1  ");
					scanf_s("%s", NeNumber, 20);
					if (strcmp(NeNumber, "-1") != 0) strcpy_s((*p)->number,20, NeNumber);

					if (strcmp(NeName, "-1") != 0 || strcmp(NeNumber, "-1") != 0)
						caunt++;

					//ソート昇順
					soot(p, start, last);
					*p = *start;

					//ファイルにセット
					File_Set(p, start, last);
					*p = *start;

					//ループ対策
					*p = pbox1;
				}
				//ポインタを次へ
				(*p) = (*p)->next;
			}
			//出力件数　出力
			printf("%d件\n", caunt);
			printf("\n");
			caunt = 0;
		}
		//検索条件がnumber
		else if (strcmp("number", IfSearch) == 0)//番号で検索
		{
			//検索
			printf("検索する番号を入力  ");
			scanf_s("%s", SeNumber, 20);

			//探す
			while (*p != NULL)
			{
				//見つかる
				if (strcmp(SeNumber, (*p)->number) == 0)
				{
					//表示　名前　番号
					printf("add | %*s |", -21, (*p)->name);
					printf("%s", (*p)->number);
					printf("\n");

					//編集
					//名前
					printf("名前を入力　変更なし -1  ");
					scanf_s("%s", NeName, 20);
					if (strcmp(NeName, "-1") != 0)	strcpy_s((*p)->name, 20, NeName);
					

					//番号
					printf("番号を入力　変更なし -1  ");
					scanf_s("%s", NeNumber, 20);
					if (strcmp(NeNumber, "-1") != 0)
					{
						strcpy_s((*p)->number, 20, NeNumber);
						pbox1 = *start;
					}
					else
					{
						//ループ対策
						pbox1 = *p;
					}
					if (strcmp(NeName, "-1") != 0 || strcmp(NeNumber, "-1") != 0)
						caunt++;

					

					//ソート昇順
					soot(p, start, last);
					*p = *start;

					//ファイルにセット
					File_Set(p, start, last);
					*p = *start;

					//ループ対策
					*p = pbox1;
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
		else if (strcmp("end", IfSearch) == 0)
		{
		//ポインタを初期位置にセット
		*p = *start;
		return;
		}
		//検索
		else if (strcmp("search", IfSearch) == 0)
		{
			printf("\n");
			search(p, start);
		}
		//一覧
		else if (strcmp("list", IfSearch) == 0)
		{
			printf("\n");
			list(p, start);
		}
		//画面をクリア
		else if (strcmp("clear", IfSearch) == 0)
		{
			system("cls");
		}
		

		printf("\n");
		//ポインタを初期位置にセット
		*p = *start;
	}

	//返却値
	return ;
}

