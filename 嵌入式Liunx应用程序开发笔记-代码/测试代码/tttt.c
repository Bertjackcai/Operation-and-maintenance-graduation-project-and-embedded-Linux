#include<stdio.h>
#include<math.h>
int main()
{
	int i,j,n,k;
	while(scanf("%d",&n),n!=0)
	{
		int a[31][31]={0};
		i=n-1;//����1�����������һ�е��м�λ�� 
		j=n/2;
		k=1;
		while(k<=n*n)
		{
			a[i][j]=k;	
			i++;
			j++;
		if(i==n&&j<n)
		i=0;
		if(i<n&&j==n)
		j=0;
		if(i==n&&j==n)
		{
			i=0;j=0;
		}
		if(k==n*n+1)
		break;
		if(a[i][j]!=0)
		{
			i=i-2>=0?i-2:n-2;
			j=j-1>=0?j-1:n-1;			
		}
		k++;
		}
		//Ӧ��ĿҪ��Ҫ���룬���1 
		if(n==1||n==3){
		for(i=0;i<n;i++){
		for(j=0;j<n-1;j++)
		printf("%d ",a[i][j]);
		printf("%d\n",a[i][j]);
		}
		printf("\n");
		}
		// ��ĿҪ��Ҫ���룬���2 
		else if(n>=5&&n<=9){
		for(i=0;i<n;i++){
		for(j=0;j<n-1;j++)
		printf("%2d ",a[i][j]);
		printf("%2d\n",a[i][j]);
		}
		printf("\n");
		}
		//��ĿҪ��Ҫ���룬���3 
		else if(n>9){
		for(i=0;i<n;i++){
		for(j=0;j<n-1;j++)
		printf("%3d ",a[i][j]);
		printf("%3d\n",a[i][j]);
		}
		printf("\n");
		}
	}
	return 0;
} 
