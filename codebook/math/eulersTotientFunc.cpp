// The totient function , also called Euler's totient function, is defined as the number of positive integers that are relatively prime to (i.e., do not contain any factor in common with) , where 1 is counted as being relatively prime to all numbers.
// This code took less than 0.5s to calculate with MAX = 10^7
#define MAX 10000000

int phi[MAX];
bool pr[MAX];

void totient(){
  for(int i = 0; i < MAX; i++){
    phi[i] = i;
    pr[i] = true;
  }
  for(int i = 2; i < MAX; i++)
    if(pr[i]){
      for(int j = i; j < MAX; j+=i){
        pr[j] = false;
        phi[j] = phi[j] - (phi[j] / i);
      }
      pr[i] = true;
    }
}
