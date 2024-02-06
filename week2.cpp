#include <iostream>
#include<string.h>
using namespace std;

int main()
{
	int min_people=10;
	int max_people=15;
	int carer_threshold=24;
	int addcarer=2;
	
	float totalcost , cost_perperson;
	//costs
	int coach_cost[]={150,190,225};
	float meal_cost[]={14.00,13.50,13.00};
	float ticket_cost[]={21.00,20.00,19.00};
	
	//TASK 1
	
	int num_people;
	cout<<"Enter the number of senior citizens: ";
	cin>>num_people;
	
	//checking no of citizens
	while((num_people<=min_people ) || (num_people>=max_people))
	{
		cout<<"\n No of citizens are either too less or too many \n enter no of citizens again:";
		cin>>num_people;
		
	}
	
	if(num_people>carer_threshold)
	{
		
		cout<<"\n Additional 2 carers should go with senior citizens.they do not have to pay anythinG.";
		num_people=num_people+addcarer;
	}

	
	if(num_people>=12 && num_people<=16)
	{
		totalcost= num_people * (meal_cost[0]+ticket_cost[0]+coach_cost[0]);
		cost_perperson= totalcost / num_people;
		cout<<"\n Total cost : $ "<<totalcost;
		cout<<"\n Cost per person : $ "<<cost_perperson;
	}
	else if(num_people>=17 && num_people<=26)
	{
		totalcost= num_people * (meal_cost[1]+ticket_cost[1]);
		if(num_people>24)
		totalcost= num_people*addcarer *(meal_cost[1]+ticket_cost[1]+coach_cost[1]);
		
		cost_perperson= totalcost/num_people;
		cout<<"\n Total cost : $ "<<totalcost;
		cout<<"\n Cost per person : $ "<<cost_perperson;	
	}
	else if(num_people>=27 && num_people<=39)
	{
		totalcost= num_people * addcarer* (meal_cost[2]+ticket_cost[2]+coach_cost[2]);
		cost_perperson=totalcost/num_people;
		cout<<"\n Total cost : $ "<<totalcost;
		cout<<"\n Cost per person : $ "<<cost_perperson;
	}
	
	
	//TASK 2
	
	string names[max_people];
	float amountpaid[max_people];
	
	for(int i=0;i<num_people;i++)
	{
		amountpaid[i]=cost_perperson;
	}
	for(int i=0;i<num_people;i++)
	{
		cout<<"\n enter the name of  senior citizen / person "<<(i+1);
		cin>>names[i];
//		cout<<"\n enter the amount paid by "<<names[i]<<" :$ ";
//		cin>>amountpaid[i];
	}
	
	int extrapeople= max_people-num_people;
	for (int i = 0; i < extrapeople; ++i) {
        cout << "Enter the name of extra person " << i + 1 << ": ";
        cin >> names[num_people + i];
        amountpaid[num_people +i]=cost_perperson;

    }
    
     // Calculate total amount collected
    float totalAmountCollected = 0;
    for (int i = 0; i < num_people + extrapeople; ++i) {
        totalAmountCollected += amountpaid[i];
    }

    // Print list of people on the outing
    cout << "\nList of people on the outing:\n";
    cout<<"\nNames\t\t Amountpaid \n";
    for (int i = 0; i < num_people + extrapeople; ++i) {
        cout << names[i] << "\t\t: $" << amountpaid[i] << endl;
    }

    cout << "\nTotal amount collected: $" << totalAmountCollected << endl;
    
    //TASK 3
    float profit;
    profit =  totalAmountCollected-totalcost;
    if(profit>0) //positive
    {
    	cout<<"\n\n Profit made : $"<<profit;
	}
	else //negative
	{
		cout<<"\n\n loss calculated : $"<<profit;
	}
}

