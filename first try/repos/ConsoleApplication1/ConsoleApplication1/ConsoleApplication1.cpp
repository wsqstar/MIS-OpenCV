#include "stdafx.h"
#include<stdio.h>
#include<string>
#include<iostream>
#include<windows.h>
#include<conio.h>
#define N 50


struct worker//Ա�����ݽṹ��
{
	char num[11];//���
	char name[20];//����
	char sex[11];//�Ա�
	char age[11];//����
	char position[11];//ְ��
	char title[11];//ְ��
	char party[11];//������ò
	char education[11];//ѧ��
	char worktime[11];//��ְʱ��
	char cometime[11];//��Ժʱ��
	char category[11];//��Ա���
}work[N];
//***********************************************************************

void menu();//��������
void browse();//��������

			  //***********************************************************************
void no_input(int i, int n) //������������Ƿ�����Լ�����Ƿ���ȷ
{
	int j, k, w1;
	do
	{
		w1 = 0;

		for (j = 0; work[i].num[j] != '\0'; j++) //�ж������Ÿ�ʽ�Ƿ���ȷ
			if (work[i].num[j]>'9')
			{
				puts("Input error!Only be made up of(0-9).Please reinput!\n");
				w1 = 1; break;
			}
		if (w1 != 1)

			for (k = 0; k<n; k++) if (k != i && strcmp(work[k].num, work[i].num) == 0) //�жϴ˱���Ƿ����
			{
				puts("This record is exist.please reinput!\n");
			}
	} while (w1 == 1);

}
//***********************************************************************
void input(int i) //�������뺯��
{
	no_input(i, i);

	printf("���:");
	scanf("%s", work[i].num);

	printf("����:");
	scanf("%s", work[i].name);

	printf("�Ա�:");
	scanf("%s", work[i].sex);

	printf("����:");
	scanf("%s", work[i].age);

	printf("ְ��:");
	scanf("%s", work[i].position);

	printf("ְ��:");
	scanf("%s", work[i].title);

	printf("������ò:");
	scanf("%s", work[i].party);

	printf("ѧ��:");
	scanf("%s", work[i].education);

	printf("����ʱ��:"); //����ʱ�䰴�������㣬������
	scanf("%s", work[i].worktime);

	printf("��Ժʱ��:");
	scanf("%s", work[i].cometime);

	printf("��Ա���:");
	scanf("%s", work[i].category);
}

//***********************************************************************
int save(int n) //������������ݵ�txt�ĵ�
{
	FILE *fp;
	int i;

	if ((fp = fopen("Pro.txt", "wb")) == NULL)
	{
		printf("\nCannot open file\n");
		return NULL;
	}

	for (i = 0; i<n; i++)
		if (work[i].num != 0)
			if (fwrite(&work[i], sizeof(struct worker), 1, fp) != 1) printf("file write error\n");

	fclose(fp);
	return 0;
}
//***********************************************************************
void printf_back() //���غ���
{
	int w;

	printf("\n\n\t��������ɹ�^_^\n\n");

	printf("ѡ����Ҫʵ�ֵĹ���\n\n\t1).������������\t2).�������˵�: [ ]\b\b");
	scanf("%d", &w);

	if (w == 1) browse();
	else menu();
}
//************************************************************************
int load() //����ǰ�����txt�ĵ��ж�������
{
	FILE *fp;
	int i;

	if ((fp = fopen("Pro.txt", "rb")) == NULL)
	{
		printf("\nCannot open file\n");
		return NULL;
	}

	for (i = 0; !feof(fp); i++)
		fread(&work[i], sizeof(struct worker), 1, fp);

	fclose(fp);

	return(i - 1);
}
//***********************************************************************
void printf_face() //ÿ��Ҫ������ݵ�ʱ���õ�����ӡ�����ݵĵ�һ�ţ���ʾ���ã�
{

	printf("\n    ��� ���� �Ա� ���� ְ�� ְ�� ������ò ���ѧ�� ��ְʱ�� ��Ժʱ�� ��Ա���\n");

}

//***********************************************************************
void printf_one(int i) //һ�δ�ӡ��һ���˵���������
{

	printf("%7s%7s%7s%7s%7s%7s%7s%7s%7s%7s%7s\n", work[i].num, work[i].name, work[i].sex, work[i].age, work[i].position,
		work[i].title, work[i].party, work[i].education, work[i].worktime, work[i].cometime, work[i].category);
}
//***********************************************************************
int modify_data(int i) //�޸����ݵĲ�������
{
	int c, w1;

	do //���
	{
		puts("\nmodify by=>\n\n 1��� 2���� 3�Ա� 4���� 5ְ�� 6ְ�� 7������ò 8���ѧ�� 9��ְʱ�� 10��Ժʱ�� 11��Ա��� ");
		printf("Which you needed?:[ ]\b\b");
		scanf("%d", &c);

		if (c>11 || c<1)
		{
			puts("\nChoice error!Please again!");
			getchar();
		}

	} while (c>11 || c<1);

	do
	{
		switch (c)
		{
		case 1:printf("num:"); scanf("%s", work[i].num); break;
		case 2:printf("name:"); scanf("%s", work[i].name); break;
		case 3:printf("sex:"); scanf("%s", work[i].sex); break;
		case 4:printf("age:"); scanf("%d", work[i].age); break;
		case 5:printf("position:"); scanf("%s", work[i].position); break;
		case 6:printf("title:"); scanf("%s", work[i].title); break;
		case 7:printf("party:"); scanf("%s", work[i].party); break;
		case 8:printf("education:"); scanf("%s", work[i].education); break;
		case 9:printf("worktime:"); scanf("%d", work[i].worktime); break;
		case 10:printf("cometime:"); scanf("%s", work[i].cometime); break;
		case 11:printf("category:"); scanf("%s", work[i].category); break;
		default:break;
		}
		puts("\nNow:\n");

		printf_face();

		printf_one(i);
		printf("\nAre you sure?\n\n\t 1).Sure 2).No and remodify 3).Back without save in this time [ ]\b\b");
		scanf("%d", &w1);
	} while (w1 == 2);

	return(w1);
}
//****************************���ܰ��*******************************************

void enter()//����1.�������ݳ�ʼ��
{
	int i, n;

	printf("How many students(0-%d)?:", N - 1);
	scanf("%d", &n);

	printf("\n ����������\n\n");

	for (i = 0; i<n; i++)
	{
		printf("\n Input %dth student record.\n", i + 1);
		input(i);//�������뺯��
	}

	if (i != 0)save(n);//�������������

	printf_back();//������ɵ��÷��غ���
}
//************************************************************************
void add() //����2.����µ�����
{
	int i, n, m, k;
	FILE*fp;

	n = load();

	printf("How many people are you want to add(0-%d)?:", N - 1 - n);
	scanf("%d", &m);

	k = m + n;
	for (i = n; i<k; i++) //����µļ�¼
	{
		printf("\nInput %dth people record.\n", i - n + 1);
		input(i);
	}

	if ((fp = fopen("Pro.txt", "ab")) == NULL)
	{
		printf("cannot open file\n");
	}

	for (i = n; i<k; i++) if (fwrite(&work[i], sizeof(struct worker), 1, fp) != 1)
		printf("file write error\n"); //���¼�¼д���ļ�

	fclose(fp);

	printf_back();
}
//************************************************************************
void modify() //����3.�༭�޸�ģ��
{
	struct worker p;

	int i, n, k, w0 = 1, w1, w2 = 0;

	n = load();

	do
	{
		k = -1;
		printf_face();

		for (i = 0; i<n; i++)
		{
			if ((i != 0) && (i % 10 == 0))
			{
				printf("\n\nRemember NO.which needed modify.pass any key to contiune ...");
				getch();
				puts("\n\n");
			}
			printf_one(i);
		}

		do
		{
			printf("\n\nEnter NO.that you want to modify! NO.:");
			scanf("%s", p.num);

			for (i = 0; i<n; i++) if (strcmp(p.num, work[i].num) == 0) //����
			{
				k = i;
				p = work[i];
			}

			if (k == -1)printf("\n\nNO exist!please again");

		} while (k == -1);

		printf_face();

		printf_one(k);

		w1 = modify_data(k);

		if (w1 == 1)
		{
			printf("\nSuccessful ^_^.\n\nAre you modify another ?\n\n\t 1).Yes 2).Back with save\t[  ]\b\b");
			scanf("%d", &w0);
			w2 = 1;
		}
		else
		{
			w0 = 0;
			if (w2 == 1)work[k] = p;
		}

		if (w0 != 1 && w2 == 1)save(n);

	} while (w0 == 1);

	menu();

}
//************************************************************************
void del() //����4.ɾ������
{
	int i, n, m;

	struct worker p;

	FILE*fp;

	n = load();

	printf("How many people are you want to del(0-%d)?:", n);
	scanf("%d", &m);


	for (i = 0; i<m; i++)
	{
		printf("\nInput %dth people num you want to del.\n", i + 1);
		scanf("%s", &p.num);

		n = load();
		system("ERASE Pro.txt");//ɾ��ԭ�ļ��Ա����´����µ��ļ� 

		if ((fp = fopen("Pro.txt", "w+")) == NULL)
		{
			printf("cannot open file\n");
		}

		for (i = 0; i<n; i++)if (strcmp(p.num, work[i].num) != 0) if (fwrite(&work[i], sizeof(struct worker), 1, fp) != 1)
			printf("file write error\n"); //���¼�¼д���ļ�


		fclose(fp);
	}
	printf_back();
}
//************************************************************************
void browse() //����5.�������ģ��
{
	int i, n;

	n = load();//������ǰ���������  txt�ĵ�

	printf_face();

	for (i = 0; i<n; i++)
	{
		if ((i != 0) && (i % 10 == 0))
		{
			printf("\n\nPass any key to continue ....");
			getch();
			puts("\n\n");
		}
		printf_one(i);
	}

	printf("\tThere are %d record.\n", n);

	printf("\nPrass any key to back ...");
	getch();

	menu();
}
//************************************************************************
void search() //����6.��ѯģ�飨���޸ģ�
{
	int i, n, k, w1 = 1, w2, w3, w4, m;

	struct worker p;

	n = load();

	do
	{
		printf("\n\nWhich way do you want to choose? \n\t1).By name 2).By num [ ]\b\b");
		scanf("%d", &m);

		switch (m)
		{
		case 1: //��������ѯ
			do
			{
				k = -1;
				printf("\n\nEnter name that you want to search! name:");
				scanf("%s", p.name);

				printf_face();
				for (i = 0; i<n; i++)if (strcmp(p.name, work[i].name) == 0)
				{
					k = i;
					printf_one(k); break;
				}

				if (k == -1)
				{
					printf("\n\nNO exist!please");

					printf("\n\nAre you again?\n\t1).again 2).NO and back [ ]\b\b");
					scanf("%d", &w1);

					if (w1 == 2)
						printf_back();
				}
			} while (k == -1 && w1 == 1); break;

		case 2: //������
			do
			{
				k = -1;
				printf("\n\nEnter num that you want to search! num.");
				scanf("%s", p.num);

				printf_face();

				for (i = 0; i<n; i++)
					if (strcmp(p.num, work[i].num) == 0)
					{
						k = i;
						printf_one(k); break;
					}

				if (k == -1)
				{
					printf("\n\nNO exist!please");
					printf("\n\nAre you again?\n\t1).again 2).NO and back [ ]\b\b");
					scanf("%d", &w1);

					if (w1 == 2)printf_back();
				}
			} while (k == -1 && w1 == 1); break;
		}


		w4 = 0;
		w3 = 0;
		if (k != -1)
		{
			printf("\n\nWhat do you want to do?\n\t 1).Search 2).Modify  3).Back menu [ ]\b\b");
			scanf("%d", &w2);

			switch (w2)
			{
			case 2:w3 = modify_data(k); break;

			}

			if (w3 == 1 || w4 == 1) {
				save(n);
				printf("\n\nSuccessful.^_^.");
				printf("\n\nWhant do you want to do? \n\t 1).Search another 2).Back [ ]\b\b");
				scanf("%d", &w2);
			}
		}

	} while (w2 == 1);

	menu();
}
//************************************************************************
void count()//����7.ͳ��ģ��
{
	int c, w1 = 1, n, i, t = 0;

	struct worker p;

	n = load();

	do //���
	{
		puts("\nmodify by=>\n\n 1��� 2���� 3�Ա� 4���� 5ְ�� 6ְ�� 7������ò 8���ѧ�� 9��ְʱ�� 10��Ժʱ�� 11��Ա��� ");
		printf("Which you needed to count?:[ ]\b\b");
		scanf("%d", &c);

		if (c>11 || c<1)
		{
			puts("\nChoice error!Please again!");
			getchar();
		}

	} while (c>11 || c<1);

	do
	{
		switch (c)
		{
		case 1:printf("num:"); scanf("%s", p.num);
			for (i = 0; i<n; i++)
			{
				if (strcmp(work[i].num, p.num) == 0)
				{
					printf_one(i);
					t++;
				}
			}
			if (t == 0)printf("\n\nû�з�����������Ϣ����\n\n");
			else printf("\n����%d�ˣ�\n", t);
			break;
		case 2:printf("name:"); scanf("%s", p.name);
			for (i = 0; i<n; i++)
			{
				if (strcmp(work[i].name, p.name) == 0)
				{
					printf_one(i);
					t++;
				}
			}
			if (t == 0)printf("\n\nû�з�����������Ϣ����\n\n");
			else printf("\n����%d�ˣ�\n", t);
			break;
		case 3:printf("sex:"); scanf("%s", p.sex);
			for (i = 0; i<n; i++)
			{
				if (strcmp(work[i].sex, p.sex) == 0)
				{
					printf_one(i);
					t++;
				}
			}
			if (t == 0)printf("\n\nû�з�����������Ϣ����\n\n");
			else printf("\n����%d�ˣ�\n", t); break;
		case 4:printf("age:"); scanf("%d", p.age);
			for (i = 0; i<n; i++)
			{
				if (strcmp(work[i].age, p.age) == 0)
				{
					printf_one(i);
					t++;
				}
			}
			if (t == 0)printf("\n\nû�з�����������Ϣ����\n\n");
			else printf("\n����%d�ˣ�\n", t); break;
		case 5:printf("position:"); scanf("%s", p.position);
			for (i = 0; i<n; i++)
			{
				if (strcmp(work[i].position, p.position) == 0)
				{
					printf_one(i);
					t++;
				}
			}
			if (t == 0)printf("\n\nû�з�����������Ϣ����\n\n");
			else printf("\n����%d�ˣ�\n", t); break;
		case 6:printf("title:"); scanf("%s", p.title);
			for (i = 0; i<n; i++)
			{
				if (strcmp(work[i].title, p.title) == 0)
				{
					printf_one(i);
					t++;
				}
			}
			if (t == 0)printf("\n\nû�з�����������Ϣ����\n\n");
			else printf("\n����%d�ˣ�\n", t); break;
		case 7:printf("party:"); scanf("%s", p.party);
			for (i = 0; i<n; i++)
			{
				if (strcmp(work[i].party, p.party) == 0)
				{
					printf_one(i);
					t++;
				}
			}
			if (t == 0)printf("\n\nû�з�����������Ϣ����\n\n");
			else printf("\n����%d�ˣ�\n", t); break;
		case 8:printf("education:"); scanf("%s", p.education);
			for (i = 0; i<n; i++)
			{
				if (strcmp(work[i].education, p.education) == 0)
				{
					printf_one(i);
					t++;
				}
			}
			if (t == 0)printf("\n\nû�з�����������Ϣ����\n\n");
			else printf("\n����%d�ˣ�\n", t); break;
		case 9:printf("worktime:"); scanf("%d", p.worktime);
			for (i = 0; i<n; i++)
			{
				if (strcmp(work[i].worktime, p.worktime) == 0)
				{
					printf_one(i);
					t++;
				}
			}
			if (t == 0)printf("\n\nû�з�����������Ϣ����\n\n");
			else printf("\n����%d�ˣ�\n", t); break;
		case 10:printf("cometime:"); scanf("%s", p.cometime);
			for (i = 0; i<n; i++)
			{
				if (strcmp(work[i].cometime, p.cometime) == 0)
				{
					printf_one(i);
					t++;
				}
			}
			if (t == 0)printf("\n\nû�з�����������Ϣ����\n\n");
			else printf("\n����%d�ˣ�\n", t); break;
		case 11:printf("category:"); scanf("%s", p.category);
			for (i = 0; i<n; i++)
			{
				if (strcmp(work[i].category, p.category) == 0)
				{
					printf_one(i);
					t++;
				}
			}
			if (t == 0)printf("\n\nû�з�����������Ϣ����\n\n");
			else printf("\n����%d�ˣ�\n", t); break;
		default:break;
		}


	} while (w1 == 2);

	menu();
}
//************************************************************************
void order()//����8.�����������Ժʱ������
{
	int m, t, j, k, i, n, w;

	struct worker g;

	n = load();



	do
	{
		printf("\n\nWhich way do you want to choose? \n\t1).By age 2).By cometime 0).exit [ ]\b\b");
		scanf("%d", &t);

		if (t != 0)
		{
			m = t;
			switch (m)
			{
			case 1: //������

				k = -1;

				printf_face();

				for (i = 0; i<n; i++)

					for (j = 0; j<n - 1; j++)if (strcmp(work[j + 1].age, work[j].age)<0)
					{
						strcpy(g.num, work[j].num); strcpy(work[j].num, work[j + 1].num); strcpy(work[j + 1].num, g.num);
						strcpy(g.name, work[j].name); strcpy(work[j].name, work[j + 1].name); strcpy(work[j + 1].name, g.name);
						strcpy(g.sex, work[j].sex); strcpy(work[j].sex, work[j + 1].sex); strcpy(work[j + 1].sex, g.sex);
						strcpy(g.age, work[j].age); strcpy(work[j].age, work[j + 1].age); strcpy(work[j + 1].age, g.age);
						strcpy(g.position, work[j].position); strcpy(work[j].position, work[j + 1].position); strcpy(work[j + 1].position, g.position);
						strcpy(g.title, work[j].title); strcpy(work[j].title, work[j + 1].title); strcpy(work[j + 1].title, g.title);
						strcpy(g.party, work[j].party); strcpy(work[j].party, work[j + 1].party); strcpy(work[j + 1].party, g.party);
						strcpy(g.education, work[j].education); strcpy(work[j].education, work[j + 1].education); strcpy(work[j + 1].education, g.education);
						strcpy(g.worktime, work[j].worktime); strcpy(work[j].worktime, work[j + 1].worktime); strcpy(work[j + 1].worktime, g.worktime);
						strcpy(g.cometime, work[j].cometime); strcpy(work[j].cometime, work[j + 1].cometime); strcpy(work[j + 1].cometime, g.cometime);
						strcpy(g.category, work[j].category); strcpy(work[j].category, work[j + 1].category); strcpy(work[j + 1].category, g.category);

					}



				for (i = 0; i<n; i++)printf_one(i);
				break;

			case 2: //����Ժʱ��

				k = -1;

				printf_face();


				for (i = 0; i<n; i++)
					for (j = 0; j<n - 1; j++)if (strcmp(work[j + 1].cometime, work[j].cometime)<0)
					{
						strcpy(g.num, work[j].num); strcpy(work[j].num, work[j + 1].num); strcpy(work[j + 1].num, g.num);
						strcpy(g.name, work[j].name); strcpy(work[j].name, work[j + 1].name); strcpy(work[j + 1].name, g.name);
						strcpy(g.sex, work[j].sex); strcpy(work[j].sex, work[j + 1].sex); strcpy(work[j + 1].sex, g.sex);
						strcpy(g.age, work[j].age); strcpy(work[j].age, work[j + 1].age); strcpy(work[j + 1].age, g.age);
						strcpy(g.position, work[j].position); strcpy(work[j].position, work[j + 1].position); strcpy(work[j + 1].position, g.position);
						strcpy(g.title, work[j].title); strcpy(work[j].title, work[j + 1].title); strcpy(work[j + 1].title, g.title);
						strcpy(g.party, work[j].party); strcpy(work[j].party, work[j + 1].party); strcpy(work[j + 1].party, g.party);
						strcpy(g.education, work[j].education); strcpy(work[j].education, work[j + 1].education); strcpy(work[j + 1].education, g.education);
						strcpy(g.worktime, work[j].worktime); strcpy(work[j].worktime, work[j + 1].worktime); strcpy(work[j + 1].worktime, g.worktime);
						strcpy(g.cometime, work[j].cometime); strcpy(work[j].cometime, work[j + 1].cometime); strcpy(work[j + 1].cometime, g.cometime);
						strcpy(g.category, work[j].category); strcpy(work[j].category, work[j + 1].category); strcpy(work[j + 1].category, g.category);

					}



				for (i = 0; i<n; i++)printf_one(i);
				break;
			default:break;

			}
		}

		if (t != 0)
		{
			printf("\nDo you want to save the order?1.yes,2.no  ");
			scanf("%d", &w);

			if (w == 1)save(n);
		}

	} while (t);
	menu();
}
//************************************************************************
//�����˵�
void menu()
{

	int n, w1;
	printf("\n");
	do {
		puts("\t\t**************MENU******************\n\n");
		puts("\t\t\t1.�������ݳ�ʼ��");
		puts("\t\t\t2.׷������");
		puts("\t\t\t3.�༭�޸�����");
		puts("\t\t\t4.ɾ������");
		puts("\t\t\t5.���ȫ����Ϣ");
		puts("\t\t\t6.��ѯ�����������߱�ţ�");
		puts("\t\t\t7.ͳ��");
		puts("\t\t\t8.�����������Ժʱ���������");
		puts("\t\t\t9.�˳�");
		puts("\n\n\t\t************************************\n");
		printf("ѡ��Ҫʵ�ֵĹ���(1-9):[ ]\b\b");
		scanf("%d", &n);

		if (n<1 || n>9)
		{
			w1 = 1;
			getchar();
		}
		else w1 = 0;
	} while (w1 == 1);


	switch (n)
	{
	case 1:enter(); break;//�������ݳ�ʼ��
	case 2:add(); break;//׷��
	case 3:modify(); break;//�༭�޸�
	case 4:del(); break;//ɾ��
	case 5:browse(); break;//���ȫ����Ϣ
	case 6:search(); break;//��ѯ
	case 7:count(); break;//ͳ��
	case 8:order(); break;//����*/
	case 9:exit(0);
	default:break;
	}

}


//******************************************************************************************

//������
int main()
{
	menu();
	return 0;
}