#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// argc: ͳ�����г���ʱ�����в����ĸ���
// *argv[]: ����ÿ���������ַ���ָ�룬ÿһ��Ԫ�ض�Ӧһ������
int main(int argc, char *argv[]) {
	int ch, bian = 0, count = 0;
	char find[50], temp[1000];
	FILE *pt;    //�ļ�ָ��

	// �ж��Ƿ������ļ�
	if (argc != 2) {
		printf("��ʹ�ø�ʽ: %s �ļ���", argv[0]);
		exit(1);    //�������˳�
	}

	// �ж��ܷ�ɹ����ļ�
	if ((pt = fopen(argv[1], "r")) == NULL) {  //��argv[1]��ֵ��ָ��pt
		printf("���ļ� %s ʧ��", argv[1]);
		exit(1);
	}

	printf("������Ҫ���ҵĵ���:");
	gets(find);
	while ((ch = getc(pt)) != EOF) {  //EOF ��ʾ�ļ�����
		if ((ch != ' ') && (ch != '\n')) {
			temp[bian] = ch;
			bian++;
		}
		else {
			temp[bian] = '\0';
			if ((strcmp(find, temp)) == 0) count++;
			bian = 0;
		}
	}
	printf("�����ļ�%s�в��ҵ��ַ���\"%s\" %d ��\n", argv[1], find, count);
	getch();
	system("pause");
	return 0;
}

//��ʱ�ػ�С����
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main() {
	char cmd[20] = "shutdown -s -t ";
	char t[5] = "0";
	int c;

	system("title C���Թػ�����");  //����cmd���ڱ���
	system("mode con cols=48 lines=25");  //���ڿ�ȸ߶� 
	system("color f0");  //����д�� red ������ɫ��
	system("date /T");
	system("TIME /T");

	printf("----------- C���Թػ����� -----------\n");
	printf("1.ʵ��10�����ڵĶ�ʱ�رռ����\n");
	printf("2.�����رռ����\n");
	printf("3.ע�������\n");
	printf("0.�˳�ϵͳ\n");
	printf("-------------------------------------\n");

	scanf("%d", &c);
	switch (c) {
	case 1:
		printf("�����ڶ�������Զ��رռ��������0~600��\n");
		scanf("%s", t);
		system(strcat(cmd, t));
		break;
	case 2:
		system("shutdown -p");
		break;
	case 3:
		system("shutdown -l");
		break;
	case 0:
		break;
	default:
		printf("Error!\n");
	}
	system("pause");
	return 0;
}

//��ȡ����ʱ��
#include<stdio.h>
#include<windows.h>

int main() {
	DWORD k = GetTickCount();
	int s = k / 1000;
	int min = 0, h = 0;
	if (s >= 60) {
		min = s / 60;
		s = s % 60;
	}
	if (min >= 60) {
		h = min / 60;
		min = min % 60;
	}
	printf("��ϵͳ���������ڹ��˵�ʱ�䣺%d h %d min %d s\n", h, min, s);

	system("pause");
	return 0;
}

//ͳ������ĵ��ʵĸ���
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char const whitespace[] = " \n\r\f\t\v";
int main()
{
	char buffer[101];
	int count;
	char *word;
	count = 0;

	// �����ı��У�ֱ������EOF
	while (gets(buffer)) {
		// �ӻ����������ȡ���ʣ�ֱ���������ڲ����е��ʡ�
		for (word = strtok(buffer, whitespace);
			word != NULL;
			word = strtok(NULL, whitespace)
			){
			if (strcmp(word, "the") == 0)
				count += 1;
		}
	}

	printf("%d\n", count);
	return EXIT_SUCCESS;
}