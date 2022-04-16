#include <iostream>
#include <fstream>

using namespace std;

class shopping
{
    private:
        int pcode;
        float price;
        float discount;
        string pname;
    public:
        void menu();
        void admin();
        void buyer();
        void add();
        void edit();
        void rem();
        void list();
        void receipt();
};
void shopping :: menu(){
m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t___________________________________\n";
    cout<<"\t\t\t\t                                   \n";
    cout<<"\t\t\t\t       SuperMarket Main Menu       \n";
    cout<<"\t\t\t\t                                   \n";
    cout<<"\t\t\t\t___________________________________\n";

    cout<<"\t\t\t\t   1) Adminstrator    |\n";
    cout<<"\t\t\t\t                      |\n";
    cout<<"\t\t\t\t   2) Buyer           |\n";
    cout<<"\t\t\t\t                      |\n";
    cout<<"\t\t\t\t   3) Exit            |\n";
   
   cout<<"\n\t\t\t\t  Please Select The Options : ";
   cin>>choice;

   switch(choice){
       case 1:
            cout<<"\t\t\t  Please Login :   \n";   
            cout<<"\n\t\t\t  Enter Email  :   \n";
            cin>>email;         
            cout<<"\n\t\t\t  Enter password  : \n";
            cin>>password;

            if(email == "anmolaman@8853gmail.com"  &&  password == "Info.anmol@123"){
                admin();
            }else{
                cout<<"\nInvalid Email or Password";
            }

            break;

       case 2:
            buyer();
            break;
       case 3:
            exit(0);
       default:
            cout<<"\nPlease Select from the given options";
   }
goto m;

} 


void shopping ::admin(){
m:
    int choice;
    cout<<"\n\n\n\t\t\t Administrtor option";
    cout<<"\n\t\t\t|_________1) Add  the  Product__________|";
    cout<<"\n\t\t\t|                                       |";
    cout<<"\n\t\t\t|________ 2) Modify the Product_________|";
    cout<<"\n\t\t\t|                                       |";
    cout<<"\n\t\t\t|________ 3) Delete the Product_________|";
    cout<<"\n\t\t\t|                                       |";
    cout<<"\n\t\t\t|________ 4) Back to Main Menu _________|";

    cout<<"\n\n\t Please Select a Option : ";
    cin>>choice;

    switch(choice){
        case 1:
            add();
            break;            
        case 2:
            edit();
            break;
        case 3:
            rem();
            break;
        case 4:
            menu();
            break;
        default :
            cout<<"\nInvalid Choice";
    }
    goto m;
}



void shopping :: buyer(){
m:
    int choice;
    cout<<"\n\t\t\t   Buyer  \n";
    cout<<"\t\t\t________________ \n";
    cout<<"                       \n";
    cout<<"\t\t\t 1) Buy Product  \n";
    cout<<"                       \n";
    cout<<"\t\t\t 2) Go Back      \n";
    cout<<"\n\nEnter your Choice : ";
    cin>>choice;

    switch(choice){
        case 1:
            receipt();
            break;
        case 2:
            menu();
            break;
        default:
            cout<<"\nInvalid Choice";
    }
    goto m;
}

void shopping :: add(){
m:

    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t\t Add new Product";
    cout<<"\n\n\tProduct code of the product ";
    cin>>pcode;
    cout<<"\n\n\tName of the product ";
    cin>>pname;
    cout<<"\n\n\tPrice of the product ";
    cin>>price;
    cout<<"\n\n\tDiscount on product ";
    cin>>discount;

    data.open("database.txt",ios::in);

    if(!data){
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
        data.close();
    }else{
        data>>c>>n>>p>>d;
        while(!data.eof()){
            if(c == pcode){
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();

        if(token==1)
            goto m;
        else{
            data.open("database.txt",ios::app|ios::out);
            data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
            data.close();            
        }
    }
    cout<<"\n\n\t\tRecord Inserted : ";

    
}



void shopping :: edit(){
    fstream data,data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Modify the record";
    cout<<"\n\t\t\t Product code :";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data){
        cout<<"File doesn't exist! ";
    }else{
        data1.open("database1.txt",ios::app|ios::out);

        data>>pcode>>pname>>price>>discount;

        while(!data.eof()){
            if(pkey == pcode){
                cout<<"\n\t\t Product new Code : ";
                cin>>c;
                cout<<"\n\t\t Name of the Product :";
                cin>>n;
                cout<<"\n\t\t Price :";
                cin>>p;
                cout<<"\n\t\t Discount : ";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\tRecord Edited ";
                token++;
            }else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
            }
            data>>pcode>>pname>>price>>discount;
        }

    }


    data.close();
    data1.close();

    remove("database.txt");
    rename("database1.txt","database.txt");


    if(token==0){
        cout<<"Record Not Found Sorry!";
    }
}



void shopping :: rem(){
    fstream data,data1;
    int pkey;
    int token = 0;
    cout<<"\n\n\t Delete Product";
    cout<<"\n\n\t Product Code ";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\nFile Doesn't Exist";
    }else{
        data.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>discount;
        while(!data.eof()){
            if(pcode == pkey){
                cout<<"\n\n\t Product deleted Successfully";
                token++;
            }else{
                data1<<" "<<pcode<<" "<<pname<<" "<<" "<<price<<" "<<discount<<"\n";
            }
            data1>>pcode>>pname>>price>>discount;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");


        if(token==0){
            cout<<"\n\nRecord Not Found";
        }
    }
}


void shopping :: list(){
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|__________________________________________________________________________\n";
    cout<<"ProNo\t\tName\t\tPrice\n";
    cout<<"\n\n|__________________________________________________________________________\n";
    data>>pcode>>pname>>price>>discount;
    while(!data.eof()){
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>discount;
    }
    data.close();
}



void shopping :: receipt(){
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout<<"\n\n\t\t\t\t RECEIPT ";
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\nEmpty database";
    }else{
        data.close();
        list();
        cout<<"\n___________________________________________________________\n";
        cout<<"\n|                                                          \n";
        cout<<"\n                please place the order                     \n";
        cout<<"\n|                                                          \n";
        cout<<"\n___________________________________________________________\n";

        do
        {
            m:
                cout<<"\n\nEnter the product code : ";
                cin>>arrc[c];
                cout<<"\nEnter the Product quantity :";
                cin>>arrq[c];
                for(int i=0;i<c;i++){
                    if(arrc[c]==arrc[i]){
                        cout<<"\n\nDuplicate Product Code.Please try Again: ";
                        goto m;
                    }
                }
                c++;
                cout<<"\n\nDo you want to buy another Product? if Yes the press y otherwise press n : ";
                cin>>choice;

        }while(choice == 'y');

        cout<<"\n\n\t\t\t_______________________________RECEIPT__________________________________________\n";
        cout<<"\nProduct No\t Product Name\t Product quantity\t Price\t Amount \t Amount with Discount\n";

        for(int i=0;i<c;i++){
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>discount;
            while(!data.eof()){
                if(pcode == arrc[i]){
                        amount = price*arrq[i];
                        discount = amount - (amount * discount / 100);
                        total = total + discount;
                        cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<discount;
                }
                data>>pcode>>pname>>price>>discount;
            }
        }


        data.close();
    }


    cout<<"\n\n___________________________________________________________";
    cout<<"Total Amount is : "<<total;

}



int main(){
    shopping s;
    s.menu();
}