#include <iostream>
#include <conio.h>
using namespace std;
#include <stdlib.h>
#include<time.h>
#include<string.h>
#include <algorithm>
#include <chrono>
#include <random>
#include <vector>
#include <fstream>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
int special,special1;
vector<int> numbers;
int val=0;




class operations
{   
    
 
    public:
        void up(int mat[4][4])
        {   int i=special;
            int j=special1;
            int curr=mat[i][j];
            int rep=mat[i-1][j];
             if(i>0){
            if((i>0 && i< 4)&&(j>=0 and j<4)){
                mat[i][j]=rep;
                mat[i-1][j]=curr;
                special=i-1;
                special1=j;
            }
        }
            
        }
        void down(int mat[4][4])
        {
            int i=special;
            int j=special1;
            int curr=mat[i][j];
            int rep=mat[i+1][j];
            
             if(i<3){
            if((i>=0 && i< 4)&&(j>=0 and j<=3)){
                
                mat[i][j]=rep;
                mat[i+1][j]=curr;
                special=i+1;
                special1=j;
            }
        }
        }
        void left(int mat[4][4])
        {
          int i=special;
            int j=special1;
            int curr=mat[i][j];
            int rep=mat[i][j-1];
            
             if(j>0){
            if((i>=0 && i< 4)&&(j>0 and j<=3)){
                
                mat[i][j]=rep;
                mat[i][j-1]=curr;
                special=i;
                special1=j-1;
            }
        }   
        }
        void right(int mat[4][4])
        {
            int i=special;
            int j=special1;
            int curr=mat[i][j];
            int rep=mat[i][j+1];
            
             if(j<3){
            if((i>=0 && i< 4)&&(j>=0 and j<3)){
               
                mat[i][j]=rep;
                mat[i][j+1]=curr;
                special=i;
                special1=j+1;
            }
        }   
        }
        
};

int gen_rand(int mat[4][4],int i,int j){
    val++;
   int rand_generated=rand()%15+1;
   return numbers[val];
    
}




int main()

{  operations obj;
   int count=0;
   bool First= true,skip=false;
   char command = 'P';
   char op;
   srand(time(0));
   int mat[4][4];
   int upper=15;
   int lower=1;
   cout<<"\n\n\n\t\t\t\t\t\t\t\t\tHow to Play the Game?\n\t\t\t\t\t\t\t\t\t\tu-->UP\n\t\t\t\t\t\t\t\t\t\td-->Down\n\t\t\t\t\t\t\t\t\t\tl-->Left\n\t\t\t\t\t\t\t\t\t\tr-->Right\n";
    std::vector<int> numbers;
    
    for(int i=1; i<16; i++)       
        numbers.push_back(i);

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(seed));

 
   for(int i=0;i<4;i++){
       for(int j=0;j<4;j++){
           
           int number = numbers[val];
           mat[i][j]=number;
           val++;
       }
   }
    srand(time(0));
    special=(rand() % 4);
    special1=(rand()%4);
    int last=mat[special][special1];
    mat[special][special1]=1000;
    if (mat[3][3]==1000){
        mat[3][3]=1000;
    }
    else{
        mat[3][3]=last;
    }
   
    //Random Fill
   
   int crt_mat[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,1000};
   while(command !='s'){
       
    if(mat[3][3]==1000 && mat[0][0]==1 && mat[1][1]==5){
           break;
       }
    if(First){
        cout<<"This is your Matrix\n";
        First=false;
    } 
    if(skip==false){
    for(int i=0;i<4;i++){
         cout<<"\t\t\t";
       for(int j=0;j<4;j++){
           if(mat[i][j]==1000){
               cout<<"_"<<"\t";
           }
           else{
                cout<<mat[i][j]<<"\t";
              
           }
       }
       cout<<"\n";
   }
    cout<<"Enter Your option :\n";
    }
    op=getch();
  
    switch(op){
        
        case KEY_UP:   
                    obj.up(mat);
                    count++;
                    skip=false;
                    break;
        case KEY_LEFT:   
                    obj.left(mat);
                    count++;
                    skip=false;
                    break;
        case KEY_RIGHT:   
                    obj.right(mat);
                    count++;
                    skip=false;
                    break;
        case KEY_DOWN:   
                    obj.down(mat);
                    count++;
                    skip=false;
                    break;
        case 's':   
                    command='s';
                    break;
        default:
                    skip=true;
                    
                    break;
         
                    
    }}
    
cout<<"\nNo.of.Steps taken: "<<count<<" Game Over! Try Again";
char ans; 
char filename[10]; 
cout<<"\n Do You want to save your Game?(y/n)";
cin>>ans;
if(ans=='y'){
    cout<<"Enter a Name for Your File : ";
    cin>>filename;
    ofstream outfile;
    outfile.open(filename);
    for(int j=0 ; j<4 ; j++){
    
        for(int i=0;i<4;i++)
        outfile << mat[j][i]<<"\t";
        outfile<< std::endl;
}
}

   
    
}