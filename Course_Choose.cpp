#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
int nocout;
struct student{
	char no[20];/*ѧ��*/
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
		cout<<"û��ѧ����¼"<<endl;
	}
	else{
	cout<<"ѧ��\t"<<"����\t";
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
	cout<<"ѧ�ţ�";cin>>student1.no;
	cout<<"������";cin>>student1.name;
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
		cout<<"��ѧ���Ѵ���"<<endl;
		nocout--;
	}
	nocout++;
}
void drop()
{
	int i;
	student student2;
	cout<<"ѧ��:";cin>>student2.no;
	i=find(student2.no);
	if (i==nocout)
	{
		cout<<"��ѧ��������"<<endl;
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
		cout<<"������һ��ѧ��:";
		cin>>no1;
		g=find(no1);
		if(g==nocout){
			cout<<"��ѧ��������"<<endl;
	  }
	}
	if(g!=nocout){
		cout<<"��������Ƴɼ�"<<endl;
		for(int j=0;j<k;j++){
			cout<<course[j]<<":";cin>>students[g].score[j];
		}
		cout<<"�Ƿ�������У���������1����������0"<<endl;
		cin>>l;
		if(l==1){
			g++;h++;
			putin(k,course, h,g);
		}
		else if(l!=0){
			cout<<"�������˸�����ȷ������"<<endl;
		}
	}
	else {
		if(h!=0){
			cout<<"��β�ˣ�û��ѧ����"<<endl;
		}
	}
}
int main(){
	nocout=0;
	int k;
	char course[60][10];
	cout<<"�γ���:";cin>>k;
	for (int u=0;u<k;u++){
		cout<<"�γ���:";
		cin>>course[u];
	}
	cout<<"������������ѧѧԺ2012���ƿ��İ��������"<<endl;
	cout<<"1.�鿴ѧ������"<<endl;
	cout<<"2.ѡ��"<<endl;
	cout<<"3.��ѡ"<<endl;
	cout<<"4.¼��ɼ�"<<endl;
	cout<<"0.�˳�����"<<endl;
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
			cout<<"���������"<<endl;
		}
	}while(1);
}


