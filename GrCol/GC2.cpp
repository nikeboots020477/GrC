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

int main(){
     int i,j, k;  



ifstream data("gc_100_5");
    int N,E; 
    data>>N>>E;

    int** mm = new int *[E]; 
    for (int i=0; i < E; i++)
        mm[i] = new int [2];

    bool ** gr = new bool *[N]; 
    for (int i=0; i < N; i++)
        gr[i] = new bool [N];

    for(int i = 0; i<E;i++){
        data>>mm[i][0]>>mm[i][1];
        
    }
    for(i=0; i<N; i++){
        for(j=0; j<N; j++)
            gr[i][j] = 0;
        gr[i][i]=1;
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