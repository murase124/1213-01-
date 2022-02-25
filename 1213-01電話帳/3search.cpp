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


void search(PhoneList** p, PhoneList** start);
void list(PhoneList** p, PhoneList** start);
char* lowerstring_ver2(char* in);
void gomi();

void search(PhoneList** p, PhoneList** start)
{
	//ポインタを初期位置にセット
	*p = *start;

	/*** 宣言 ***/
	char search[7];
	char Name[20];
	char* PName;
	char SeName[20];
	char* PSeName;
	char SeNameMax[20];
	char* PSeNameMax;
	char SeNumber[20];
	char SeNumberMax[20];
	int caunt = 0;

	/*** 動作 ***/
	//コマンドがendでなければ
	while (true)
	{
		//コマンド入力　説明
		printf("mode search\n");
		printf("| 終了 |   検索対象    | 一覧 | 画面クリア |\n");
		printf("| end  | name | number | list |    clear   |\n");
		scanf_s("%s", search, 7);
		printf("\n");

		//検索条件がname
		if (strcmp("name", search) == 0)
		{
			//検索
			printf("検索する名前を入力  ");
			scanf_s("%s", SeName, 20);
			//探す
			while (*p != NULL)
			{
				//検索文字も長さ
				int len = strlen(SeName);
				//検索文字をコピー
				strcpy_s(SeNameMax, SeName);
				strcpy_s(Name,(*p)->name);

				//最後の文字に対して文字コード＋１
				SeNameMax[len - 1] = SeName[len - 1] + 1;	
				//小文字にそろえる
				PSeName = lowerstring_ver2(SeName);
				PName = lowerstring_ver2(Name);
				PSeNameMax = lowerstring_ver2(SeNameMax);

				//見つかる　最初から検索文字数まで同じ
				//if (strcmp(lowerstring_ver2((*p)->name),lowerstring_ver2( SeName)) >= 0 && strcmp(lowerstring_ver2(SeNameMax),lowerstring_ver2((*p)->name)) > 0)
				if (strcmp(PName, PSeName) >= 0 && strcmp(PSeNameMax, PName) > 0)
				{
					caunt++;
					//出力
					printf("add | %*s |",-21, (*p)->name);
					printf("%s", (*p)->number);
					printf("\n");
				}
				//ポインタを次へ
				(*p) = (*p)->next;
			}
			//出力件数　出力
			printf("%d件\n", caunt);
			caunt = 0;
		}
		//検索条件がnumber
		else if (strcmp("number", search) == 0)
		{
			//検索
			printf("検索する番号を入力  ");
			scanf_s("%s", SeNumber, 20);
			//探す
			while (*p != NULL)
			{
				//検索文字も長さ
				int len = strlen(SeNumber);
				//検索文字をコピー
				strcpy_s(SeNumberMax, SeNumber);
				//最後の文字に対して文字コード＋１
				SeNumberMax[len - 1] = SeNumber[len - 1] + 1;

				//見つかる　最初から検索文字数まで同じ
				if (strcmp(SeNumber, ((*p)->number)) <= 0 && strcmp(SeNumberMax, (*p)->number) > 0)
				{
					caunt++;
					//出力
					printf("add | %*s |",-21, (*p)->name);
					printf("%s", (*p)->number);
					printf("\n");
				}
				//ポインタを次へ
				(*p) = (*p)->next;
			}
			//出力件数　出力
			printf("%d件\n", caunt);
			caunt = 0;
		}
		//終了
		else if (strcmp(search, "end") == 0)
		{
			//ポインタを初期位置にセット
			*p = *start;
			return;
		}
		//一覧
		else if (strcmp("list", search) == 0)
		{
			printf("\n");
			list(p, start);
		}
		//画面をクリア
		else if (strcmp( "clear", search) == 0)
		{
			system("cls");
		}

		printf("\n");
		//ポインタを初期位置にセット
		*p = *start;
	}

	
}