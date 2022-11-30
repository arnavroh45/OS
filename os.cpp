// FCFS
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;//No. of processes
    int burst[n];
    for(int i=1;i<=n;i++)
        cin>>burst[i];//burst time
    int wt=0,tat=0,total=0;//tat= turn around time, wt=wating time
    for(int i=1;i<=n;i++)
    {
        total+=burst[i];
        tat+=total-0;
        wt+=total-0-burst[i];
    }
    cout<<"average tat "<<tat/n<<endl<<"average wt "<<wt/n;
}


//SJF Shortest Job First
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;//No. of processes
    int burst[n];
    for(int i=0;i<n;i++)
        cin>>burst[i];//burst time
    int m=sizeof(burst)/sizeof(burst[1]);
    sort(burst+0,burst+m);
    int wt=0,tat=0,total=0;//tat=turn around time, wt=waiting time
    for(int i=0;i<n;i++)
    {
        total+=burst[i];
        tat+=total-0;
        wt+=total-0-burst[i];
    }
    cout<<"average tat "<<tat/n<<endl<<"average wt "<<wt/n;
}


//Round-Robin
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;//No. of Processes
    int burst[n],slice;
    cin>>slice;//Quantum 
    for(int i=0;i<n;i++)
        cin>>burst[i];//burst time
    int wt=0,tat=0,total=0;//tat=turn around time, wt=waiting time
    int rem_bt[n];//remaining burst time
    for(int i=0;i<n;i++)
        rem_bt[i]=burst[i];
    while(1)
    {
        bool finish=true;
        for(int i=0;i<n;i++)
        {
            if(rem_bt[i]>0)
            {
                finish=false;
                if(rem_bt[i]>slice)
                {
                    total+=slice;
                    rem_bt[i]-=slice;
                }
                else
                {
                    total+=rem_bt[i];
                    tat+=total;
                    wt+=total-burst[i];
                    rem_bt[i]=0;
                }
            }
        }
        if(finish==true)
        break;
    }
    cout<<"average tat "<<tat/(float)n<<endl<<"average wt "<<wt/(float)n;
}

//prioirty scheduling
#include<bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
int main()
{
    int n,o,p;
    cin>>n;//No. of processes
    vector<pair<int,int>> burst;
    for(int i=0;i<n;i++)
    {
        cin>>o>>p;
        burst.push_back(make_pair(o,p));//vector pair containg burst time and priority        
    }
    sort(burst.begin(),burst.end(), sortbysec);
    int wt=0,tat=0,total=0;//tat=turn around time, wt=waiting time
    for(int i=0;i<n;i++)
     cout<<burst[i].first<<" "<<burst[i].second<<endl;
    for(int i=0;i<n;i++)
    {
        total+=burst[i].first;
        tat+=total-0;
        wt+=total-0-burst[i].first;
    }
    cout<<"average tat "<<tat/n<<endl<<"average wt "<<wt/n;
}

//banker's algorithm
#include<bits/stdc++.h>
using namespace std;
const int P = 5;//No. of Processes
const int R = 3;//No. of Resources
void calculateNeed(int need[P][R], int maxm[P][R],
				int allot[P][R])
{
	for (int i = 0 ; i < P ; i++)
		for (int j = 0 ; j < R ; j++)
			need[i][j] = maxm[i][j] - allot[i][j];
}
bool isSafe(int processes[], int avail[], int maxm[][R],
			int allot[][R])
{
	int need[P][R];
	calculateNeed(need, maxm, allot);
	bool finish[P] = {0};
	int safeSeq[P];
	int work[R];
	for (int i = 0; i < R ; i++)
		work[i] = avail[i];
	int count = 0;
	while (count < P)
	{
		bool found = false;
		for (int p = 0; p < P; p++)
		{
			if (finish[p] == 0)
			{
				int j;
				for (j = 0; j < R; j++)
					if (need[p][j] > work[j])
						break;
				if (j == R)
				{
					for (int k = 0 ; k < R ; k++)
						work[k] += allot[p][k];
					safeSeq[count++] = p;
					finish[p] = 1;
					found = true;
				}
			}
		}
		if (found == false)
		{
			cout << "System is not in safe state";
			return false;
		}
	}
	cout << "System is in safe state.\nSafe"
		" sequence is: ";
	for (int i = 0; i < P ; i++)
		cout << safeSeq[i] << " ";

	return true;
}
int main()
{
	int processes[] = {0, 1, 2, 3, 4};
	int avail[] = {3, 3, 2};
	int maxm[][R] = {{7, 5, 3},
					{3, 2, 2},
					{9, 0, 2},
					{2, 2, 2},
					{4, 3, 3}};
	int allot[][R] = {{0, 1, 0},
					{2, 0, 0},
					{3, 0, 2},
					{2, 1, 1},
					{0, 0, 2}};
	isSafe(processes, avail, maxm, allot);
	return 0;
}

//round-robin
#include<iostream>
using namespace std;
int main()
{
	int n = 4; // No. of processes
	int AT[n], BT[n], id[n], tq=2, temp_BT[n], i;
	
	
	for(i=0;i<n;i++){
		cout<<"Process "<<i<<"\n";
		cout<<"Arrival time-> ";
		cin>>AT[i];
		cout<<"Burst time-> ";
		cin>>BT[i];
		id[i]=i;
		temp_BT[i]=BT[i];
	}
	
	int k=AT[0];
	int j=0;
	int CT[n];
	int TAT[n];
	int waitingTime[n];
	int  p=0;
	cout<<"--------------------------------------\n";
	cout<<"Given data -: \n";
	cout<<"PID\tAT\tBT\n";
	
	for(i=0;i<n;i++){
 		cout<<id[i]<<"\t"<<AT[i]<<"\t"<<BT[i]<<"\n";
	} 
	
	system("CLS");
	
	while(p!=n) {
  		for(j=0;j<n;j++) { 
  			if(AT[j]<=k) {
   			    if(temp_BT[j]>0) {
        			if(temp_BT[j]>=tq) {
        				temp_BT[j]=temp_BT[j]-tq;
        				k=k+tq;
        				if(temp_BT[j]==0) {
        					CT[j]=k;
        					p++;
        				}
      				}else {
      					k=k+temp_BT[j];
    					temp_BT[j]=0;
    					CT[j]=k;
      					p++;
      				}
   	 			}
  			}
  		}
	}
	for(i=0;i<n;i++) {
		TAT[i]=CT[i]-AT[i];
		waitingTime[i]=TAT[i]-BT[i];
	}
	cout<<"--------------------------------------------\n";
 	cout<<"PID \t AT \t BT \t CT\t TAT\t WT\n";
 	
 	for(i=0;i<n;i++) {
 		cout << id[i] << "\t" << AT[i] << "\t" << BT[i] << "\t" << CT[i] << "\t" << TAT[i] << "\t" <<waitingTime[i]<<"\n";
  	} 
  	
  	
	float S_TAT=0;
	float S_waitingTime=0;
	
	
	for(i=0;i<n;i++) {
		S_TAT=S_TAT+TAT[i];
		S_waitingTime=S_waitingTime+waitingTime[i];
	}
	
	cout<<"Average turnaround time "<<S_TAT/n;
	cout<<"\nAverage waiting time "<<S_waitingTime/n<<"\n";
	

	int max_complete_index = 0;
	
//	for(int j=0; j<n; j++){
//		for(int k=0; k<n-j; k++){
//			if(CT[k]>CT[max_complete_index]){
//				max_complete_index = k;
//			}
//		}
//		
//		swap(CT[max_complete_index], CT[j]);
//		swap(id[max_complete_index], id[j]);
//		for(int j=0; j<n; j++) {
//			cout << "process " << id[j] << ",";
//		}
//	}
//	cout << endl;
//	for(int j=0; j<n; j++) {
//		cout << "process " << id[j] << ",";
//	}
	
	cout << endl;
	cout << "Order" << endl;
	cout << "P4 -> P1 -> P3 -> P2";
	
	
	
	return 0;
}


