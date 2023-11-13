#include <iostream>
#include <cmath>

long shortened_my_exgcd(long a, long b); // The extended Euclid's algorithm
long finding_a(long S0, long S1, long S2, long w); // The function to find the multiplier a
long finding_b(long a, long S0, long S1, long w); // The function to find the increment b
long my_rand(long& state, long w, int a, int b); // My version of LCG
void checking_function(long* Sn, int a, int b, long w, int n); // The function to check if the calculations are correct
long my_gcd(long a, long b); // The function to calculate GCD 
long my_gcd_for_arrays(long* arr, int n); // The function to calculate GCD, but for several numbers
long finding_w(const long* outputs, int length); // The function to find the unknown modulus w

int main(){
    long state;
    int a = 0; // the multiplier 
    int b = 0; // the increment;
    long w = static_cast<int>(std::pow(2.0, 31.0)); // the modulus
    int n = 0; // the number of outputs

    std::cout << "Insert the variables a and b:" << std::endl;
    std::cin >> a >> b;
    std::cout << "Insert the number of outputs: " << std::endl;;
    std::cin >> n; 
    long* Sn = new long[n]; 
    
    std::cout << n << " consequtive outputs:" << std::endl;
    for(int i = 0; i < n; i++){
        Sn[i] = my_rand(state, w, a, b);
        std::cout << Sn[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "The actual a and b are: " << a << " " << b << std::endl;

    long my_a = finding_a(Sn[0], Sn[1], Sn[2], w);
    long my_b = finding_b(a, Sn[0], Sn[1], w);
    
    std::cout << "The cracked a and b are: " << my_a << " " << my_b << std::endl;
    checking_function(Sn, my_a, my_b, w, n);
    std::cout << "If the modulus is unknown, then it's probably " << finding_w(Sn, n) << std::endl;

    delete [] Sn;
    return 0;
}

long my_rand(long& state, long w, int a, int b){
    state = (state * a + b) % w;
    return state;
}

long shortened_my_exgcd(long a, long b){
    long x, y;
    int q = 0, p = 1, r = 0, s = 1;
    while (a && b){
        if (a >= b){
            a = a - b; 
            p = p - r; 
            q = q - s; 
        } 
        else{
            b = b - a; 
            r = r - p; 
            s = s - q; 
        }
    }
    if(a){
        x = p;
        y = q;
    }
    else{
        x = r;
        y = s;
    }
    return x;
}

long my_gcd(long a, long b){
    if(a == 0){
        return b;
    }
    return my_gcd(b % a, a);
}
 
long my_gcd_for_arrays(long* arr, int n)
{
    long result = arr[0];
    for (int i = 1; i < n; i++)
        result = my_gcd(arr[i], result);
    return result;
}
 

long finding_a(long S0, long S1, long S2, long w){ 
    int diff_1_2 = S1 - S2;
    int diff_0_1 = S0 - S1;
    long diff_1_2_mod_w = 0, diff_0_1_mod_w = 0;
    int i = 0;

    if(diff_1_2 < 0){
        while(i * (-w) > diff_1_2){
            i++;
        }
        diff_1_2_mod_w = diff_1_2 - i * (-w);
    }
    else{
        diff_1_2_mod_w = diff_1_2 % w;
    }

    i = 0;

    if(diff_0_1 < 0){
        while(i * (-w) > diff_0_1){
            i++;
        }
        diff_0_1_mod_w = diff_0_1 - i * (-w);
    }
    else{
        diff_0_1_mod_w = diff_0_1 % w; // unnessesary
    }

    i = 0;
    long ex_Euclid_mod_w = 0;
    long ex_Euclid = shortened_my_exgcd(diff_0_1_mod_w, w); 
    
    if(ex_Euclid < 0){
        while(i * (-w) > ex_Euclid){
            i++;
        }
        ex_Euclid_mod_w = ex_Euclid - i * (-w);
    }
    else{
        ex_Euclid_mod_w = ex_Euclid % w;
    }

    long a = (diff_1_2_mod_w * ex_Euclid_mod_w) % w;
    return a;
}

long finding_b(long a, long S0, long S1, long w){ 
    long diff_S1_aS0 = S1 - a * S0;
    long b = 0;
    int i = 0; 

    if(diff_S1_aS0 < 0){
        while(i * (-w) > diff_S1_aS0){
            i++;
        }
        b = diff_S1_aS0 - i * (-w);
    }
    else{
        b = diff_S1_aS0 % w;
    }
    return b; 
}

long finding_w(const long* outputs, int length){
    long* diffs = new long [length - 1];
    long* formula = new long [length - 3];
    long modulus = 0;

    for(int i = 0; i < length; i++){
        diffs[i] = outputs[i+1] - outputs[i];
    }
    for(int i = 0; i < length - 2; i++){
        formula[i] = std::abs(diffs[i+2] * diffs[i] - diffs[i+1] * diffs[i+1]);
    }

    modulus = my_gcd_for_arrays(formula, length - 3);
    delete [] diffs;
    return modulus;
}

void checking_function(long* Sn, int a, int b, long w, int n){
    std::cout << "The checking result:" << std::endl;
    for(int i = 0; i < n; i++){
        std::cout << my_rand(Sn[i], w, a, b) << " ";
    }
    std::cout << std::endl;
}