#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
	unsigned int n;
	scanf("%u",&n);
	vector<bool>isPrime(n,1);//lim tested to 1e14 got to 1e10 no idea whats up with that

	for(unsigned int i=2;i*i<n;++i){
		if(isPrime[i]==0) continue;
		printf("%u\n",i);
		isPrime[i]=0;
		for(unsigned int j=i*i;j<n;j+=i) isPrime[j]=0;
	}


	for(unsigned int i=0;i<n;++i){
		if(isPrime[i]==0) continue;
		printf("%u\n",i);
	}

	return 0;
}
