#include <stdio.h>

long int ceil_(int r,int n){
    if(r==1){
        return 1;
    }
    if((r-1)%(n)==0){
        return (r-1)/(n);
    }
    return (r-1)/(n)+1;
}

int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	while(t--){
	    int n;
	    scanf("%d",&n);
	    long long int a[n];
	    long long int mod=1000000007;
	    for(int i=0;i<n;i++){
	        scanf("%lld",&a[i]);
	    }
	    int q;
	    scanf("%d",&q);
	    while(q--){
	        int r;
	        scanf("%d",&r);
	        if(a[0]==1){
	            if(n==1){
	                printf("%d ",r);   
	            }
	            else{
	            long long int ans=ceil_(r,n);
	            printf("%lld ",ans%mod);
	            }
	        }
	        else{
	            long long int sum=0;
	            int i;
	            for(i=0;i<r-1;i++){
	                int x=i%n;
	                if(a[x]%2==0){
	                    if(a[x+1]==1 && i+1!=r-1 && x+1!=n-1){
	                        sum=(sum+a[x]-1)%mod;
	                        i++;
	                    }
	                    else if(x==n-1){
	                        sum=(sum+a[x]-1)%mod;
	                    }
	                    else{
	                        sum=(sum+a[x])%mod;
	                    }
	                }
	                else{
	                    if(a[x+1]==1 && i+1!=r-1 && x+1!=n-1){
	                        sum=(sum+a[x])%mod;
	                        i++;
	                    }
	                    else if(x==n-1){
	                        sum=(sum+a[x])%mod;
	                    }
	                    else{
	                        sum=(sum+a[x]-1)%mod;
	                    }
	                }
	            }
	            sum=(sum+a[(r-1)%n])%mod;
	            printf("%lld ",sum);
	        }
	        
	    }
        printf("\n");
	}
	return 0;
}

