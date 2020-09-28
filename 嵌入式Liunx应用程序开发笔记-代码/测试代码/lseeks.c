/***  lseeks.c  ***/
/**** lseek ��дָ�붨λ���� ***/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>

int main()
{
    int fd;       //�ļ�������
    char buf[10]; //��д������

    //O_CREAT �����޴��ļ�������һ��
    //O_TRUNC �����ļ����������
    //O_APPEND ���ļ�ĩβ������ӷ�ʽ��
    if ((fd = open("hello.txt", O_CREAT | O_TRUNC | O_APPEND | O_RDWR, 0644)) == -1)
    //  if ((fd = open("hello.txt",O_CREAT|O_TRUNC|O_RDWR,0644)) == -1)
    {
      //��׼��������
      perror("Error: open hello.txt \n");
      return 0;
    }

    //��һ����д��aaa
    if (write(fd, "aaa", 3) != 3)
      perror("Error: write aaa ");
    printf("1. write aaa ok \n");
    printf("cat: \n");

    //����ϵͳ���� cat ���鿴�ļ�����
    system("cat hello.txt");
    getchar(); //��ͣ���۲���

    //�ڶ���������д��bbb
    if (write(fd, "bbb", 3) != 3)
      perror("Error: write bbb \n");
    printf("2. write bbb ok \n");
    printf("cat: \n");

    //����ϵͳ���� cat ���鿴�ļ�����
    system("cat hello.txt");
    getchar(); //��ͣ���۲���

    //��������д��ccc�����ǵڶ�����bbb
    //lseek����λ���ļ���ʼλ�ã�SEEK_SET���ļ�ͷ
    //ƫ����Ϊ3 ����Ϊ������һ����bbb
    //ע����֤�˲���ʵ��д��λ��
    lseek(fd, 3, SEEK_SET);
    if (write(fd, "ccc", 3) != 3)
      perror("Error: write ccc \n");
    printf("3. write ccc from SEEK_SET+3 ok \n");
    printf("cat: \n");

    //����ϵͳ���� cat ���鿴�ļ�����
    system("cat hello.txt");
    getchar(); //��ͣ���۲���

    //���Ĳ�������ʼλ�ö�3���ֽڣ��������ȡ������
    //lseek����λ���ļ���ʼλ�ã�SEEK_SET���ļ�ͷ��ƫ����Ϊ0
    lseek(fd, 0, SEEK_SET);
    if (read(fd, buf, 3) != 3)
      perror("Error: read");
    buf[3] = '\0'; //�����ַ�����������%s
    printf("4. read from SEEK_SET to buf ok \n");
    printf("buf: %s", buf);
    getchar(); //��ͣ���۲���

    //���岽������ʼλ��ƫ��3���ֽڣ���3���ֽڣ��������ȡ������
    //lseek����λ����ʼλ��ƫ��3 ���ֽڣ�SEEK_SET���ļ�ͷ��ƫ����Ϊ3
    lseek(fd, 3, SEEK_SET);
    if (read(fd, buf, 3) != 3)
      perror("read");
    buf[3] = '\0'; //�����ַ�����������%s
    printf("5. read from SEEK_SET+3 to buf ok \n");
    printf("buf: %s", buf);
    getchar(); //��ͣ���۲���

    //�������������岽��ȡ������д���ļ�
    //lseek ���ƶ�������λ�ڵ�ǰλ�ã�SEEK_SET���ļ�ͷ��ƫ����Ϊ3
    if (3 != write(fd, buf, 3))
      perror("Error: write from buf \n");
    printf("6. write from buf ok \n");
    printf("cat: \n");

    //����ϵͳ���� cat ���鿴�ļ�����
    system("cat hello.txt");
    getchar(); //��ͣ���۲���

    close(fd);
    return 0;
}