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
		printf("\t请输入你要选择的习题：\n");
		printf("\n\t1.100以内四则运算 (小数点后保留两位)\n\n");
		printf("\n\t2.整数四则运算\n\n");
		printf("\n\t3.改变背景颜色\n\n");
		do{
			printf("选择为：");
			scanf("%d",&chooce);
			if(chooce!=1 && chooce!=2 && chooce!=3)
				printf("【输入有误，请重新输入!】\n");
		}while(chooce!=1 && chooce!=2 && chooce!=3);
		if(chooce==3)
        {
            blank();
        }
		printf("\n请输入四则运算的数目：");
		while(1)
            {
			scanf("%d",&n);
			if(n<=0)
				printf("【数目有误，请重新输入!】\n");
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

//第一个运算符计算
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
//第二个运算符计算
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

//随机产生运算符
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

//100以内四则运算
void test1(int n)
{
	int i,rightnum=0,wrongnum=0;//rightnumber正确的个数,wrongnumber错误的个数
	float a,b,c,answer,result;
	char op,op2;//运算符
	srand(time(NULL));
	for(i=0;i<n;i++)
	{
		a=(float)(rand() % 100+1);//获取随机数
		b=(float)(rand() % 100+1);
		c=(float)(rand() % 100+1);
		op=mark();//获取随机运算符
		op2=mark();
		if((op=='+' || op=='-') && (op2=='*' || op2=='/')){
		result=algorithm(a,op,algorithm2(b,op2,c));
		}
		else{
		result=algorithm2(algorithm(a,op,b),op2,c);//根据运算符优先级得出结果
	}
		if(result< 0)//如果结果为非正数，则重新获取题目
		{
			i--;
			continue;
		}
		else{
			printf("%.f %c %.f %c %.f = ",a,op,b,op2,c);
			scanf("%f",&answer);

				if((int)(100.0*answer+0.5)/100.0==(int)(100.0*result+0.5)/100.0 && result>=0)//四舍五入精确到小数点后两位
				{
					printf("【回答正确!】\n\n");
					rightnum++;
				}
				else
				{
					printf("【回答错误!答案是：%.2f】\n\n",(int)(100.0*result+0.5)/100.0);
					wrongnum++;
				}
		}
	}
	printf("你总共答对了%d题，准确率为%.2f％!\n",rightnum,(float)rightnum/(float)n*100);
	system("pause");
	system("CLS");
	printf("\n\n");
}

void test2(int n){
    int a, answer, result,i,b,rightnum=0,wrongnum=0;
    srand(time(NULL));
    for(i=0;i<n;i++){
    a=rand() % 10+1;//获取随机数
    printf("%d!=",a);
    result=jiecheng(a);
    scanf("%d",&answer);
    if(answer==result)
    {
        printf("回答正确!\n\n");
        rightnum++;
    }
    else{
        printf("回答错误!\n\n");
        wrongnum++;
    }
    }
    printf("你总共答对了%d题，准确率为%.2f％!\n",rightnum,(float)rightnum/(float)n*100);
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
    printf("请选择背景颜色：");
    printf("1 = 黑色 ，2 = 灰色，3 = 蓝色， 4 = 淡蓝色，5 = 绿色 ，6 = 淡绿色，7 = 湖蓝色 \n 8 = 淡浅绿色，9 = 红色， 10 = 淡红色，11 = 紫色 ，12 = 淡紫色，13 = 黄色 ，14 = 淡黄色\n");
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


