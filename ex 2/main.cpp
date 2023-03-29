#include "Names.h"

int Names :: totalSize =0;

int main() {
Names *arr;
int option,num,num2,num3,numOfteams;
char temp[20];

cout<<"enter number of teams:";
cin>>numOfteams;
arr=new Names[numOfteams];

 int flag=0;
 int flag2=0;
 while(flag!=1){
     if(flag2==0) {
         cout << endl;
         cout << " 1: to print all\t 2: to add\t 3: Remove\t 4: assign\t 5: is Equal\t 6: is contain" << endl
              << "7: is contained\t 8: intersecticon\t 9: belong\t 10: total size\t 11: quit" << endl;
         cout << "enter option:";
     }
      flag2=0;
      cin>>option;
      cout <<endl;
     switch (option) {

         case 1:
             for(int i=0; i<numOfteams; i++){
                cout<<endl<<"all names for team["<<i+1<<"]: "<<endl;
                cout<<arr[i];
            }
             break;

         case 2:

              correctNumber(&num, numOfteams);
               cout<<endl<<"enter name to add:";
               getchar();
               cin>>temp;
               arr[num-1]+=temp;
             break;

         case 3:
             correctNumber(&num, numOfteams);
             cout<<endl<<"enter name to remove:";
             getchar();
             cin>>temp;
             arr[num-1]-=temp;
             break;

         case 4:

             correctNumber(&num, &num2, numOfteams);
             arr[num-1]=arr[num2-1]; // operator =.
             break;

         case 5: //ok

             correctNumber(&num, &num2, numOfteams);
             if(arr[num-1]==arr[num2-1])
                 cout<<"the same names";
             else
                 cout<<"At least one different name exists";
               break;

         case 6:  // operator >=  ok

             correctNumber(&num, &num2, numOfteams);
             if(arr[num-1]>=arr[num2-1])
                 cout<<"The first group is contained in the second"<<endl;
             else
                 cout<<"The first group is not contained in the second"<<endl;
             break;

         case 7: // operator <=
             correctNumber(&num, &num2, numOfteams);
             if(arr[num-1]<=arr[num2-1])
                 cout<<"The first group is contained in the second"<<endl;
             else
                 cout<<"The first group is not contained in the second"<<endl;
             break;

         case 8:
             if(numOfteams<3){
                 cout<<"To use this function, you must have at least three groups"<<endl;
                 break;
             }
             else {
                 correctNumber(&num, &num2, &num3, numOfteams);
                 arr[num-1]=arr[num2-1]*arr[num3-1];

                 if (arr[num - 1].getSize() == 0) {
                     cout << "foreign groups" << endl;
                 } else cout << "success!!" << endl;
                 break;
             }
         case 9:
             cout<<"enter name to search:";
             cin>>temp;
             cout<<"The teams where it appeared: ";
             isAppear(arr, temp, numOfteams);
             break;

         case 10:
             cout<<"the size of all team together is: "<<Names::allSizes(arr, numOfteams)<<endl;
             break;

         case 11:
             delete[] arr;
             flag=1;
             break;

         default:
           cout<<"invalid input try again:";
           flag2=1;
           break;
     }
 }

cout<<endl<<"Bye Bye"<<endl;

    return 0;
}
