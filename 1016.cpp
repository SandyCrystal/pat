//
// Created by wxd on 2020/6/6.
//

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

struct records{
    string name;
    int status,month,time,day,hour,minute;
};



bool cmp(records a,records b){
    return a.name!=b.name?a.name<b.name:a.time<b.time;
}

// 计算每一个通话记录的相对开销
double billFromZero(records call,int*rate){
    double total = rate[call.hour]*call.minute+rate[24]*60*call.day;
    for(int i=0;i<call.hour;i++){
        total +=rate[i]*60;
    }
    return total/100.0;
}

int main(){
    int rate[25]={0},N;
    for(int i=0;i<24;i++){
        scanf("%d",&rate[i]);
        rate[24]+=rate[i];
    }
    scanf("%d",&N);
    vector<records> data(N);

    for(int i=0;i<N;i++){
        cin>>data[i].name;
        scanf("%d:%d:%d:%d",&data[i].month,&data[i].day,&data[i].hour,&data[i].minute);
        string temp;
        cin>>temp;
        data[i].status = (temp=="on-line")?1:0;
        // 换算成分钟，方便排序以及最后结果计算
        data[i].time = data[i].day*24*60+data[i].hour*60+data[i].minute;
    }
    sort(data.begin(),data.end(),cmp);
    map<string,vector<records>>customer;
    for(int i=1;i<N;i++){
        // 匹配符合条件的一对记录
        if(data[i].name==data[i-1].name&&data[i-1].status==1&&data[i].status==0){
            customer[data[i-1].name].push_back(data[i-1]);
            customer[data[i].name].push_back(data[i]);
        }
    }
    for(auto it:customer){
        vector<records> temp = it.second;
        cout<<it.first;
        printf(" %02d\n",temp[0].month);
        double total = 0.0f;
        for(int i=1;i<temp.size();i+=2){
            // 通过相对花费差额来计算真实花费
            double t = billFromZero(temp[i],rate) - billFromZero(temp[i-1],rate);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",temp[i-1].day,temp[i-1].hour,temp[i-1].minute,temp[i].day,temp[i].hour,temp[i].minute,temp[i].time - temp[i-1].time,t);
            total+=t;
        }
        printf("Total amount: $%.2f\n",total);
    }
    return 0;
}
