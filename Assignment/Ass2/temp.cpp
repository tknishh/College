#include<iostream>
#include<string.h>
using namespace std ;
class administration ;
class facality ;
class student 
{   friend class administration ;
     friend class facality ;
    string name ;
    int rollno ;

    public  :
     void diplay_student()
     { printf("%-6d",rollno );
       cout<<"                   "<<name ;
      
     }

};



class T1T2T3 : virtual public student
{ friend class facality ;
 friend class administration ;
  float T1 ,T2 ,T3 ;
   public :
  void display_t1t2t2()
  {
    cout<<"\n marks in :\n";
    cout<<"    T1 = "<<T1<<endl  ;
    cout<<"    T2 = "<<T2<<endl  ;
    cout<<"    T3 = "<<T3<<endl  ;
  }
  };

  class P1P2 :virtual public student
  {  friend class facality ;
   friend class administration ;
    float P1 ,P2 ;
    public :
    void displayp1p2()
    {
    cout<<"\n marks in :\n";
    cout<<"    P1 = "<<P1<<endl  ;
    cout<<"    P2 = "<<P2<<endl  ;
    }

  };

  class attendance :virtual public student
  {
       float attnd_prcnt ;
       public :
       void display_attendence()
       {
         cout<<"\npercentage of attendence : "<<attnd_prcnt ;
       }
  };

  class facality ;
  class total : virtual public T1T2T3 ,virtual public P1P2 , virtual public attendance
  {  friend class facality ;
     friend class administration ;
    float total_marks ;
    char grade ;
     public :
    void display_total()
    {
      cout<<"total marks = "<<total_marks ;
    }
    void display_grade()
    {
      cout<<"      "<<grade<<"                  " ;
    }
  };  

  
class facality 
{
  public :
 void get_exam_marks(total & t )
  {
    cout<<"\nenter the marks in :\n" ;
    cout<<"     T1 = ";
    cin>>t.T1 ;
    fflush(stdin) ;
     cout<<"     T2 = ";
    cin>>t.T2 ;
    fflush(stdin) ;
     cout<<"     T3 = ";
    cin>>t.T3 ;
    fflush(stdin) ;
     cout<<"     p1 = ";
    cin>>t.P1  ;
    fflush(stdin) ;
     cout<<"     P2 = ";
    cin>>t.P2 ;
    fflush(stdin) ;
    
   
  }
   void sorting1(total * t , int num )
    {  total temp ;
        
      for(int i= 0 ; i <num ;i++)
      {  for(int j = 1+i ;j < num ; j++ )
           {if (t[j].total_marks > t[i].total_marks)
              { temp = t[i] ;
               t[i] = t[j] ;
               t[j] = temp ;
              }
           }
            
      }
      for(int i =0 ;i< num ;i++)
         { for(int j= i+1 ; j<num ;j++)
           {
               if(t[i].grade == t[j].grade)
               {
                   if(t[i].name > t[j].name)
                     { total temp ;
                       temp = t[i] ;
                       t[i] = t[j] ;
                        t[j] = temp ;
                     }
               }
           }
         }  
       cout<<"    GRADE   |         ROLL NO        |                  NAME         \n" ;   
        cout<<"____________________________\n" ;
     for (int i =0 ;i < num ; i++)
    {   t[i].display_grade() ;
      t[i].diplay_student() ;
       
        cout<<"" ;


    }
    }

    void sorting2(total * t , int num )
    { 
       for(int i =0 ;i< num ;i++)
         { for(int j= i+1 ; j<num ;j++)
           {   
                if(t[i].name > t[j].name)
                     { total temp ;
                       temp = t[i] ;
                       t[i] = t[j] ;
                        t[j] = temp ;
                     }
               
           }
         }  
       cout<<"    GRADE   |         ROLL NO        |                  NAME         \n" ;   
        cout<<"____________________________\n" ;
     for (int i =0 ;i < num ; i++)
    {   t[i].display_grade() ;
      t[i].diplay_student() ;
       
        cout<<"\n_____|________|_______________\n" ;


    }


    }

    void searching (total * t , int num , string search){ 
     int k = 0 ;
     int length = search.length() ;
     for(int i = 0 ; i < num ; i ++ ){   
          if(t[i].name[length] == ' '){ 
              int j = 0 ;
              for( j = 0 ; j < length ; j ++ ){ 
		  int l= 0 ;
              if( search[j] != t[i].name[j])
                  break ;
              
                  if(j == length -1)
                  {
                        k ++ ;
                        if(l =0 )
                        {cout<<"    GRADE   |         ROLL NO        |                  NAME         \n" ;  
                              cout<<"____________________________\n" ; }
                                    t[i].display_grade() ;
                                     t[i].diplay_student() ;
       
                                  cout<<"\n_____|________|_______________\n"  ;
                   l = 1 ;
                                 
                  }
               

              
      }
          }
      }
	if(k==0){
          cout<<"\nno result found . " ;
      }
	}
}; 

  
class administration
{  public :
  void get_student(total& t)
  {  cout<<"enter name : " ;
      fflush(stdin) ;
    getline(cin , t.name ) ;
    fflush(stdin );
    cout<<"enter roll no : ";
    cin>> t.rollno ;
    fflush(stdin) ;
  }

   int total_marks(total& t)
   {
     t.total_marks = t.T1 + t.T2 + t.T3 + t.P1 + t.P2 ; 
     return t.total_marks ;
    }

    char grade(total & t)
    {
      if(t.total_marks /350 > 0.8)
       t.grade = 'A' ;
       else if ((t.total_marks/350) < 0.8 &&  (t.total_marks/100)>0.7)
       t.grade = 'B' ;
       else if ((t.total_marks/350) < 0.7 &&  (t.total_marks/100)>0.6)
       t.grade = 'C' ;
        else if ((t.total_marks/350) < 0.6 &&  (t.total_marks/100)>0.5)
       t.grade = 'D' ;
       else 
       t.grade = 'F' ;
       return t.grade ;
    }
  };
int main()
{   administration a;
    facality f ;
    cout<<"enter the number of students :";
    int num ;
    fflush(stdin) ;
     cin>> num ;
   total t[num] ;
   for(int i =0 ; i<num ;i++)
   {
     a.get_student(t[i]) ;
     f.get_exam_marks (t[i])  ;
     a.total_marks(t[i]) ;
     a.grade(t[i]) ;
   }
      cout<<"\n\n    print name and grade of students in ascending order of grade .if grades are then print name in respective alphabatical order .\n";
      cout<<"     using function 'sorting1 ' \n\n" ;
      f.sorting2(&t[0],num) ; 
      cout << " \n\n print name and grade in alphabatical order of name of student\n      using function 'sorting2' \n\n";
      f.sorting1(&t[0],num) ;
       cout<<"\n\nserch by first name of student\n     using function 'searching()'\n\n " ;
      cout<<"\n\nenter the first name to search : " ;
      string s ;
      cin >> s ;
    fflush(stdin) ;
    f.searching(&t[0],num , s) ;

    return 0 ;
    }
