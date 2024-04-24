#include<iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Array_Based_List {
public:
    int array_size;
    int Element_In_Array;
    int *next_ptr;
    int *new_array;
    vector <int> myvector;
    static int counter;
    static int Mantain_Back_Value;
    

    // Constructor...
    Array_Based_List() {
        cout << "Enter Array Size: ";
        cin >> array_size;
        new_array = new int[array_size];
        cout << "\t\t How Many Elements You want To Insert in Array: ";
        cin >> Element_In_Array;

        // To Check if User Mistakenly/Intentionally Enter the  Elemen_In_Array > array_size;
        if(Element_In_Array > array_size){
            cout<<"Please Enter The Valid No Of Element in Array...";
            return;
        }
        cout << "Please Enter Values To Fill The Array:  \n";
        for (int i = 0; i < Element_In_Array; i++) {
            cin >> *(new_array + i);
        }
        next_ptr = new_array; // Assign the address of the first element to next_ptr
    }

    

    // return Number of Elements in Array Not the total size of the array....
    int get() {
        return Element_In_Array;
    }

    // Orignal Length of the Array...
    int Array_Size() {
        return array_size;
    }

    // This function Always point to the Start of the Array...
    int Start() {
        return *(new_array);
    }

    // This function Always point to the End of the Array...
    int End() {
        if (Element_In_Array > 0) {
            return *(new_array + Element_In_Array - 1);
        }
        return -1; // Return some invalid value indicating no elements if Element_In_Array is 0
    }

    int Next(){
        // initially it will Pointing to The Start of the Array.
        
        // -- If no Element in Array....
        if(Element_In_Array <= 0){
            cout<<"Array is Empty...."<<endl;
            return -1;          // Some invalid value.....
        }
        else{
            int temp_Variable = *(new_array + counter);
            counter += 1;
         // If User Reached to the end of the Array-List.
            if(counter > Element_In_Array){
                cout<< "You Are Already At Lasy index..";
                return -1 ;
            }
            return temp_Variable; 
        }

    }


    /*
        --  The update Function will Take two Parameters the postion and insert Value, the user Should enter The Position and the Insert_Value to Insert The Value at the Mention Position, but the Postion Should not be Greater then the ELement_In_Array.
    */

    void Update(int Position,int insert_value){
        if(Position > Element_In_Array){
            cout<<"Plz Enter a Valid Position.."<<endl;
            return;
        }
        else{
            *(new_array + Position) =insert_value;
            cout<<"The Value At Mention Position is: "<< *(new_array + Position)<<endl;
            Print_Array_List();

        }
    }
// To print the whole Array without-Indexing.....
    void Print_Array_List(){
        cout<<"The Array_List Is: ";
        for(int i =0 ; i< Element_In_Array; i++){
            cout<<*(new_array + i)<<" ";
        }
        
    }

// call this Again and again in the Main to see the Result....
    void Back(){
        if(Element_In_Array <= 0){
            cout<<"No Elemnt in Array, Therefore we Can't Back.."<<endl;
            return; 
        }
        else{
            Mantain_Back_Value = Element_In_Array -1;
            cout<<"When the Back Function Call: "<<*(new_array + Mantain_Back_Value) <<endl;
            Element_In_Array -= 1;

        }
    }
void print_vector(){
    cout<<"The Updated Array-based-List Is: ";
    for(auto j= myvector.begin() ; j!= myvector.end(); j++){
            cout<< *j<<" ";
        }
}

void Remove(int Delete_Position){
    
    if(Delete_Position >=Element_In_Array || Element_In_Array == 0 ){
        cout<<"You May Enter Wrong Position, or the Array is Empty Kindly Cross-check it..."<<endl;
        return;
    }
    else{
        for(int i =0 ; i< Element_In_Array ;i++){
            myvector.push_back( *(new_array+ i));
        }
        myvector.erase( myvector.begin() + Delete_Position);
        print_vector();
        cout<<"\n";
    }
}

void Add_Element(int Add_Value_Position , int Add_New_value){
     for(int iter =0 ; iter< Element_In_Array ;iter++){
            myvector.push_back( *(new_array+ iter));
        }
    if(Add_Value_Position  >= Element_In_Array){
            cout<<"Plz Enter a Valid Position.."<<endl;
            return;
        }
        else{
             myvector.insert(myvector.begin() + Add_Value_Position ,Add_New_value);
            print_vector();
        }
   
}


// Destructor to free the Dynamically Alocated Space and as well as Pointers...
    ~Array_Based_List() {
        next_ptr =NULL;
        delete next_ptr;
        delete[] new_array;
    }


};
int Array_Based_List :: counter = 0;
int Array_Based_List::Mantain_Back_Value =100;


int main() {
    // ADT ---->> Array Data-Structure....
    Array_Based_List ADT;
    cout<<"\t\t |--------------------------------------------------------|"<<endl;
    cout<<"\t\t\t\tSelect  Operation From the Given Menu..."<<endl;
    cout<<"\t\t |--------------------------------------------------------|"<<endl;
    cout<<"\t\t\t --        Type get for Get-Operation"<<endl;
    cout<<"\t\t\t --        Type arraysize for Array-Size-Operation"<<endl;
    cout<<"\t\t\t --        Type start for Start-Operation"<<endl;
    cout<<"\t\t\t --        Type end for End-Operation"<<endl;
    cout<<"\t\t\t --        Type next for Next-Operation"<<endl;
    cout<<"\t\t\t --        Type update for Update-Operation"<<endl;
    cout<<"\t\t\t --        Type remove for Remove-Operation"<<endl;
    cout<<"\t\t\t --        Type add for Add-Element-Operation"<<endl;
    cout<<"-------------------------------------------------------------------------------------------------"<<endl;
    string Operation_Name;
   
        cout << "Type Your Operation-Name: ";
        cin >> Operation_Name;

        if (Operation_Name == "arraysize") {
            cout << "The Original Size Of The Array Is: " << ADT.Array_Size() << endl;
            ADT.Print_Array_List();
            cout<<endl;
        } else if (Operation_Name == "get") {
            cout << "The Elements in Array-List Are: " << ADT.get() << endl;
            ADT.Print_Array_List();
            cout<<endl;
        } else if (Operation_Name == "start") {
            cout << "The Start of The Array Is: " << ADT.Start() << endl;
            ADT.Print_Array_List();
            cout<<endl;
        } else if (Operation_Name == "end") {
            cout << "The End of The Array Is: " << ADT.End() << endl;
            ADT.Print_Array_List();
            cout<<endl;
        } else if (Operation_Name == "next") {
            cout << "The Next function Call: " << ADT.Next() << endl;
            ADT.Print_Array_List();
            cout<<endl;
        } else if (Operation_Name == "update") {
            ADT.Update(4 , 4);
            ADT.Print_Array_List();
            cout<<endl;
        } else if (Operation_Name == "remove") {
            ADT.Remove(1);
        } else if (Operation_Name == "add") {
            ADT.Add_Element(5, 1115);
        } else {
            cout << "Invalid operation name." << endl;
        }
        

    return 0;
}
