#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include <termios.h>
#include <stdio.h>

using namespace std;
int const l=6; // kol strok

int getch(){ //чтобы гетч работал
        int ch;
        struct termios oldt, newt;
        tcgetattr( STDIN_FILENO, &oldt );
        newt = oldt;
        newt.c_lflag &= ~( ICANON | ECHO );
        tcsetattr( STDIN_FILENO, TCSANOW, &newt );
        ch = getchar();
        tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
        return ch;
}

class Menu{ // класс для меню
    private:
    string menu[l]; // то, что выводим
    string menuelements[l]; //то, что считываем
    int kol;
    public:
    Menu() {kol=0;};
        void Add(string Str){ //добавление элемента в список
            menuelements[kol]=Str;
            kol++;
            for(int i=0;i<kol;i++){
            menu[i]="   "+menuelements[i]; //пробелы
            }
        }
        void Print(){ //вывод меню на экран
           cout<< endl;
        for(int i=0;i<kol;i++){
            for (int j=0;abs(j)< menu[i].size();j++){ //kak dvumernyi
            cout<<menu[i][j];
            }
      cout<< endl;
            }
        }
        void Push(int item){//таргет
            menu[item]=" * "+menuelements[item]+" * "; //печать * выбранного элемента
            int i=0;
            while (i<kol){
            if (i!=item){
                menu[i]="   "+menuelements[i]; //остальным печатаем пробелы

                }
                i++;
            }
        }
        int Sum(){
        return kol;
        }
};
struct Node{
Node *next;
string data;
Node *prev;//ïðåäûäóùèé
};
class Link{
Node *first;
Node *last;
int Count;
public:
Link():first(NULL),last(NULL){}
int GetCount() {
return Count; }

void Add(string n){
    Count++;
Node *current = first;
Node *newlink = new Node;

//while(Count<3) {
if (first==NULL){//åñëè ïåðâûé äîáàâëÿåì
first=newlink;
last=newlink;
newlink->next=first;
newlink->prev=first;
newlink->data=n;
}else{
while (current->next!=first) {//èäåì äî ïîñëåäíåãî
current=current->next;
}
current->next=newlink;//ïîñëåäíèé òåïåðü óêàçûâàåò íà íîâûé
first->prev=newlink;
last=newlink;
newlink->next=first;
newlink->prev=current;
newlink->data=n;
}
}
//if()
//}


void Showfromfirst(){
Node *current = first;
do {
cout<<current->data<<endl;
current=current->next;
} while (current!=first);
}
void Showfromlast(){
Node *current = last;
do {
cout<<current->data<<endl;
current=current->prev;
} while (current!=last);
}
};
bool exit(){//функция выхода
cout<<"****** press 'y' to exit ******";
cout<<endl;
char sure;
sure=getch();
if (sure== 'y'){
return 1;
}
else {
system("clear");
return 0;
}
}
 /*bool back() {
cout<<"****** press 'y' to  back to main menu ******";
cout<<endl;
char sur;
sur=getch();
 if ( sur == 'y') {
 return 1;
 }
 else {
 system("clear");
 return 0;
 }
 } */

int main() {
    //cout<<getch();
    string s;
    Link List;
    Link *tes=new Link;
Menu *MainMenu= new Menu; //списочек
	MainMenu->Add("Work with Files");
    MainMenu->Add("Show");
    MainMenu->Add("Add");
    MainMenu->Add("Edit");
    MainMenu->Add("Delete");
    MainMenu->Add("Exit");

    Menu *FileMenu= new Menu;
    FileMenu->Add("Open fail");
    FileMenu->Add("save change");
    FileMenu->Add("back to main menu");

    Menu *AddMenu= new Menu;
    AddMenu->Add("add in top");
    AddMenu->Add("add in center");
    AddMenu->Add("add after item");
    AddMenu->Add("back to main menu");

    Menu *DeleteMenu= new Menu;
    DeleteMenu->Add("delete first item");
    DeleteMenu->Add("delete item for number");
    DeleteMenu->Add("back to main menu");

    Menu *EditMenu= new Menu;
    EditMenu->Add("change name item");
    EditMenu->Add("change plases");
    EditMenu->Add("back to main menu");

	int selected_item = 0;
	int selected_item_f = 0;
	int selected_item_a = 0;
	int selected_item_d = 0;
	int selected_item_e = 0;
	int selected_item_q = 0;
    MainMenu->Push(selected_item);
	MainMenu->Print();
	while (true){
    switch (getch()) {
	case 65://вверх
            system("clear");
            selected_item--;
            if(selected_item<0){
                selected_item=MainMenu->Sum()-1;
            }
           MainMenu->Push(selected_item);
            MainMenu->Print();
			break;
		case 66://вниз
			system("clear");
			selected_item++;
		if (selected_item>MainMenu->Sum()-1){
		selected_item=0;
		}
		 MainMenu->Push(selected_item);
            MainMenu->Print();
break;
    case 27://esc, выход из программы
            system("clear");
  if (exit()==1)
            {
                exit(0);
            }
            else
            {
                system("clear");
                MainMenu->Print();
            }
            break;
case 49: // 1
selected_item=0;
system("clear");
 MainMenu->Push(selected_item);
            MainMenu->Print();
break;
case 50: // 2
selected_item=1;
system("clear");
MainMenu->Push(selected_item);
MainMenu->Print();
break;
case 51:// 3
selected_item=2;
system("clear");
MainMenu->Push(selected_item);
MainMenu->Print();
break;
case 52:// 4
selected_item=3;
system("clear");
MainMenu->Push(selected_item);
MainMenu->Print();
break;

case 53:// 5
selected_item=4;
system("clear");
MainMenu->Push(selected_item);
MainMenu->Print();
break;

case 48:// 0
selected_item=5;
system("clear");
MainMenu->Push(selected_item);
MainMenu->Print();
break;
case 10: //энтер
                        switch (selected_item){ //заходим в подменю в зависимости от позиции
            case 0://вход в работу с файлами
            system("clear");
            cout<<"****this is work with files****";
            cout<<endl;
            FileMenu->Push(selected_item_f);
            FileMenu->Print();
            int a;
                  do  {
                    a=getch();
                    switch (a) {
                    case 65://вверх
                        system("clear");
                        cout<<"****this is work with files****";
                        cout<<endl;
                        selected_item_f--;
                        if(selected_item_f<0){
                            selected_item_f=FileMenu->Sum()-1;
                        }

                        FileMenu->Push(selected_item_f);
                        FileMenu->Print();

                    break;
                    case 66://вниз
                        system("clear");
                        cout<<"****this is work with files****";
                        cout<<endl;
                        selected_item_f++;
                        if(selected_item_f>FileMenu->Sum()-1){
                            selected_item_f=0;
                        }

                        FileMenu->Push(selected_item_f);
                        FileMenu->Print();
                    break;

break;
case 48:// 0
selected_item_f=2;
system("clear");
cout<<"****this is work with files****";
                        cout<<endl;
FileMenu->Push(selected_item_f);
FileMenu->Print();
break;

case 49:// 1
selected_item_f=0;
system("clear");
cout<<"****this is work with files****";
                        cout<<endl;
FileMenu->Push(selected_item_f);
FileMenu->Print();
break;

case 50:// 2
selected_item_f=1;
system("clear");
cout<<"****this is work with files****";
                        cout<<endl;
FileMenu->Push(selected_item_f);
FileMenu->Print();
break;

                        case 10: //энтер в подменю файл

                        switch(selected_item_f){
                        case 2: //выход в главное меню
                        system("clear");
                        MainMenu->Print();
                        break; }

break;
                    }
                  }
                    while (a!=10 || selected_item_f!=2) ;
                    system("clear");
                    MainMenu->Print();

            break;
case 1: // подменю просмотра
system("clear");
cout<<"********* this is show *******";
cout<<endl;
cout<<endl;
if (tes->GetCount()!=0) {
cout<<endl;
tes->Showfromfirst();
cout<<endl<<endl;
}
else {
cout<<endl;
cout<<"0 items";
}

if (tes->GetCount()!=0) {
cout<<endl;
tes->Showfromlast();
cout<<endl<<endl;
}
else {
cout<<endl;
cout<<"0 items";
}
 break;
            //break;
            case 2://добавление
            system("clear");
            cout<<"*******this is add*******";
                        cout<<endl;
            AddMenu->Push(selected_item_a);
            AddMenu->Print();
                  do  {
                    a=getch();
                    switch (a) {
                    case 65://вверх
                        system("clear");
                        cout<<"*******this is add*******";
                        cout<<endl;
                        selected_item_a--;
                        if(selected_item_a<0){
                            selected_item_a=AddMenu->Sum()-1;
                        }

                        AddMenu->Push(selected_item_a);
                        AddMenu->Print();

                    break;
                    case 66://вниз
                        system("clear");
                        cout<<"*******this is add*******";
                        cout<<endl;
                        selected_item_a++;
                        if(selected_item_a>AddMenu->Sum()-1){
                            selected_item_a=0;
                        }

                        AddMenu->Push(selected_item_a);
                        AddMenu->Print();
                        break;

case 48:// 0
selected_item_a=3;
system("clear");
cout<<"*******this is add*******";
                        cout<<endl;
AddMenu->Push(selected_item_a);
AddMenu->Print();
break;

case 49:// 1
selected_item_a=0;
system("clear");
cout<<"*******this is add*******";
                        cout<<endl;
AddMenu->Push(selected_item_a);
AddMenu->Print();
break;

case 50:// 2
selected_item_a=1;
system("clear");
cout<<"*******this is add*******";
                        cout<<endl;
AddMenu->Push(selected_item_a);
AddMenu->Print();
break;
case 51:// 3
selected_item_a=2;
system("clear");
cout<<"*******this is add*******";
                        cout<<endl;
AddMenu->Push(selected_item_a);
AddMenu->Print();
break;
                        case 10: //энтер в подменю добавления
                        //Link *tes=new Link;
                        switch(selected_item_a){
                            case 1:
                            system("clear");

cin>>s;
cout<<endl;

tes->Add(s);
s='\0';
/*cout<<"success";
getchar(); */
cout<<endl<<endl;
getchar();
system("clear");
cout<<"*******this is add*******";
AddMenu->Print();

break;

 case 2:

            break;

break;
                        case 3: //выход в главное меню
                        system("clear");
                        MainMenu->Print();
                        break;
                        }
                        break;

                    }
                    }
                    while (a!=10 || selected_item_a!=3) ;
                    system("clear");
                    MainMenu->Print();


           break;

case 3://редактирование
            system("clear");
            cout<<"*******this is edit*******";
                        cout<<endl;
            EditMenu->Push(selected_item_e);
            EditMenu->Print();
                  do  {
                    a=getch();
                    switch (a) {
                    case 65://вверх
                        system("clear");
                        cout<<"*******this is edit*******";
                        cout<<endl;
                        selected_item_e--;
                        if(selected_item_e<0){
                            selected_item_e=EditMenu->Sum()-1;
                        }

                        EditMenu->Push(selected_item_e);
                        EditMenu->Print();

                    break;
                    case 66://вниз
                        system("clear");
                        cout<<"*******this is edit*******";
                        cout<<endl;
                        selected_item_e++;
                        if(selected_item_e>EditMenu->Sum()-1){
                            selected_item_e=0;
                        }

                        EditMenu->Push(selected_item_e);
                        EditMenu->Print();
                    break;
case 48:// 0
selected_item_e=2;
system("clear");
cout<<"*******this is edit*******";
                        cout<<endl;
EditMenu->Push(selected_item_e);
EditMenu->Print();
break;

case 49:// 1
selected_item_e=0;
system("clear");
cout<<"*******this is edit*******";
                        cout<<endl;
EditMenu->Push(selected_item_e);
EditMenu->Print();
break;

case 50:// 2
selected_item_e=1;
system("clear");
cout<<"*******this is edit*******";
                        cout<<endl;
EditMenu->Push(selected_item_e);
EditMenu->Print();
break;

                        case 10://энтер в редактировании
                        switch(selected_item_e){
                        case 2://выход в главное меню
                        system("clear");
                        MainMenu->Print();
                        break; }
break;



                    }
                  }
                    while (a!=10 || selected_item_e!=2);
                    system("clear");
                    MainMenu->Print();

            break;
       case 4://удаление
            system("clear");
            cout<<"******this is delete******";
                        cout<<endl;
            DeleteMenu->Push(selected_item_d);
            DeleteMenu->Print();
                  do    {
                    a=getch();
                  switch (a) {
                    case 65://вверх
                        system("clear");
                        cout<<"******this is delete******";
                        cout<<endl;
                        selected_item_d--;
                        if(selected_item_d<0){
                            selected_item_d=DeleteMenu->Sum()-1;
                        }

                        DeleteMenu->Push(selected_item_d);
                        DeleteMenu->Print();

                    break;
                    case 66://вниз
                        system("clear");
                         cout<<"******this is delete******";
                        cout<<endl;
                        selected_item_d++;
                        if(selected_item_d>DeleteMenu->Sum()-1){
                            selected_item_d=0;
                        }

                        DeleteMenu->Push(selected_item_d);
                        DeleteMenu->Print();
                    break;
case 48:// 0
selected_item_d=2;
system("clear");
cout<<"******this is delete******";
                        cout<<endl;
DeleteMenu->Push(selected_item_d);
DeleteMenu->Print();
break;

case 49:// 1
selected_item_d=0;
system("clear");
cout<<"******this is delete******";
                        cout<<endl;
DeleteMenu->Push(selected_item_d);
DeleteMenu->Print();
break;

case 50:// 2
selected_item_d=1;
system("clear");
cout<<"******this is delete******";
                        cout<<endl;
DeleteMenu->Push(selected_item_d);
DeleteMenu->Print();
break;
                        case 10://энтер для удаления
                        switch(selected_item_d){
                        case 2://выход в главное меню
                        system("clear");
                        MainMenu->Print();
                        break; }
break;
                }
                  }
                    while (a!=10 || selected_item_d!=2) ;
                    system("clear");
                    MainMenu->Print();

            break;

            case 5://вызов выхода
            system("clear");
  if (exit()==1)
            {
                exit(0);
            }
            else
            {
                system("clear");
                MainMenu->Print();
            }
            break;

}
}

}

}
