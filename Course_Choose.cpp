#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
int nocout;
struct student{
	char no[20];/*学号*/
	char name[22];
	int score[60];
};
student students[500];
int find(char no[20]){
	int i;
	for(i=0;i<nocout;i++){
		if(strcmp(students[i].no,no)==0)
               break;
	}
	return i;
}
void list(int k,char course[60][10])
{
	int i;
	if(nocout==0){
		cout<<"没有学生记录"<<endl;
	}
	else{
	cout<<"学号\t"<<"姓名\t";
	    for(i=0;i<k;i++){
			if(i==(k-1)){
				cout<<course[i]<<endl;
			}
			else{
				cout<<course[i]<<"\t";
			}
		}

		for(i=0;i<nocout;i++){
			cout<<students[i].no<<"\t";
			cout<<students[i].name<<"\t";
            for(int j=0;j<k;j++){
				if(j==(k-1)){
					cout<<students[i].score[j]<<endl;
				}
				else{
					cout<<students[i].score[j]<<"\t";
				}
			}
		}
	}
}
void choose()
{
	int i;
	student student1;
	cout<<"学号：";cin>>student1.no;
	cout<<"姓名：";cin>>student1.name;
	i=find(student1.no);
	if(i==nocout)
	{
		for (int j= 0;j< 10;j++)
		{
			students[i].no[j]=student1.no[j];
		    students[i].name[j]=student1.name[j];
		}
	}
	else
	{
		cout<<"此学生已存在"<<endl;
		nocout--;
	}
	nocout++;
}
void drop()
{
	int i;
	student student2;
	cout<<"学号:";cin>>student2.no;
	i=find(student2.no);
	if (i==nocout)
	{
		cout<<"此学生不存在"<<endl;
	}
	else
	{
		for(i=find(student2.no);i<(nocout-1);i++)
		{
            for(int j=0;j<60;j++)
			{
            students[i].no[j]=students[i+1].no[j];
            students[i].name[j]=students[i+1].name[j];
            students[i].score[j]=students[i+1].score[j];
            }
         }
         nocout--;
	}

}
void putin(int k,char course[60][10],int h,int g){   
	char no1[20];
	int l,i;
	if(h==0){
		cout<<"请输入一个学号:";
		cin>>no1;
		g=find(no1);
		if(g==nocout){
			cout<<"此学生不存在"<<endl;
	  }
	}
	if(g!=nocout){
		cout<<"请输入各科成绩"<<endl;
		for(int j=0;j<k;j++){
			cout<<course[j]<<":";cin>>students[g].score[j];
		}
		cout<<"是否继续进行，是则输入1，否则输入0"<<endl;
		cin>>l;
		if(l==1){
			g++;h++;
			putin(k,course, h,g);
		}
		else if(l!=0){
			cout<<"您输入了个不正确的数字"<<endl;
		}
	}
	else {
		if(h!=0){
			cout<<"到尾了，没有学生了"<<endl;
		}
	}
}
int main(){
	nocout=0;
	int k;
	char course[60][10];
	cout<<"课程数:";cin>>k;
	for (int u=0;u<k;u++){
		cout<<"课程名:";
		cin>>course[u];
	}
	cout<<"计算机工程与科学学院2012级计科四班杨贵富制作"<<endl;
	cout<<"1.查看学生名单"<<endl;
	cout<<"2.选课"<<endl;
	cout<<"3.退选"<<endl;
	cout<<"4.录入成绩"<<endl;
	cout<<"0.退出程序"<<endl;
	do{
		int n;
		cin>>n;
		switch(n){
		case 1:
			list(k,course);
			break;
		case 2:
			choose();
			break;
		case 3:
			drop();
			break;
		case 4:
			putin(k,course,0,0);
			break;
		case 0:
			exit(0);
		default:
			cout<<"您输入错误"<<endl;
		}
	}while(1);
}


