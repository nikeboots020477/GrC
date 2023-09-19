#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <math.h>
using namespace std;

struct el
{int dd;
int ind;
};


int main(){
     int i,j, k;  



ifstream data("gc_500_9");
    int N,E; 
    data>>N>>E;

    int** mm = new int *[E]; 
    for (int i=0; i < E; i++)
        mm[i] = new int [2];
    
    struct el sort[N];

    for(i=0;i<N;i++) {sort[i].dd=0; sort[i].ind=i;}

    bool ** gr = new bool *[N]; 
    for (int i=0; i < N; i++)
        gr[i] = new bool [N];

    for(int i = 0; i<E;i++){
        data>>mm[i][0]>>mm[i][1];
        sort[mm[i][0]].dd= sort[mm[i][0]].dd+1;
        sort[mm[i][1]].dd= sort[mm[i][1]].dd+1;
    }
     
struct el temp;
for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (sort[j].dd < sort[j + 1].dd) {
                temp = sort[j];
                sort[j]= sort[j + 1];
                sort[j + 1] = temp;
            }
        }
    }

for(i=0; i<N; i++){
        for(j=0; j<N; j++)
            gr[i][j] = 0;
        gr[i][i]=1;
    }
int temp2[E][2];
for(i=0;i<E;i++)  {mm[i][0]= sort[mm[i][0]].ind;
mm[i][1]= sort[mm[i][1]].ind;
}

for(i=0; i<E; i++){
        gr[mm[i][0]][mm[i][1]]=true;
        gr[mm[i][1]][mm[i][0]]=true;
    }


data.close();

    int cl[N];
    for(i=0; i<N; i++) cl[i]=0;


    k=1;
    for(i=0;i<N;i++) {
        if(cl[i]) continue;
        cl[i] = k;
        bool flag = 0;
        if(i!=N-1) {
			for (j=i+1; j<N; j++) {
			if (!gr[i][j] && !cl[j]) {
			flag = 1;
			break;
			}
		}
		}
		else { k++; break; }

        while(flag){
            for(j=i+1;j<N-1;j++){
                if(!gr[i][j] && !cl[j])
                    break;
            }
            if(j==N)
                break;
            cl[j]=k;
            for(int q=0; q<N; q++)
                if (gr[i][q]+gr[j][q]!=0) gr[i][q]=1;
            flag = 0;
			for (j=i+1; j<N; j++) {
				if (!gr[i][j] && !cl[j]) {
					flag = 1;
					break;
				}
			}
        }
        k++;
    }    

    cout<<k-1;
    

   

return 0;



}
