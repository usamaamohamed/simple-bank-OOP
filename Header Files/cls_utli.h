#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <limits>
#include "clsDate.h"
using namespace std;


class cls_utli
{
public:
//generate random number

    static void Srand() //to generate randon number
    {
        srand((unsigned) time(NULL));
    } 

    static int RandomNumber(int From, int To) 
    { 
        //Function to generate a random number
        int randNum = rand() % (To - From + 1)+From ; 
        return randNum; 
    } 

//read valid number

    static int ReadNumber() 
    { 
        int Number;     
        cout << "Please enter a number?" << endl;     
        cin >> Number; 
        while (cin.fail())     
        { 
            // user didn't input a number    
            cin.clear();      
            cin.ignore( std::numeric_limits < std::streamsize > ::max(), '\n');          
            cout << "Invalid input data type ,Enter a valid number:" << endl;         
            cin >> Number;     
        } 
        return Number; 
    }

    static int Read_positive_Number(string message = "Please enter a positive number") 
    { 
        int Number;   
        cout << message << endl;     
        cin >> Number; 
        while (cin.fail())     
        { 
            // user didn't input a number    
            cin.clear();      
            cin.ignore( std::numeric_limits < std::streamsize > ::max(), '\n');          
            cout << "Invalid Number, Enter a positive one:" << endl;         
            cin >> Number;     
        } 
        while (Number <=0)
        {
            cout << "number must be bigger than 0 ,enter a positive number; ";
            cin >> Number;
        }
        return Number; 
    }

    static int Read_negative_Number() 
    { 
        int Number; 
        cout << "Please enter a negative number?" << endl;     
        cin >> Number; 
        while (cin.fail())     
        { 
            // user didn't input a number    
            cin.clear();      
            cin.ignore( std::numeric_limits < std::streamsize > ::max(), '\n');          
            cout << "Invalid Number, Enter a negative one:" << endl;         
            cin >> Number;     
        } 
        while (Number >=0)
        {
            cout << "number must be smaller than 0 ,enter a negative number; ";
            cin >> Number;
        }
        return Number; 
    }
////////////////////////////////////////////////////////////////////////////
//deal with strings
    static char invert_character_case(char &S1)
    {
        int ascii = 0;
        ascii = int (S1);
        if (ascii >= 97 && ascii <= 122)
        {
            S1 = toupper(S1);
            //S1 = char(S1 - 32);
        }
        else if (ascii >= 65 && ascii <= 90)
        {
            S1 = tolower(S1);
            //S1 = char(S1 + 32);
        }
        else cout << "not a character\n";
        return S1;
    }
    //-----------------------------------------------------//
    static char invert_case(char &S1)
    {
        return (  isupper(S1)?  tolower(S1) : toupper(S1) );
    }
    //-----------------------------------------------------//
    static string invert_all_character_cases(string &S1)
    {
        int ascii = 0;
        for (int i = 0 ; i < S1.length() ; i++)
        {
            ascii = int (S1[i]);
            if (ascii >= 97 && ascii <= 122)
            {
                S1[i] = toupper(S1[i]);
                //S1 = char(S1 - 32);
            }
            else if (ascii >= 65 && ascii <= 90)
            {
                S1[i] = tolower(S1[i]);
                //S1 = char(S1 + 32);
            }
        }
        return S1;
    }
    //-----------------------------------------------------//
    static string invert_all_cases(string &S1)
    {
        for (int i = 0; i < S1.length(); i++)
        {
            S1[i] = isupper(S1[i])? tolower(S1[i]) : toupper(S1[i]);
        }
    
        return S1;
    }   
    //-----------------------------------------------------//
    static void all_upper(string S1) 
    { 
        bool isFirstLetter = true;     
        cout << "\nall string upper: \n";
        for (short i = 0; i < S1.length(); i++)     
        { 
    
            S1[i] = toupper(S1[i]);       
            //S1[i] = char ( int(S1[i] - 32));         
        } 
        cout << S1 << "\n\n";
    } 
    //-----------------------------------------------------//
    static void all_lower(string S1) 
    { 
        bool isFirstLetter = true;     
        cout << "\nall string lower: \n"; 
        for (short i = 0; i < S1.length(); i++)     
        { 
            S1[i] = tolower(S1[i]);       
            //S1[i] = char ( int(S1[i] + 32));         
        } 
        cout << S1;
    } 
    //-----------------------------------------------------//
    static void first_letter_upper(string S1) 
    { 
        bool isFirstLetter = true;     
        cout << "\nFirst letters of this string: \n"; 
        for (short i = 0; i < S1.length(); i++)     
        { 
            if (S1[i] != ' ' && isFirstLetter)         
            {      
                S1[i] = toupper(S1[i]);       
                //S1[i] = char ( int(S1[i] - 32));         
            }         
            isFirstLetter = (S1[i] == ' ' ? true : false);     
        } 
        cout << S1;
    }
    //-----------------------------------------------------//
    static void first_letter_lower(string S1) 
    { 
        bool isFirstLetter = true;     
        cout << "\nFirst letters of this string: \n"; 
        for (short i = 0; i < S1.length(); i++)     
        { 
            if (S1[i] != ' ' && isFirstLetter)         
            {      
                S1[i] = tolower(S1[i]);       
                //S1[i] = char ( int(S1[i] + 32));         
            }         
            isFirstLetter = (S1[i] == ' ' ? true : false);     
        } 
        cout << S1;
    }
    //-----------------------------------------------------//
    static string encrypte_text(string message , int encryption_key = 4)
    {
        string message_encrypted = message;
        for (int i = 0; i < message.length(); i++)
        {
            message_encrypted[i] = char( int(message[i]) + encryption_key);
        }
    
        return message_encrypted;
    }
    //-----------------------------------------------------//
    static string decrypte_text(string  message_encrypted , int encryption_key = 4 )
    {
        string message = message_encrypted;
        for (int i = 0; i < message_encrypted.length(); i++)
        {
            message[i] = char( int(message_encrypted[i]) - encryption_key);
        }
    
        return message;
    }
    //-----------------------------------------------------//
    enum enCharType { Small_Letter = 1, Capital_Letter = 2,  Digit = 3 , Mix_Chars=4 , Special_Character = 5};

    static char GetRandomCharacter(enCharType CharType) 
    { 
        switch (CharType)     
        { 
            case enCharType::Small_Letter:     
            { 
                return char(RandomNumber(97, 122)); 
                break;     
            } 
            case enCharType::Capital_Letter:     
            { 
                return char(RandomNumber(65, 90)); 
                break;     
            } 
            case enCharType::Special_Character:     
            { 
                return char(RandomNumber(33, 47)); 
                break;     
            } 
            case enCharType::Digit:     
            { 
                return char(RandomNumber(48, 57)); 
                break;     
            }     
        } 
    } 

    static string GenerateWord(enCharType CharType, short Length) 
    { 
        string Word; 
        for (int i = 1; i <= Length; i++)     
        {         
            Word = Word + GetRandomCharacter(CharType);     
        } 
        return Word; 
    }

    static string  GenerateKey(enCharType CharType=Capital_Letter) 
    { 
        string Key = "";     
        Key = Key + GenerateWord(CharType, 5) + "-";     
        Key = Key + GenerateWord(CharType, 5) + "-";     
        Key = Key + GenerateWord(CharType, 5) + "-";     
        Key = Key + GenerateWord(CharType, 5) ;          
    
        return Key; 
    }
    
    static void GenerateKeys() 
    { 
        short NumberOfKeys = Read_positive_Number("enter number of keys you want to generate:");
        for (int i = 1; i <= NumberOfKeys; i++)     
        {         
            cout << "Key [" << i << "] : "; 
            cout << GenerateKey() << endl;     
        } 
    }


   static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomNumber(From, To);
    }

   static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType,short Wordlength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateWord(CharType,Wordlength);

    }

   static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
   {
       for (int i = 0; i < arrLength; i++)
           arr[i] = GenerateKey(CharType);
   }

   static  void Swap(int& A, int& B)
    {
        int Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

   static  void Swap(double& A, double& B)
   {
       double Temp;

       Temp = A;
       A = B;
       B = Temp;
   }

   static  void Swap(bool& A, bool& B)
   {
       bool Temp;

       Temp = A;
       A = B;
       B = Temp;
   }

   static  void Swap(char& A, char& B)
   {
       char Temp;

       Temp = A;
       A = B;
       B = Temp;
   }

   static  void Swap(string & A, string & B)
    {
        string Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

   static  void Swap(clsDate & A, clsDate& B)
   {
       clsDate::SwapDates(A, B);

   }

   static  void ShuffleArray(int arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }

    }

   static  void ShuffleArray(string arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }

    }

   static string  Tabs(short NumberOfTabs)
   {
       string t = "";

       for (int i = 1; i < NumberOfTabs; i++)
       {
           t = t + "\t";
           cout << t;
       }
       return t;

   }


   static string NumberToText(int Number)
   {

       if (Number == 0)
       {
           return "";
       }

       if (Number >= 1 && Number <= 19)
       {
           string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
       "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
         "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

           return  arr[Number] + " ";

       }

       if (Number >= 20 && Number <= 99)
       {
           string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
           return  arr[Number / 10] + " " + NumberToText(Number % 10);
       }

       if (Number >= 100 && Number <= 199)
       {
           return  "One Hundred " + NumberToText(Number % 100);
       }

       if (Number >= 200 && Number <= 999)
       {
           return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
       }

       if (Number >= 1000 && Number <= 1999)
       {
           return  "One Thousand " + NumberToText(Number % 1000);
       }

       if (Number >= 2000 && Number <= 999999)
       {
           return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
       }

       if (Number >= 1000000 && Number <= 1999999)
       {
           return  "One Million " + NumberToText(Number % 1000000);
       }

       if (Number >= 2000000 && Number <= 999999999)
       {
           return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
       }

       if (Number >= 1000000000 && Number <= 1999999999)
       {
           return  "One Billion " + NumberToText(Number % 1000000000);
       }
       else
       {
           return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
       }


   }

///////////////////////////////////////////////////////////////////
//deal with files

    static void create_file(string file_name , string message)
    {
        fstream myfile;
        myfile.open(file_name , ios::out); //write mode
        if (myfile.is_open())
        {
            myfile << message;
            myfile.close();
        }
    }
//-------------------------------------------------------------------------------------------------------//
    static void copy_content_to_vector(string file_name, vector <string> &v_file_content)
    {   
        v_file_content.clear();
        fstream myfile;
        myfile.open(file_name ,ios::in); // read mode
        if (myfile.is_open())
        {
            string line;
            while (getline(myfile,line))
            {
                v_file_content.push_back(line);
            }
            myfile.close();
        }
    }
//-------------------------------------------------------------------------------------------------------//
    static void save_vector_to_file(string file_name, vector <string> &v_file_content)
    {
        fstream myfile;
        myfile.open(file_name , ios::out); // (write mode): create a txt file , clear all data , add text that i write
        if (myfile.is_open())
        {
            for (string & line : v_file_content)
            {
                if (line != "")
                {
                    myfile << line << "\n";
                }
            
            }
            myfile.close();
        }
    }
//-------------------------------------------------------------------------------------------------------//
    static void delete_record_from_file(string file_name, vector <string> &v_file_content , string record)
    {
        for (string &line : v_file_content)
        {
            if (line == record)
            {
                line = "";
            }
        } 
        save_vector_to_file(file_name , v_file_content);
    }
//-------------------------------------------------------------------------------------------------------//
    static void update_record_from_file(string file_name, vector <string> &v_file_content , string deleted_record , string updated_record)
    {
        for (string &line : v_file_content)
        {
            if (line == deleted_record)
            {
                line = updated_record;
            }
        }
        save_vector_to_file(file_name , v_file_content);
    }
//-------------------------------------------------------------------------------------------------------//
    static void add_record_to_file(string file_name ,vector <string> &v_file_content, string added_record)
    {
        fstream myfile;
        myfile.open(file_name , ios::out | ios::app ); // append mode
        if (myfile.is_open())
        {
            myfile << added_record << "\n";   
            myfile.close();
        }
        copy_content_to_vector(file_name , v_file_content);
        
    }
//-------------------------------------------------------------------------------------------------------//
    static void print_file_content(string file_name )
    {
        fstream myfile;
        myfile.open(file_name , ios::in); // read mode
        if (myfile.is_open())
        {
            string line;
            while(getline(myfile,line))
            {
                cout << line << "\n";
            }
            myfile.close();
        }
    }
};
