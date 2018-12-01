#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// argc: 统计运行程序时命令行参数的个数
// *argv[]: 储存每个参数的字符串指针，每一个元素对应一个参数
int main(int argc, char *argv[]) {
	int ch, bian = 0, count = 0;
	char find[50], temp[1000];
	FILE *pt;    //文件指针

	// 判断是否输入文件
	if (argc != 2) {
		printf("请使用格式: %s 文件名", argv[0]);
		exit(1);    //非正常退出
	}

	// 判断能否成功打开文件
	if ((pt = fopen(argv[1], "r")) == NULL) {  //将argv[1]赋值给指针pt
		printf("打开文件 %s 失败", argv[1]);
		exit(1);
	}

	printf("请输入要查找的单词:");
	gets(find);
	while ((ch = getc(pt)) != EOF) {  //EOF 表示文件结束
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
	printf("共在文件%s中查找到字符串\"%s\" %d 个\n", argv[1], find, count);
	getch();
	system("pause");
	return 0;
}

//定时关机小程序
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main() {
	char cmd[20] = "shutdown -s -t ";
	char t[5] = "0";
	int c;

	system("title C语言关机程序");  //设置cmd窗口标题
	system("mode con cols=48 lines=25");  //窗口宽度高度 
	system("color f0");  //可以写成 red 调出颜色组
	system("date /T");
	system("TIME /T");

	printf("----------- C语言关机程序 -----------\n");
	printf("1.实现10分钟内的定时关闭计算机\n");
	printf("2.立即关闭计算机\n");
	printf("3.注销计算机\n");
	printf("0.退出系统\n");
	printf("-------------------------------------\n");

	scanf("%d", &c);
	switch (c) {
	case 1:
		printf("您想在多少秒后自动关闭计算机？（0~600）\n");
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

//获取开机时间
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
	printf("重系统启动到现在过了的时间：%d h %d min %d s\n", h, min, s);

	system("pause");
	return 0;
}

//统计输入的单词的个数
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

	// 读入文本行，直到发现EOF
	while (gets(buffer)) {
		// 从缓冲区逐个提取单词，直到缓冲区内不再有单词。
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