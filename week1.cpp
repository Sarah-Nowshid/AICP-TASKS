#include <iostream>
#include<string.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	//task 1
	int n=30 ,difference[n];
	string names[n];
	float weight[n];
	float weight_lterm[n];
	cout<<"\n weights of the student on first term \n";
	for(int i=0;i<n;i++)
	{
		cout<<"enter student "<<i<<" name's :";
		cin>>names[i];
		cout<<"\n enter his/her weight :";
		cin>>weight[i];
		//validating weight
		while(weight[i]<20)
		{
			cout<<"\n your weight is invalid, enter again :";
			cin>>weight[i];
		}
	}
	
	//displaying information
	cout<<endl;
	cout<<endl;
	

	
	//task 2
	cout<<"\n now, weights of the student recorded on last term\n";
	for(int i=0;i<n;i++)
	{
		cout<<"\n enter student "<<i<<"weight ";
		cin>>weight_lterm[i];
		while(weight[i]<20)
		{
			cout<<"\n your weight is invalid, enter again :";
			cin>>weight_lterm[i];
		}
		//difference in weights
		if(weight[i]>=weight_lterm[i])
		{
			difference[i]=weight[i]-weight_lterm[i];
		}
		else if(weight_lterm[i]>=weight[i])
		{
			difference[i]=weight_lterm[i]-weight[i];
		}
			
	}
	cout<<endl;
	cout<<endl;
	//task 3
	cout<<"Names\t\t\tWeights\t\t\tDifference"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<endl;
		cout<<names[i]<<"\t\t\t"<<weight[i]<<"\t\t\t"<<difference[i]<<"\n";
		if(difference[i]<2.5)
		{
			cout<<names[i]<<" has a fall in weight";
		}
		else if(difference[i]>2.5)
		{
			cout<<names[i]<<" has a rise in weight";
		}
	}
	
	return 0;
}