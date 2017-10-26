#include "../template.cpp"

// todo non-destructive - this method swaps elements and destroyes indices

// put in unordered array and what smallest elem you want to find
// idx from 0 to arr.size()-1
int findKthMin(vi &arr, int kth){
    int low = 0, high = arr.size()-1, pivot, left, right;
    bool flag;
    while(low < high){
        pivot = (low + high) / 2;
        swap(arr[pivot], arr[low]);
        pivot = low;
        flag = true; // pivot on left?
        left = low;
        right = high;
        while(true){
            if(flag){
                while(left < right && arr[left] < arr[right]) right--;
            }else{
                while(left < right && arr[left] < arr[right]) left++;
            }
            if(left >= right)break;
            swap(arr[left], arr[right]);
            if(flag){
                left++;
            }else{
                right--;
            }
            flag = !flag;
        }
        if(left == kth)break;

        if(left < kth){
            low = left + 1;
        }else{
            high = left - 1;
        }
    }
    return kth;
}

void test(vi &arr, ll k){
    ll r=findKthMin(arr, k);
    cout << k << "-th lowest elem is " << arr[r] << " at index " << r << endl;
}

int main () {
    vi arr={5,9,1,5,2};
    test(arr, 0);
    test(arr, 1);
    test(arr, 2);
    test(arr, 3);
    test(arr, 4);
    
    return 0;
}
