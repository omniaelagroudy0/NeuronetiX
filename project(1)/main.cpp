#include<iostream>
#include<string.h>

using namespace std;


// Global variables for pet's name, hunger, and happiness

string petName;
int hunger=50;
int happiness=50;
bool petAdopted=false; //to check about exist pet

void adoptPet();  //function to intialize a pet
bool feedPet();   //function to feed a pet(increase a level hunger)
bool playedPet(); //function to play with a pet (increase a happiness)
void status();    //function to display the current status of the pet
void endgame();   //function to end the game and display the final result



int main()
{
    int option;
    do
    {
        cout<<"1. Adopt Pet"<<endl;
        cout<<"2. Feed Pet"<<endl;
        cout<<"3. Play with Pet"<<endl;
        cout<<"4. Check Status"<<endl;
        cout<<"5. End Game"<<endl;
        cout<<"Choose an option:";
        cin>>option;


        switch (option)
        {
        case 1:
            adoptPet(); //function to initialize pet
            break;
        case 2:
             //function to feed pet
            if(feedPet()==0)
            {

                return 0;
            }
            break;
        case 3:
            //function to increase the level of happiness
            if(playedPet()==0)
            {
            return 0;
            }
            break;
        case 4:
            status();//function to display the level of happiness and hunger
            break;
        case 5:
            endgame();
            break;
        default:
            cout << "Invalid choice. Please choose a number between 1 and 5.\n\n";

        };

    }while(option!=5);


    return 0;
}

void adoptPet()
{
    cout<<"Enter the name of your pet\n";
    cin>>petName;
    hunger = 50;
    happiness = 50;
    petAdopted = true;
    cout<<"Now you have a pet:"<<petName<<"\n\n";

}

bool feedPet()
{
    if( petAdopted == true )
    {
        if(hunger < 90)
        {

            hunger += 10;
            happiness -= 10;

            if(happiness == 0)
            {
                cout<<"Game Over. Your pet's condition has reached a critical level\n";
                cout<<petName<<"'s hunger : "<<hunger<<"\n";
                cout<<petName<<"'s happiness : "<<happiness<<"\n\n";
                return 0;
            }

            cout << "pet has been fed\n\n";
            return 1;

        }
        else if(hunger >= 90)
        {
            hunger -= 10;
            happiness -= 10;

            if(happiness == 0)
            {
                cout<<"Game Over. Your pet's condition has reached a critical level\n";
                cout<<petName<<"'s hunger : "<<hunger<<"\n";
                cout<<petName<<"'s happiness : "<<happiness<<"\n\n";
                return 0;
            }
            cout << "pet has been fed\n\n";
            return 1;

        }

    }
    else
    {
        cout<<"you don't have a pet to feed \n\n";
        return 1;
    }


}

bool playedPet()
{
    if( petAdopted == true )
    {
        if(happiness < 90)
        {

            happiness += 10;
            hunger -= 10;

            if(hunger == 0)
            {
                cout<<"Game Over. Your pet's condition has reached a critical level\n";
                cout<<petName<<"'s hunger : "<<hunger<<"\n";
                cout<<petName<<"'s happiness : "<<happiness<<"\n\n";
                return 0;
            }


            cout << "Pet played and is happier now\n\n";
            return 1;

        }
        else if(happiness >= 90)
        {
            hunger -= 10;
            happiness -= 10;

            if(hunger == 0)
            {
                cout<<"Game Over. Your pet's condition has reached a critical level\n";
                cout<<petName<<"'s hunger : "<<hunger<<"\n";
                cout<<petName<<"'s happiness : "<<happiness<<"\n\n";
                return 0;
            }

            cout<<petName<<"'s too happy"<<"and no further increase is allowed"<<"\n\n";
            return 1;

        }

    }

    else
    {
        cout<<"you don't have a pet to play with \n\n";
        return 1;
    }
}
void status()
{
    if( petAdopted == true )
    {
        cout<<petName<<"'s hunger : "<<hunger<<"\n";
        cout<<petName<<"'s happiness : "<<happiness<<"\n\n";
    }
    else
    {
        cout<<"you don't have a pet \n\n";
    }
}
void endgame()
{

    if( petAdopted == true )
    {

        cout<<"Final status of "<<petName<<"\n"<<"hunger : "<<hunger<<"\n"<<"happiness : "<<happiness<<"\n";
    }
    else
    {
        cout<<"you don't have a pet \n";
    }
}

