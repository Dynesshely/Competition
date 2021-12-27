#include <bits/stdc++.h>
using namespace std;
struct ticket {
    int time;
    int price;
};
int main(){
    int n;
    unsigned long long count = 0;
    list<ticket> tickets;
    cin>>n;
    for (int i = 0; i < n; i++) {
        int type;int price;int time;
        cin>>type>>price>>time;
        if(type==0){
            count+=price;
            ticket tick;
            tick.price=price;
            tick.time=time;
            tickets.push_back(tick);
        }else if(type == 1){
            bool sign=false;
            list<ticket>::iterator it;
            for(it = tickets.begin(); it != tickets.end();){
                if(time - it->time <= 45){
                    if(it->price >= price){
                        tickets.erase(it++);
                        sign = true;
                        break;
                    }else{
                        it++;
                    }
                }else{
                    tickets.erase(it++);
                }
            }
            if(!sign){
                count+=price;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}

//#include <bits/stdc++.h>
//using namespace std;
//
//class ticket
//{
//	public:
//		int time;
//		int price;
//		bool used;
//};
//
//int main()
//{
//	int ls;
//	cin>>ls;
//	int records[ls][3];
//	for(int i=0;i<ls;i++){
//		for(int j=0;j<3;j++){
//			cin>>records[i][j];
//		}
//	}
//	//开始吟唱
//	//0 10 3 - 0地铁1公交车，票价，乘车时间 
//	long long sum=0;
//	int index=0;
//	ticket tickets[100010];
//	for(int i=0;i<ls;i++){
//		if(records[i][0]==0){
//			//加票 
//			ticket ti;
//			ti.time=records[i][2];
//			ti.price=records[i][1];
//			ti.used=false;
//			tickets[index]=ti;
//			index++; 
//			//加钱 
//			sum+=records[i][1];
//		}else{
//			bool canFree = false;//是否可以免费 
//			for(int j=0;j<index;j++){
//				ticket ti=tickets[j];
//				if(records[i][2]-ti.time<=45 && records[i][1]<=ti.price && !ti.used){
//					canFree=true;
//					ti.used=true;
//					break;
//				}
//			}
//			if(!canFree){
//				sum+=records[i][1];
//			}
//		}
//	}
//	cout<<sum;
//	return 0;
//}
