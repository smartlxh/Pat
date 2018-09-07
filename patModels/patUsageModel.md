### 常用工具
#### 最大公因数gcd与最小公倍数lcm
```
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}

int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}

```
#### 常用函数
```
reverse(str.begin(),str.end());
str.substr(a,b) // a为起始位，b为个数
upper_bound(array.begin(),array.end())
lower_bound(array.begin(),array.end())
tolower(char)
toupper(char)
stoi(str)
```
判断是否是质数
```
bool isPrime(int a){

    for(int i=2;i*i<=a;i++){
        if(a%i==0) return false;
    }
    return true;
}

```
