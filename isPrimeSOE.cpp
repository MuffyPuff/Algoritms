#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	unsigned int n;
	scanf("%u",&n);
	vector<bool>isPrime(n,1);//lim ~8e6?

	for(unsigned int i=2;i*i<n&&isPrime[n]==1;++i){
		if(isPrime[i]==0) continue;
		isPrime[i]=0;
		for(unsigned int j=i*i;j<n;j+=i) isPrime[j]=0;
	}

	if(isPrime[n]==1) printf("True");

	return 0;
}
