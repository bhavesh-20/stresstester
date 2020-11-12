#include <stdio.h>

long int ceil_(long long int r,int n){
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
	    long long int prefix[n];
	    for(int i=0;i<n;i++){
	                int x=i;
	                if(a[x]%2==0){
	                    if(a[x+1]==1 && x+1!=n-1){
	                        prefix[x]=(a[x]-1)%mod;
	                        i++;
	                        prefix[i]=0;
	                    }
	                    else if(x==n-1){
	                        prefix[x]=(a[x]-1)%mod;
	                    }
	                    else{
	                        prefix[x]=(a[x])%mod;
	                    }
	                }
	                else{
	                    if(a[x+1]==1  && x+1!=n-1){
	                        prefix[x]=(a[x])%mod;
	                        i++;
	                        prefix[i]=0;
	                    }
	                    else if(x==n-1){
	                        prefix[x]=(a[x])%mod;
	                    }
	                    else{
	                        prefix[x]=(a[x]-1)%mod;
	                    }
	                }
	            }
	   for(int i=1;i<n;i++){
	       prefix[i]=(prefix[i]+prefix[i-1])%mod;
	   }
	   //for(int i=0;i<n;i++){
	   //    printf("%d ",prefix[i]);
	   //}
	    int q;
	    scanf("%d",&q);
	    while(q--){
	        long long int r;
	        scanf("%lld",&r);
	        if(a[0]==1){
	            if(n==1){
	                printf("%lld ",r%mod);   
	            }
	            else{
	            long long int ans=ceil_(r,n);
	            printf("%lld ",ans%mod);
	            }
	        }
	        else{
	            long long int sum=0;
	            long long int index,ct;
	            ct=(r)/n;
	            index=(r)%n;
	            if(index==0){
	               ct--;
	               index=n-1;
	               sum=(ct*prefix[n-1])%mod;
	               sum=(sum+prefix[index-1]+a[index])%mod;
	               if(a[index]==1 && index!=n-1){
	                   sum--;
	               }
	            }
	            else{
	                sum=(ct*prefix[n-1])%mod;
	                if(index-2>=0)
	                   sum=(sum+prefix[index-2])%mod;
	                sum=(sum+a[index-1])%mod;
	                if(a[index-1]==1 && index-1!=n-1){
	                   if(index-2>=0){
	                    if(a[index-2]%2!=0)
	                        sum--;
	                    else
	                        sum++;
	                   }
	                }
	            }
	            printf("%lld ",sum);
	        }
	        
	    }
	    printf("\n");
	}
	return 0;
}