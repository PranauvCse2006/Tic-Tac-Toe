#include<iostream>
using namespace std;

char board[3][3]=
{
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};
void displayBoard(){
    cout<<endl;
    for(int i=0;i<3;i++){
        cout<<" ";
        for(int j=0;j<3;j++){
            cout<<board[i][j];
            if(j<2)
            {
                cout<<" | ";
            }
        }
        cout<<endl;

        if(i<2)
        {
            cout<<"---|---|---"<<endl;
        }
    }
    cout<<endl;
}

int main()
{
    int choice;
    char player='X';
    displayBoard();
    while(true)
    {
        cout<< "Player " << player << ", enter a number: ";
        cin >> choice;

        if(choice==1)
          board[0][0]=player;
        else if(choice==2)
          board[0][1]=player;
        else if(choice==3)
          board[0][2]=player;
        else if(choice==4)
          board[1][0]=player;
        else if(choice==5)
          board[1][1]=player;
        else if(choice==6)
          board[1][2]=player;
        else if(choice==7)
          board[2][0]=player;
        else if(choice==8)
          board[2][1]=player;
        else if(choice==9)
          board[2][2]=player;

        displayBoard();
        if(player=='X')
           player='O';
        else
           player='X';
    }
    return 0;
}