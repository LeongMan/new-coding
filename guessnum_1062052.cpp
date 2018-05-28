#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
	int A[4]={0},B[4]={0};
	int a,temp;
	srand((unsigned)time(NULL));
	for (int i=0;i<4;i++)
	{
		A[i]=rand()%9+1;
		if (i==3)
		{
			if (A[i-3]!=A[i-2]&&A[i-3]!=A[i-1]&&A[i-3]!=A[i]&&A[i-2]!=A[i-1]&&A[i-2]!=A[i]&&A[i-1]!=A[i])
			{
				cout << "ANS=" << A[i-3] << A[i-2] << A[i-1] << A[i];
			}
			else
			{
				i=0;
			}
		}
	}
	cout << endl;
	for (int i=0;i<4;i++)
	{
		B[i]=rand()%9+1;
		if (i==3)
		{
			tryagain:
			if (B[i-3]!=B[i-2]&&B[i-3]!=B[i-1]&&B[i-3]!=B[i]&&B[i-2]!=B[i-1]&&B[i-2]!=B[i]&&B[i-1]!=B[i])
			{
				a=0,temp=0;
				cout << B[i-3] << B[i-2] << B[i-1] << B[i] << endl;
				if (A[i-3]==B[i-3] && A[i-2]==B[i-2] && A[i-1]==B[i-1] && A[i]==B[i])
				{
					cout << "猜對了"; 
				}
				else if (A[i-3]!=B[i-3] && A[i-2]==B[i-2] && A[i-1]==B[i-1] && A[i]==B[i])//3A0B--第1錯 
				{
					B[i-3]=rand()%9+1;
					cout << "3A0B" << endl;
					goto tryagain;
				}
				else if (A[i-3]==B[i-3] && A[i-2]!=B[i-2] && A[i-1]==B[i-1] && A[i]==B[i])//3A0B--第2錯 
				{
					B[i-2]=rand()%9+1;
					cout << "3A0B" << endl;
					goto tryagain;
				}
				else if (A[i-3]==B[i-3] && A[i-2]==B[i-2] && A[i-1]!=B[i-1] && A[i]==B[i])//3A0B--第3錯 
				{
					B[i-1]=rand()%9+1;
					cout << "3A0B" << endl;
					goto tryagain;
				}
				else if (A[i-3]==B[i-3] && A[i-2]==B[i-2] && A[i-1]==B[i-1] && A[i]!=B[i])//3A0B--第4錯 
				{
					B[i]=rand()%9+1;
					cout << "3A0B" << endl;
					goto tryagain;
				}
				else if (A[i-3]!=B[i-3] && A[i-2]!=B[i-2] && A[i-1]==B[i-1] && A[i]==B[i])//12錯 
				{
					if (A[i-3]==B[i-2] && A[i-2]==B[i-3])//2A2B
					{
						B[i-2]=A[i-2];
						B[i-3]=A[i-3];
						cout << "2A2B" << endl;
						goto tryagain;
					}
					else if (A[i-3]==B[i-2])//2A1B--改1 
					{
						B[i-3]=A[i-3];
						B[i-2]=rand()%9+1;
						cout << "2A1B" << endl;
						goto tryagain;
					}
					else if (A[i-2]==B[i-3])//2A1B--改2 
					{
						B[i-2]=A[i-2];
						B[i-3]=rand()%9+1;
						cout << "2A1B" << endl;
						goto tryagain;
					}
					else
					{
					    B[i-3]=rand()%9+1;
					    B[i-2]=rand()%9+1;
					    cout << "2A0B" << endl;
					    goto tryagain;
					} 
				}
				else if (A[i-3]!=B[i-3] && A[i-2]==B[i-2] && A[i-1]!=B[i-1] && A[i]==B[i])//13錯 
				{
					if (A[i-3]==B[i-1] && A[i-1]==B[i-3])//2A2B
					{
						B[i-1]=A[i-1];
						B[i-3]=A[i-3];
						cout << "2A2B" << endl;
						goto tryagain;
					}
					else if (A[i-3]==B[i-1])//2A1B--改1 
					{
						B[i-3]=A[i-3];
						B[i-1]=rand()%9+1;
						cout << "2A1B" << endl;
						goto tryagain;
					}
					else if (A[i-1]==B[i-3])//2A1B--改3 
					{
						B[i-1]=A[i-1];
						B[i-3]=rand()%9+1;
						cout << "2A1B" << endl;
						goto tryagain;
					}
					else
					{
					    B[i-3]=rand()%9+1;
					    B[i-1]=rand()%9+1;
					    cout << "2A0B" << endl;
					    goto tryagain;
					} 
				}
				else if (A[i-3]!=B[i-3] && A[i-2]==B[i-2] && A[i-1]==B[i-1] && A[i]!=B[i])//14錯 
				{
					if (A[i-3]==B[i] && A[i]==B[i-3])//2A2B
					{
						B[i]=A[i];
						B[i-3]=A[i-3];
						cout << "2A2B" << endl;
						goto tryagain;
					}
					else if (A[i-3]==B[i])//2A1B--改1
					{
						B[i-3]=A[i-3];
						B[i]=rand()%9+1;
						cout << "2A1B" << endl;
						goto tryagain;
					}
					else if (A[i]==B[i-3])//2A1B--改4 
					{
						B[i]=A[i];
						B[i-3]=rand()%9+1;
						cout << "2A1B" << endl;
						goto tryagain;
					}
					else
					{
					    B[i-3]=rand()%9+1;
					    B[i]=rand()%9+1;
					    cout << "2A0B" << endl;
					    goto tryagain;
					} 
				}
				else if (A[i-3]==B[i-3] && A[i-2]!=B[i-2] && A[i-1]!=B[i-1] && A[i]==B[i])//23錯 
				{
					if (A[i-2]==B[i-1] && A[i-1]==B[i-2])//2A2B
					{
						B[i-1]=A[i-1];
						B[i-2]=A[i-2];
						cout << "2A2B" << endl;
					    goto tryagain;
					}
					else if (A[i-2]==B[i-1])//2A1B--改2 
					{
						B[i-2]=A[i-2];
						B[i-1]=rand()%9+1;
						cout << "2A1B" << endl;
					    goto tryagain;
					}
					else if (A[i-1]==B[i-2])//2A1B--改3
					{
						B[i-1]=A[i-1];
						B[i-2]=rand()%9+1;
						cout << "2A1B" << endl;
					    goto tryagain;
					}
					else
					{
					    B[i-1]=rand()%9+1;
					    B[i-2]=rand()%9+1;
					    cout << "2A0B" << endl;
					    goto tryagain;
					}
				}
				else if (A[i-3]==B[i-3] && A[i-2]!=B[i-2] && A[i-1]==B[i-1] && A[i]!=B[i])//24錯 
				{
					if (A[i-2]==B[i] && A[i]==B[i-2])//2A2B
					{
						B[i-2]=A[i-2];
						B[i]=A[i];
						cout << "2A2B" << endl;
					    goto tryagain;
					}
					else if (A[i-2]==B[i])//2A1B--改2 
					{
						B[i-2]=A[i-2];
						B[i]=rand()%9+1;
						cout << "2A1B" << endl;
					    goto tryagain;
					}
					else if (A[i]==B[i-2])//2A1B--改4
					{
						B[i]=A[i];
						B[i-2]=rand()%9+1;
						cout << "2A1B" << endl;
					    goto tryagain;
					}
					else
					{
					    B[i]=rand()%9+1;
					    B[i-2]=rand()%9+1;
					    cout << "2A0B" << endl;
					    goto tryagain;
					}
				}
				else if (A[i-3]==B[i-3] && A[i-2]==B[i-2] && A[i-1]!=B[i-1] && A[i]!=B[i])//34錯 
				{
					if (A[i-1]==B[i] && A[i]==B[i-1])//2A2B
					{
						B[i-1]=A[i-1];
						B[i]=A[i];
						cout << "2A2B" << endl;
					    goto tryagain;
					}
					else if (A[i-1]==B[i])//2A1B--改3 
					{
						B[i-1]=A[i-1];
						B[i]=rand()%9+1;
						cout << "2A1B" << endl;
					    goto tryagain;
					}
					else if (A[i]==B[i-1])//2A1B--改4 
					{
						B[i]=A[i];
						B[i-1]=rand()%9+1;
						cout << "2A1B" << endl;
					    goto tryagain;
					}
					else
					{
					    B[i-1]=rand()%9+1;
					    B[i]=rand()%9+1;
					    cout << "2A0B" << endl;
					    goto tryagain;
					}
				}
				else if (A[i-3]!=B[i-3] && A[i-2]!=B[i-2] && A[i-1]!=B[i-1] && A[i]==B[i])//123錯 
				{
					for (int j=0;j<3;j++)
					{
						for (int k=0;k<3;k++)
						{
							if (A[j]==B[k])
							{
								a++;
							}
						}
					}
					if (a==1)
					{
						temp=B[i-3];
						B[i-3]=B[i-2];
						B[i-2]=B[i-1];
						B[i-1]=temp;
						cout << "1A1B" << endl;
						goto tryagain;
					}
					else if (a==2)
					{
						temp=B[i-3];
						B[i-3]=B[i-2];
						B[i-2]=B[i-1];
						B[i-1]=temp;
						cout << "1A2B" << endl;
						goto tryagain;
					}
					else if (a==3)
					{
						temp=B[i-3];
						B[i-3]=B[i-2];
						B[i-2]=B[i-1];
						B[i-1]=temp;
						cout << "1A3B" << endl;
						goto tryagain;
					}
					else
					{
						B[i-3]=rand()%9+1;
					    B[i-2]=rand()%9+1;
					    B[i-1]=rand()%9+1;
					    cout << "1A0B" << endl;
					    goto tryagain;
					}
				}
				else if (A[i-3]!=B[i-3] && A[i-2]!=B[i-2] && A[i-1]==B[i-1] && A[i]!=B[i])//124錯 
				{
					for (int j=0;j<4;j++)
					{
						for (int k=0;k<4;k++)
						{
							if (k!=2||j!=2)
							{
								if (A[j]==B[k])
								{
									a++;
								}
							}
						}
					}
					if (a==1)
					{
						temp=B[i];
						B[i]=B[i-2];
						B[i-2]=B[i-3];
						B[i-3]=temp;
						cout << "1A1B" << endl;
						goto tryagain;
					}
					else if (a==2)
					{
						temp=B[i];
						B[i]=B[i-2];
						B[i-2]=B[i-3];
						B[i-3]=temp;
						cout << "1A2B" << endl;
						goto tryagain;
					}
					else if (a==3)
					{
						temp=B[i];
						B[i]=B[i-2];
						B[i-2]=B[i-3];
						B[i-3]=temp;
						cout << "1A3B" << endl;
						goto tryagain;
					}
					else 
					{
						B[i]=rand()%9+1;
					    B[i-2]=rand()%9+1;
					    B[i-3]=rand()%9+1;
					    cout << "1A0B" << endl;
					    goto tryagain;
					}
				}
				else if (A[i-3]!=B[i-3] && A[i-2]==B[i-2] && A[i-1]!=B[i-1] && A[i]!=B[i])//134錯 
				{
					for (int j=0;j<4;j++)
					{
						for (int k=0;k<4;k++)
						{
							if (j!=1||k!=1)
							{
								if (A[j]==B[k])
								{
									a++;
								}
							}
						}
					}
					if (a==1)
					{
						temp=B[i];
						B[i]=B[i-3];
						B[i-3]=B[i-1];
						B[i-1]=temp;
						cout << "1A1B" << endl;
						goto tryagain;
					}
					else if (a==2)
					{
						temp=B[i];
						B[i]=B[i-3];
						B[i-3]=B[i-1];
						B[i-1]=temp;
						cout << "1A2B" << endl;
						goto tryagain;
					}
					else if (a==3)
					{
						temp=B[i];
						B[i]=B[i-3];
						B[i-3]=B[i-1];
						B[i-1]=temp;
						cout << "1A3B" << endl;
						goto tryagain;
					}
					else
					{
						B[i]=rand()%9+1;
					    B[i-3]=rand()%9+1;
					    B[i-1]=rand()%9+1;
					    cout << "1A0B" << endl;
					    goto tryagain;
					}
				}
				else if (A[i-3]==B[i-3] && A[i-2]!=B[i-2] && A[i-1]!=B[i-1] && A[i]!=B[i])//234錯 
				{
					for (int j=1;j<4;j++)
					{
						for (int k=1;k<4;k++)
						{
							if (A[j]==B[k])
							{
								a++;
							}
						}
					}
					if (a==1)
					{
						temp=B[i];
						B[i]=B[i-2];
						B[i-2]=B[i-1];
						B[i-1]=temp;
						cout << "1A1B" << endl;
						goto tryagain;
					}
					else if (a==2)
					{
						temp=B[i];
						B[i]=B[i-2];
						B[i-2]=B[i-1];
						B[i-1]=temp;
						cout << "1A2B" << endl;
						goto tryagain;
					}
					else if (a==3)
					{
						temp=B[i];
						B[i]=B[i-2];
						B[i-2]=B[i-1];
						B[i-1]=temp;
						cout << "1A3B" << endl;
						goto tryagain;
					}
					else 
					{
						B[i]=rand()%9+1;
					    B[i-2]=rand()%9+1;
					    B[i-1]=rand()%9+1;
					    cout << "1A0B" << endl;
					    goto tryagain;
					}
				} 				
				else 
				{
					for (int j=0;j<4;j++)
					{
						for (int k=0;k<4;k++)
						{
							if (A[j]==B[k])
							{
								a++;
							}
						}
					}
					if (a==1)
					{
						temp=B[i-3];
						B[i-3]=B[i-2];
						B[i-2]=B[i-1];
						B[i-1]=B[i];
						B[i]=temp;
						cout << "0A1B" << endl;
						goto tryagain;
					}
					else if (a==2)
					{
						temp=B[i-3];
						B[i-3]=B[i-2];
						B[i-2]=B[i-1];
						B[i-1]=B[i];
						B[i]=temp;
						cout << "0A2B" << endl;
						goto tryagain;
					}
					else if (a==3)
					{
						temp=B[i-3];
						B[i-3]=B[i-2];
						B[i-2]=B[i-1];
						B[i-1]=B[i];
						B[i]=temp;
						cout << "0A3B" << endl;
						goto tryagain;
					}
					else if (a==4)
					{
						temp=B[i-3];
						B[i-3]=B[i-2];
						B[i-2]=B[i-1];
						B[i-1]=B[i];
						B[i]=temp;
						cout << "0A4B" << endl;
						goto tryagain;
					}
					cout << "0A0B" << endl;
					i=0;
				}
			}
			else
			{
				i=0;
			}
		}
	}
	return 0;
}
