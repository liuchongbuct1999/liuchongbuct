#include <stdio.h> 
#include <time.h>
#include <math.h>
#include <stdlib.h>
//ʵ��ѡ��ĳһ����ĸ��������ڸõ�ĺ���ֵ�����̶� 
double function(double x){
	return sin(x);
}
int main(){
	//��ʼ��20����
	srand((unsigned)time(NULL)); //����ÿ�εõ������������һ�� 
	double x[20];
	double value[20] ;
	for(int i = 0;i<20;i++){
		x[i] = ((double)rand() / RAND_MAX) * 10 ;//��ʼ���ĵ���0-10
		value[i] = function(x[i]);
		printf("x=%.4lf,f(x)=%.4lf\n", x[i], value[i]);
	} 
	
	//Ϊ�˷�ֹ�����������̶Ĳ���Ӱ�죬�����е���ֵ����ȥ��Сֵ��������� 
	double min=0;
	for(int i = 0;i<20;i++){
		if(value[i]<min){
			min = value[i];
		}
	}
	printf("min(value)=%.4lf\n",min);
	
	for(int i = 0;i<20;i++){
		value[i]-=min;
	} 
	
	double sum;
	for(int i = 0;i<20;i++) {
		sum+=value[i];
	}
	printf("sum(value(+))=%.4lf\n",sum);
	
	int number[20] = {0};//����ĳ���������Ŀ 
	//���պ���ֵ��С����ѡ��ĸ��� 
	
	for(int i = 0;i < 100000;i++){
		double qujian = 0;
		double random = ((double)rand() / RAND_MAX) * sum;
		for(int i = 0; i < 20 ;i++) {
			qujian += value[i];
			if(random < qujian){
				number[i]++;
				break;
			}
		}
	}
		
	for(int i = 0; i<20; i++){
		printf("value[%d]=%.4lf,number[%d]=%d\n",i, value[i], i,number[i]);
	}

	return 0;
}
