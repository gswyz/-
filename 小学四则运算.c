#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<windows.h>

float algorithm(float x,char op,float y);
float algorithm2(float x,char op2,float y);
char createnumberop();
void test1(int n);




main()
{
	int chooce,n;
	while(1)
	{
		printf("\t��������Ҫѡ���ϰ�⣺\n");
		printf("\n\t1.100������������ (С���������λ)\n\n");
		printf("\n\t2.������������\n\n");
		printf("\n\t3.�ı䱳����ɫ\n\n");
		do{
			printf("ѡ��Ϊ��");
			scanf("%d",&chooce);
			if(chooce!=1 && chooce!=2 && chooce!=3)
				printf("��������������������!��\n");
		}while(chooce!=1 && chooce!=2 && chooce!=3);
		if(chooce==3)
        {
            blank();
        }
		printf("\n�����������������Ŀ��");
		while(1)
            {
			scanf("%d",&n);
			if(n<=0)
				printf("����Ŀ��������������!��\n");
            else
                break;
		}
		if(chooce==1)
		{
			test1(n);
		}
		if(chooce==2)
        {
            test2(n);
        }
	}
}

//��һ�����������
float algorithm(float x,char op,float y)
{
	float result;
	switch(op)
	{
	case'+':result = x + y;break;
	case'-':result = x - y;break;
	case'*':result = x * y;break;
	case'/':result = x / y;break;
	}
	return result;
}
//�ڶ������������
float algorithm2(float x,char op2,float y)
{
	float result;
	switch(op2)
	{
	case'+':result = x + y;break;
	case'-':result = x - y;break;
	case'*':result = x * y;break;
	case'/':result = x / y;break;
	}
	return result;
}

//������������
char mark()
{
	int op;
	op=rand() % 4+1;
	switch(op)
	{
	case 1:return'+';
	case 2:return'-';
	case 3:return'*';
	case 4:return'/';
	}
	return 0;
}

//100������������
void test1(int n)
{
	int i,rightnum=0,wrongnum=0;//rightnumber��ȷ�ĸ���,wrongnumber����ĸ���
	float a,b,c,answer,result;
	char op,op2;//�����
	srand(time(NULL));
	for(i=0;i<n;i++)
	{
		a=(float)(rand() % 100+1);//��ȡ�����
		b=(float)(rand() % 100+1);
		c=(float)(rand() % 100+1);
		op=mark();//��ȡ��������
		op2=mark();
		if((op=='+' || op=='-') && (op2=='*' || op2=='/')){
		result=algorithm(a,op,algorithm2(b,op2,c));
		}
		else{
		result=algorithm2(algorithm(a,op,b),op2,c);//������������ȼ��ó����
	}
		if(result< 0)//������Ϊ�������������»�ȡ��Ŀ
		{
			i--;
			continue;
		}
		else{
			printf("%.f %c %.f %c %.f = ",a,op,b,op2,c);
			scanf("%f",&answer);

				if((int)(100.0*answer+0.5)/100.0==(int)(100.0*result+0.5)/100.0 && result>=0)//�������뾫ȷ��С�������λ
				{
					printf("���ش���ȷ!��\n\n");
					rightnum++;
				}
				else
				{
					printf("���ش����!���ǣ�%.2f��\n\n",(int)(100.0*result+0.5)/100.0);
					wrongnum++;
				}
		}
	}
	printf("���ܹ������%d�⣬׼ȷ��Ϊ%.2f��!\n",rightnum,(float)rightnum/(float)n*100);
	system("pause");
	system("CLS");
	printf("\n\n");
}

void test2(int n){
    int a, answer, result,i,b,rightnum=0,wrongnum=0;
    srand(time(NULL));
    for(i=0;i<n;i++){
    a=rand() % 10+1;//��ȡ�����
    printf("%d!=",a);
    result=jiecheng(a);
    scanf("%d",&answer);
    if(answer==result)
    {
        printf("�ش���ȷ!\n\n");
        rightnum++;
    }
    else{
        printf("�ش����!\n\n");
        wrongnum++;
    }
    }
    printf("���ܹ������%d�⣬׼ȷ��Ϊ%.2f��!\n",rightnum,(float)rightnum/(float)n*100);
	system("pause");
	system("CLS");
	printf("\n\n");
}

int jiecheng(int a){
    int f;
    if(a==0 || a==1)
    {
        f=1;
    }
    else{
        f=jiecheng(a-1)*a;
    }
    return f;
}

void blank(){
    int a;
    printf("��ѡ�񱳾���ɫ��");
    printf("1 = ��ɫ ��2 = ��ɫ��3 = ��ɫ�� 4 = ����ɫ��5 = ��ɫ ��6 = ����ɫ��7 = ����ɫ \n 8 = ��ǳ��ɫ��9 = ��ɫ�� 10 = ����ɫ��11 = ��ɫ ��12 = ����ɫ��13 = ��ɫ ��14 = ����ɫ\n");
    scanf("%d",&a);
    switch(a)
    {
        case 1:system("color 0f");break;
        case 2:system("color 8f");break;
        case 3:system("color 1f");break;
        case 4:system("color 9f");break;
        case 5:system("color 2f");break;
        case 6:system("color Af");break;
        case 7:system("color 3f");break;
        case 8:system("color Bf");break;
        case 9:system("color 4f");break;
        case 10:system("color cf");break;
        case 11:system("color 5f");break;
        case 12:system("color Df");break;
        case 13:system("color 6f");break;
        case 14:system("color Ef");break;
    }
}


