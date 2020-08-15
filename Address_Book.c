#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int i,count=0,c;
FILE *f1;
struct AddressBook
{
	char fn[15];
	char ln[15];
	int age;
	char phone[11];
	char city[15];
	char pincode[7];
	char address[100];


}a[50];
void AddItem(int b)
{
	int j,k,y;

	printf("Enter First Name : ");
	scanf("%s",a[b].fn);
	printf("Enter Last Name : ");
	scanf("%s",a[b].ln);
	printf("Enter Age : ");
	scanf("%d",&a[b].age);
	printf("Enter Phone Number : +91 ");
	scanf("%s",a[b].phone);
      z:
	for(i=0;i<=count;i++)
	{
		for(j=i+1;j<=count;j++)
		{
			y=0;
			for(k=0;k<strlen(a[i].phone);k++)
			{
				if(a[i].phone[k]==a[j].phone[k])
				{
					++y;
				}
			}
			if(y==strlen(a[i].phone))
			{
				printf("Same Number Cannot Be Used\n");
				printf("Re - Enter the phone number: +91 ");
				scanf("%s", &a[j].phone);
				goto z;
			}
		}
	}
	printf("Enter City : ");
	scanf("%s",a[b].city);
	printf("Enter Pincode : ");
	scanf("%s",a[b].pincode);
	printf("Enter Address : ");
	scanf("%s",a[b].address);
	f1=fopen("data.txt","a");
	fprintf(f1,"   %d\t%s\t\t%s\t\t%d\t%s\t%s\t%s\t%s\n",b+1,a[b].fn,a[b].ln,a[b].age,a[b].phone,a[b].city,a[b].pincode,a[b].address);
	fclose(f1);
	++count;
}
void SearchItem(int b)
{
	int y=0,j,n,c1=0;
	char number[11],fn1[15],ln1[15];
	if(b==0)
	{
		printf("Not Even Single Data Is Present Then How You Will Search");
	}
	else
	{
		printf("\n1.First-Name");
		printf("\n2.Last-Name");
		printf("\n3.Phone-Number");
		printf("\nWith Which Value You Would Like To Search : ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("Enter First-Name : ");
				scanf("%s",fn1);
				for(i=0;i<count;i++)
				{
					y=0;
					for(j=0;j<strlen(fn1);j++)
					{
						if(a[i].fn[j]==fn1[j])
						{
							++y;
						}
					}
					if(y==strlen(fn1))
					{
						++c1;
						printf("\nSearched Successfully\n");
						printf("\nItem No : %d",i+1);
						printf("\nFirst Name : %s",a[i].fn);
						printf("\nLast Name : %s",a[i].ln);
						printf("\nAge : %d",a[i].age);
						printf("\nPhone Number : +91 %s",a[i].phone);
						printf("\nCity : %s",a[i].city);
						printf("\nPincode : %s",a[i].pincode);
						printf("\nAddress : %s\n",a[i].address);

					}
					if(c1<=i&&i==count-1)
					{
						c1=0;
						goto v;
					}
				}
				if(y<strlen(fn1))
				{
					printf("\n!!!!! Matching Not Found !!!!!\n");
				}
			      v:
				break;
			  case 2:
				printf("Enter Last-Name : ");
				scanf("%s",ln1);
				for(i=0;i<count;i++)
				{
					y=0;
					for(j=0;j<strlen(ln1);j++)
					{
						if(a[i].ln[j]==ln1[j])
						{
							++y;
						}
					}
					if(y==strlen(ln1))
					{
						++c1;
						printf("\nSearched Successfully\n");
						printf("\nItem No : %d",i+1);
						printf("\nFirst Name : %s",a[i].fn);
						printf("\nLast Name : %s",a[i].ln);
						printf("\nAge : %d",a[i].age);
						printf("\nPhone Number : +91 %s",a[i].phone);
						printf("\nCity : %s",a[i].city);
						printf("\nPincode : %s",a[i].pincode);
						printf("\nAddress : %s\n",a[i].address);
					}
					if(c1<=i&&i==count-1)
					{
						c1=0;
						goto r;
					}
				}
				if(y<strlen(ln1))
				{
					printf("\n!!!!! Matching Not Found !!!!!\n");
				}
			      r:
				break;
			  case 3:
				printf("Enter Phone-Number : ");
				scanf("%s",number);
				for(i=0;i<count;i++)
				{
					y=0;
					for(j=0;j<strlen(number);j++)
					{
						if(a[i].phone[j]==number[j])
						{
							++y;
						}
					}
					if(y==strlen(number))
					{
						++c1;
						printf("\nItem No : %d",i+1);
						printf("\nFirst Name : %s",a[i].fn);
						printf("\nLast Name : %s",a[i].ln);
						printf("\nAge : %d",a[i].age);
						printf("\nPhone Number : +91 %s",a[i].phone);
						printf("\nCity : %s",a[i].city);
						printf("\nPincode : %s",a[i].pincode);
						printf("\nAddress : %s\n",a[i].address);
					}
					if(c1<=i&&i==count-1)
					{
						c1=0;
						goto s;
					}
				}
				if(y<strlen(number))
				{
					printf("\n!!!!! Matching Not Found !!!!!\n");
				}
			      s:
				break;
			default:
				printf("!!!! Invalid Choice !!!!");
		}
	}
}
void DisplayItem()
{
	int j;
	printf("Which Data You Want To display : ");
	scanf("%d",&j);
	if(j>count||j==0)
	{
		printf("Data For %d Is Not available",j);
	}
	else
	{
		printf("\nItem No : %d",j);
		--j;
		printf("\nFirst Name : %s",a[j].fn);
		printf("\nLast Name : %s",a[j].ln);
		printf("\nAge : %d",a[j].age);
		printf("\nPhone Number : +91 %s",a[j].phone);
		printf("\nCity : %s",a[j].city);
		printf("\nPincode : %s",a[j].pincode);
		printf("\nAddress : %s\n",a[j].address);
	}
}
void AllItem(int d)
{
	for(d=0;d<count;d++)
	{
		printf("\nItem No : %d",d+1);
		printf("\nFirst Name : %s",a[d].fn);
		printf("\nLast Name : %s",a[d].ln);
		printf("\nAge : %d",a[d].age);
		printf("\nPhone Number : +91 %s",a[d].phone);
		printf("\nCity : %s",a[d].city);
		printf("\nPincode : %s",a[d].pincode);
		printf("\nAddress : %s\n",a[d].address);
	}
}
main()
{
	while(1)
	{
		clrscr();
		printf("\nCurrently There Is %d Items",count);
		printf("\n**********************");
		printf("\n1.Add Item.          *");
		printf("\n2.Search Item.       *");
		printf("\n3.Display Item.      *");
		printf("\n4.Display All Items. *");
		printf("\n5.Exit.              *");
		printf("\n**********************");
		printf("\n\nEnter Number To Perform Above Options : ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				AddItem(count);
				getch();
				break;
			case 2:
				SearchItem(count);
				getch();
				break;
			case 3:
				DisplayItem();
				getch();
				break;
			case 4:
				AllItem(i);
				getch();
				break;
			case 5:
				printf("\nThanks For Using Address Book");
				getch();
				exit(0);
			default:
				printf("\nNo Options Were Available For Entered Number %d ",c);
		}
	}
}