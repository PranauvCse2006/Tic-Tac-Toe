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
    cout << "     TIC TAC TOE "<<endl;
    cout << "=======================\n\n";
    for(int i=0;i<3;i++){
        cout<<"  ";
        for(int j=0;j<3;j++){
            cout<<board[i][j];
            if(j<2)
            {
                cout<<"  |  ";
            }
        }
        cout<<endl;

        if(i<2)
        {
            cout<<"-----|-----|----"<<endl;
        }
    }
    cout<<endl;
}
bool checkWin(){
    for(int i=0;i<3;i++)
    {
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]){
            return true;
    
        }
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i]){
            return true;

        }
    }
        if(board[0][0]==board[1][1] && board[1][1]==board[2][2]){
            return true;
        }
        if(board[0][2]==board[1][1] && board[1][1]==board[2][0]){
            return true;
        }
        
    
     return false;
}
bool isValidMove(int choice)
{
    if(choice == 1 && board[0][0] == '1')
        return true;

    else if(choice == 2 && board[0][1] == '2')
        return true;

    else if(choice == 3 && board[0][2] == '3')
        return true;

    else if(choice == 4 && board[1][0] == '4')
        return true;

    else if(choice == 5 && board[1][1] == '5')
        return true;

    else if(choice == 6 && board[1][2] == '6')
        return true;

    else if(choice == 7 && board[2][0] == '7')
        return true;

    else if(choice == 8 && board[2][1] == '8')
        return true;

    else if(choice == 9 && board[2][2] == '9')
        return true;

    return false;
}

void resetBoard()
{
    char value = '1';
    for(int i = 0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            board[i][j] = value;
            value++;
        }
    }
}

int main()
{
    int choice;
    int moves=0;
    char player='X';
    char playAgain;

    do
    {
        resetBoard();

        moves = 0;
        player = 'X';
    
    displayBoard();
    
    while(true)
    {
        cout<< "Player " << player << ", enter a number: ";
        cin >> choice;
        if(!isValidMove(choice))
        {
            cout << "Invaild move! Try again."<<endl;
            continue;
        }

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

          moves++;

        displayBoard();

        if(checkWin())
        {
            cout<< "Player "<< player <<" WINS!"<<endl;
            break;
        }
        
        if(moves==9)
        {
            cout<< "It's a draw"<<endl;
            break;
        }
        if(player=='X')
           player='O';
        else
           player='X';
    }
        cout<<"Play again? (y/n): ";
        cin>>playAgain;
 } while(playAgain == 'y' || playAgain == 'Y');
    return 0;
}