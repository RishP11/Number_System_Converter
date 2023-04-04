#include<bits/stdc++.h>
using namespace std ;
//Function for separating integer and fractional parts:
pair<string,string> separate(string inp){
    string p1,p2 ;
    p1="" ;
    p2="0." ;
    int i=0 ;
    while(i<inp.size()){
        if(inp[i]=='.'){
            break;
        }
        p1+=inp[i] ;
        i++ ;
    }
    i++ ;
    while(i<size(inp)){
        p2+=inp[i] ;
        i++ ;
    }
    return {p1,p2} ;
}
//Function to convert any number system to decimal number system:
pair<int,float> anytodecimal(string whole,string frac,int rad1,map<int,char>m){
    int wdec=0 ;float fdec=0 ;
    //Converting the integer part:
    for(int i=size(whole)-1;i>=0;i--){
        int j=0 ;
        while(m[j]!=whole[i]){
            j++ ;
        }
        wdec+=j*pow(rad1,size(whole)-1-i) ;
    }
    //Converting the fractional part:
    if(frac!="0."){
        for(int i=2;i<size(frac);i++){
            int j=0 ;
            while(m[j]!=frac[i]){
                j++ ;
            }
            fdec+=j*pow(1.0/rad1,i-1) ;
        }
    }
    return {wdec,fdec} ;
}
//Function to convert decimal numbers to any system.
pair<string,string> decimaltoany(int w,float f,int rad2,map<int,char>m){
    //Converting integer part :
    string finW="" ;
    while(w!=0){
        int temp=w%rad2 ;
        for(int i=0;i<rad2;i++){
            if(i==temp){
                finW=finW+m[temp] ;
            }
        }
        w=w/rad2 ;
    }
    //Converting fractional part:
    string finF="" ;
    for(int i=0;i<10;i++){
        f=f*rad2 ;
        int t=int(f) ; 
        finF=finF+m[t] ;
        f=f-t ;
    }
    return {finW,finF} ;
}
int main(){
    //Input from the user:
    cout << "------------------------------------------------" << endl ;
    int rad1 ;
    cout << "Enter input Radix:" ;
    cin >> rad1 ;
    string inp ;
    cout << "Enter number in above mentioned system:" ;
    cin >> inp ;
    int rad2 ;
    cout << "Enter output Radix :" ;
    cin >> rad2 ;
    //Making a map:
    map<int,char> m ;
    m[0]='0' ;
    m[1]='1' ;
    m[2]='2' ;
    m[3]='3' ;
    m[4]='4' ;
    m[5]='5' ;
    m[6]='6' ;
    m[7]='7' ;
    m[8]='8' ;
    m[9]='9' ;
    m[10]='A' ;
    m[11]='B' ;
    m[12]='C' ;
    m[13]='D' ;
    m[14]='E' ;
    m[15]='F' ;
    //Using defined function for separation of the number:
    string whole=separate(inp).first ;
    string frac=separate(inp).second ;
    //Conversion of every number regardless of the system to Decimal:
    int tempW=anytodecimal(whole,frac,rad1,m).first ;
    float tempF=anytodecimal(whole,frac,rad1,m).second ;
    //Final conversion to the desired number system:
    string finW,finF ;
    if(rad2==10){
        cout << "The Number is:" << tempW+tempF << endl ;
    }
    else{
       finW=decimaltoany(tempW,tempF,rad2,m).first;
       finF=decimaltoany(tempW,tempF,rad2,m).second;
       reverse(finW.begin(),finW.end()) ;
       cout << finW << "." << finF << endl ;
    }
    cout << "------------------------------------------------" ;
}