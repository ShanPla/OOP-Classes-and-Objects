#include <iostream>
using namespace std;

//	Where Menu function is called
void Menu(){
	cout<<"Options";
	cout<<"\n1. Add Book";
	cout<<"\n2. Display Book";
	cout<<"\n3. Search Book";
	cout<<"\n4. Exit";
}

	char ans;
	int choice;
	int size;


class Details{
	private:
		
		string title,author;
		int year;
		
	public:
		
		void setTitle(string a){
			title = a;	
		}
		void setAuthor(string b){
			author = b;	
		}
		void setYear(int c){
			year = c;	
		}
		
		string getTitle(){
			return title;
		}
		string getAuthor(){
			return author;
		}
		int getYear(){
			return year;
		}
};

//  Declaration of Book
	Details Book[100];
	
//	Where addBook function is called	
void addBook(){
	
	string Title,Author;	
	int Year;
	
	for(int i = 0; i<size+1; i++){
		
	cout<<"\nEnter Book Title: ";
	getline(cin, Title);
	Book[size].setTitle(Title);
	
	cout<<"\nEnter Author Name: ";
	getline(cin, Author);
	Book[size].setAuthor(Author);
	
	cout<<"\nEnter Book Year: ";
	cin>>Year;
	Book[size].setYear(Year);

	size = size+1;

	cout<<"\nBook added successfully!";	
	cout<<"\nDo you want to add another book? (Y/N): \n"<<endl;
	cin>>ans;
	cin.ignore();	
	
	if(ans == 'N' || ans == 'n'){
		break;
	}
}
}

//	Where displayBook function is called
void displayBook(){
	
	system("CLS");	
	
	cout<<"Book List: ";
	cout<<"\nTitle		Author		Year"<<endl;
	
	for(int i = 0; i<size; i++){
		cout<<Book[i].getTitle()<<"		"<<Book[i].getAuthor()<<"		"<<Book[i].getYear()<<"\n"<<endl;

	}
}

//	Where searchBook function is called
void searchBook(){
	
	system("CLS");
	string search;
	bool bookFound = false;
	
	cout<<"Options";
	cout<<"\n1. Title";
	cout<<"\n2. Author";
	cout<<"\n3. Year";
	cout<<"\nWhat category would you like to search in?: ";
	cin>>choice;
	cin.ignore();
	
	if(choice == 1){
			
			cout<<"Please input title: ";
			getline(cin, search);
			
		for(int i = 0; i<size; i++){

			if(search.compare(Book[i].getTitle()) == 0){

				cout<<"\nBook found!";
				cout<<"\nBook's title: "<<Book[i].getTitle();
				cout<<"\nBook's author: "<<Book[i].getAuthor();
				cout<<"\nBook year: "<<Book[i].getYear()<<"\n"<<endl;	
				
				cout<<"Is this the book you're looking for? (Y/N): ";
				cin>>ans;
				cin.ignore();	
				
			if(ans == 'Y' || ans == 'y'){
				bookFound = true;
				break;
			}
			
			if(!(ans == 'Y' || ans == 'y')){
				continue;
			}
		}
	}
		if(!bookFound){
			cout<<"\nThere is no other book called "<<search<<" in the library."<<endl;
		}
}
	
	if(choice == 2){
			
			cout<<"Please input author name: ";
			getline(cin, search);
			
		for(int i = 0; i<size; i++){

			if(search.compare(Book[i].getAuthor()) == 0){
				
				cout<<"\nBook found!";
				cout<<"\nBook's title: "<<Book[i].getTitle();
				cout<<"\nBook's author: "<<Book[i].getAuthor();
				cout<<"\nBook year: "<<Book[i].getYear()<<"\n"<<endl;	
				
				cout<<"Is this the book you're looking for? (Y/N): ";
				cin>>ans;
				cin.ignore();	
				
			if(ans == 'Y' || ans == 'y'){
				bookFound = true;
				break;
			}
			
			if(!(ans == 'Y' || ans == 'y')){
				continue;
			}
		}
	}
		if(!bookFound){
			cout<<"\nThere is no other author called "<<search<<" in the library."<<endl;
		}
	}
	
	if(choice == 3){
			
			cout<<"Please input year of book: ";
			cin>>choice;
			cin.ignore();	
			
		for(int i = 0; i<size; i++){	

			if(choice == Book[i].getYear()){
				
				cout<<"\nBook found!";
				cout<<"\nBook's title: "<<Book[i].getTitle();
				cout<<"\nBook's author: "<<Book[i].getAuthor();
				cout<<"\nBook year: "<<Book[i].getYear()<<"\n"<<endl;	
				
				cout<<"Is this the book you're looking for? (Y/N): ";
				cin>>ans;
				cin.ignore();	
				
			if(ans == 'Y' || ans == 'y'){
				bookFound = true;
				break;
			}
			
			if(!(ans == 'Y' || ans == 'y')){
				continue;
			}
			}
		}
		if(!bookFound){
			cout<<"\nThere is no other book with the year of "<<search<<" in the library."<<endl;
		}
	}
}

int main(){

	do{

//	Calls Menu			
	Menu();

	cout<<"\nEnter choice: ";
	cin>>choice;
	cin.ignore();
	
//	Calls functions based on choice	
	switch(choice){
		case 1:
			addBook();
			break;
		
		case 2:
			displayBook();
			break;
		
		case 3:
			searchBook();
			break;
		
		case 4:
			cout<<"Terminating program..."<<endl;
			break;	
		
		default:
			cout<<"\nEnter choice 1-4."<<endl;
			break;							
	}
	
}while(choice!=4);
	
	return 0;
}