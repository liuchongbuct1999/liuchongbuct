#include <stdio.h> 
#include <time.h>
#include <math.h>
#include <stdlib.h>
//实现选择某一个点的概率正比于该点的函数值，轮盘赌 
double function(double x){
	return sin(x);
}
int main(){
	//初始化20个点
	srand((unsigned)time(NULL)); //这样每次得到的随机数都不一样 
	double x[20];
	double value[20] ;
	for(int i = 0;i<20;i++){
		x[i] = ((double)rand() / RAND_MAX) * 10 ;//初始化的点在0-10
		value[i] = function(x[i]);
		printf("x=%.4lf,f(x)=%.4lf\n", x[i], value[i]);
	} 
	
	//为了防止负数对于轮盘赌产生影响，将所有的数值都减去最小值变成正数。 
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
	
	int number[20] = {0};//落在某个区间的数目 
	//按照函数值大小决定选择的概率 
	
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
